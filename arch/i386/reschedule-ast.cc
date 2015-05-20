#include "syscall.h"
#include "dispatch.h"
#include "idt.h"
#include "gdt.h"
#include "machine.h"
#include "paging.h"
#include "lapic.h"
#include "util/assert.h"
#include "os/scheduler/scheduler.h"

extern "C" uint8_t _estack_os;

namespace arch {

#ifdef CONFIG_ARCH_PRIVILEGE_ISOLATION
static const uint32_t iret_schedule[]  = {
	(uint32_t) __OS_ASTSchedule,
	GDT::USER_CODE_SEGMENT | 0x3,
	0x3200,
	(uint32_t) &(_estack_os) - 2048,
	GDT::USER_DATA_SEGMENT | 0x3
};
#endif

IRQ_HANDLER(IRQ_RESCHEDULE) {
#ifndef CONFIG_ARCH_PRIVILEGE_ISOLATION
	// If we have no privilege isolation, we have to switch to the os_stack
	asm volatile ("mov %0, %%esp;" :: "i"(&(_estack_os) - 2048));
#endif

	// block ISR2s by raising APIC task priority
	LAPIC::set_task_prio(128);

#ifdef CONFIG_ARCH_MPU
	// change to OS page directory
	PageDirectory::enable(pagedir_os);
#endif

	// reset save_sp to detect IRQ from non-userspace in idt.S
	save_sp = 0;

	// send end-of-interrupt signal
	LAPIC::send_eoi();

#ifdef CONFIG_ARCH_PRIVILEGE_ISOLATION

	// return from interrupt and proceed with syscall in ring 3
	asm volatile("mov %0, %%esp" :: "i"(&iret_schedule));
	Machine::return_from_interrupt();
#else
	__OS_ASTSchedule(0);
	Machine::unreachable();
#endif
}

}; // namespace arch
