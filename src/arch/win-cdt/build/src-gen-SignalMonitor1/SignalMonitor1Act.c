/**
 *  \file       SignalMonitor1.c
 *  \brief      Active object's action implementations.
 */

/* -------------------------- Development history -------------------------- */
/*
 */

/* -------------------------------- Authors -------------------------------- */
/*
 */

/* --------------------------------- Notes --------------------------------- */
/* ----------------------------- Include files ----------------------------- */
#include "rkh.h"
#include "signal.h"
#include "SignalMonitor1.h"
#include "SignalMonitor1Act.h"
#include "bsp.h"
#include "SignalMonitor1ActRequired.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
void 
SignalMonitor1_ToIdleExt0(SignalMonitor1 *const me, RKH_EVT_T *pe)
{
	me->currInput = 0;
	me->lastInput = 0;
		
	RKH_TR_FWK_AO(me);
	RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
	RKH_TR_FWK_STATE(me, &Idle);
	RKH_TR_FWK_STATE(me, &Success);
	RKH_TR_FWK_STATE(me, &Failure);
	RKH_TR_FWK_SIG(evFailHigh);
	RKH_TR_FWK_SIG(evFailLow);
	#if 1
		RKH_TR_FWK_OBJ_NAME(SignalMonitor1_ToIdleExt0, "ToIdleExt0");
		RKH_TR_FWK_OBJ_NAME(SignalMonitor1_enFailure, "enFailure");
	#endif
	
	Init();
}

/* ............................. Entry actions ............................. */
void 
SignalMonitor1_enFailure(SignalMonitor1 *const me)
{
	MeasureFailure();
}

/* ............................. Exit actions .............................. */
/* ................................ Guards ................................. */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
