/**
 *  \file       FailSignal.c
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
#include "FailSignal.h"
#include "bsp.h"
#include "FailSignalRequired.h"

/* ----------------------------- Local macros ------------------------------ */

/* ......................... Declares active object ........................ */
typedef struct FailSignal FailSignal;
typedef struct RegionB RegionB;

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE FailSignal_Idle, FailSignal_Success, FailSignal_Failure, RegionB_StateA, RegionB_StateB, RegionB_StateD;
RKH_DCLR_COMP_STATE RegionB_StateC;
RKH_DCLR_CHOICE_STATE FailSignal_C0, RegionB_C1;
RKH_DCLR_FINAL_STATE FailSignalFinal, RegionB_StateCFinal, RegionBFinal;
RKH_DCLR_SHIST_STATE RegionB_H1;

/* ........................ Declares effect actions ........................ */
static void ToIdleExt0(FailSignal *const me, RKH_EVT_T *pe);
static void C0ToFailureExt7(FailSignal *const me, RKH_EVT_T *pe);
static void StateAToStateBExt8(RegionB *const me, RKH_EVT_T *pe);
static void ToStateAExt11(RegionB *const me, RKH_EVT_T *pe);
static void C1ToH1Ext14(RegionB *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */
static void enFailure(FailSignal *const me);
static void enStateA(RegionB *const me);

/* ......................... Declares exit actions ......................... */

/* ............................ Declares guards ............................ */
static rbool_t isCondC1ToStateC13(RegionB *const me, RKH_EVT_T *pe);
static rbool_t isCondC1ToH114(RegionB *const me, RKH_EVT_T *pe);

/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(FailSignal_Idle, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(FailSignal_Success, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(FailSignal_Failure, enFailure, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(RegionB_StateA, enStateA, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(RegionB_StateB, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(RegionB_StateD, NULL, NULL, &RegionB_StateC, NULL);

RKH_CREATE_HISTORY_STORAGE(RegionB_StateC);
RKH_CREATE_COMP_REGION_STATE(RegionB_StateC, NULL, NULL, RKH_ROOT, &RegionB_StateD, NULL, RKH_SHISTORY, NULL, NULL, &RegionB_StateD, RKH_GET_HISTORY_STORAGE(RegionB_StateC));

RKH_CREATE_TRANS_TABLE(FailSignal_Idle)
	RKH_TRREG(evFailLow, NULL, NULL, &FailSignal_Success),
	RKH_TRREG(evFailHigh, NULL, NULL, &FailSignal_Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(FailSignal_Success)
	RKH_TRREG(evFailHigh, NULL, NULL, &FailSignal_Failure),
	RKH_TRREG(evFailLow, NULL, NULL, &FailSignal_C0),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(FailSignal_Failure)
	RKH_TRREG(evFailLow, NULL, NULL, &FailSignal_Success),
	RKH_TRREG(evFailHigh, NULL, NULL, &FailSignalFinal),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(RegionB_StateA)
	RKH_TRREG(evFailHigh, NULL, StateAToStateBExt8, &RegionB_StateB),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(RegionB_StateB)
	RKH_TRREG(evFailHigh, NULL, NULL, &RegionB_C1),
	RKH_TRREG(evFailLow, NULL, NULL, &RegionBFinal),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(RegionB_StateC)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(RegionB_StateD)
	RKH_TRREG(evFailLow, NULL, NULL, &RegionB_StateCFinal),
RKH_END_TRANS_TABLE

RKH_CREATE_CHOICE_STATE(FailSignal_C0);
RKH_CREATE_CHOICE_STATE(RegionB_C1);

RKH_CREATE_BRANCH_TABLE(FailSignal_C0)
	RKH_BRANCH(ELSE, C0ToFailureExt7, &FailSignal_Failure),
RKH_END_BRANCH_TABLE

RKH_CREATE_BRANCH_TABLE(RegionB_C1)
	RKH_BRANCH(isCondC1ToStateC13, NULL, &RegionB_StateC),
	RKH_BRANCH(isCondC1ToH114, C1ToH1Ext14, &RegionB_H1),
	RKH_BRANCH(ELSE, NULL, &RegionB_StateB),
RKH_END_BRANCH_TABLE

RKH_CREATE_FINAL_STATE(FailSignalFinal, RKH_NULL);
RKH_CREATE_FINAL_STATE(RegionB_StateCFinal, RKH_NULL);
RKH_CREATE_FINAL_STATE(RegionBFinal, RKH_NULL);

/* ............................. Active object ............................. */
struct FailSignal
{
    RKH_SMA_T sma;      /* base structure */
    rInt currInput;
    rInt lastInput;
    rInt foo;
    rInt bar;
    rInt baz;
};

RKH_SMA_CREATE(FailSignal, failSignal, 0, HCAL, &FailSignal_Idle, ToIdleExt0, NULL);
RKH_SMA_DEF_PTR(failSignal);

/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
static void 
ToIdleExt0(FailSignal *const me, RKH_EVT_T *pe)
{
	me->currInput = 0;
	me->lastInput = 0;
	me->foo = 0;
	me->bar = 0;
	me->baz = 0;
		
	RKH_TR_FWK_AO(me);
	RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
	RKH_TR_FWK_STATE(me, &FailSignal_Idle);
	RKH_TR_FWK_STATE(me, &FailSignal_Success);
	RKH_TR_FWK_STATE(me, &FailSignal_Failure);
	RKH_TR_FWK_STATE(me, &RegionB_StateA);
	RKH_TR_FWK_STATE(me, &RegionB_StateB);
	RKH_TR_FWK_STATE(me, &RegionB_StateC);
	RKH_TR_FWK_STATE(me, &RegionB_StateD);
	RKH_TR_FWK_PSTATE(me, &RegionB_H1);
	RKH_TR_FWK_PSTATE(me, &FailSignal_C0);
	RKH_TR_FWK_PSTATE(me, &RegionB_C1);
	RKH_TR_FWK_STATE(me, &FailSignalFinal);
	RKH_TR_FWK_STATE(me, &RegionB_StateCFinal);
	RKH_TR_FWK_STATE(me, &RegionBFinal);
	RKH_TR_FWK_SIG(evFailHigh);
	RKH_TR_FWK_SIG(evFailLow);
	#if 0
		RKH_TR_FWK_OBJ_NAME(ToIdleExt0, "ToIdleExt0");
		RKH_TR_FWK_OBJ_NAME(C0ToFailureExt7, "C0ToFailureExt7");
		RKH_TR_FWK_OBJ_NAME(StateAToStateBExt8, "StateAToStateBExt8");
		RKH_TR_FWK_OBJ_NAME(ToStateAExt11, "ToStateAExt11");
		RKH_TR_FWK_OBJ_NAME(C1ToH1Ext14, "C1ToH1Ext14");
		RKH_TR_FWK_OBJ_NAME(enFailure, "enFailure");
		RKH_TR_FWK_OBJ_NAME(enStateA, "enStateA");
		RKH_TR_FWK_OBJ_NAME(isCondC1ToStateC13, "isCondC1ToStateC13");
		RKH_TR_FWK_OBJ_NAME(isCondC1ToH114, "isCondC1ToH114");
	#endif
	
	Init();
}

static void 
C0ToFailureExt7(FailSignal *const me, RKH_EVT_T *pe)
{
	me->baz = 1;
}

static void 
StateAToStateBExt8(FailSignal *const me, RKH_EVT_T *pe)
{
	me->foo = 8;
}

static void 
ToStateAExt11(FailSignal *const me, RKH_EVT_T *pe)
{
	me->bar = 0;
}

static void 
C1ToH1Ext14(FailSignal *const me, RKH_EVT_T *pe)
{
	me->foo = 16;
}

/* ............................. Entry actions ............................. */
static void 
enFailure(FailSignal *const me)
{
	measureFailure();
}

static void 
enStateA(FailSignal *const me)
{
	me->foo = 32;
}

/* ............................. Exit actions .............................. */
/* ................................ Guards ................................. */
static rbool_t 
isCondC1ToStateC13(FailSignal *const me, RKH_EVT_T *pe)
{
	return ((me->foo == 0)) ? true : false;
}
	
static rbool_t 
isCondC1ToH114(FailSignal *const me, RKH_EVT_T *pe)
{
	return ((me->foo == 1)) ? true : false;
}
	
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
