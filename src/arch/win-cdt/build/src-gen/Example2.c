/**
 *  \file       example2.c
 *  \brief      Active object implementation.
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
#include "signals.h"
#include "rkhtmr.h"
#include "Example2.h"
#include "bsp.h"
#include "Example2Required.h"

/* ----------------------------- Local macros ------------------------------ */
#define WaitTime0	RKH_TIME_MS(100)
#define WaitTime1	RKH_TIME_SEC(3)

/* ......................... Declares active object ........................ */
typedef struct Example2 Example2;

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE Example2_StateA, Example2_StateB, Example2_StateC, Example2_StateD, Example2_StateE, Example2_StateG, Example2_StateF11, Example2_CompState21;
RKH_DCLR_COMP_STATE Example2_CompState, Example2_StateF, Example2_StateF1, Example2_CompState2;
RKH_DCLR_CHOICE_STATE Example2_C0, Example2_C1;
RKH_DCLR_FINAL_STATE Example2_CompStateFinal, Example2Final;
RKH_DCLR_SHIST_STATE Example2_H1, Example2_H2;

/* ........................ Declares effect actions ........................ */
static void ToStateAExt0(Example2 *const me, RKH_EVT_T *pe);
static void StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe);
static void StateCToC1Ext8(Example2 *const me, RKH_EVT_T *pe);
static void StateCToH1Ext9(Example2 *const me, RKH_EVT_T *pe);
static void CompStateToStateCExt10(Example2 *const me, RKH_EVT_T *pe);
static void StateEToCompStateFinalExt15(Example2 *const me, RKH_EVT_T *pe);
static void ToStateGExt17(Example2 *const me, RKH_EVT_T *pe);
static void H2ToStateGExt18(Example2 *const me, RKH_EVT_T *pe);
static void ToStateF11Ext19(Example2 *const me, RKH_EVT_T *pe);
static void C0ToC1Ext22(Example2 *const me, RKH_EVT_T *pe);
static void C1ToCompStateExt23(Example2 *const me, RKH_EVT_T *pe);
static void C1ToStateAExt24(Example2 *const me, RKH_EVT_T *pe);
static void StateAToStateALoc2(Example2 *const me, RKH_EVT_T *pe);
static void CompState21ToCompState21Loc6(Example2 *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */
static void enStateA(Example2 *const me);
static void enStateB(Example2 *const me);
static void enStateC(Example2 *const me);
static void enCompState(Example2 *const me);
static void enCompState21(Example2 *const me);

/* ......................... Declares exit actions ......................... */
static void exStateA(Example2 *const me);
static void exStateB(Example2 *const me);
static void exCompState(Example2 *const me);
static void exCompState21(Example2 *const me);

/* ............................ Declares guards ............................ */
static rbool_t isCondStateCToCompState7(Example2 *const me, RKH_EVT_T *pe);
static rbool_t isCondC0ToStateC21(Example2 *const me, RKH_EVT_T *pe);
static rbool_t isCondC0ToC122(Example2 *const me, RKH_EVT_T *pe);
static rbool_t isCondC1ToCompState23(Example2 *const me, RKH_EVT_T *pe);

/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(Example2_StateA, enStateA, exStateA, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(Example2_StateB, enStateB, exStateB, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(Example2_StateC, enStateC, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(Example2_StateD, NULL, NULL, &Example2_CompState, NULL);
RKH_CREATE_BASIC_STATE(Example2_StateE, NULL, NULL, &Example2_CompState, NULL);
RKH_CREATE_BASIC_STATE(Example2_StateG, NULL, NULL, &Example2_StateF, NULL);
RKH_CREATE_BASIC_STATE(Example2_StateF11, NULL, NULL, &Example2_StateF1, NULL);
RKH_CREATE_BASIC_STATE(Example2_CompState21, enCompState21, exCompState21, &Example2_CompState2, NULL);

RKH_CREATE_HISTORY_STORAGE(Example2_CompState);
RKH_CREATE_COMP_REGION_STATE(Example2_CompState, enCompState, exCompState, RKH_ROOT, &Example2_StateD, NULL, RKH_SHISTORY, NULL, NULL, NULL, RKH_GET_HISTORY_STORAGE(Example2_CompState));
RKH_CREATE_HISTORY_STORAGE(Example2_StateF);
RKH_CREATE_COMP_REGION_STATE(Example2_StateF, NULL, NULL, &Example2_CompState, &Example2_StateG, ToStateGExt17, RKH_SHISTORY, NULL, H2ToStateGExt18, &Example2_StateG, RKH_GET_HISTORY_STORAGE(Example2_StateF));
RKH_CREATE_COMP_REGION_STATE(Example2_StateF1, NULL, NULL, &Example2_StateF, &Example2_StateF11, ToStateF11Ext19, RKH_NO_HISTORY, NULL, NULL, NULL, NULL);
RKH_CREATE_COMP_REGION_STATE(Example2_CompState2, NULL, NULL, RKH_ROOT, &Example2_CompState21, NULL, RKH_NO_HISTORY, NULL, NULL, NULL, NULL);

RKH_CREATE_TRANS_TABLE(Example2_StateA)
	RKH_TRREG(evB, NULL, NULL, &Example2_StateB),
	RKH_TRCOMPLETION(NULL, NULL, &Example2_StateB),
	RKH_TRINT(evA, NULL, StateAToStateALoc2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_StateB)
	RKH_TRREG(evA, NULL, StateBToStateCExt3, &Example2_StateC),
	RKH_TRREG(evB, NULL, StateBToStateCExt3, &Example2_StateC),
	RKH_TRREG(evA, NULL, NULL, &Example2_C0),
	RKH_TRREG(evC, NULL, NULL, &Example2_CompState2),
	RKH_TRREG(evTout0, NULL, NULL, &Example2_CompState2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_StateC)
	RKH_TRREG(evA, isCondStateCToCompState7, NULL, &Example2_CompState),
	RKH_TRREG(evB, NULL, StateCToC1Ext8, &Example2_C1),
	RKH_TRREG(evC, NULL, StateCToH1Ext9, &Example2_H1),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_CompState)
	RKH_TRREG(evB, NULL, CompStateToStateCExt10, &Example2_StateC),
	RKH_TRREG(evC, NULL, NULL, &Example2Final),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_StateD)
	RKH_TRREG(evA, NULL, NULL, &Example2_StateE),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_StateE)
	RKH_TRREG(evC, NULL, NULL, &Example2_H2),
	RKH_TRREG(evA, NULL, StateEToCompStateFinalExt15, &Example2_CompStateFinal),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_StateF)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_StateG)
	RKH_TRREG(evC, NULL, NULL, &Example2_StateF1),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_StateF1)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_StateF11)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_CompState2)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Example2_CompState21)
	RKH_TRINT(evTout1, NULL, CompState21ToCompState21Loc6),
RKH_END_TRANS_TABLE

RKH_CREATE_CHOICE_STATE(Example2_C0);
RKH_CREATE_CHOICE_STATE(Example2_C1);

RKH_CREATE_BRANCH_TABLE(Example2_C0)
	RKH_BRANCH(isCondC0ToStateC21, NULL, &Example2_StateC),
	RKH_BRANCH(isCondC0ToC122, C0ToC1Ext22, &Example2_C1),
	RKH_BRANCH(ELSE, NULL, &Example2_StateC),
RKH_END_BRANCH_TABLE

RKH_CREATE_BRANCH_TABLE(Example2_C1)
	RKH_BRANCH(isCondC1ToCompState23, C1ToCompStateExt23, &Example2_CompState),
	RKH_BRANCH(ELSE, C1ToStateAExt24, &Example2_StateA),
RKH_END_BRANCH_TABLE

RKH_CREATE_FINAL_STATE(Example2_CompStateFinal, RKH_NULL);
RKH_CREATE_FINAL_STATE(Example2Final, RKH_NULL);

/* ............................. Active object ............................. */
struct Example2
{
    RKH_SMA_T sma;      /* base structure */
    RKHTmEvt tmEvtObj0;
    RKHTmEvt tmEvtObj1;
    rInt intVar;
    rbool_t boolVar;
    rInt uninitializedIntVar;
    rbool_t uninitializedBoolVar;
};

RKH_SMA_CREATE(Example2, example2, 0, HCAL, &Example2_StateA, ToStateAExt0, NULL);
RKH_SMA_DEF_PTR(example2);

/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static rInt foo = 0;


/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
static void 
ToStateAExt0(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 1;
	me->boolVar = true;
	me->uninitializedIntVar = 0;
	me->uninitializedBoolVar = false;
		
	RKH_TR_FWK_AO(me);
	RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
	RKH_TR_FWK_STATE(me, &Example2_StateA);
	RKH_TR_FWK_STATE(me, &Example2_StateB);
	RKH_TR_FWK_STATE(me, &Example2_StateC);
	RKH_TR_FWK_STATE(me, &Example2_CompState);
	RKH_TR_FWK_STATE(me, &Example2_StateD);
	RKH_TR_FWK_STATE(me, &Example2_StateE);
	RKH_TR_FWK_STATE(me, &Example2_StateF);
	RKH_TR_FWK_STATE(me, &Example2_StateG);
	RKH_TR_FWK_STATE(me, &Example2_StateF1);
	RKH_TR_FWK_STATE(me, &Example2_StateF11);
	RKH_TR_FWK_STATE(me, &Example2_CompState2);
	RKH_TR_FWK_STATE(me, &Example2_CompState21);
	RKH_TR_FWK_PSTATE(me, &Example2_H1);
	RKH_TR_FWK_PSTATE(me, &Example2_H2);
	RKH_TR_FWK_PSTATE(me, &Example2_C0);
	RKH_TR_FWK_PSTATE(me, &Example2_C1);
	RKH_TR_FWK_STATE(me, &Example2_CompStateFinal);
	RKH_TR_FWK_STATE(me, &Example2Final);
	RKH_TR_FWK_SIG(evA);
	RKH_TR_FWK_SIG(evB);
	RKH_TR_FWK_SIG(evC);
	RKH_TR_FWK_TIMER(&me->tmEvtObj0.tmr);
	RKH_TR_FWK_TIMER(&me->tmEvtObj1.tmr);
	#if 0
		RKH_TR_FWK_OBJ_NAME(ToStateAExt0, "ToStateAExt0");
		RKH_TR_FWK_OBJ_NAME(StateBToStateCExt3, "StateBToStateCExt3");
		RKH_TR_FWK_OBJ_NAME(StateCToC1Ext8, "StateCToC1Ext8");
		RKH_TR_FWK_OBJ_NAME(StateCToH1Ext9, "StateCToH1Ext9");
		RKH_TR_FWK_OBJ_NAME(CompStateToStateCExt10, "CompStateToStateCExt10");
		RKH_TR_FWK_OBJ_NAME(StateEToCompStateFinalExt15, "StateEToCompStateFinalExt15");
		RKH_TR_FWK_OBJ_NAME(ToStateGExt17, "ToStateGExt17");
		RKH_TR_FWK_OBJ_NAME(H2ToStateGExt18, "H2ToStateGExt18");
		RKH_TR_FWK_OBJ_NAME(ToStateF11Ext19, "ToStateF11Ext19");
		RKH_TR_FWK_OBJ_NAME(C0ToC1Ext22, "C0ToC1Ext22");
		RKH_TR_FWK_OBJ_NAME(C1ToCompStateExt23, "C1ToCompStateExt23");
		RKH_TR_FWK_OBJ_NAME(C1ToStateAExt24, "C1ToStateAExt24");
		RKH_TR_FWK_OBJ_NAME(StateAToStateALoc2, "StateAToStateALoc2");
		RKH_TR_FWK_OBJ_NAME(CompState21ToCompState21Loc6, "CompState21ToCompState21Loc6");
		RKH_TR_FWK_OBJ_NAME(enStateA, "enStateA");
		RKH_TR_FWK_OBJ_NAME(enStateC, "enStateC");
		RKH_TR_FWK_OBJ_NAME(enCompState, "enCompState");
		RKH_TR_FWK_OBJ_NAME(exStateA, "exStateA");
		RKH_TR_FWK_OBJ_NAME(exCompState, "exCompState");
		RKH_TR_FWK_OBJ_NAME(isCondStateCToCompState7, "isCondStateCToCompState7");
		RKH_TR_FWK_OBJ_NAME(isCondC0ToStateC21, "isCondC0ToStateC21");
		RKH_TR_FWK_OBJ_NAME(isCondC0ToC122, "isCondC0ToC122");
		RKH_TR_FWK_OBJ_NAME(isCondC1ToCompState23, "isCondC1ToCompState23");
	#endif
	
	simpleOp();
}

static void 
StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

static void 
StateCToC1Ext8(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

static void 
StateCToH1Ext9(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

static void 
CompStateToStateCExt10(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

static void 
StateEToCompStateFinalExt15(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

static void 
ToStateGExt17(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 8;
}

static void 
H2ToStateGExt18(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 1;
}

static void 
ToStateF11Ext19(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 16;
}

static void 
C0ToC1Ext22(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

static void 
C1ToCompStateExt23(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar++;
}

static void 
C1ToStateAExt24(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 0;
}

static void 
StateAToStateALoc2(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
	me->intVar++;
	foo++;
}

static void 
CompState21ToCompState21Loc6(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

/* ............................. Entry actions ............................. */
static void 
enStateA(Example2 *const me)
{
	me->boolVar = false;
}

static void 
enStateB(Example2 *const me)
{
	RKH_SET_STATIC_EVENT(&me->tmEvtObj0, evTout0);
	RKH_TMR_INIT(&me->tmEvtObj0.tmr, RKH_UPCAST(RKH_EVT_T, &me->tmEvtObj0), NULL);
	RKH_TMR_ONESHOT(&me->tmEvtObj0.tmr, RKH_UPCAST(RKH_SMA_T, me), WaitTime0);
}

static void 
enStateC(Example2 *const me)
{
	me->intVar = opWithParamAndReturn(me->intVar);
	me->intVar = opWithReturn();
	opWithParams(me->intVar, me->boolVar);
}

static void 
enCompState(Example2 *const me)
{
	me->intVar++;
}

static void 
enCompState21(Example2 *const me)
{
	RKH_SET_STATIC_EVENT(&me->tmEvtObj1, evTout1);
	RKH_TMR_INIT(&me->tmEvtObj1.tmr, RKH_UPCAST(RKH_EVT_T, &me->tmEvtObj1), NULL);
	RKH_TMR_PERIODIC(&me->tmEvtObj1.tmr, RKH_UPCAST(RKH_SMA_T, me), WaitTime1, WaitTime1);
}

/* ............................. Exit actions .............................. */
static void 
exStateA(Example2 *const me)
{
	me->intVar = 2;
}

static void 
exStateB(Example2 *const me)
{
	rkh_tmr_stop(&me->tmEvtObj0.tmr);
}

static void 
exCompState(Example2 *const me)
{
	me->boolVar = true;
}

static void 
exCompState21(Example2 *const me)
{
	rkh_tmr_stop(&me->tmEvtObj1.tmr);
}

/* ................................ Guards ................................. */
static rbool_t 
isCondStateCToCompState7(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 5)) ? true : false;
}
	
static rbool_t 
isCondC0ToStateC21(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 0)) ? true : false;
}
	
static rbool_t 
isCondC0ToC122(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 1)) ? true : false;
}
	
static rbool_t 
isCondC1ToCompState23(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->boolVar == false)) ? true : false;
}
	
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
