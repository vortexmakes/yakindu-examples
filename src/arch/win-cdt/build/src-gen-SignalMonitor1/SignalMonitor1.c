/**
 *  \file       SignalMonitor1.c
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
#include "SignalMonitor1.h"
#include "SignalMonitor1Act.h"

/* ----------------------------- Local macros ------------------------------ */
/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(Idle ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Success ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Failure ,SignalMonitor1_enFailure ,NULL ,RKH_ROOT, NULL);

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
RKH_SMA_CREATE(SignalMonitor1, signalMonitor1, 0, HCAL, &Idle, SignalMonitor1_ToIdleExt0, NULL);
RKH_SMA_DEF_PTR(signalMonitor1);

/* ------------------------------- Constants ------------------------------- */

/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
