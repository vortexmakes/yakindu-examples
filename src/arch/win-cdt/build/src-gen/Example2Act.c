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
#include "rkhtmr.h"
#include "signals.h"
#include "Example2.h"
#include "Example2Act.h"
#include "bsp.h"
#include "Example2ActRequired.h"

/* ----------------------------- Local macros ------------------------------ */
#define WaitTime0	RKH_TIME_MS(100)
#define WaitTime1	RKH_TIME_SEC(3)

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
	RKH_TR_FWK_STATE(me, &StateF1);
	RKH_TR_FWK_STATE(me, &StateF11);
	RKH_TR_FWK_STATE(me, &CompState2);
	RKH_TR_FWK_STATE(me, &CompState21);
	RKH_TR_FWK_SIG(evA);
	RKH_TR_FWK_SIG(evB);
	RKH_TR_FWK_SIG(evC);
	RKH_TR_FWK_TIMER(&me->tmEvtObj0.tmr);
	RKH_TR_FWK_TIMER(&me->tmEvtObj1.tmr);
	#if 0
		RKH_TR_FWK_OBJ_NAME(Example2_ToStateAExt0, "ToStateAExt0");
		RKH_TR_FWK_OBJ_NAME(Example2_StateBToStateCExt3, "StateBToStateCExt3");
		RKH_TR_FWK_OBJ_NAME(Example2_StateCToExample2_C1Ext8, "StateCToExample2_C1Ext8");
		RKH_TR_FWK_OBJ_NAME(Example2_StateCToH1Ext9, "StateCToH1Ext9");
		RKH_TR_FWK_OBJ_NAME(Example2_CompStateToStateCExt10, "CompStateToStateCExt10");
		RKH_TR_FWK_OBJ_NAME(Example2_StateEToCompState_FinalExt15, "StateEToCompState_FinalExt15");
		RKH_TR_FWK_OBJ_NAME(Example2_ToStateGExt17, "ToStateGExt17");
		RKH_TR_FWK_OBJ_NAME(Example2_H2ToStateGExt18, "H2ToStateGExt18");
		RKH_TR_FWK_OBJ_NAME(Example2_ToStateF11Ext19, "ToStateF11Ext19");
		RKH_TR_FWK_OBJ_NAME(Example2_Example2_C0ToExample2_C1Ext22, "Example2_C0ToExample2_C1Ext22");
		RKH_TR_FWK_OBJ_NAME(Example2_Example2_C1ToCompStateExt23, "Example2_C1ToCompStateExt23");
		RKH_TR_FWK_OBJ_NAME(Example2_Example2_C1ToStateAExt24, "Example2_C1ToStateAExt24");
		RKH_TR_FWK_OBJ_NAME(Example2_StateAToStateALoc2, "StateAToStateALoc2");
		RKH_TR_FWK_OBJ_NAME(Example2_CompState21ToCompState21Loc6, "CompState21ToCompState21Loc6");
		RKH_TR_FWK_OBJ_NAME(Example2_enStateA, "enStateA");
		RKH_TR_FWK_OBJ_NAME(Example2_enStateC, "enStateC");
		RKH_TR_FWK_OBJ_NAME(Example2_enCompState, "enCompState");
		RKH_TR_FWK_OBJ_NAME(Example2_exStateA, "exStateA");
		RKH_TR_FWK_OBJ_NAME(Example2_exCompState, "exCompState");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondStateCToCompState7, "isCondStateCToCompState7");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondExample2_C0ToStateC21, "isCondExample2_C0ToStateC21");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondExample2_C0ToExample2_C122, "isCondExample2_C0ToExample2_C122");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondExample2_C1ToCompState23, "isCondExample2_C1ToCompState23");
	#endif
	
	simpleOp();
}

void 
Example2_StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
Example2_StateCToExample2_C1Ext8(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

void 
Example2_StateCToH1Ext9(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

void 
Example2_CompStateToStateCExt10(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
Example2_StateEToCompState_FinalExt15(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

void 
Example2_ToStateGExt17(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 8;
}

void 
Example2_H2ToStateGExt18(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 1;
}

void 
Example2_ToStateF11Ext19(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 16;
}

void 
Example2_Example2_C0ToExample2_C1Ext22(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

void 
Example2_Example2_C1ToCompStateExt23(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar++;
}

void 
Example2_Example2_C1ToStateAExt24(Example2 *const me, RKH_EVT_T *pe)
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

void 
Example2_CompState21ToCompState21Loc6(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

/* ............................. Entry actions ............................. */
void 
Example2_enStateA(Example2 *const me)
{
	me->boolVar = false;
}

void 
Example2_enStateB(Example2 *const me)
{
	RKH_SET_STATIC_EVENT(&me->tmEvtObj0, evTout0);
	RKH_TMR_INIT(&me->tmEvtObj0.tmr, RKH_UPCAST(RKH_EVT_T, &me->tmEvtObj0), NULL);
	RKH_TMR_ONESHOT(&me->tmEvtObj0.tmr, RKH_UPCAST(RKH_SMA_T, me), WaitTime0);
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

void 
Example2_enCompState21(Example2 *const me)
{
	RKH_SET_STATIC_EVENT(&me->tmEvtObj1, evTout1);
	RKH_TMR_INIT(&me->tmEvtObj1.tmr, RKH_UPCAST(RKH_EVT_T, &me->tmEvtObj1), NULL);
	RKH_TMR_PERIODIC(&me->tmEvtObj1.tmr, RKH_UPCAST(RKH_SMA_T, me), WaitTime1, WaitTime1);
}

/* ............................. Exit actions .............................. */
void 
Example2_exStateA(Example2 *const me)
{
	me->intVar = 2;
}

void 
Example2_exStateB(Example2 *const me)
{
	rkh_tmr_stop(&me->tmEvtObj0.tmr);
}

void 
Example2_exCompState(Example2 *const me)
{
	me->boolVar = true;
}

void 
Example2_exCompState21(Example2 *const me)
{
	rkh_tmr_stop(&me->tmEvtObj1.tmr);
}

/* ................................ Guards ................................. */
rbool_t 
Example2_isCondStateCToCompState7(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 5)) ? true : false;
}

rbool_t 
Example2_isCondExample2_C0ToStateC21(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 0)) ? true : false;
}

rbool_t 
Example2_isCondExample2_C0ToExample2_C122(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 1)) ? true : false;
}

rbool_t 
Example2_isCondExample2_C1ToCompState23(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->boolVar == false)) ? true : false;
}

/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
