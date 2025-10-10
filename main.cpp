/*
 * Lab6Task4.cpp
 *
 * Created: 10/10/2025 12:02:18 AM
 * Author : Usman
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void dat(unsigned char);
void keypad(void);

int main(void)
{
	DDRD = 0x0F;   // PD0..PD3 = outputs (rows), PD4..PD7 = inputs (columns)
	PORTD = 0xF0;  // enable pull-ups on PD4..PD7 (columns)
	DDRB = 0xFF;   // 7-seg output on PORTB

	while (1)
	{
		keypad();
	}
	return 0;
}

void keypad()
{
	unsigned char c1,c2,c3,c4;

	// Row1 (PD0 low)
	PORTD = 0xFE; // 1111 1110
	_delay_ms(2);
	c1 = (PIND & (1<<PIND4)) == 0;
	c2 = (PIND & (1<<PIND5)) == 0;
	c3 = (PIND & (1<<PIND6)) == 0;
	c4 = (PIND & (1<<PIND7)) == 0;
	if (c1) { dat(1); while((PIND & (1<<PIND4))==0); }
	else if (c2) { dat(2); while((PIND & (1<<PIND5))==0); }
	else if (c3) { dat(3); while((PIND & (1<<PIND6))==0); }
	else if (c4) { dat(10); while((PIND & (1<<PIND7))==0); }

	// Row2 (PD1 low)
	PORTD = 0xFD; // 1111 1101
	_delay_ms(2);
	c1 = (PIND & (1<<PIND4)) == 0;
	c2 = (PIND & (1<<PIND5)) == 0;
	c3 = (PIND & (1<<PIND6)) == 0;
	c4 = (PIND & (1<<PIND7)) == 0;
	if (c1) { dat(4); while((PIND & (1<<PIND4))==0); }
	else if (c2) { dat(5); while((PIND & (1<<PIND5))==0); }
	else if (c3) { dat(6); while((PIND & (1<<PIND6))==0); }
	else if (c4) { dat(15); while((PIND & (1<<PIND7))==0); }

	// Row3 (PD2 low)
	PORTD = 0xFB; // 1111 1011
	_delay_ms(2);
	c1 = (PIND & (1<<PIND4)) == 0;
	c2 = (PIND & (1<<PIND5)) == 0;
	c3 = (PIND & (1<<PIND6)) == 0;
	c4 = (PIND & (1<<PIND7)) == 0;
	if (c1) { dat(7); while((PIND & (1<<PIND4))==0); }
	else if (c2) { dat(8); while((PIND & (1<<PIND5))==0); }
	else if (c3) { dat(9); while((PIND & (1<<PIND6))==0); }
	else if (c4) { dat(12); while((PIND & (1<<PIND7))==0); }

	// Row4 (PD3 low)
	PORTD = 0xF7; // 1111 0111
	_delay_ms(2);
	c1 = (PIND & (1<<PIND4)) == 0;
	c2 = (PIND & (1<<PIND5)) == 0;
	c3 = (PIND & (1<<PIND6)) == 0;
	c4 = (PIND & (1<<PIND7)) == 0;
	if (c1) { dat(0); while((PIND & (1<<PIND4))==0); }
	else if (c2) { dat(13); while((PIND & (1<<PIND5))==0); }
	else if (c3) { dat(14); while((PIND & (1<<PIND6))==0); }
}

void dat(unsigned char y)
{
	unsigned char seven_seg_array[16] = {
		0x3F, // 0
		0x06, // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D, // 6
		0x07, // 7
		0x7F, // 8
		0x6F, // 9
		0x40, // 10 (-)
		0x49, // 11 (E)
		0x63, // 12 (C)
		0x71, // 13 (F)
		0x76, // 14 (H)
	};

	if (y == 15)
	{
		PORTB = 0x00; // clear display
	}
	else if (y < 15)
	{
		PORTB = seven_seg_array[y]; // output on PORTB
	}
}
