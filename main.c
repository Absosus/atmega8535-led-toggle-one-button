#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int num;

ISR(INT0_vect){
	num++;
	if (num == 1){
		PORTA &= ~(1<<PA0);
	} else if (num == 2){
		PORTA |= (1<<PA0);
	} else {
		PORTA &= ~(1<<PA0);
	}
}

int main(){
	DDRA = 0x01;
	PORTA &= ~(1<<PA0);
	GICR = 0b01000000;
	DDRD |= (1<<PD2);
	PORTD |= (1<<PD2);
	MCUCR &= ~((1<<ISC01) | (1<<ISC00));
	sei();
	while(1){
		_delay_ms(100);
		num = 0;
	}
	return 0;
}