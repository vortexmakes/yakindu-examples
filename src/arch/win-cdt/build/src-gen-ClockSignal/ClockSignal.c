/**
 *  \file       ClockSignal.c
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
#include "rkhsma.h"
#include "signal.h"
#include "ClockSignal.h"
#include "ClockSignalAct.h"

/* ----------------------------- Local macros ------------------------------ */
/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(Idle ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(WaitFallEdge ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(WaitRisEdge ,NULL ,NULL ,RKH_ROOT, NULL);



RKH_CREATE_TRANS_TABLE(Idle)
RKH_TRREG(evClockHigh, NULL, NULL, &WaitFallEdge),
RKH_TRREG(evClockLow, NULL, NULL, &WaitRisEdge),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(WaitFallEdge)
RKH_TRREG(evClockLow, NULL, ClockSignal_WaitFallEdgeToWaitRisEdgeExt3, &WaitRisEdge),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(WaitRisEdge)
RKH_TRREG(evClockHigh, NULL, NULL, &WaitFallEdge),
RKH_END_TRANS_TABLE


/* ............................. Active object ............................. */
RKH_SMA_CREATE(ClockSignal, ClockSignal, 0, HCAL, &Idle, ClockSignal_ToIdleExt0, NULL);
RKH_SMA_DEF_PTR(ClockSignal);

/* ------------------------------- Constants ------------------------------- */

/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
