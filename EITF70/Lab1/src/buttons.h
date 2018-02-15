/*
 * buttons.h
 *
 *  Created on: 25 jan. 2018
 *      Author: cek11kmi
 */

#ifndef SRC_BUTTONS_H_
#define SRC_BUTTONS_H_

#define BUTTONS_DATA (unsigned int *) 	0x40000000
#define BUTTONS_CONTROL	(unsigned int *)	0x40000004
#define UP 0b00010
#define DOWN 0b10000
#define MIDDLE 0b00001
#define LEFT 0b00100
#define RIGHT 0b01000

#endif /* SRC_BUTTONS_H_ */
