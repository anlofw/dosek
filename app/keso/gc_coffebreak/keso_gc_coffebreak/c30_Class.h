/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#ifndef __C30_CLASS_H__
#define __C30_CLASS_H__
#include "keso_object_pointer.h"
#include "keso_types.h"

#define C30_CLASS_ID ((class_id_t)30)

/* object data */
typedef struct {
/* c30_Class */
/* c1_Object */
OBJECT_HEADER
/* c1_Object */
/* c30_Class */
} c30_Class_t;
#define C30_CLASS_OBJ(_obj_) ((c30_Class_t*)(_obj_))
#define KESO_ALLOC_C30_CLASS() KESO_ALLOC(C30_CLASS_ID,sizeof(c30_Class_t),0)
#define KESO_ALLOC_STACK_C30_CLASS(_mem_) keso_alloc_stack((object_pointer)&(_mem_), C30_CLASS_ID,sizeof(c30_Class_t),0)
#define KESO_ALLOC_INLINE_C30_CLASS() KESO_ALLOC(C30_CLASS_ID,sizeof(c30_Class_t),0)

/* class methods prototypes */



#endif /* !defined(__C30_CLASS_H__) */