/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#ifndef __C11_EXCEPTION_H__
#define __C11_EXCEPTION_H__
#include "keso_object_pointer.h"
#include "keso_types.h"

#define C11_EXCEPTION_ID ((class_id_t)11)

/* object data */
typedef struct {
/* c11_Exception */
/* c10_Throwable */
	object_pointer c10f1_message;
/* c1_Object */
OBJECT_HEADER
/* c1_Object */
/* c10_Throwable */
/* c11_Exception */
} c11_Exception_t;
#define C11_EXCEPTION_OBJ(_obj_) ((c11_Exception_t*)((object_pointer*)(_obj_)-1))
#define ACCFIELD_C11_EXCEPTION_C10F1_MESSAGE(_obj_) (C11_EXCEPTION_OBJ(_obj_)->c10f1_message)
#define KESO_ALLOC_C11_EXCEPTION() KESO_ALLOC(C11_EXCEPTION_ID,sizeof(c11_Exception_t),1)
#define KESO_ALLOC_STACK_C11_EXCEPTION(_mem_) keso_alloc_stack((object_pointer)&(_mem_), C11_EXCEPTION_ID,sizeof(c11_Exception_t),1)
#define KESO_ALLOC_INLINE_C11_EXCEPTION() KESO_ALLOC(C11_EXCEPTION_ID,sizeof(c11_Exception_t),1)

/* class methods prototypes */



#endif /* !defined(__C11_EXCEPTION_H__) */