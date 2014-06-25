

#include "os.h"
#include "depsvc.h"
#include "arch/generic/hardware_threads.h"
#include "dependability_service.h"
#include "output.h"

DeclareTask(CheckedTask);
DeclareAlarm(PeriodicActivation);
DeclareCounter(PeriodicActivationCounter);

typedef char chararray[100];
DeclareCheckedObject(area, chararray);

/* Implementation that must be moved to the generator */
#include "dependability_service.h"
struct Checked_Object obj(area, 100);

void OSEKOS_AcquireCheckedObject(CHECKEDOBJECTStruct *s)
{
	acquire_CheckedObject(&obj);
}
void OSEKOS_ReleaseCheckedObject(CHECKEDOBJECTStruct *s)
{
	release_CheckedObject(&obj);
}
/********/

const unsigned int stacksize = 4096;
char dependability_stack[stacksize];

void os_main()
{
	arch::start_hardware_thread(1, dependability_stack, stacksize, dependability_service);
	StartOS(0);
}

TASK(CheckedTask) {
	static unsigned int c = 0;
	/* Implementation that must be moved to the generator */
	if (!c)
		dep_queue.insert(&obj);
	/**********/
	AcquireCheckedObject(area);
	for (unsigned int i = 1; i < sizeof(area); ++i) {
		area[i] = area[i - 1] + 1;
	}
	ReleaseCheckedObject(area);
	kout << c << endl;
	if (++c > 10) {
		ShutdownMachine();
	}
	TerminateTask();
}
