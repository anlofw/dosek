/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c11_Integer.h"
#include "c8_StringBuilder.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 2 c8_StringBuilder_m8_append
 *
 * c5_HelloWorld_m2_printList
 * (valid java/lang/StringBuilder, int)
 *
 * c5_HelloWorld_m3_run
 * (valid java/lang/StringBuilder, int)
 *
 * total (valid java/lang/StringBuilder, int)
 */

/* c8_StringBuilder_m8_append #non_blocking */
/* java/lang/StringBuilder.append(I)Ljava/lang/StringBuilder; */

object_pointer c8_StringBuilder_m8_append(object_pointer obj0, jint i1)
{
	object_pointer obj3_0;
	object_pointer obj2_0;
	
/* c8_StringBuilder_m8_append_B0:  Pred:  No: 1 done */
	
/*==============================================================/
| 158:   return append(Integer.toString(i));
/==============================================================*/

	obj3_0 = c11_Integer_m1_toString(i1);
	obj2_0 = c8_StringBuilder_m1_append(obj0, obj3_0);
	/* goto c8_StringBuilder_m8_append_B10 */

	
/* c8_StringBuilder_m8_append_B10:  Pred:  0 No: 3 done */

	return (object_pointer)obj2_0;

}

