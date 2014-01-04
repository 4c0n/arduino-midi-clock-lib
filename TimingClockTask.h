#ifndef TimingClockTask_h
#define TimingClockTask_h

#include "Arduino.h"
#include "MIDIClock.h"
#include <AbstractTask.h>
#include <MIDI.h>
#include <TimingClockMessage.h>

class TimingClockTask : public AbstractTask {
	private:
		TimingClockMessage msg;
		MIDI & midi = MIDI::getInstance();
	public:
		TimingClockTask(unsigned long executionTime) : AbstractTask(executionTime) {
		}


		virtual ~TimingClockTask() {
		}


		void execute() {
			this->midi.send(msg.getStatus());
		}
};

#endif 
