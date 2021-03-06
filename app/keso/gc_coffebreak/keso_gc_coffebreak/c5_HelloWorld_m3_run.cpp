/* THIS FILE IS AUTO-GENERATED BY KESO! DON'T EDIT */

#include "c5_HelloWorld.h"
#include "c7_DebugOut.h"
#include "c8_StringBuilder.h"
#include "c9_QueueElement.h"
#include "keso_types.h"
#include "global.h"
#include "domains.h"


/*
 * call analysis 1 c5_HelloWorld_m3_run
 *
 * <kore>
 * ()
 *
 * total ()
 */

/* c5_HelloWorld_m3_run c5_HelloWorld_m2_printList */
/* test/HelloWorld.run()V */

void c5_HelloWorld_m3_run(object_pointer* pref, object_pointer obj0)
{
	jint i5_0;
	jint i7_0;
	jint i8_0;
	jint i9_0;
	jint i7_1;
	jint i11_0;
	jint i9_4;
	object_pointer volatile obj[8];
	/* initial new frame (big) */
	for (int c = 0; c < 7; c++) {
		obj[c] = (object_pointer) (void *) 0;
	}
	*pref = (object_pointer) (void *) ((int) obj | 0x1); /* register new frame */
	
/* c5_HelloWorld_m3_run_B0:  Pred:  No: 1 done */
	
/*==============================================================/
| 60:   head = tail = new QueueElement(runs++);
/==============================================================*/

	obj[6] = KESO_ALLOC_C9_QUEUEELEMENT();
	i5_0 = (ACCFIELD_C5_HELLOWORLD_C5F1_RUNS(obj0));
	i7_0 = (i5_0+0x1);
	(ACCFIELD_C5_HELLOWORLD_C5F1_RUNS(obj0)) = (jint)i7_0;
	(ACCFIELD_C9_QUEUEELEMENT_C9F2_VALUE(obj[6])) = (jint)i5_0;
	(ACCFIELD_C9_QUEUEELEMENT_C9F1_NEXT(obj[6])) = (object_pointer)(object_pointer) (void *) 0;
	obj[0] = obj[6];

	
c5_HelloWorld_m3_run_B21: /* Pred:  0 6 174 No: 4 done */
	
/*==============================================================/
: 61: 
: 62:   while(true) {
| 63:    DebugOut.println("Queue Run " + runs);
: 64: 
: 65:    // remove first item from the list => garbage
| 66:    if(runs>Config.getInt("QueueLength", 4)) {
/==============================================================*/

	obj[1] = KESO_ALLOC_C8_STRINGBUILDER();
	c8_StringBuilder_m3__init_(obj[1]);
	obj[2] = c8_StringBuilder_m1_append(obj[1], ((object_pointer) ((object_pointer*) &str3+1)));
	i8_0 = (ACCFIELD_C5_HELLOWORLD_C5F1_RUNS(obj0));
	obj[3] = c8_StringBuilder_m8_append(obj[2], i8_0);
	obj[4] = c8_StringBuilder_m9_toString(obj[3]);
	c7_DebugOut_m5_println(obj[4]);
	i9_0 = (ACCFIELD_C5_HELLOWORLD_C5F1_RUNS(obj0));
	if (i9_0<=0x4) goto c5_HelloWorld_m3_run_B74;

	
/* c5_HelloWorld_m3_run_B59:  Pred:  21 No: 9 done */
	
/*==============================================================/
| 67:     if(tail == head) {
/==============================================================*/

	if (obj[6]!=obj[0]) goto z45_c5_HelloWorld_m3_run_B4;

	
/* z44_c5_HelloWorld_m3_run_B4:  Pred:  59 No: 11 done */
	
/*==============================================================/
| 68:      tail = head.next();
/==============================================================*/

	obj[6] = (ACCFIELD_C9_QUEUEELEMENT_C9F1_NEXT(obj[0]));

	
z45_c5_HelloWorld_m3_run_B4: /* Pred:  59 64 No: 13 done */
	
/*==============================================================/
: 69:     }
| 70:     head = head.next();
/==============================================================*/

	obj[0] = (ACCFIELD_C9_QUEUEELEMENT_C9F1_NEXT(obj[0]));

	
c5_HelloWorld_m3_run_B74: /* Pred:  21 69 No: 14 done */
	
/*==============================================================/
: 71:    }
: 72: 
: 73:    // append another element
| 74:    tail.next(new QueueElement(runs++));
/==============================================================*/

	obj[5] = obj[6];
	obj[6] = KESO_ALLOC_C9_QUEUEELEMENT();
	i7_1 = (ACCFIELD_C5_HELLOWORLD_C5F1_RUNS(obj0));
	i11_0 = (i7_1+0x1);
	(ACCFIELD_C5_HELLOWORLD_C5F1_RUNS(obj0)) = (jint)i11_0;
	(ACCFIELD_C9_QUEUEELEMENT_C9F2_VALUE(obj[6])) = (jint)i7_1;
	(ACCFIELD_C9_QUEUEELEMENT_C9F1_NEXT(obj[6])) = (object_pointer)(object_pointer) (void *) 0;

	
/* z48_c5_HelloWorld_m3_run_B2:  Pred:  74 No: 17 done */
	
/*==============================================================/
: 78:    if(Config.getInt("usePortal",0) == 1) {
: 79:     ListPrintService lps = (ListPrintService) PortalService.lookup("ListPrintService");
: 80:     lps.printList(head);
: 81:    } else {
| 82:     printList(head);
: 86:     GC.guard(512,1);
: 87:    }
: 88: 
: 89:    if (Config.getInt("MaxRuns",0)!=0) {
| 90:     if (runs>=Config.getInt("MaxRuns",0)) {
/==============================================================*/

	(ACCFIELD_C9_QUEUEELEMENT_C9F1_NEXT(obj[5])) = (object_pointer)obj[6];
	c5_HelloWorld_m2_printList((object_pointer *) &obj[7], obj0, obj[0]);
	i9_4 = (ACCFIELD_C5_HELLOWORLD_C5F1_RUNS(obj0));
	if (i9_4<0x14) goto c5_HelloWorld_m3_run_B21;

	
/* c5_HelloWorld_m3_run_B174:  Pred:  6 No: 25 done */
	
/*==============================================================/
| 91:      System.exit(0);
/==============================================================*/

	ShutdownOS((StatusType) (0));
	goto c5_HelloWorld_m3_run_B21;

}

