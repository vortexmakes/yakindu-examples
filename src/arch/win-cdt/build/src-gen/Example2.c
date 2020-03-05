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
#include "Example2ActRequired.h"

/* ----------------------------- Local macros ------------------------------ */
#define WaitTime0	RKH_TIME_MS(100)
#define WaitTime1	RKH_TIME_SEC(3)

/* ......................... Declares active object ........................ */
typedef struct Example2 Example2;

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE StateA, StateB, StateC, StateD, StateE, StateG, StateF11, CompState21;
RKH_DCLR_COMP_STATE CompState, StateF, StateF1, CompState2;
RKH_DCLR_CHOICE_STATE C0, C1;
RKH_DCLR_FINAL_STATE CompState_Final, Example2_Final;
RKH_DCLR_SHIST_STATE H1, H2;

/* ........................ Declares effect actions ........................ */
void ToStateAExt0(Example2 *const me, RKH_EVT_T *pe);
void StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe);
void StateCToC1Ext8(Example2 *const me, RKH_EVT_T *pe);
void StateCToH1Ext9(Example2 *const me, RKH_EVT_T *pe);
void CompStateToStateCExt10(Example2 *const me, RKH_EVT_T *pe);
void StateEToCompState_FinalExt15(Example2 *const me, RKH_EVT_T *pe);
void ToStateGExt17(Example2 *const me, RKH_EVT_T *pe);
void H2ToStateGExt18(Example2 *const me, RKH_EVT_T *pe);
void ToStateF11Ext19(Example2 *const me, RKH_EVT_T *pe);
void C0ToC1Ext22(Example2 *const me, RKH_EVT_T *pe);
void C1ToCompStateExt23(Example2 *const me, RKH_EVT_T *pe);
void C1ToStateAExt24(Example2 *const me, RKH_EVT_T *pe);
void StateAToStateALoc2(Example2 *const me, RKH_EVT_T *pe);
void CompState21ToCompState21Loc6(Example2 *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */
void enStateA(Example2 *const me);
void enStateB(Example2 *const me);
void enStateC(Example2 *const me);
void enCompState(Example2 *const me);
void enCompState21(Example2 *const me);

/* ......................... Declares exit actions ......................... */
void exStateA(Example2 *const me);
void exStateB(Example2 *const me);
void exCompState(Example2 *const me);
void exCompState21(Example2 *const me);

/* ............................ Declares guards ............................ */
rbool_t isCondStateCToCompState7(Example2 *const me, RKH_EVT_T *pe);
rbool_t isCondC0ToStateC21(Example2 *const me, RKH_EVT_T *pe);
rbool_t isCondC0ToC122(Example2 *const me, RKH_EVT_T *pe);
rbool_t isCondC1ToCompState23(Example2 *const me, RKH_EVT_T *pe);

/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(StateA, enStateA, exStateA, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(StateB, enStateB, exStateB, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(StateC, enStateC, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(StateD, NULL, NULL, &CompState, NULL);
RKH_CREATE_BASIC_STATE(StateE, NULL, NULL, &CompState, NULL);
RKH_CREATE_BASIC_STATE(StateG, NULL, NULL, &StateF, NULL);
RKH_CREATE_BASIC_STATE(StateF11, NULL, NULL, &StateF1, NULL);
RKH_CREATE_BASIC_STATE(CompState21, enCompState21, exCompState21, &CompState2, NULL);

RKH_CREATE_HISTORY_STORAGE(CompState);
RKH_CREATE_COMP_REGION_STATE(CompState, enCompState, exCompState, RKH_ROOT, &StateD, NULL, RKH_SHISTORY, NULL, NULL, NULL, RKH_GET_HISTORY_STORAGE(CompState));
RKH_CREATE_HISTORY_STORAGE(StateF);
RKH_CREATE_COMP_REGION_STATE(StateF, NULL, NULL, &CompState, &StateG, ToStateGExt17, RKH_SHISTORY, NULL, H2ToStateGExt18, &StateG, RKH_GET_HISTORY_STORAGE(StateF));
RKH_CREATE_COMP_REGION_STATE(StateF1, NULL, NULL, &StateF, &StateF11, ToStateF11Ext19, RKH_NO_HISTORY, NULL, NULL, NULL, NULL);
RKH_CREATE_COMP_REGION_STATE(CompState2, NULL, NULL, RKH_ROOT, &CompState21, NULL, RKH_NO_HISTORY, NULL, NULL, NULL, NULL);

RKH_CREATE_TRANS_TABLE(StateA)
	RKH_TRREG(evB, NULL, NULL, &StateB),
	RKH_TRCOMPLETION(NULL, NULL, &StateB),
	RKH_TRINT(evA, NULL, StateAToStateALoc2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateB)
	RKH_TRREG(evA, NULL, StateBToStateCExt3, &StateC),
	RKH_TRREG(evB, NULL, StateBToStateCExt3, &StateC),
	RKH_TRREG(evA, NULL, NULL, &C0),
	RKH_TRREG(evC, NULL, NULL, &CompState2),
	RKH_TRREG(evTout0, NULL, NULL, &CompState2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateC)
	RKH_TRREG(evA, isCondStateCToCompState7, NULL, &CompState),
	RKH_TRREG(evB, NULL, StateCToC1Ext8, &C1),
	RKH_TRREG(evC, NULL, StateCToH1Ext9, &H1),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(CompState)
	RKH_TRREG(evB, NULL, CompStateToStateCExt10, &StateC),
	RKH_TRREG(evC, NULL, NULL, &Example2_Final),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateD)
	RKH_TRREG(evA, NULL, NULL, &StateE),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateE)
	RKH_TRREG(evC, NULL, NULL, &H2),
	RKH_TRREG(evA, NULL, StateEToCompState_FinalExt15, &CompState_Final),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateF)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateG)
	RKH_TRREG(evC, NULL, NULL, &StateF1),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateF1)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateF11)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(CompState2)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(CompState21)
	RKH_TRINT(evTout1, NULL, CompState21ToCompState21Loc6),
RKH_END_TRANS_TABLE

RKH_CREATE_CHOICE_STATE(C0);
RKH_CREATE_CHOICE_STATE(C1);

RKH_CREATE_BRANCH_TABLE(C0)
	RKH_BRANCH(isCondC0ToStateC21, NULL, &StateC),
	RKH_BRANCH(isCondC0ToC122, C0ToC1Ext22, &C1),
	RKH_BRANCH(ELSE, NULL, &StateC),
RKH_END_BRANCH_TABLE

RKH_CREATE_BRANCH_TABLE(C1)
	RKH_BRANCH(isCondC1ToCompState23, C1ToCompStateExt23, &CompState),
	RKH_BRANCH(ELSE, C1ToStateAExt24, &StateA),
RKH_END_BRANCH_TABLE

RKH_CREATE_FINAL_STATE(Example2_Final, RKH_NULL);

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

RKH_SMA_CREATE(Example2, example2, 0, HCAL, &StateA, ToStateAExt0, NULL);
RKH_SMA_DEF_PTR(example2);

/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static rInt foo = 0;


/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
void 
ToStateAExt0(Example2 *const me, RKH_EVT_T *pe)
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
		RKH_TR_FWK_OBJ_NAME(ToStateAExt0, "ToStateAExt0");
		RKH_TR_FWK_OBJ_NAME(StateBToStateCExt3, "StateBToStateCExt3");
		RKH_TR_FWK_OBJ_NAME(StateCToC1Ext8, "StateCToC1Ext8");
		RKH_TR_FWK_OBJ_NAME(StateCToH1Ext9, "StateCToH1Ext9");
		RKH_TR_FWK_OBJ_NAME(CompStateToStateCExt10, "CompStateToStateCExt10");
		RKH_TR_FWK_OBJ_NAME(StateEToCompState_FinalExt15, "StateEToCompState_FinalExt15");
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

void 
StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
StateCToC1Ext8(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

void 
StateCToH1Ext9(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

void 
CompStateToStateCExt10(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

void 
StateEToCompState_FinalExt15(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = false;
}

void 
ToStateGExt17(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 8;
}

void 
H2ToStateGExt18(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 1;
}

void 
ToStateF11Ext19(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 16;
}

void 
C0ToC1Ext22(Example2 *const me, RKH_EVT_T *pe)
{
	me->boolVar = true;
}

void 
C1ToCompStateExt23(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar++;
}

void 
C1ToStateAExt24(Example2 *const me, RKH_EVT_T *pe)
{
	me->intVar = 0;
}

void 
StateAToStateALoc2(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
	me->intVar++;
	foo++;
}

void 
CompState21ToCompState21Loc6(Example2 *const me, RKH_EVT_T *pe)
{
	simpleOp();
}

/* ............................. Entry actions ............................. */
void 
enStateA(Example2 *const me)
{
	me->boolVar = false;
}

void 
enStateB(Example2 *const me)
{
	RKH_SET_STATIC_EVENT(&me->tmEvtObj0, evTout0);
	RKH_TMR_INIT(&me->tmEvtObj0.tmr, RKH_UPCAST(RKH_EVT_T, &me->tmEvtObj0), NULL);
	RKH_TMR_ONESHOT(&me->tmEvtObj0.tmr, RKH_UPCAST(RKH_SMA_T, me), WaitTime0);
}

void 
enStateC(Example2 *const me)
{
	me->intVar = opWithParamAndReturn(me->intVar);
	me->intVar = opWithReturn();
	opWithParams(me->intVar, me->boolVar);
}

void 
enCompState(Example2 *const me)
{
	me->intVar++;
}

void 
enCompState21(Example2 *const me)
{
	RKH_SET_STATIC_EVENT(&me->tmEvtObj1, evTout1);
	RKH_TMR_INIT(&me->tmEvtObj1.tmr, RKH_UPCAST(RKH_EVT_T, &me->tmEvtObj1), NULL);
	RKH_TMR_PERIODIC(&me->tmEvtObj1.tmr, RKH_UPCAST(RKH_SMA_T, me), WaitTime1, WaitTime1);
}

/* ............................. Exit actions .............................. */
void 
exStateA(Example2 *const me)
{
	me->intVar = 2;
}

void 
exStateB(Example2 *const me)
{
	rkh_tmr_stop(&me->tmEvtObj0.tmr);
}

void 
exCompState(Example2 *const me)
{
	me->boolVar = true;
}

void 
exCompState21(Example2 *const me)
{
	rkh_tmr_stop(&me->tmEvtObj1.tmr);
}

/* ................................ Guards ................................. */
rbool_t 
isCondStateCToCompState7(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 5)) ? true : false;
}

rbool_t 
isCondC0ToStateC21(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 0)) ? true : false;
}

rbool_t 
isCondC0ToC122(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->intVar == 1)) ? true : false;
}

rbool_t 
isCondC1ToCompState23(Example2 *const me, RKH_EVT_T *pe)
{
	return ((me->boolVar == false)) ? true : false;
}

/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
