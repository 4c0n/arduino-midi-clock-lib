#include "Arduino.h"
#include "MIDIClock.h"
#include "TimingClockTask.h"

MIDIClock::MIDIClock() : Scheduler(32) {
	this->bpm = 120;
	this->init();
}


MIDIClock::MIDIClock(byte bpm) : Scheduler(32) {
	this->bpm = bpm;
	this->init();
}


void MIDIClock::init() {
	unsigned long now = millis() + 500;

	for(int i = 0; i < 6; i++) {
		TimingClockTask * task = new TimingClockTask(now + (i * this->getIntervalMillis()));
		this->scheduleTask(task);
	}
}


unsigned long MIDIClock::getIntervalMillis() {
	return 60000 / this->bpm / 6;
}


unsigned long MIDIClock::getIntervalMicros() {
	return 60000000 / this->bpm / 6;
}


void MIDIClock::executeTimingClockTask() {
	this->executeTask();

	if(this->queue->getSize() < 6) {
		
	}
}
