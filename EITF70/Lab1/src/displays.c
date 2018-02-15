/* * displays.c
 *
 *  Created on: 24 jan. 2018
 *      Author: cek11kmi
 */

#include "displays.h"

const	unsigned	int	display_codes[]={
	0b0111111,		//	�index	0�
	0b0000110,		//	�index	1�
	0b1011011,		//	�index	2�
	0b1001111,		//	�index	3�
	0b1100110,		//	�index	4�
	0b1101101,		//	�index	5�
	0b1111101,		// �index	6�
	0b0000111,		//	�index	7�
	0b1111111,		//	�index	8�
	0b1101111};		//	�index	9�

void displayDigitAtIndex(unsigned char index, unsigned char digit) {
	if ((index < 8) && (digit < 10))
		*((unsigned int *) (SEVEN_SEGMENT_DISPLAY_BASE + index * 4)) =
				display_codes[digit];
}

unsigned int numberOfDigits(unsigned int x) {
	unsigned int count = 1;
	while (x / 10 > 0) {
		count++;
		x = x / 10;
	}
	return count;
}
void displayNumber(unsigned int x) {
	unsigned int index = 0;
	if (numberOfDigits(x) < 9)
		do {
			displayDigitAtIndex(index, x % 10);
			index++;
			x = x / 10;
		} while (x > 0);
}

void resetDisplayAtIndex(unsigned char index)
{
	if (index < 8)
	{
		*((unsigned int *) (SEVEN_SEGMENT_DISPLAY_BASE + index * 4)) = 0;
	}
}

void resetDisplays()
{
	for (int i = 0; i < 8; i++){
		resetDisplayAtIndex(i);
	}
}

void displayNumberAtIndex(unsigned char index, unsigned int number)
{
	if ((index + numberOfDigits(number)) < 9)
		do {
			displayDigitAtIndex(index, number % 10);
			index++;
			number = number / 10;
		} while (number > 0);
}

void displayNumberAtIndexAlarmClock(unsigned char index, unsigned int number)
{
	displayDigitAtIndex(index, number % 10);
	index++;
	displayDigitAtIndex(index, number/10);

}
