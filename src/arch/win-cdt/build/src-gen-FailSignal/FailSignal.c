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

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE FailSignal_Idle, FailSignal_Success, FailSignal_Failure, RegionB_StateA, RegionB_StateB, RegionB_StateD;
RKH_DCLR_COMP_STATE RegionB_StateC;
RKH_DCLR_CHOICE_STATE RegionB_C0;
RKH_DCLR_FINAL_STATE FailSignalFinal, RegionB_StateCFinal, RegionBFinal;
RKH_DCLR_SHIST_STATE RegionB_H1;

/* ........................ Declares effect actions ........................ */
static void ToIdleExt0(FailSignal *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */
static void enFailure(FailSignal *const me);

/* ......................... Declares exit actions ......................... */

/* ............................ Declares guards ............................ */
static rbool_t isCondC0ToStateC11(FailSignal *const me, RKH_EVT_T *pe);
static rbool_t isCondC0ToH112(FailSignal *const me, RKH_EVT_T *pe);

/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(FailSignal_Idle, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(FailSignal_Success, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(FailSignal_Failure, enFailure, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(RegionB_StateA, NULL, NULL, RKH_ROOT, NULL);
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
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(FailSignal_Failure)
	RKH_TRREG(evFailLow, NULL, NULL, &FailSignal_Success),
	RKH_TRREG(evFailHigh, NULL, NULL, &FailSignalFinal),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(RegionB_StateA)
	RKH_TRREG(evFailHigh, NULL, NULL, &RegionB_StateB),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(RegionB_StateB)
	RKH_TRREG(evFailHigh, NULL, NULL, &RegionB_C0),
	RKH_TRREG(evFailLow, NULL, NULL, &RegionBFinal),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(RegionB_StateC)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(RegionB_StateD)
	RKH_TRREG(evFailLow, NULL, NULL, &RegionB_StateCFinal),
RKH_END_TRANS_TABLE

RKH_CREATE_CHOICE_STATE(RegionB_C0);

RKH_CREATE_BRANCH_TABLE(RegionB_C0)
	RKH_BRANCH(isCondC0ToStateC11, NULL, &RegionB_StateC),
	RKH_BRANCH(isCondC0ToH112, NULL, &RegionB_H1),
	RKH_BRANCH(ELSE, NULL, &RegionB_StateB),
RKH_END_BRANCH_TABLE

RKH_CREATE_FINAL_STATE(FailSignalFinal, RKH_NULL);

/* ............................. Active object ............................. */
struct FailSignal
{
    RKH_SMA_T sma;      /* base structure */
    rInt currInput;
    rInt lastInput;
    rInt foo;
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
	RKH_TR_FWK_PSTATE(me, &RegionB_C0);
	RKH_TR_FWK_STATE(me, &FailSignalFinal);
	RKH_TR_FWK_STATE(me, &RegionB_StateCFinal);
	RKH_TR_FWK_STATE(me, &RegionBFinal);
	RKH_TR_FWK_SIG(evFailHigh);
	RKH_TR_FWK_SIG(evFailLow);
	#if 0
		RKH_TR_FWK_OBJ_NAME(ToIdleExt0, "ToIdleExt0");
		RKH_TR_FWK_OBJ_NAME(enFailure, "enFailure");
		RKH_TR_FWK_OBJ_NAME(isCondC0ToStateC11, "isCondC0ToStateC11");
		RKH_TR_FWK_OBJ_NAME(isCondC0ToH112, "isCondC0ToH112");
	#endif
	
	Init();
}

/* ............................. Entry actions ............................. */
static void 
enFailure(FailSignal *const me)
{
	measureFailure();
}

/* ............................. Exit actions .............................. */
/* ................................ Guards ................................. */
static rbool_t 
isCondC0ToStateC11(FailSignal *const me, RKH_EVT_T *pe)
{
	return ((me->foo == 0)) ? true : false;
}
	
static rbool_t 
isCondC0ToH112(FailSignal *const me, RKH_EVT_T *pe)
{
	return ((me->foo == 1)) ? true : false;
}
	
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
