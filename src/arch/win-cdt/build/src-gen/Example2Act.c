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
	RKH_TR_FWK_SIG(evA);
	RKH_TR_FWK_SIG(evB);
	RKH_TR_FWK_SIG(evC);
	#if 1
		RKH_TR_FWK_OBJ_NAME(Example2_ToStateAExt0, "ToStateAExt0");
		RKH_TR_FWK_OBJ_NAME(Example2_StateBToStateCExt3, "StateBToStateCExt3");
		RKH_TR_FWK_OBJ_NAME(Example2_StateCToC1Ext6, "StateCToC1Ext6");
		RKH_TR_FWK_OBJ_NAME(Example2_StateCToH1Ext7, "StateCToH1Ext7");
		RKH_TR_FWK_OBJ_NAME(Example2_CompStateToStateCExt8, "CompStateToStateCExt8");
		RKH_TR_FWK_OBJ_NAME(Example2_H2ToStateGExt13, "H2ToStateGExt13");
		RKH_TR_FWK_OBJ_NAME(Example2_C0ToC1Ext16, "C0ToC1Ext16");
		RKH_TR_FWK_OBJ_NAME(Example2_C1ToCompStateExt17, "C1ToCompStateExt17");
		RKH_TR_FWK_OBJ_NAME(Example2_C1ToStateAExt18, "C1ToStateAExt18");
		RKH_TR_FWK_OBJ_NAME(Example2_StateAToStateALoc2, "StateAToStateALoc2");
		RKH_TR_FWK_OBJ_NAME(Example2_enStateA, "enStateA");
		RKH_TR_FWK_OBJ_NAME(Example2_enStateC, "enStateC");
		RKH_TR_FWK_OBJ_NAME(Example2_enCompState, "enCompState");
		RKH_TR_FWK_OBJ_NAME(Example2_exStateA, "exStateA");
		RKH_TR_FWK_OBJ_NAME(Example2_exCompState, "exCompState");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondStateCToCompState5, "isCondStateCToCompState5");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondC0ToStateC15, "isCondC0ToStateC15");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondC0ToC116, "isCondC0ToC116");
		RKH_TR_FWK_OBJ_NAME(Example2_isCondC1ToCompState17, "isCondC1ToCompState17");
	#endif
	
	simpleOp();
}

void 
Example2_StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
Example2_StateCToC1Ext6(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

void 
Example2_StateCToH1Ext7(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

void 
Example2_CompStateToStateCExt8(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
Example2_H2ToStateGExt13(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 1;
}

void 
Example2_C0ToC1Ext16(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

void 
Example2_C1ToCompStateExt17(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar++;
}

void 
Example2_C1ToStateAExt18(Example2 *const me, RKH_EVT_T *pe)
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
Example2_isCondStateCToCompState5(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 5)) ? true : false;
}

rbool_t 
Example2_isCondC0ToStateC15(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 0)) ? true : false;
}

rbool_t 
Example2_isCondC0ToC116(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 1)) ? true : false;
}

rbool_t 
Example2_isCondC1ToCompState17(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->boolVar == false)) ? true : false;
}

/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
