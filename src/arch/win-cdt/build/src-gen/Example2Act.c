/**
 *  \file       Example2.c
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
#include "Example2.h"
#include "Example2Act.h"
#include "bsp.h"
#include "Example2ActRequired.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
void 
Example2_ToStateAExt0(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 1;
	me->boolVar = true;
	me->uninitializedIntVar = 0;
	me->uninitializedBoolVar = false;
		
	RKH_TR_FWK_AO(me);
	RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
	RKH_TR_FWK_STATE(me, &StateA);
	RKH_TR_FWK_STATE(me, &StateB);
	RKH_TR_FWK_STATE(me, &StateC);
	RKH_TR_FWK_STATE(me, &CompState);
	RKH_TR_FWK_STATE(me, &StateD);
	RKH_TR_FWK_STATE(me, &StateE);
	RKH_TR_FWK_SIG(evA);
	RKH_TR_FWK_SIG(evB);
	#if 1
		RKH_TR_FWK_OBJ_NAME(Example2_initial, "initial");
		RKH_TR_FWK_OBJ_NAME(Example2_ToStateAExt0, "ToStateAExt0");
		RKH_TR_FWK_OBJ_NAME(Example2_StateBToStateCExt3, "StateBToStateCExt3");
		RKH_TR_FWK_OBJ_NAME(Example2_CompStateToStateCExt5, "CompStateToStateCExt5");
		RKH_TR_FWK_OBJ_NAME(Example2_StateAToStateALoc2, "StateAToStateALoc2");
		RKH_TR_FWK_OBJ_NAME(Example2_enStateA, "enStateA");
		RKH_TR_FWK_OBJ_NAME(Example2_enStateC, "enStateC");
		RKH_TR_FWK_OBJ_NAME(Example2_enCompState, "enCompState");
		RKH_TR_FWK_OBJ_NAME(Example2_exStateA, "exStateA");
		RKH_TR_FWK_OBJ_NAME(Example2_exCompState, "exCompState");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondStateCToCompState4, "isCondStateCToCompState4");
	#endif
	
	simpleOp();
}

void 
Example2_StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
Example2_CompStateToStateCExt5(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
Example2_StateAToStateALoc2(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
	intVar++;
}

/* ............................. Entry actions ............................. */
void 
Example2_enStateA(Example2 *const me)
{
	boolVar = false;
}

void 
Example2_enStateC(Example2 *const me)
{
	intVar = opWithParamAndReturn(intVar);
	intVar = opWithReturn();
	opWithParams(intVar, boolVar);
}

void 
Example2_enCompState(Example2 *const me)
{
	intVar++;
}

/* ............................. Exit actions .............................. */
void 
Example2_exStateA(Example2 *const me)
{
	intVar = 2;
}

void 
Example2_exCompState(Example2 *const me)
{
	boolVar = true;
}

/* ................................ Guards ................................. */
rbool_t 
Example2_isCondStateCToCompState4(Example2 *const me, RKH_EVT_T *pe)
{
	return ((intVar == 5)) ? true : false;
}

/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
