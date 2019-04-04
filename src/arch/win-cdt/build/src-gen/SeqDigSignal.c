/**
 *  \file       SeqDigSignal.c
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
#include "SeqDigSignal.h"
#include "SeqDigSignalAct.h"

/* ----------------------------- Local macros ------------------------------ */
/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(Idle ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Seq0 ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Seq1 ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Seq2 ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Seq3 ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Seq4 ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Seq5 ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(Failure ,NULL ,NULL ,RKH_ROOT, NULL);



RKH_CREATE_TRANS_TABLE(Idle)
RKH_TRREG(evIn1, NULL, SeqDigSignal_IdleToSeq0Ext1, &Seq0),
RKH_TRREG(evIn2, NULL, NULL, &Seq2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Seq0)
RKH_TRREG(evIn0, NULL, SeqDigSignal_Seq0ToSeq1Ext3, &Seq1),
RKH_TRREG(evIn1, NULL, NULL, &Failure),
RKH_TRREG(evIn2, NULL, NULL, &Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Seq1)
RKH_TRREG(evIn2, NULL, NULL, &Seq2),
RKH_TRREG(evIn0, NULL, NULL, &Failure),
RKH_TRREG(evIn1, NULL, NULL, &Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Seq2)
RKH_TRREG(evIn0, NULL, NULL, &Seq3),
RKH_TRREG(evIn1, NULL, NULL, &Failure),
RKH_TRREG(evIn2, NULL, NULL, &Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Seq3)
RKH_TRREG(evIn0, NULL, NULL, &Seq4),
RKH_TRREG(evIn1, NULL, NULL, &Failure),
RKH_TRREG(evIn2, NULL, NULL, &Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Seq4)
RKH_TRREG(evIn0, NULL, NULL, &Seq5),
RKH_TRREG(evIn1, NULL, NULL, &Failure),
RKH_TRREG(evIn2, NULL, NULL, &Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Seq5)
RKH_TRREG(evIn1, NULL, NULL, &Idle),
RKH_TRREG(evIn0, NULL, NULL, &Failure),
RKH_TRREG(evIn2, NULL, NULL, &Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(Failure)
RKH_TRCOMPLETION(NULL, NULL, &Idle),
RKH_END_TRANS_TABLE


/* ............................. Active object ............................. */
RKH_SMA_CREATE(SeqDigSignal, SeqDigSignal, 0, HCAL, &Idle, SeqDigSignal_ToIdleExt0, NULL);
RKH_SMA_DEF_PTR(SeqDigSignal);

/* ------------------------------- Constants ------------------------------- */

/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
