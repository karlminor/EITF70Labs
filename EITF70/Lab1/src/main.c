/* setup
 char b;
 int main() {
 b=9;
 while(1==1) {
 if(b<10){
 b--;
 }
 }
 return 0;
 }
 */

/* assignment 1
 unsigned char b;
 int main() {
 b=9;
 while(1==1) {
 if(b<10){
 b--;
 }
 }
 return 0;
 }
 */

/* assignment 2
 int b;
 int main() {
 b=9;
 while(1==1) {
 if(b<10){
 b--;
 }
 }
 return 0;
 }
 */

/* assignment 3
 unsigned int b;
 int main() {
 b=9;
 while(1==1) {
 if(b<10){
 b--;
 }
 }
 return 0;
 }
 */

/* assignment 4
 char b[10];
 int main() {
 int i;
 while(1==1) {
 for(i=0;i<10;i++){
 b[i]=i;
 }
 }
 return 0;
 }
 */

/* assignment 5
 int b[10];
 int main() {
 int i;
 while(1==1) {
 for(i=0;i<10;i++){
 b[i]=i;
 }
 }
 return 0;
 }
 */

/* assignment 6
 char *address;
 char b;
 int main(){
 b=0;
 address = &b;
 *address = 5;
 while(1==1){}
 return 0;
 }
 */

/* assignment 7
 char *address;
 int b;
 int main(){
 b=0XFFFFFFF;
 address = (char *)&b+3;
 *address += 0xF0;
 while(1==1){}
 return 0;
 }
 */

/* assignment 8
 #include "address_mapping.h"

 unsigned int state;
 unsigned int counter;
 int main() {
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 counter=10;
 while(1==1){
 while(counter>=0){
 state=*SWITCHES_DATA;
 *LED_DATA=counter;
 counter--;
 }
 }
 }
 */

/* assignment 9
 #include "address_mapping.h"

 unsigned int state;
 int main() {
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 *LED_DATA=10;
 while(1==1){
 while(*LED_DATA>=0){
 state=*SWITCHES_DATA;
 *LED_DATA=*LED_DATA-1;
 }
 }
 }
 */

/* assignment 10
 #include "address_mapping.h"

 unsigned int state;
 int main() {
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 *LED_DATA=10;
 while(1==1){
 state=*SWITCHES_DATA;
 *SWITCHES_DATA=0xFFFF;
 *LED_DATA=*SWITCHES_DATA;
 }
 }
 */

/* assignment 11
 #include "address_mapping.h"

 int main() {
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 *LED_DATA=0;
 while(1==1){
 *LED_DATA=*SWITCHES_DATA;
 }
 }
 */

/*#include "address_mapping.h"

 int state, *pointer;

 int main() {
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 *LED_DATA=0;
 while(1==1){
 state = *SWITCHES_DATA;
 int switchesOn = 0;
 for(int i = 0; i < 16; i++) {
 if(((state>>i) & 1) == 1) {
 switchesOn++;
 }
 }
 int display = 1;
 display = (display<<switchesOn)-1;

 *LED_DATA = display;
 }
 }
 */

//LAB 2:
/*unsigned int *LED_1;
 unsigned int value;
 int i;
 int main() {
 LED_1 = (unsigned int *) 0x44A00000;
 while (1 == 1) {
 value = 1;
 for (i = 1; i < 32; i++) {
 *LED_1 = value;
 value = value << 1;
 }
 }
 }
 */
/* Assignment 3
 #include "displays.h"
 unsigned char i;
 int main() {
 while (1 == 1) {
 for (i = 0; i < 10; i++)
 displayDigitAtIndex(i % 8, i);
 }
 }
 */
/*
 #include "displays.h"
 int main()
 {
 while (1==1){
 displayNumber(12345678);
 resetDisplays();
 displayNumber(11111111);
 resetDisplays();
 displayNumber(123456789);
 }
 }
 */
/*
 #include "displays.h"
 int main()
 {
 while (1==1){
 displayNumberAtIndex(3,55555);
 resetDisplays();
 displayNumberAtIndex(7,1);
 resetDisplays();
 displayNumberAtIndex(0,88888888);
 resetDisplays();
 displayNumberAtIndex(6, 333);
 }
 }
 */

/*#include "buttons.h"
 unsigned int state;
 int main()
 {
 *BUTTONS_CONTROL=0xFFFFFFFF;
 while (1==1)
 {
 state=*BUTTONS_DATA;
 }
 }*/

/*#include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 99990000;
 while (1 == 1) {
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == 0)
 ;	//keep reading the data register
 if (*BUTTONS_DATA == UP)
 counter++;
 if (*BUTTONS_DATA == DOWN)
 counter--;
 }
 }*/

/*#include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 0;
 while (1 == 1) {
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == 0);	//keep reading the data register
 buttons_state = *BUTTONS_DATA;
 if (buttons_state == UP)
 counter++;
 if (buttons_state == DOWN)
 counter--;
 while (*BUTTONS_DATA == buttons_state);
 }
 }
 */
/*
 #include	"buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 0;
 while (1 == 1) {
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == 0);
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;
 if (buttons_state == UP)
 counter++;
 if (buttons_state == DOWN)
 counter--;
 while (*BUTTONS_DATA == buttons_state);
 for (i = 0; i < 20000; i++);
 }
 }*/

/*#include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 0;
 while (1 == 1) {
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == 0);
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;
 if ((buttons_state & UP) == UP)
 counter++;
 if ((buttons_state & DOWN) == DOWN)
 counter--;
 while (*BUTTONS_DATA == buttons_state);
 for (i = 0; i < 20000; i++);
 }
 }
 */

/*#include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 99999997;
 while (1 == 1) {
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == 0);
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;
 if ((buttons_state & UP) == UP)
 if(!(numberOfDigits(counter+1)==9))
 {
 counter++;
 }
 if ((buttons_state & DOWN) == DOWN)
 if(counter != 0)
 {
 counter--;
 }
 while (*BUTTONS_DATA == buttons_state);
 for (i = 0; i < 20000; i++);
 }
 }
 */

/*#include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 99999997;
 displayNumber(counter);
 while (1 == 1) {
 while (*BUTTONS_DATA == 0);
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;
 if ((buttons_state & UP) == UP)
 if(!(numberOfDigits(counter+1)==9))
 {
 counter++;
 }
 if ((buttons_state & DOWN) == DOWN)
 if(counter != 0)
 {
 counter--;
 }
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == buttons_state);
 for (i = 0; i < 20000; i++);
 }
 }
 */

/*#include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 unsigned int pos;
 unsigned int previous_buttons_state;
 unsigned int action;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 0;
 pos = 0;
 resetDisplays();
 displayNumber(0);
 previous_buttons_state = 0;
 while (1 == 1) {
 while (*BUTTONS_DATA == 0) {
 previous_buttons_state = 0;
 }
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;
 if (previous_buttons_state < buttons_state) {
 action = buttons_state ^ previous_buttons_state;
 if ((action & UP) == UP && pos+numberOfDigits(counter+1) < 9) {
 counter++;
 }
 if ((action & DOWN) == DOWN && counter != 0) {
 counter--;
 }
 if ((action & LEFT) == LEFT && numberOfDigits(counter)+(pos+1) < 9) {
 pos++;
 }
 if ((action & RIGHT) == RIGHT && pos != 0) {
 pos--;
 }
 if ((action & MIDDLE) == MIDDLE) {
 counter = 0;
 pos = 0;
 }
 }
 resetDisplays();
 displayNumberAtIndex(pos, counter);
 previous_buttons_state = buttons_state;

 while (*BUTTONS_DATA == buttons_state);
 for (i = 0; i < 20000; i++);
 }
 }
 */
/*
 #include "address_mapping.h"
 void readSwitches_writeLed();
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 readSwitches_writeLed();
 }
 void readSwitches_writeLed() {
 unsigned int temp;
 temp = *SWITCHES_DATA;
 *LED_DATA = temp;
 }
 */
/*
 #include "address_mapping.h"
 void readSwitches_writeLed();
 unsigned int readSwitches();
 void writeLed(unsigned int value);
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 readSwitches_writeLed();
 }
 void readSwitches_writeLed() {
 unsigned int temp;
 temp = readSwitches();
 writeLed(temp);
 }
 unsigned int readSwitches() {
 unsigned int temp;
 temp = *SWITCHES_DATA;
 return temp;
 }
 void writeLed(unsigned int value) {
 *LED_DATA = value;
 }
 */
/*
 #include "address_mapping.h"
 void readSwitches_writeLed();
 unsigned int readSwitches();
 void writeLed(unsigned int value, unsigned int v1, unsigned int v2,
 unsigned int v3, unsigned int v4, unsigned int v5, unsigned int v6, unsigned int v7);
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 readSwitches_writeLed();
 }
 void readSwitches_writeLed() {
 unsigned int temp;
 temp = readSwitches();
 writeLed(temp, temp + 1, temp + 2,
 temp + 3, temp + 4, temp + 5, temp + 6, temp + 7); //the i-th argument is temp+i
 }
 unsigned int readSwitches() {
 unsigned int temp;
 temp = *SWITCHES_DATA;
 return temp;
 }
 void writeLed(unsigned int value, unsigned int v1, unsigned int v2,
 unsigned int v3, unsigned int v4, unsigned int v5, unsigned int v6, unsigned int v7) {
 *LED_DATA = value;
 }
 */
/*
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 readSwitches_writeLed_Assembly();
 }
 */

/*
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 function();
 }
 */
/*
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 #include "displays.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 process_switches();
 }

 */
/*
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 #include "displays.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 switches_battle();
 }
 */
/*
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 #include "displays.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1){
 switches_matcher();
 //count_switches();
 }
 }
 */
/*
 #include "displays.h"
 #include "address_mapping.h"
 #include "buttons.h"
 #include "interrupt_controller.h"
 #include "timers.h"
 #include "microBlaze.h"
 unsigned int currentButtonsState = 0;
 unsigned int prevButtonsState = 0;
 unsigned int blinker = 0b0001000;
 unsigned int blinkerOnOff = 0;
 unsigned int application_state = 0;
 unsigned char index_pos = 0;
 int main() {
 resetDisplays();
 initTimers();
 initController();
 enableMicroBlazeInterrupts();
 enableTimers();
 while (1 == 1) {
 switch (application_state) {
 case 0:
 *LED_DATA = 1 << application_state;
 if (currentButtonsState != prevButtonsState) {
 if (((currentButtonsState & MIDDLE)!= (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0))
 application_state++;
 if (((currentButtonsState & LEFT) != (prevButtonsState & LEFT)) && ((currentButtonsState & LEFT) != 0))
 if (index_pos< 7)
 index_pos++;
 if (((currentButtonsState & RIGHT) != (prevButtonsState & RIGHT)) && ((currentButtonsState & RIGHT) != 0))
 if (index_pos > 0)
 index_pos--;
 prevButtonsState = currentButtonsState;
 }
 resetDisplays();
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) = blinker & blinkerOnOff;
 break;
 case 1:
 *LED_DATA = 1 << application_state;
 if (currentButtonsState != prevButtonsState) {
 if (((currentButtonsState & MIDDLE)!= (prevButtonsState & MIDDLE))&& ((currentButtonsState & MIDDLE) != 0))
 application_state++;
 if (((currentButtonsState & RIGHT) != (prevButtonsState & RIGHT)) && ((currentButtonsState & RIGHT) != 0))
 if (index_pos< 7)
 index_pos++;
 if (((currentButtonsState & LEFT) != (prevButtonsState & LEFT)) && ((currentButtonsState & LEFT) != 0))
 if (index_pos > 0)
 index_pos--;
 prevButtonsState = currentButtonsState;
 }
 resetDisplays();
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) = blinker & blinkerOnOff;
 break;
 case 2:
 *LED_DATA = 1 << application_state;
 if (currentButtonsState != prevButtonsState) {
 if (((currentButtonsState & MIDDLE) != (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0))
 application_state++;
 if (((currentButtonsState & UP) != (prevButtonsState & UP)) && ((currentButtonsState & UP) != 0))
 if (index_pos< 7)
 index_pos++;
 if (((currentButtonsState & DOWN) != (prevButtonsState & DOWN)) && ((currentButtonsState & DOWN) != 0))
 if (index_pos> 0)
 index_pos--;
 prevButtonsState = currentButtonsState;
 }
 resetDisplays();
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) = blinker & blinkerOnOff;
 break;
 case 3:
 *LED_DATA = 1 << application_state;
 if (currentButtonsState != prevButtonsState) {
 if (((currentButtonsState & MIDDLE) != (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0))
 application_state=0;
 if (((currentButtonsState & DOWN) != (prevButtonsState & DOWN)) && ((currentButtonsState & DOWN) != 0))
 if (index_pos< 7)
 index_pos++;
 if (((currentButtonsState & UP) != (prevButtonsState & UP)) && ((currentButtonsState & UP) != 0))
 if (index_pos> 0)
 index_pos--;
 prevButtonsState = currentButtonsState;
 }
 resetDisplays();
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) = blinker & blinkerOnOff;
 break;
 default:
 break;
 }

 }
 }
 */

#include "displays.h"
#include "address_mapping.h"
#include "buttons.h"
#include "interrupt_controller.h"
#include "timers.h"
#include "microBlaze.h"
#include "alarm_clock.h"

/*
 *  Keeps the current state of the push buttons. Modified only in the interrupt handler for TIMER1 timer1AlarmClockInterruptHandler()
 */
unsigned int currentButtonsState = 0;

/*
 *  Keeps the previous state of the push buttons
 */
unsigned int prevButtonsState = 0;

/*
 *  Keeps the binary pattern for the bottom-most horizontal segment
 */
unsigned int blinker = 0b0001000;

/*
 *  Changes from 0x00000000 to 0xFFFFFFFF and vice-versa. Modified only in the interrupt handler for TIMER1 timer1AlarmClockInterruptHandler()
 *  Used to indicate if the blinker should be on or off
 */
unsigned int blinkerOnOff = 0;

/*
 *  Keeps track of the current state of the alarm-clock.
 *  value 0 == RUN state
 *  value 1 == SET_TIME state
 *  value 2 == SET_ALARM state
 *  value 3 == ALARM state
 */
unsigned int alarmclock_state = 0;

/*
 *  Keeps track of the index of the seven-segment display whose value might be modified by pressing the up or the down button
 */
unsigned char index_pos = 0;

/*
 *  Keeps the time set by the user.
 *  Element at index 0 refers to hours and should only accept values in the range 0-23
 *  Element at index 1 refers to minutes and should only accept values in the range 0-59
 *  Element at index 2 refers to seconds and should only accept values in the range 0-59
 *  Element at index 3 refers to hundreds of a second and should only accept values in the range 0-99
 */
unsigned char newTime[4];

/*
 *  Keeps the running time.
 *  Modified in the interrupt handler for TIMER1 timer1AlarmClockInterruptHandler() or when the state changes from SET_TIME to RUN
 *  Element at index 0 refers to hours and should only accept values in the range 0-23
 *  Element at index 1 refers to minutes and should only accept values in the range 0-59
 *  Element at index 2 refers to seconds and should only accept values in the range 0-59
 *  Element at index 3 refers to hundreds of a second and should only accept values in the range 0-99
 */
unsigned char currentTime[4];

/*
 *  Keeps the time that indicates when the alarm goes off.
 *  Element at index 0 refers to hours and should only accept values in the range 0-23
 *  Element at index 1 refers to minutes and should only accept values in the range 0-59
 *  Element at index 2 refers to seconds and should only accept values in the range 0-59
 *  Element at index 3 refers to hundreds of a second and should only accept values in the range 0-99
 */
unsigned char alarmTime[4];

/*
 *  Implement the code based on the description written as a comment
 */

int main() {
	resetDisplays();
	initTimers_alarmClock();
	initController_alarmClock();
	enableTimer1();
	enableMicroBlazeInterrupts();
	currentTime[0] = 23;
	currentTime[1] = 59;
	currentTime[2] = 50;
	currentTime[3] = 23;
	while (1 == 1) {
		switch (alarmclock_state) {
		case 0:

			/*
			 * Turn off the 16 LEDs.
			 * Displays the current time on the eight seven-segment displays
			 * Changes the state of the alarm-clock to ALARM and enables TIMER2 only if the current time is the same as the alarm time and the leftmost switch is turned on
			 * Checks if the UP or DOWN button are pressed now but has not been pressed before
			 * If the UP button is pressed now, but has not been pressed before
			 * 			-the state of the alarm-clock changes to SET_TIME
			 * 			-the newTime is set to the same value as the currentTime
			 * 			-the newTime is displayed on the eight seven-segment displays
			 * 			-the index_pos is initialized to zero
			 * If the DOWN button is pressed now, but has not been pressed before
			 * 			-the state of the alarm-clock changes to SET_ALARM
			 * 			-the alarmTime is displayed on the eight seven-segment displays
			 * 			-the index_pos is initialized to zero
			 * 			-the 16 LEDs are turned on
			 */

			*LED_DATA = 0;
			display(currentTime);

			if (compareTimeArray(currentTime, alarmTime)
					&& *SWITCHES_DATA > 0b111111111111111) {
				display(currentTime);
				alarmclock_state = 3;
				enableTimer2();
			}
			if (currentButtonsState != prevButtonsState) {
				if (((currentButtonsState & UP) != (prevButtonsState & UP))
						&& ((currentButtonsState & UP) != 0)) {
					alarmclock_state = 1;
					setTime(newTime, currentTime);
					display(newTime);
					index_pos = 0;
				}
				if (((currentButtonsState & DOWN) != (prevButtonsState & DOWN))
						&& ((currentButtonsState & DOWN) != 0)) {
					alarmclock_state = 2;
					display(alarmTime);
					index_pos = 0;
					*LED_DATA = 0xFFFF;
				}
				prevButtonsState = currentButtonsState;
			}

			break;
		case 1:
			/*
			 * Only when the state of the buttons has changed, the newTime is displayed
			 * If the UP or DOWN buttons are pressed now, but have not been pressed before
			 * 		-based on the index_pos, the corresponding element in the newTime array is incremented or decremented
			 * If the LEFT or RIGHT buttons are pressed now, but have not been pressed before
			 * 		-the index_pos is incremented/decremented by 2
			 * If the MIDDLE button is pressed now, but has not been pressed before,
			 * 		-the currentTime is set to be the same as the newTime
			 * 		-the state of the alarm-clock changes to RUN
			 * Based on the blinkerOnOff variable, the bottom-most horizontal segments of the displays with indices "index_pos" and "index_pos+1" are turned-on or turned-off
			 * NOTE: The data registers of the SEVEN_SEGMENT_DISPLAY device are read-write registers, i.e. when reading the data register controlling a particular seven-segment display, one obtains the same information that is used to drive (control) the seven-segment display
			 */
			if (currentButtonsState != prevButtonsState) {
				if (((currentButtonsState & MIDDLE)
						!= (prevButtonsState & MIDDLE))
						&& ((currentButtonsState & MIDDLE) != 0)) {
					setTime(currentTime, newTime);
					alarmclock_state = 0;
				}
				if (((currentButtonsState & RIGHT) != (prevButtonsState & RIGHT))
						&& ((currentButtonsState & RIGHT) != 0)) {
					if (index_pos > 0) {
						display(newTime);
						index_pos -= 2;
					}
				}
				if (((currentButtonsState & LEFT) != (prevButtonsState & LEFT))
						&& ((currentButtonsState & LEFT) != 0)) {
					if (index_pos < 6) {
						display(newTime);
						index_pos += 2;
					}
				}
				if (((currentButtonsState & UP) != (prevButtonsState & UP))
						&& ((currentButtonsState & UP) != 0)) {
					switch (index_pos) {
					case 0:

						if (newTime[3] == 99) {
							newTime[3] = 0;
						} else {
							newTime[3]++;
						}
						break;
					case 2:

						if (newTime[2] == 59) {
							newTime[2] = 0;
						} else {
							newTime[2]++;
						}
						break;
					case 4:

						if (newTime[1] == 59) {
							newTime[1] = 0;
						} else {
							newTime[1]++;
						}
						break;
					case 6:

						if (newTime[0] == 23) {
							newTime[0] = 0;
						} else {
							newTime[0]++;
						}
						break;
					default:
						break;
					}
					display(newTime);
				}
				if (((currentButtonsState & DOWN) != (prevButtonsState & DOWN))
						&& ((currentButtonsState & DOWN) != 0)) {
					switch (index_pos) {
					case 0:
						if (newTime[3] == 0) {
							newTime[3] = 99;
						} else {
							newTime[3]--;
						}
						break;
					case 2:
						if (newTime[2] == 0) {
							newTime[2] = 59;
						} else {
							newTime[2]--;
						}
						break;
					case 4:
						if (newTime[1] == 0) {
							newTime[1] = 59;
						} else {
							newTime[1]--;
						}
						break;
					case 6:
						if (newTime[0] == 0) {
							newTime[0] = 23;
						} else {
							newTime[0]--;
						}
						break;
					default:
						break;
					}
					display(newTime);
				}
				prevButtonsState = currentButtonsState;
			}
			blink();
			break;
		case 2:
			/*
			 * Only when the state of the buttons has changed, the alarmTime is displayed
			 * If the UP or DOWN buttons are pressed now, but have not been pressed before
			 * 		-based on the index_pos, the corresponding element in the alarmTime is incremented or decremented
			 * If the LEFT or RIGHT buttons are pressed now, but have not been pressed before
			 * 		-the index_pos is incremented/decremented by 2
			 * If the MIDDLE button is pressed now, but has not been pressed before,
			 * 		-the 16 LEDs are turned off
			 * 		- the state of the alarm-clock changes to RUN
			 * Based on the blinkerOnOff variable, the bottom-most horizontal segments of the displays with indices "index_pos" and "index_pos+1" are turned-on or turned-off
			 * NOTE: The data registers of the SEVEN_SEGMENT_DISPLAY device are read-write registers, i.e. when reading the data register controlling a particular seven-segment display, one obtains the same information that is used to drive (control) the seven-segment display
			 */
			if (currentButtonsState != prevButtonsState) {
				if (((currentButtonsState & MIDDLE)
						!= (prevButtonsState & MIDDLE))
						&& ((currentButtonsState & MIDDLE) != 0)) {
					alarmclock_state = 0;
				}
				if (((currentButtonsState & RIGHT) != (prevButtonsState & RIGHT))
						&& ((currentButtonsState & RIGHT) != 0)) {
					if (index_pos > 0) {
						display(alarmTime);
						index_pos -= 2;
					}
				}
				if (((currentButtonsState & LEFT) != (prevButtonsState & LEFT))
						&& ((currentButtonsState & LEFT) != 0)) {
					if (index_pos < 6) {
						display(alarmTime);
						index_pos += 2;
					}
				}
				if (((currentButtonsState & UP) != (prevButtonsState & UP))
						&& ((currentButtonsState & UP) != 0)) {
					switch (index_pos) {
					case 0:

						if (alarmTime[3] == 99) {
							alarmTime[3] = 0;
						} else {
							alarmTime[3]++;
						}
						break;
					case 2:

						if (alarmTime[2] == 59) {
							alarmTime[2] = 0;
						} else {
							alarmTime[2]++;
						}
						break;
					case 4:

						if (alarmTime[1] == 59) {
							alarmTime[1] = 0;
						} else {
							alarmTime[1]++;
						}
						break;
					case 6:

						if (alarmTime[0] == 23) {
							alarmTime[0] = 0;
						} else {
							alarmTime[0]++;
						}
						break;
					default:
						break;
					}
					display(alarmTime);
				}
				if (((currentButtonsState & DOWN) != (prevButtonsState & DOWN))
						&& ((currentButtonsState & DOWN) != 0)) {
					switch (index_pos) {
					case 0:
						if (alarmTime[3] == 0) {
							alarmTime[3] = 99;
						} else {
							alarmTime[3]--;
						}
						break;
					case 2:
						if (alarmTime[2] == 0) {
							alarmTime[2] = 59;
						} else {
							alarmTime[2]--;
						}
						break;
					case 4:
						if (alarmTime[1] == 0) {
							alarmTime[1] = 59;
						} else {
							alarmTime[1]--;
						}
						break;
					case 6:
						if (alarmTime[0] == 0) {
							alarmTime[0] = 23;
						} else {
							alarmTime[0]--;
						}
						break;
					default:
						break;
					}
					display(alarmTime);
				}
				prevButtonsState = currentButtonsState;
			}
			blink();
			break;
		case 3:
			/*
			 * Based on the state of blinkerOnOff, the 16 LEDs are turned on or off
			 * Checks if the state of the buttons has changed
			 * If the MIDDLE button is pressed, but has not been pressed before
			 * 		-the alarmTime is incremented by 5s
			 * 		-TIMER2 is stopped an the interrupts in the device are acknowledged
			 * 		-the alarm-clock state is changed to RUN
			 */
			if (currentButtonsState != prevButtonsState) {
				if (((currentButtonsState & MIDDLE)
						!= (prevButtonsState & MIDDLE))
						&& ((currentButtonsState & MIDDLE) != 0)) {
					snooze();

					*TIMER2_CTRL &= (~(1 << 7)); //disable timer
					*TIMER2_CTRL |= (1 << 8);
					*IAR = 0b100;
					alarmclock_state = 0;

				}
				prevButtonsState = currentButtonsState;
			}
			alarm();
			break;
		default:
			break;
		}
	}
}

void initTimers_alarmClock() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */

	*TIMER1_LOAD = 999999;
	*TIMER1_CTRL = (1 << 8) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 1);
	*TIMER2_LOAD = 0xFFFFFFFF - 500000000;
	*TIMER2_CTRL = (1 << 8) | (1 << 6) | (1 << 5);

}

void enableTimer1() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	*TIMER1_CTRL = (*TIMER1_CTRL | (1 << 7)) & (~(1 << 5));

}

void enableTimer2() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	*TIMER2_CTRL = (1 << 8) | (1 << 6) | (1 << 5);
	*TIMER2_CTRL = (*TIMER2_CTRL | (1 << 7)) & (~(1 << 5));
}

void display(unsigned char *time_array) {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	int index = 6;
	for (int i = 0; i < 4; i++) {
		displayNumberAtIndexAlarmClock(index, time_array[i]);
		index -= 2;
	}
}

unsigned int compareTimeArray(unsigned char * time_array1,
		unsigned char *time_array2) {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	for (int i = 0; i < 4; i++) {
		if (time_array1[i] != time_array2[i]) {
			return 0;
		}
	}
	return 1;
}

void setTime(unsigned char *newTime_array, unsigned char *oldTime_array) {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	for (int i = 0; i < 4; i++) {
		newTime_array[i] = oldTime_array[i];
	}
}

void initController_alarmClock() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	*IER |= 0b110;
	*IVAR1 = (unsigned int) timer1AlarmClockInterruptHandler;
	*IVAR2 = (unsigned int) timer2AlarmClockInterruptHandler;
	*MER |= 0b11;
}

void timer1AlarmClockInterruptHandler() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	if (currentTime[3] == 99) {
		currentTime[3] = 0;
		if (currentTime[2] == 59) {
			currentTime[2] = 0;
			if (currentTime[1] == 59) {
				currentTime[1] = 0;
				if (currentTime[0] == 23) {
					currentTime[0] = 0;
				} else {
					currentTime[0] += 1;
				}
			} else {
				currentTime[1] += 1;
			}
		} else {
			currentTime[2] += 1;
		}
	} else {
		currentTime[3] += 1;
	}

	if (currentTime[3] % 2 == 0) {
		currentButtonsState = *BUTTONS_DATA;
	}
	if (currentTime[3] % 25 == 0) {
		blinkerOnOff = ~blinkerOnOff;
	}
	*TIMER1_CTRL |= (1 << 8);
	*IAR = 0b10;
}

void timer2AlarmClockInterruptHandler() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	alarmclock_state = 0;
	*TIMER2_CTRL |= (1 << 8);
	*IAR = 0b100;
}

void blink() {
	if (blinkerOnOff == 0xFFFFFFFF) {
		*((unsigned int *) (SEVEN_SEGMENT_DISPLAY_BASE + index_pos * 4)) |=
				blinker;
		*((unsigned int *) (SEVEN_SEGMENT_DISPLAY_BASE + (index_pos + 1) * 4)) |=
				blinker;
	} else {
		*((unsigned int *) (SEVEN_SEGMENT_DISPLAY_BASE + index_pos * 4)) &=
				~blinker;
		*((unsigned int *) (SEVEN_SEGMENT_DISPLAY_BASE + (index_pos + 1) * 4)) &=
				~blinker;
	}
}

void alarm() {
	if (blinkerOnOff == 0xFFFFFFFF) {
		*LED_DATA = 0xFFFF;
	} else {
		*LED_DATA = 0;
	}
}

void snooze() {
	if (alarmTime[2] >= 55) {
		alarmTime[2] = (alarmTime[2]+5)%60;
		if (alarmTime[1] == 59) {
			alarmTime[1] = 0;
			if (alarmTime[0] == 23) {
				alarmTime[0] = 0;
			} else {
				alarmTime[0] += 1;
			}
		} else {
			alarmTime[1] += 1;
		}
	} else {
		alarmTime[2] += 5;
	}
}

