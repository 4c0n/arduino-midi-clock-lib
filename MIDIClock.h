#ifndef MIDIClock_h
#define MIDIClock_h

#include "Arduino.h"
#include <Scheduler.h>
#include <TimingClockMessage.h>

class MIDIClock {
	private:
		byte bpm;
		unsigned long lastExecutionTime;
		Scheduler scheduler;
		TimingClockMessage message;

	public:
		MIDIClock();
		MIDIClock(byte bpm);

	private:
		void init();
		unsigned long getIntervalMillis();
		unsigned long getIntervalMicros();

	public:
		void executeTimingClockTask();
		unsigned long getLastExecutionTime();
};

#endif
