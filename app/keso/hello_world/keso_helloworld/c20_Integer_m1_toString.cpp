/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c15_StringBuilder.h"
#include "c20_Integer.h"
#include "c21_Character.h"
#include "char_array.h"
#include "keso_exceptions.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 1 c20_Integer_m1_toString
 *
 * c30_DebugOutPrintStream_m8_println
 * (int)
 *
 * total (int)
 */

/* c20_Integer_m1_toString #non_blocking */
/* java/lang/Integer.toString(I)Ljava/lang/String; */

object_pointer c20_Integer_m1_toString(jint i0)
{
	jint i8;
	jint i9;
	jint i13;
	jint i16;
	jint i17;
	object_pointer obj18;
	jint i19;
	jint i22;
	object_pointer obj28;
	object_pointer obj29;
	object_pointer obj32;
	
/* c20_Integer_m1_toString_B0:  Pred:  No: 1 done */
	
/*==============================================================/
| 113:   return toString(i, 10);
/==============================================================*/

	obj29 = KESO_ALLOC_C15_STRINGBUILDER();
	obj32 = keso_alloc_char_array(0xa);
	(ACCFIELD_C15_STRINGBUILDER_C15F1_DATA(obj29)) = (object_pointer)obj32;
	(ACCFIELD_C15_STRINGBUILDER_C15F2_LENGTH(obj29)) = (jint)(0);
	if (i0!=(0)) goto z16_c20_Integer_m4_toString_B28;

	
/* z35_c20_Integer_m4_toString_B19:  Pred:  0 No: 5 done */

	c15_StringBuilder_m4_append(obj29, 0x30);
	obj28 = c15_StringBuilder_m9_toString(obj29);
	goto c20_Integer_m1_toString_B8;

	
z16_c20_Integer_m4_toString_B28: /* Pred:  0 No: 8 done */

	i13 = (0);
	if (i0>=(0)) goto z15_c20_Integer_m4_toString_B37;

	
/* z17_c20_Integer_m4_toString_B32:  Pred:  28 No: 9 done */

	i0 = (i0* -1);
	i13 = 0x1;

	
z15_c20_Integer_m4_toString_B37: /* Pred:  28 41 32 No: 10 done */

	if (i0<=(0)) goto z14_c20_Integer_m4_toString_B60;

	
/* z18_c20_Integer_m4_toString_B41:  Pred:  37 No: 11 done */

	i8 = (i0%0xa);
	i9 = c21_Character_m2_forDigit(i8, 0xa);
	c15_StringBuilder_m4_append(obj29, i9);
	i0 = (i0/0xa);
	goto z15_c20_Integer_m4_toString_B37;

	
z14_c20_Integer_m4_toString_B60: /* Pred:  37 No: 13 done */

	if (i13==(0)) goto z13_c20_Integer_m4_toString_B71;

	
/* z37_c20_Integer_m4_toString_B67:  Pred:  60 No: 15 done */

	c15_StringBuilder_m4_append(obj29, 0x2d);

	
z13_c20_Integer_m4_toString_B71: /* Pred:  60 64 No: 16 done */

	i16 = (0);

	
z38_c15_StringBuilder_m5_reverse_B9: /* Pred:  71 20 No: 18 done */

	if (i16>=((ACCFIELD_C15_STRINGBUILDER_C15F2_LENGTH(obj29))/0x2)) goto z41_c15_StringBuilder_m5_reverse_B80;

	
/* z39_c15_StringBuilder_m5_reverse_B20:  Pred:  2 No: 20 done */

	i17 = (((ACCFIELD_C15_STRINGBUILDER_C15F2_LENGTH(obj29))-0x1)-i16);
	obj18 = (ACCFIELD_C15_STRINGBUILDER_C15F1_DATA(obj29));
				KESO_CHECK_CALOAD_NULLPOINTER(obj18,"c20_Integer_m1_toString",3, 15);

	
/* z40_c15_StringBuilder_m5_reverse_B27:  Pred:  12 No: 21 done */

				KESO_CHECK_CALOAD_ARRAY_NOTNULL(obj18,i16,"c20_Integer_m1_toString",3, 16);
	i19 = CHAR_ARRAY_ALOAD(obj18, i16);
				KESO_CHECK_CALOAD_ARRAY_NOTNULL(obj18,i17,"c20_Integer_m1_toString",3, 17);
	i22 = CHAR_ARRAY_ALOAD(obj18, i17);
				KESO_CHECK_CASTORE_ARRAY_NOTNULL(obj18,i16,"c20_Integer_m1_toString",3, 18);
	CHAR_ARRAY_LEA(obj18, i16) = i22;
				KESO_CHECK_CASTORE_ARRAY_NOTNULL(obj18,i17,"c20_Integer_m1_toString",3, 19);
	CHAR_ARRAY_LEA(obj18, i17) = i19;
	i16 = (i16+0x1);
	goto z38_c15_StringBuilder_m5_reverse_B9;

	
z41_c15_StringBuilder_m5_reverse_B80: /* Pred:  2 No: 23 done */

	obj28 = c15_StringBuilder_m9_toString(obj29);
	/* goto c20_Integer_m1_toString_B8 */

	
c20_Integer_m1_toString_B8: /* Pred:  53 16 No: 7 done */

	return (object_pointer)obj28;

}

