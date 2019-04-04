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
		
	RKH_TR_FWK_AO(me);
	RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
	RKH_TR_FWK_STATE(me, &Idle);
	RKH_TR_FWK_STATE(me, &WaitFallEdge);
	RKH_TR_FWK_STATE(me, &WaitRisEdge);
	RKH_TR_FWK_SIG(evHigh);
	RKH_TR_FWK_SIG(evLow);
	#if 1
		RKH_TR_FWK_OBJ_NAME(ClockSignal_initial, "initial");
		RKH_TR_FWK_OBJ_NAME(ClockSignal_ToIdleExt0, "ToIdleExt0");
	#endif
	
	Init();
}

/* ............................. Entry actions ............................. */
/* ............................. Exit actions .............................. */
/* ................................ Guards ................................. */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */