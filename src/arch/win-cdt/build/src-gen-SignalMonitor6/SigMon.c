/**
 *  \file       SigMon.c
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
#include "SigMon.h"
#include "SigMonAct.h"

/* ----------------------------- Local macros ------------------------------ */
/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(SigMon_Inactive, NULL, NULL, &SigMon_Inactive, NULL);

RKH_CREATE_BASIC_STATE(SigMon_WaitSyncSeq, NULL, NULL, &SigMon_WaitSyncSeq, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq0, SigMon_enSigMon_Seq0, NULL, &SigMon_Seq0, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq2, NULL, NULL, &SigMon_Seq2, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq3, NULL, NULL, &SigMon_Seq3, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq4, NULL, NULL, &SigMon_Seq4, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq5, NULL, NULL, &SigMon_Seq5, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq11, NULL, NULL, &SigMon_Seq11, NULL);

RKH_CREATE_BASIC_STATE(SigMon_OutOfSeq, NULL, NULL, &SigMon_OutOfSeq, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq1, NULL, NULL, &SigMon_Seq1, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq10, NULL, NULL, &SigMon_Seq10, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq8, NULL, NULL, &SigMon_Seq8, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq7, NULL, NULL, &SigMon_Seq7, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq6, NULL, NULL, &SigMon_Seq6, NULL);

RKH_CREATE_BASIC_STATE(SigMon_Seq9, NULL, NULL, &SigMon_Seq9, NULL);

RKH_CREATE_COMP_REGION_STATE(SigMon_Active, SigMon_enSigMon_Active, SigMon_exSigMon_Active, &SigMon_Active, &SigMon_WaitSyncSeq, NULL, RKH_NO_HISTORY, NULL, NULL, NULL, NULL);

RKH_CREATE_TRANS_TABLE(SigMon_Inactive)
RKH_TRREG(evEnable, NULL, NULL, &SigMon_Active),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Active)
RKH_TRREG(evDisable, NULL, NULL, &SigMon_Inactive),
RKH_TRREG(evFailure, NULL, SigMon_SigMon_ActiveToNULLExt3, &NULL),
RKH_TRINT(evSync, NULL, SigMon_SigMon_ActiveToSigMon_ActiveLoc2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_WaitSyncSeq)
RKH_TRREG(evIn1, NULL, NULL, &SigMon_Seq0),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq0)
RKH_TRREG(evIn4, NULL, NULL, &SigMon_Seq1),
RKH_TRREG(evIn0, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRINT(evIn1, NULL, SigMon_SigMon_Seq0ToSigMon_Seq0Loc4),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq2)
RKH_TRREG(evIn6, NULL, SigMon_SigMon_Seq2ToSigMon_Seq3Ext8, &SigMon_Seq3),
RKH_TRREG(evIn0, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn4, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRINT(evIn0, NULL, SigMon_SigMon_Seq2ToSigMon_Seq2Loc5),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq3)
RKH_TRREG(evIn2, NULL, NULL, &SigMon_Seq4),
RKH_TRREG(evIn0, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn4, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq4)
RKH_TRREG(evIn4, NULL, NULL, &SigMon_Seq5),
RKH_TRREG(evIn0, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq5)
RKH_TRREG(evIn0, NULL, NULL, &SigMon_Seq6),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn4, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq11)
RKH_TRREG(evIn1, NULL, NULL, &SigMon_Seq0),
RKH_TRREG(evIn0, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn4, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_OutOfSeq)
RKH_TRREG(evIn1, NULL, NULL, &SigMon_Seq0),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq1)
RKH_TRREG(evIn0, NULL, NULL, &SigMon_Seq2),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn4, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRINT(evIn4, NULL, SigMon_SigMon_Seq1ToSigMon_Seq1Loc6),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq10)
RKH_TRREG(evIn5, NULL, NULL, &SigMon_Seq11),
RKH_TRREG(evIn0, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn4, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRINT(evIn1, NULL, SigMon_SigMon_Seq10ToSigMon_Seq10Loc7),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq8)
RKH_TRREG(evIn4, NULL, NULL, &SigMon_Seq9),
RKH_TRREG(evIn0, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRINT(evIn0, NULL, SigMon_SigMon_Seq8ToSigMon_Seq8Loc8),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq7)
RKH_TRREG(evIn0, NULL, NULL, &SigMon_Seq8),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn4, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq6)
RKH_TRREG(evIn4, NULL, NULL, &SigMon_Seq7),
RKH_TRREG(evIn0, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SigMon_Seq9)
RKH_TRREG(evIn0, NULL, NULL, &SigMon_Seq10),
RKH_TRREG(evIn1, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn2, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn4, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn5, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRREG(evIn6, NULL, NULL, &SigMon_OutOfSeq),
RKH_TRINT(evIn4, NULL, SigMon_SigMon_Seq9ToSigMon_Seq9Loc9),
RKH_END_TRANS_TABLE

/* ............................. Active object ............................. */
RKH_SMA_CREATE(SigMon, sigMon, 0, HCAL, &SigMon_Inactive, NULL, NULL);
RKH_SMA_DEF_PTR(sigMon);

/* ------------------------------- Constants ------------------------------- */

/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
