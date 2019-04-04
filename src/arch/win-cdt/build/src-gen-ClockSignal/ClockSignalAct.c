/**
 *  \file       ClockSignal.c
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
#include "ClockSignal.h"
#include "ClockSignalAct.h"
#include "bsp.h"
#include "ClockSignalActRequired.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
void 
ClockSignal_ToIdleExt0(ClockSignal *const me, RKH_EVT_T *pe)
{
	me->currInput = 0;
	me->lastInput = 0;
		
	RKH_TR_FWK_AO(me);
	RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
	RKH_TR_FWK_STATE(me, &Idle);
	RKH_TR_FWK_STATE(me, &WaitFallEdge);
	RKH_TR_FWK_STATE(me, &WaitRisEdge);
	RKH_TR_FWK_SIG(evClockHigh);
	RKH_TR_FWK_SIG(evClockLow);
	#if 1
		RKH_TR_FWK_OBJ_NAME(ClockSignal_initial, "initial");
		RKH_TR_FWK_OBJ_NAME(ClockSignal_ToIdleExt0, "ToIdleExt0");
		RKH_TR_FWK_OBJ_NAME(ClockSignal_WaitFallEdgeToWaitRisEdgeExt3, "WaitFallEdgeToWaitRisEdgeExt3");
	#endif
	
	Init();
}

void 
ClockSignal_WaitFallEdgeToWaitRisEdgeExt3(ClockSignal *const me, RKH_EVT_T *pe)
{
	SeqDigSignal_dispatch(currInput);
}

/* ............................. Entry actions ............................. */
/* ............................. Exit actions .............................. */
/* ................................ Guards ................................. */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
