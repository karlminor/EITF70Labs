/*
 * displays.h
 *
 *  Created on: 24 jan. 2018
 *      Author: cek11kmi
 */

#ifndef SRC_DISPLAYS_H_
#define SRC_DISPLAYS_H_

#define SEVEN_SEGMENT_DISPLAY_BASE 0x44A00000

#endif /* SRC_DISPLAYS_H_ */

void displayDigitAtIndex(unsigned char index, unsigned char digit);
unsigned int numberOfDigits(unsigned int x);
void displayNumber(unsigned int x);
void resetDisplayAtIndex(unsigned char index);
void resetDisplays();
void displayNumberAtIndex(unsigned char index, unsigned int number);
void displayNumberAtIndexAlarmClock(unsigned char index, unsigned int number);
