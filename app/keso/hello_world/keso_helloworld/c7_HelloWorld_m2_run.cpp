/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c15_StringBuilder.h"
#include "c16_A.h"
#include "c1_Object.h"
#include "c23_String.h"
#include "c25_System.h"
#include "c30_DebugOutPrintStream.h"
#include "c7_HelloWorld.h"
#include "char_array.h"
#include "keso_exceptions.h"
#include "keso_time.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 2 c7_HelloWorld_m2_run
 *
 * <kore>
 * ()
 *
 * <kore>
 * ()
 *
 * total ()
 */

/* c7_HelloWorld_m2_run #non_blocking */
/* test/HelloWorld.run()V */
struct c7_HelloWorld_m2_run_s7 {
ARRAY_HEADER
jchar data[15];
};
static struct c7_HelloWorld_m2_run_s7 c7_HelloWorld_m2_run_arr7 ALIGN4 = {
/*.class_id=*/CHAR_ARRAY_ID, /*.size=*/14,  {34,72,101,108,108,111,32,87,111,114,108,100,33,34,0}
};
c23_String_t ALIGN4 c7_HelloWorld_m2_run_str7 = {/*.c23f1_value=*/(object_pointer)&c7_HelloWorld_m2_run_arr7, /*.class_id=*/C23_STRING_ID};

void c7_HelloWorld_m2_run(object_pointer obj0)
{
	object_pointer obj2_0;
	object_pointer obj3_0;
	object_pointer obj2_1;
	object_pointer obj2_2;
	jint i1_1;
	object_pointer obj2_3;
	object_pointer obj2_4;
	jlong l4_0;
	object_pointer obj2_5;
	jlong l4_1;
	object_pointer obj2_6;
	object_pointer obj3_1;
	object_pointer obj3_2;
	jlong l5_0;
	jlong l5_1;
	object_pointer obj3_3;
	object_pointer obj3_4;
	object_pointer obj3_5;
	object_pointer obj2_7;
	object_pointer obj3_6;
	object_pointer obj3_7;
	jlong l5_2;
	object_pointer obj3_8;
	object_pointer obj3_9;
	object_pointer obj3_10;
	object_pointer obj2_8;
	object_pointer obj3_11;
	object_pointer obj3_12;
	jlong l5_3;
	object_pointer obj3_13;
	object_pointer obj3_14;
	object_pointer obj3_15;
	object_pointer obj2_9;
	object_pointer obj2_10;
	object_pointer obj44;
	jint i1_1_0;
	
/* c7_HelloWorld_m2_run_B0:  Pred:  No: 1 done */
	
/*==============================================================/
| 38:   System.out.println(System.getProperty("ddom1.ttask1.HelloString","Hello World!"));
| 39:   System.out.println("You successfully compiled and ran KESO. Goodbye...\n");
: 40: 
| 41:   int x = aobj.hashCode();
/==============================================================*/

	obj2_0 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	obj3_0 = ((object_pointer) ((object_pointer*) &c7_HelloWorld_m2_run_str7+1));
	c30_DebugOutPrintStream_m6_println(obj2_0, obj3_0);
	obj2_1 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	c30_DebugOutPrintStream_m6_println(obj2_1, ((object_pointer) ((object_pointer*) &str3+1)));
	obj2_2 = (ACCFIELD_C7_HELLOWORLD_C7F3_AOBJ(obj0));
				KESO_CHECK_INVOKEVIRTUAL_NULLPOINTER(obj2_2,"c7_HelloWorld_m2_run",25, 12);

	
/* z12_c7_HelloWorld_m2_run_B28:  Pred:  0 No: 5 done */

	i1_1_0 = c1_Object_m2_hashCode(obj2_2);

	
c7_HelloWorld_m2_run_B29: /* Pred:  25 168 No: 6 done */
	
/*==============================================================/
: 42:   while(true) { // trick jino in believing that the incremented value of x will be needed
| 43:    System.out.print("hash value: ");
| 44:    System.out.println((long) x);
| 45:    aobj.m2();
/==============================================================*/

	i1_1 = i1_1_0;
	obj2_3 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	c30_DebugOutPrintStream_m7_print(obj2_3, ((object_pointer) ((object_pointer*) &str4+1)));
	obj2_4 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	l4_0 = ((jlong)i1_1);
	c30_DebugOutPrintStream_m4_println(obj2_4, l4_0);
	obj2_5 = (ACCFIELD_C7_HELLOWORLD_C7F3_AOBJ(obj0));
	obj44 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	c30_DebugOutPrintStream_m6_println(obj44, ((object_pointer) ((object_pointer*) &str5+1)));
				KESO_CHECK_INVOKEVIRTUAL_NULLPOINTER(obj2_5,"c7_HelloWorld_m2_run",49, 13);

	
/* z17_c7_HelloWorld_m2_run_B9:  Pred:  29 No: 11 done */
	
/*==============================================================/
: 46: 
| 47:    stop = System.nanoTime();
: 48: 
| 49:    System.out.println("Runtime " + (stop-start) + " ns");
| 50:    System.out.println("\tstart: " + start + " ns");
| 51:    System.out.println("\tstop: " + stop + " ns");
: 52: 
| 53:    System.out.print("\thash value again: ");
| 54:    System.out.println(x++);
/==============================================================*/

	c16_A_m1_m1(obj2_5);
	l4_1 = keso_nanotime();
	(ACCFIELD_C7_HELLOWORLD_C7F2_STOP(obj0)) = (jlong)l4_1;
	obj2_6 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	obj3_1 = KESO_ALLOC_C15_STRINGBUILDER();
	c15_StringBuilder_m3__init_(obj3_1);
	obj3_2 = c15_StringBuilder_m1_append(obj3_1, ((object_pointer) ((object_pointer*) &str6+1)));
	l5_0 = (ACCFIELD_C7_HELLOWORLD_C7F2_STOP(obj0));
	l5_1 = (l5_0-(ACCFIELD_C7_HELLOWORLD_C7F1_START(obj0)));
	obj3_3 = c15_StringBuilder_m10_append(obj3_2, l5_1);
	obj3_4 = c15_StringBuilder_m1_append(obj3_3, ((object_pointer) ((object_pointer*) &str7+1)));
	obj3_5 = c15_StringBuilder_m9_toString(obj3_4);
	c30_DebugOutPrintStream_m6_println(obj2_6, obj3_5);
	obj2_7 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	obj3_6 = KESO_ALLOC_C15_STRINGBUILDER();
	c15_StringBuilder_m3__init_(obj3_6);
	obj3_7 = c15_StringBuilder_m1_append(obj3_6, ((object_pointer) ((object_pointer*) &str8+1)));
	l5_2 = (ACCFIELD_C7_HELLOWORLD_C7F1_START(obj0));
	obj3_8 = c15_StringBuilder_m10_append(obj3_7, l5_2);
	obj3_9 = c15_StringBuilder_m1_append(obj3_8, ((object_pointer) ((object_pointer*) &str7+1)));
	obj3_10 = c15_StringBuilder_m9_toString(obj3_9);
	c30_DebugOutPrintStream_m6_println(obj2_7, obj3_10);
	obj2_8 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	obj3_11 = KESO_ALLOC_C15_STRINGBUILDER();
	c15_StringBuilder_m3__init_(obj3_11);
	obj3_12 = c15_StringBuilder_m1_append(obj3_11, ((object_pointer) ((object_pointer*) &str9+1)));
	l5_3 = (ACCFIELD_C7_HELLOWORLD_C7F2_STOP(obj0));
	obj3_13 = c15_StringBuilder_m10_append(obj3_12, l5_3);
	obj3_14 = c15_StringBuilder_m1_append(obj3_13, ((object_pointer) ((object_pointer*) &str7+1)));
	obj3_15 = c15_StringBuilder_m9_toString(obj3_14);
	c30_DebugOutPrintStream_m6_println(obj2_8, obj3_15);
	obj2_9 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	c30_DebugOutPrintStream_m7_print(obj2_9, ((object_pointer) ((object_pointer*) &str10+1)));
	obj2_10 = SC25_SYSTEM_C25F2_OUT(((domain_t *) &__DOSEK_APPDATA_dom1__DDesc));
	i1_1_0 = (i1_1+0x1);
	/* goto z34_c7_HelloWorld_m2_run_B178 */

	
/* z34_c7_HelloWorld_m2_run_B178:  Pred:  5 No: 28 done */
	
/*==============================================================/
| 55:    TaskService.terminate();
/==============================================================*/

	c30_DebugOutPrintStream_m8_println(obj2_10, i1_1);
	TerminateTask();
	goto c7_HelloWorld_m2_run_B29;

}

