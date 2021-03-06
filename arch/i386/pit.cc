/**
 * @file
 * @ingroup i386
 * @brief i386 Programmable Interval Timer (PIT)
 */

#include "pit.h"
#include "ioport.h"
#include "machine.h"
#include "idt.h"
#include "pic.h"
#include "ioapic.h"
#include "os/counter.h"
#include "paging.h"

namespace arch {

void PIT::init() {
	// generate interrupt @ 1 kHz
	set_periodic(1000);

	// setup IRQ handler
	/* HACK:
	   The PIT is sometimes connected to pin 0 (Bochs),
	   and sometimes to pin 2 (QEMU) of the I/O APIC, so we setup both.
	   The real solution is to parse the multiprocessor tables for
	   redirection entries, but that would be *much* more work.

	   Alternative solution: unmask PIT interrupt (only!) in PIC and
	   use the LAPIC LINT0 handler.
	*/
	IOAPIC::setup_irq(0, 48); // Bochs
	IOAPIC::setup_irq(2, 48); // QEMU
}

void PIT::set_periodic(uint16_t rate) {
	uint16_t divisor = PIT_RATE / rate;

	// lo+hi byte, square wave generator mode
	outb(PIT_COMMAND_PORT, 0x36);
	io_wait();
	outb(PIT_CHANNEL0_PORT, divisor & 0xFF);
	io_wait();
	outb(PIT_CHANNEL0_PORT, divisor >> 8);
}



/** \brief PIT interrupt handler */
ISR(IRQ_PIT) {
	// increment counters
	os::Counter::tick();

	// send end of interrupt
	LAPIC::send_eoi();
}

}; // namespace arch
