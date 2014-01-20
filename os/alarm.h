#ifndef __OS_KRN_ALARM_H__
#define __OS_KRN_ALARM_H__

#include "stdint.h"
#include "counter.h"
#include "util/inline.h"

// TODO
//#include "scheduler/thetasks.h"
//#include "scheduler/scheduler.h"

// TESTING
#include "arch/i386/serial.h"
extern Serial serial;

namespace os {

class Alarm;
extern Alarm alarm0;

class Alarm {
	typedef uint32_t Ticks;

	// base
	Counter& configuration_;

	// state
	bool armed_;
	Ticks absoluteTime_;
	Ticks cycleTime_;

	// action
	// TODO
	//const Task* task_; // task to activate / set event to (if applicable)

public:
	// TODO
	//constexpr Alarm(Counter& counter) : configuration_(counter), armed_(false), absoluteTime_(0), cycleTime_(0), task_(0) {}
	//constexpr Alarm(Counter& counter, const Task& task) : configuration_(counter), armed_(false), absoluteTime_(0), cycleTime_(0), task_(&task) {}
	constexpr Alarm(Counter& counter) : configuration_(counter), armed_(false), absoluteTime_(0), cycleTime_(0) {}

	void setArmed (bool armed) {
		armed_ = armed;
	}

	bool getArmed () {
		return armed_;
	}

	void setAbsoluteTime (Ticks absoluteTime) {
		absoluteTime_ = absoluteTime;
	}

	void setRelativeTime (Ticks relativeTime) {
		Ticks remaining = configuration_.maxallowedvalue - configuration_.getValue();

		if(remaining >= relativeTime) {
			absoluteTime_ = configuration_.getValue() + relativeTime;
		} else {
			absoluteTime_ = relativeTime - remaining - 1;
		}
	}

	Ticks getAbsoluteTime () {
		return absoluteTime_;
	}

	void setCycleTime (Ticks cycleTime) {
		cycleTime_ = cycleTime;
	}

	Ticks getCycleTime () {
		return cycleTime_;
	}

	forceinline void triggerAction () {
		// TESTING
		serial << "TRIGGER ALARM" << endl;

		// TODO
		//if(task_) {
		//	scheduler::ActivateTask(*task_);
		//}
	}

	forceinline void trigger () {
		if(getCycleTime() > 0) {
			// reconf cyclic alarm
			setRelativeTime(getCycleTime());
		} else {
			// disable single shot
			setArmed(false);
		}

		triggerAction();
	}

	Ticks getRemainingTicks() {
		if(absoluteTime_ > configuration_.getValue()) {
			return absoluteTime_ - configuration_.getValue();
		} else {
			return absoluteTime_ + (configuration_.maxallowedvalue - configuration_.getValue());
		}
	}

	forceinline void checkTrigger(const Counter* counter) {
		if(getArmed() && (&configuration_ == counter) && getAbsoluteTime() == counter->getValue())
			trigger();
	}

	static forceinline void checkCounter(const Counter* counter) {
		// TODO: call all generated alarms
		alarm0.checkTrigger(counter);
	}
};

} // namespace os

#endif // __OS_KRN_ALARM_H__