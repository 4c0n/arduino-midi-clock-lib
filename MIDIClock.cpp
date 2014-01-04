#include "Arduino.h"
#include "MIDIClock.h"
#include "TimingClockTask.h"
#include <LedOffTask.h>

MIDIClock::MIDIClock() {
	this->bpm = 120;
	this->init();
}


MIDIClock::MIDIClock(byte bpm) {
	this->bpm = bpm;
	this->init();
}


void MIDIClock::init() {
	unsigned long now = millis() + 500;

	for(int i = 0; i < 6; i++) {
		this->lastExecutionTime = now + (i * this->getIntervalMicros());
		TimingClockTask * task = new TimingClockTask(this->lastExecutionTime);
		this->scheduler.scheduleTask(task);
	}
}


unsigned long MIDIClock::getIntervalMillis() {
	return (60000 / this->bpm) / 6;
}


unsigned long MIDIClock::getIntervalMicros() {
	return (60000000 / this->bpm) / 6;
}


void MIDIClock::executeTimingClockTask() {
	if(this->scheduler.executeTask()) {
		this->count++;
		if(this->count == 6) {
			this->count = 0;
			digitalWrite(13, HIGH);
		}
		else if(this->count == 1) digitalWrite(13, LOW);
	}

	if(this->scheduler.getNumTasksScheduled() < 6) {
		this->lastExecutionTime += this->getIntervalMicros();
		TimingClockTask * task = new TimingClockTask(this->lastExecutionTime);
		this->scheduler.scheduleTask(task);
	}
}

unsigned long MIDIClock::getLastExecutionTime() {
	return this->lastExecutionTime;
}
