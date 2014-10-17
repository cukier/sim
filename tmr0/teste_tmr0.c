#include <18F252.h>

#INT_TIMER0
void isr_tmr0 () {
	output_bit (pin_c0, ~input (pin_c0));
}

void main (void) {
	setup_timer_0 (T0_DIV_1);
	// setup_timer_0 (T0_INTERNAL | T0_DIV_32);
	enable_interrupts (INT_TIMER0);
	enable_interrupts (global);
	// fdasf
	while (true) {
		if (input (pin_b0)) {
			setup_timer_0 (T0_DIV_1);
		}
		else {
			setup_timer_0 (T0_OFF);
		}
	}
}