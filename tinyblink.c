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

#define LED1 PB1
#define LED2 PB2
#define LED2 PB3


int main(void)
{
    const int msecsDelayPost = 500;
    
    // Set up Port B pin 4 mode to output
    DDRB |= 1<<LED1;
    
    // Set up Port B pin 4 mode to output
    DDRB |= 1<<LED2;
    
    // Set up Port B pin 4 mode to output
    DDRB |= 1<<LED3;
    
    // Set up Port B data to be all low
    PORTB = 0;  
    
    // Toggle Port B pin 4 output state
    PORTB ^= 1<<PB3;
    
    while (1) {
        // Toggle Port B pin 4 output state
        PORTB ^= 1<<PB4;

        // Toggle Port B pin 4 output state
        PORTB ^= 1<<PB3;
 
        // Pause a little while
        _delay_ms (msecsDelayPost);
    }
 
    return 0;
}

