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
#include "rkhsma.h"
#include "signal.h"
#include "FailSignal.h"
#include "FailSignalAct.h"

/* ----------------------------- Local macros ------------------------------ */
/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(Idle ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Success ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Failure ,FailSignal_enFailure ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_TRANS_TABLE(Idle)
RKH_TRREG(evFailLow, NULL, NULL, &Success),
RKH_TRREG(evFailHigh, NULL, NULL, &Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Success)
RKH_TRREG(evFailHigh, NULL, NULL, &Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Failure)
RKH_TRREG(evFailLow, NULL, NULL, &Success),
RKH_END_TRANS_TABLE

/* ............................. Active object ............................. */
RKH_SMA_CREATE(FailSignal, failSignal, 0, HCAL, &Idle, FailSignal_ToIdleExt0, NULL);
RKH_SMA_DEF_PTR(failSignal);

/* ------------------------------- Constants ------------------------------- */

/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
