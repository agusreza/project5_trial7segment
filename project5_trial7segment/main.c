/*
 * project5_trial7segment.c
 *
 * Created: 18/11/2020 08:27:57
 * Author : agusr
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

/*
		a = PC0 
		b = PC1
		c = PC2
		d = PC3
		e = PC4
		f = PC5
		
		g = PB0
	   dp = PB1
	   
	   seg1 = PB2
	   seg2 = PB3
	   seg3 = PB4
	   seg4 = PB5
*/

char temporary;		// char 8 bit
char temporaryy[12]; // temporaryy[0]-temporary[11]

char seg_code[] =		//array
{
	// dp.g.f.e.d.c.b.a
	0b00111111,	// 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111, // 9
	0b10000000  // . 
};

void tampilkanAngka (int angkanya);
void segment1 (void);
void segment2 (void);
void segment3 (void);
void segment4 (void);

int main(void)
{
	
	DDRB = 0xff;
	DDRC = 0xff;
	
	PORTB = 0x00;
	
//	tampilkanAngka(2);
//	segment1();
	
    while (1) 
    {
		tampilkanAngka(1);
		segment1();
		_delay_ms(10);
		
		tampilkanAngka(2);
		segment2();
		_delay_ms(10);
		
		tampilkanAngka(3);
		segment3();
		_delay_ms(10);
		
		tampilkanAngka(4);
		segment4();
		_delay_ms(10);
    }
}

void tampilkanAngka (int angkanya)
{
	char temp0;
	
	// portC 
	// portB
	
	// dp.g.f.e.d.c.b.a
	// b7.b6.b5.b4.b3.b2.b1.b0	-> portC
	
	//       b5.b4.b3.b2.b1.b0	-> portC
	//                   dp. g	-> portB
	
	PORTC = seg_code[angkanya];
	
	temp0 = seg_code[angkanya];
	temp0 = temp0 >> 6;
	PORTB = temp0;
	
}

void segment1(void)
{
	char temp1;
	
	// cuma nyalakan 7segment D1, PortB2
	// b7.b6.b5.b4.b3.b2.b1.b0	-> portC
	
	//       b5.b4.b3.b2.b1.b0	-> portC
	//       s4.s3.s2.s1.dp. g	-> portB
	
	// PB2
	//PORTB = 0b11111011;
	
	/*
	baca portB 
	diolah -> s1 / PB2 aja
	keluarkan ke portB 
	*/
	
	temp1 =  PINB;
	temp1 &= 0b00000011;
	temp1 |= 0b11111000; //pasti PB2 = '0'
	PORTB =  temp1;
}


void segment2 (void)
{
	char temp1;
		
	temp1 =  PINB;
	temp1 &= 0b00000011;
	temp1 |= 0b11110100; //pasti PB3 = '0'
	PORTB =  temp1;
}
void segment3 (void)
{
	char temp1;
	
	temp1 =  PINB;
	temp1 &= 0b00000011;
	temp1 |= 0b11101100; //pasti PB4 = '0'
	PORTB =  temp1;
}
void segment4 (void)
{
	char temp1;
	
	temp1 =  PINB;
	temp1 &= 0b00000011;
	temp1 |= 0b11011100; //pasti PB5 = '0'
	PORTB =  temp1;
}




