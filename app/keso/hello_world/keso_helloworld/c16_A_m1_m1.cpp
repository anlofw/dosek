/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c16_A.h"
#include "c25_System.h"
#include "c30_DebugOutPrintStream.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 1 c16_A_m1_m1
 *
 * c7_HelloWorld_m2_run
 * (valid test/B)
 *
 * total (valid test/B)
 */

/* c16_A_m1_m1 #non_blocking */
/* test/A.m1()V */

void c16_A_m1_m1(object_pointer obj0)
{
	object_pointer obj1_0;
	
/* c16_A_m1_m1_B0:  Pred:  No: 1 done */
	
/*==============================================================/
| 28:   System.out.println("m1");
| 29:  }
/==============================================================*/

	obj1_0 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	c30_DebugOutPrintStream_m6_println(obj1_0, ((object_pointer) ((object_pointer*) &str11+1)));
	/* goto c16_A_m1_m1_B10 */

	
/* c16_A_m1_m1_B10:  Pred:  0 No: 3 done */

	return;

}

