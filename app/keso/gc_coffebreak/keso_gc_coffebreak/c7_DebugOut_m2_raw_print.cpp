/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c7_DebugOut.h"
#include "c8_StringBuilder.h"
#include "char_array.h"
#include "keso_exceptions.h"
#include "keso_write_char_array.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 1 c7_DebugOut_m2_raw_print
 *
 * c7_DebugOut_m5_println
 * (?null java/lang/StringBuilder)
 *
 * total (?null java/lang/StringBuilder)
 */

/* c7_DebugOut_m2_raw_print #non_blocking */
/* keso/io/DebugOut.raw_print(Ljava/lang/StringBuilder;)V */

void c7_DebugOut_m2_raw_print(object_pointer obj0)
{
		KESO_CHECK_LGETFIELD_NULLPOINTER(obj0,"c7_DebugOut_m2_raw_print",-1, 5);
	char_array_t* char_array = (char_array_t*)(ACCFIELD_C8_STRINGBUILDER_C8F1_DATA(obj0));
	KESO_WRITE_CHAR_ARRAY(char_array, (ACCFIELD_C8_STRINGBUILDER_C8F2_LENGTH(obj0)));
	return;
}

