/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c7_DebugOut.h"
#include "c8_StringBuilder.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 1 c7_DebugOut_m3__clinit_
 *
 * <kore>
 * ()
 *
 * total ()
 */

/* c7_DebugOut_m3__clinit_ #non_blocking */
/* keso/io/DebugOut.<clinit>()V */

void c7_DebugOut_m3__clinit_(void)
{
	object_pointer obj0_0;
	
/* c7_DebugOut_m3__clinit__B0:  Pred:  No: 1 done */
	
/*==============================================================/
| 31:  private final static StringBuilder buf = new StringBuilder();
/==============================================================*/

	obj0_0 = KESO_ALLOC_C8_STRINGBUILDER();
	c8_StringBuilder_m3__init_(obj0_0);
	SC7_DEBUGOUT_C7F1_BUF(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc)) = (object_pointer)obj0_0;
	/* goto c7_DebugOut_m3__clinit__B12 */

	
/* c7_DebugOut_m3__clinit__B12:  Pred:  0 No: 3 done */

	return;

}

