/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c13_StringIndexOutOfBoundsException.h"
#include "c23_String.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 1 c23_String_m8_out_of_bounds
 *
 * c23_String_m3_getChars
 * (valid java/lang/Object)
 *
 * total (valid java/lang/Object)
 */

/* c23_String_m8_out_of_bounds #non_blocking */
/* java/lang/String.out_of_bounds()Ljava/lang/StringIndexOutOfBoundsException; */

object_pointer c23_String_m8_out_of_bounds(object_pointer obj0)
{
	object_pointer obj2_0;
	
/* c23_String_m8_out_of_bounds_B0:  Pred:  No: 1 done */
	
/*==============================================================/
| 506:   return new StringIndexOutOfBoundsException();
/==============================================================*/

	obj2_0 = KESO_ALLOC_C13_STRINGINDEXOUTOFBOUNDSEXCEPTION();
	/* goto c23_String_m8_out_of_bounds_B9 */

	
/* c23_String_m8_out_of_bounds_B9:  Pred:  0 No: 3 done */

	return (object_pointer)obj2_0;

}
