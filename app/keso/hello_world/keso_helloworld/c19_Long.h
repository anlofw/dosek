/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#ifndef __C19_LONG_H__
#define __C19_LONG_H__
#include "keso_object_pointer.h"
#include "keso_types.h"

#define C19_LONG_ID ((class_id_t)19)

/* object data */
typedef struct {
/* c19_Long */
/* c18_Number */
/* c1_Object */
OBJECT_HEADER
/* c1_Object */
/* c18_Number */
/* c19_Long */
} c19_Long_t;
#define C19_LONG_OBJ(_obj_) ((c19_Long_t*)(_obj_))
#define KESO_ALLOC_C19_LONG() KESO_ALLOC(C19_LONG_ID,sizeof(c19_Long_t),0)
#define KESO_ALLOC_STACK_C19_LONG(_mem_) keso_alloc_stack((object_pointer)&(_mem_), C19_LONG_ID,sizeof(c19_Long_t),0)
#define KESO_ALLOC_INLINE_C19_LONG() KESO_ALLOC(C19_LONG_ID,sizeof(c19_Long_t),0)

/* class methods prototypes */
/* c19_Long_m1_toString #non_blocking */
/* toString(J)Ljava/lang/String; */
object_pointer c19_Long_m1_toString(jlong l0);
/* c19_Long_m2_toString #non_blocking */
/* toString(JI)Ljava/lang/String; */
object_pointer c19_Long_m2_toString(jlong l0, jint i2);
/* c19_Long_m4__clinit_ #non_blocking */
/* <clinit>()V */
void c19_Long_m4__clinit_(void);



#endif /* !defined(__C19_LONG_H__) */
