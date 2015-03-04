/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "global.h"
#include "c29_String.h"
#include "c11_Integer.h"
#include "c7_DebugOut.h"


#include "domains.h"
void PostTaskHook() {
	// At least an empty PostTaskHook to satisfy ProOSEK
}

void StartupHook() {
	/* Initialize keso_task_index */
	keso_task_index[keso_gc_task] = KESO_INVALID_TASK;
	keso_task_index[task1] = &__DOSEK_APPDATA_dom1__task1_obj;
	// Initialize heaps
	__DOSEK_APPDATA_dom1__DDesc.hd.freemem->size = 128;
	__DOSEK_APPDATA_dom1__DDesc.hd.freemem->next = (coffee_listel_t*) NULL;

	/* Call class constructors */
	{
		/* Domain: dom1 */
		c7_DebugOut_m3__clinit_();
	}

	/* Call each Task's constructor */
	c5_HelloWorld_m1__init_(((object_pointer) &__DOSEK_APPDATA_dom1__task1_user_obj));

}

void PreTaskHook() {
	// Initialize keso_curr_task and keso_curr_domain (if multi domain)
	KESO_TASKCLASSTYPE *ct = keso_curr_task_fkt();
	keso_curr_task = ct;
}

TASK (task1) {
	keso_stack_simple_t stack;
	stack.domain = ((domain_t *) &__DOSEK_APPDATA_dom1__DDesc);
	stack.llrefs = (object_pointer *) KESO_EOLL;
	stack.next = NULL;
	KESO_CURRENT_TASK->_stack = (keso_stack_t *)&stack;

	c5_HelloWorld_m3_run((object_pointer*)&(stack.llrefs),((object_pointer) &__DOSEK_APPDATA_dom1__task1_user_obj));
	stack.llrefs=NULL;
	KESO_CURRENT_TASK->_stack = NULL;
	TerminateTask();
}

