/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#ifndef __C29_PRINTSTREAM_H__
#define __C29_PRINTSTREAM_H__
#include "keso_object_pointer.h"
#include "keso_types.h"

#define C29_PRINTSTREAM_ID ((class_id_t)29)

/* object data */
typedef struct {
/* c29_PrintStream */
/* c28_FilterOutputStream */
	object_pointer c28f1_out;
/* c27_OutputStream */
/* c1_Object */
OBJECT_HEADER
/* c1_Object */
/* c27_OutputStream */
/* c28_FilterOutputStream */
	jbyte c29f2_error;
/* c29_PrintStream */
} c29_PrintStream_t;
#define C29_PRINTSTREAM_OBJ(_obj_) ((c29_PrintStream_t*)((object_pointer*)(_obj_)-1))
#define ACCFIELD_C29_PRINTSTREAM_C29F2_ERROR(_obj_) (C29_PRINTSTREAM_OBJ(_obj_)->c29f2_error)
#define ACCFIELD_C29_PRINTSTREAM_C28F1_OUT(_obj_) (C29_PRINTSTREAM_OBJ(_obj_)->c28f1_out)
#define KESO_ALLOC_C29_PRINTSTREAM() KESO_ALLOC(C29_PRINTSTREAM_ID,sizeof(c29_PrintStream_t),1)
#define KESO_ALLOC_STACK_C29_PRINTSTREAM(_mem_) keso_alloc_stack((object_pointer)&(_mem_), C29_PRINTSTREAM_ID,sizeof(c29_PrintStream_t),1)
#define KESO_ALLOC_INLINE_C29_PRINTSTREAM() KESO_ALLOC(C29_PRINTSTREAM_ID,sizeof(c29_PrintStream_t),1)

/* class methods prototypes */
#define INVOKE_C29_PRINTSTREAM_M4_PRINTLN(_self_) ((void (*) (object_pointer obj0, jlong l1))dispatch_table[-29+(_self_)->class_id])
/* abstract method c29_PrintStream_m4_println */
#define c29_PrintStream_m4_println ((void (*) (object_pointer obj0, jlong l1))keso_throw_method_not_implemented("",0))
#define INVOKE_C29_PRINTSTREAM_M2_PRINTLN(_self_) ((void (*) (object_pointer obj0, object_pointer obj1))dispatch_table[-26+(_self_)->class_id])
/* abstract method c29_PrintStream_m2_println */
#define c29_PrintStream_m2_println ((void (*) (object_pointer obj0, object_pointer obj1))keso_throw_method_not_implemented("",0))
#define INVOKE_C29_PRINTSTREAM_M3_PRINT(_self_) ((void (*) (object_pointer obj0, object_pointer obj1))dispatch_table[-20+(_self_)->class_id])
/* abstract method c29_PrintStream_m3_print */
#define c29_PrintStream_m3_print ((void (*) (object_pointer obj0, object_pointer obj1))keso_throw_method_not_implemented("",0))
#define INVOKE_C29_PRINTSTREAM_M5_PRINTLN(_self_) ((void (*) (object_pointer obj0, jint i1))dispatch_table[-23+(_self_)->class_id])
/* abstract method c29_PrintStream_m5_println */
#define c29_PrintStream_m5_println ((void (*) (object_pointer obj0, jint i1))keso_throw_method_not_implemented("",0))



#endif /* !defined(__C29_PRINTSTREAM_H__) */
