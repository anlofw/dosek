#include <string.h>
#include <syscall.h>
#include <unistd.h>

#include "irq.h"
#include "os/scheduler/scheduler.h"

using namespace arch;

static void panic(int signal) {
	kout << "spurious interrupt: " << signal << endl;
}

IRQ::IRQ() {
    for(unsigned int i = 0; i < SIGMAX; i++)
        m_gate[i] = &panic;
	ast_level = 0;
	sigfillset(&full_mask);
}

void IRQ::set_handler(int signum, irq_handler_t handler) {
    m_gate[signum] = handler;
}

void IRQ::enable(int signum) {
    struct sigaction sig;

    memset(&sig, 0, sizeof(sig));
    sig.sa_handler = guardian;
    sig.sa_flags = SA_RESTART;
	sigfillset(&sig.sa_mask);

    sigaction(signum, &sig, NULL);
}

void IRQ::disable(int signum) {
    struct sigaction sig;

    memset(&sig, 0, sizeof(sig));
    sig.sa_handler = SIG_IGN;
    sig.sa_flags = SA_RESTART;

    sigaction(signum, &sig, NULL);
}

void IRQ::trigger_interrupt(int irq) {
	/* Send an signal to the current thread */
	unsigned int tid = ::syscall(SYS_gettid);
	::syscall(SYS_tgkill, getpid(), tid, irq);
}

void IRQ::disable_interrupts() {
	syscall(SYS_rt_sigprocmask, SIG_BLOCK, &full_mask, NULL, 8);
}

void IRQ::enable_interrupts() {
	syscall(SYS_rt_sigprocmask, SIG_UNBLOCK, &full_mask, NULL, 8);
}

bool IRQ::interrupts_enabled() {
	sigset_t mask;
	syscall(SYS_rt_sigprocmask, NULL, NULL, &mask, 8);
	return sigisemptyset(&mask);
}

void IRQ::guardian(int signum) {
	/* Interrupts are prohibited during the ISR */
	irq.ast_level++;
    irq.m_gate[signum](signum);
	irq.ast_level--;
	if (irq.ast_level == 0 && irq.ast_requested) {
		irq.ast_requested = false;
		__OS_ASTSchedule(0);
	}
}

IRQ arch::irq;
