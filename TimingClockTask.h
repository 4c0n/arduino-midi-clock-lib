#ifndef TimingClockTask_h
#define TimingClockTask_h

#include "Arduino.h"
#include "MIDIClock.h"
#include <AbstractTask.h>
#include <TimingClockMessage.h>

class TimingClockTask : public AbstractTask {
	private:
		MIDIClock * clock;
	public:
		TimingClockTask(unsigned long executionTime, MIDIClock * clock) : AbstractTask(executionTime) {
			this->clock = clock;
		}

		void execute() {

		}
};

#endif 
