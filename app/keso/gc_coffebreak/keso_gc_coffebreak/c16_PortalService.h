/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#ifndef __C16_PORTALSERVICE_H__
#define __C16_PORTALSERVICE_H__
#include "keso_object_pointer.h"
#include "keso_types.h"

#define C16_PORTALSERVICE_ID ((class_id_t)16)

/* object data */
typedef struct {
/* c16_PortalService */
/* c1_Object */
OBJECT_HEADER
/* c1_Object */
/* c16_PortalService */
} c16_PortalService_t;
#define C16_PORTALSERVICE_OBJ(_obj_) ((c16_PortalService_t*)(_obj_))
#define KESO_ALLOC_C16_PORTALSERVICE() KESO_ALLOC(C16_PORTALSERVICE_ID,sizeof(c16_PortalService_t),0)
#define KESO_ALLOC_STACK_C16_PORTALSERVICE(_mem_) keso_alloc_stack((object_pointer)&(_mem_), C16_PORTALSERVICE_ID,sizeof(c16_PortalService_t),0)
#define KESO_ALLOC_INLINE_C16_PORTALSERVICE() KESO_ALLOC(C16_PORTALSERVICE_ID,sizeof(c16_PortalService_t),0)

/* class methods prototypes */



#endif /* !defined(__C16_PORTALSERVICE_H__) */
