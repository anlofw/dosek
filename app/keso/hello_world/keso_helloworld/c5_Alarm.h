/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#ifndef __C5_ALARM_H__
#define __C5_ALARM_H__
#include "keso_object_pointer.h"
#include "keso_os.h"
#include "keso_types.h"

#define C5_ALARM_ID ((class_id_t)5)

/* object data */
typedef struct {
/* c5_Alarm */
/* c1_Object */
OBJECT_HEADER
/* c1_Object */
	KESO_CONST AlarmType _alarm_id;
/* c5_Alarm */
} c5_Alarm_t;
#define C5_ALARM_OBJ(_obj_) ((c5_Alarm_t*)(_obj_))
#define KESO_ALLOC_C5_ALARM() KESO_ALLOC(C5_ALARM_ID,sizeof(c5_Alarm_t),0)
#define KESO_ALLOC_STACK_C5_ALARM(_mem_) keso_alloc_stack((object_pointer)&(_mem_), C5_ALARM_ID,sizeof(c5_Alarm_t),0)
#define KESO_ALLOC_INLINE_C5_ALARM() KESO_ALLOC(C5_ALARM_ID,sizeof(c5_Alarm_t),0)

/* class methods prototypes */



#endif /* !defined(__C5_ALARM_H__) */
