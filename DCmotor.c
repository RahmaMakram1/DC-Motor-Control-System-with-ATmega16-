
#include "DCmotor.h"

void DCmotor_Init(void)
{
	/*Make PORTB pins 0,1 as output pins for the motor*/
	DDRB|=(1<<PB0)|(1<<PB1);

	/*The motor will start the operation rotating clockwise*/
	DCmotor_set_Operation_DirectionMode(DC_MOTOR_ROTATING_CLOCK_WISE);
}
void DCmotor_set_Operation_DirectionMode(uint8 motorDirection)
{

	switch (motorDirection)
	{
		/*Stop the motor's motion*/
	case 0:
		PORTB&=~ ( (PB0) | (PB1) );
		break;

	/*Rotate the motor in a Clock-wise manner*/
	case 1:
		PORTB&=~(1<<PB0);
		PORTB|=(1<<PB1);
		break;

	/*Rotate the motor in an Anti-Clock-wise manner*/
	case 2:
		PORTB ^= 0x03;
	}

}
