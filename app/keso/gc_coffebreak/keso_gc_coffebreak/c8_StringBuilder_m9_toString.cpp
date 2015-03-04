/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c29_String.h"
#include "c8_StringBuilder.h"
#include "char_array.h"
#include "keso_exceptions.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 4 c8_StringBuilder_m9_toString
 *
 * c5_HelloWorld_m2_printList
 * (valid java/lang/StringBuilder)
 *
 * c5_HelloWorld_m3_run
 * (valid java/lang/StringBuilder)
 *
 * c11_Integer_m1_toString
 * (valid java/lang/StringBuilder)
 *
 * c11_Integer_m1_toString
 * (valid java/lang/StringBuilder)
 *
 * total (valid java/lang/StringBuilder)
 */

/* c8_StringBuilder_m9_toString #non_blocking */
/* java/lang/StringBuilder.toString()Ljava/lang/String; */

object_pointer c8_StringBuilder_m9_toString(object_pointer obj0)
{
	object_pointer obj2_0;
	object_pointer obj3_0;
	jint i4_0;
	jint i11;
	jint i15;
	object_pointer obj19;
	
/* c8_StringBuilder_m9_toString_B0:  Pred:  No: 1 done */
	
/*==============================================================/
| 62:   return new String(data, 0, length);
/==============================================================*/

	obj2_0 = KESO_ALLOC_C29_STRING();
	obj3_0 = (ACCFIELD_C8_STRINGBUILDER_C8F1_DATA(obj0));
	i4_0 = (ACCFIELD_C8_STRINGBUILDER_C8F2_LENGTH(obj0));

	
/* z51_c8_StringBuilder_m9_toString_B8:  Pred:  0 No: 3 done */

	obj19 = keso_alloc_char_array(i4_0);
	(ACCFIELD_C29_STRING_C29F1_VALUE(obj2_0)) = (object_pointer)obj19;
	i11 = (0);

	
z23_c29_String_m1__init__B14: /* Pred:  10 20 No: 5 done */

	if (i11>=i4_0) goto c8_StringBuilder_m9_toString_B18;

	
/* z53_c29_String_m1__init__B32:  Pred:  14 No: 7 done */

				KESO_CHECK_CALOAD_ARRAY_NOTNULL(obj3_0,i11,"c8_StringBuilder_m9_toString",13, 9);
	i15 = CHAR_ARRAY_ALOAD(obj3_0, i11);
				KESO_CHECK_CASTORE_ARRAY_NOTNULL(obj19,i11,"c8_StringBuilder_m9_toString",13, 10);
	CHAR_ARRAY_LEA(obj19, i11) = i15;
	i11 = (i11+0x1);
	goto z23_c29_String_m1__init__B14;

	
c8_StringBuilder_m9_toString_B18: /* Pred:  14 No: 10 done */

	return (object_pointer)obj2_0;

}

