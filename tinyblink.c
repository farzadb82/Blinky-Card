/*
 * ATtiny13 LED Flasher
 * File: main.c
 */

#define F_CPU 1000000UL
 
#include <avr/io.h>
#include <util/delay.h>

#define output_low(port,pin) port &= ~(1<<pin)
#define output_high(port,pin) port |= (1<<pin)
#define output_toggle(port,pin) port ^= (1<<pin)
#define set_input(portdir,pin) portdir &= ~(1<<pin)
#define set_output(portdir,pin) portdir |= (1<<pin)

#define LED1 PB0
#define LED2 PB1
#define LED3 PB2


int main(void)
{
    const int msecsDelayPost = 500;
    
    // Setup the Port for I/O
    set_output(DDRB, LED1);
    set_output(DDRB, LED2);
    set_output(DDRB, LED3);
    
    // Setup the initial state
    output_low(PORTB, LED1);
    output_high(PORTB, LED2);
    output_low(PORTB, LED3);
    
    while (1) {
        // Toggle all ports
        output_toggle(PORTB, LED1);
        output_toggle(PORTB, LED2);
        output_toggle(PORTB, LED3);
        
        // Pause a little while
        _delay_ms (msecsDelayPost);
    }
    
    return 0;
}

