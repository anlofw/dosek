/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#ifndef __C5_HELLOWORLD_H__
#define __C5_HELLOWORLD_H__
#include "keso_object_pointer.h"
#include "keso_types.h"

#define C5_HELLOWORLD_ID ((class_id_t)5)

/* object data */
typedef struct {
/* c5_HelloWorld */
/* c1_Object */
OBJECT_HEADER
/* c1_Object */
	jint c5f1_runs;
/* c5_HelloWorld */
} c5_HelloWorld_t;
#define C5_HELLOWORLD_OBJ(_obj_) ((c5_HelloWorld_t*)(_obj_))
#define ACCFIELD_C5_HELLOWORLD_C5F1_RUNS(_obj_) (C5_HELLOWORLD_OBJ(_obj_)->c5f1_runs)
#define KESO_ALLOC_C5_HELLOWORLD() KESO_ALLOC(C5_HELLOWORLD_ID,sizeof(c5_HelloWorld_t),0)
#define KESO_ALLOC_STACK_C5_HELLOWORLD(_mem_) keso_alloc_stack((object_pointer)&(_mem_), C5_HELLOWORLD_ID,sizeof(c5_HelloWorld_t),0)
#define KESO_ALLOC_INLINE_C5_HELLOWORLD() KESO_ALLOC(C5_HELLOWORLD_ID,sizeof(c5_HelloWorld_t),0)

/* class methods prototypes */
/* c5_HelloWorld_m1__init_ #non_blocking */
/* <init>()V */
void c5_HelloWorld_m1__init_(object_pointer obj0);
/* c5_HelloWorld_m2_printList c28_EventService_m1_waitEvent */
/* printList(Ltest/QueueElement;)V */
void c5_HelloWorld_m2_printList(object_pointer* pref, object_pointer obj0, object_pointer obj1);
/* c5_HelloWorld_m3_run c5_HelloWorld_m2_printList */
/* run()V */
void c5_HelloWorld_m3_run(object_pointer* pref, object_pointer obj0);



#endif /* !defined(__C5_HELLOWORLD_H__) */