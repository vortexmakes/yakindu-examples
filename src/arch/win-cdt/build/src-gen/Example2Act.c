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
static rInt foo = 0;

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
	RKH_TR_FWK_STATE(me, &StateF);
	RKH_TR_FWK_STATE(me, &StateG);
	RKH_TR_FWK_STATE(me, &CompState2);
	RKH_TR_FWK_STATE(me, &CompState21);
	RKH_TR_FWK_SIG(evA);
	RKH_TR_FWK_SIG(evB);
	RKH_TR_FWK_SIG(evC);
	#if 1
		RKH_TR_FWK_OBJ_NAME(Example2_ToStateAExt0, "ToStateAExt0");
		RKH_TR_FWK_OBJ_NAME(Example2_StateBToStateCExt3, "StateBToStateCExt3");
		RKH_TR_FWK_OBJ_NAME(Example2_StateCToC1Ext7, "StateCToC1Ext7");
		RKH_TR_FWK_OBJ_NAME(Example2_StateCToH1Ext8, "StateCToH1Ext8");
		RKH_TR_FWK_OBJ_NAME(Example2_CompStateToStateCExt9, "CompStateToStateCExt9");
		RKH_TR_FWK_OBJ_NAME(Example2_StateEToNULLExt14, "StateEToNULLExt14");
		RKH_TR_FWK_OBJ_NAME(Example2_H2ToStateGExt16, "H2ToStateGExt16");
		RKH_TR_FWK_OBJ_NAME(Example2_C0ToC1Ext19, "C0ToC1Ext19");
		RKH_TR_FWK_OBJ_NAME(Example2_C1ToCompStateExt20, "C1ToCompStateExt20");
		RKH_TR_FWK_OBJ_NAME(Example2_C1ToStateAExt21, "C1ToStateAExt21");
		RKH_TR_FWK_OBJ_NAME(Example2_StateAToStateALoc2, "StateAToStateALoc2");
		RKH_TR_FWK_OBJ_NAME(Example2_enStateA, "enStateA");
		RKH_TR_FWK_OBJ_NAME(Example2_enStateC, "enStateC");
		RKH_TR_FWK_OBJ_NAME(Example2_enCompState, "enCompState");
		RKH_TR_FWK_OBJ_NAME(Example2_exStateA, "exStateA");
		RKH_TR_FWK_OBJ_NAME(Example2_exCompState, "exCompState");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondStateCToCompState6, "isCondStateCToCompState6");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondC0ToStateC18, "isCondC0ToStateC18");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondC0ToC119, "isCondC0ToC119");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondC1ToCompState20, "isCondC1ToCompState20");
	#endif
	
	simpleOp();
}

void 
Example2_StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
Example2_StateCToC1Ext7(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

void 
Example2_StateCToH1Ext8(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

void 
Example2_CompStateToStateCExt9(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
Example2_StateEToNULLExt14(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

void 
Example2_H2ToStateGExt16(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 1;
}

void 
Example2_C0ToC1Ext19(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

void 
Example2_C1ToCompStateExt20(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar++;
}

void 
Example2_C1ToStateAExt21(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 0;
}

void 
Example2_StateAToStateALoc2(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
	me->intVar++;
	foo++;
}

/* ............................. Entry actions ............................. */
void 
Example2_enStateA(Example2 *const me)
{
	me->boolVar = false;
}

void 
Example2_enStateC(Example2 *const me)
{
	me->intVar = opWithParamAndReturn(me->intVar);
	me->intVar = opWithReturn();
	opWithParams(me->intVar, me->boolVar);
}

void 
Example2_enCompState(Example2 *const me)
{
	me->intVar++;
}

/* ............................. Exit actions .............................. */
void 
Example2_exStateA(Example2 *const me)
{
	me->intVar = 2;
}

void 
Example2_exCompState(Example2 *const me)
{
	me->boolVar = true;
}

/* ................................ Guards ................................. */
rbool_t 
Example2_isCondStateCToCompState6(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 5)) ? true : false;
}

rbool_t 
Example2_isCondC0ToStateC18(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 0)) ? true : false;
}

rbool_t 
Example2_isCondC0ToC119(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 1)) ? true : false;
}

rbool_t 
Example2_isCondC1ToCompState20(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->boolVar == false)) ? true : false;
}

/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
