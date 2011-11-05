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
    const int msecsDelayPost = 700;
    int output[] = { 1, 2, 4, 7, 0, 7, 3, 6, 7, 4, 2, 1, 0 };
    int idx = 0;
    
    // Setup the Port for I/O
    set_output(DDRB, LED1);
    set_output(DDRB, LED2);
    set_output(DDRB, LED3);
    
    // Setup the initial state
    output_low(PORTB, LED1);
    output_low(PORTB, LED2);
    output_low(PORTB, LED3);
    
    while (1) {
        // Toggle all ports
        PORTB = output[idx];
        
        // Pause a little while
        _delay_ms (msecsDelayPost);
        
        idx += 1;
        if (idx > sizeof(output)) { idx = 0; }
    }
    
    return 0;
}

