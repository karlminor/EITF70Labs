#ifndef SRC_TIMERS_H_
#define SRC_TIMERS_H_

#define TIMER1_CTRL	(unsigned int *)	0x41C10000
#define TIMER1_LOAD	(unsigned int *)	0x41C10004
#define TIMER2_CTRL	(unsigned int *)	0x41C00000
#define TIMER2_LOAD	(unsigned int *)	0x41C00004
extern unsigned int currentButtonsState;
extern unsigned int blinkerOnOff;

void initTimers();
void enableTimers();

void timer1InterruptHandler() __attribute__((fast_interrupt));
void timer2InterruptHandler() __attribute__((fast_interrupt));


#endif /* SRC_TIMERS_H_ */
