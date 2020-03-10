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
#include "rkh.h"
#include "signals.h"
#include "SeqDigSignal.h"
#include "bsp.h"
#include "SeqDigSignalRequired.h"

/* ----------------------------- Local macros ------------------------------ */

/* ......................... Declares active object ........................ */
typedef struct SeqDigSignal SeqDigSignal;

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE SeqDigSignal_Idle, SeqDigSignal_Seq0, SeqDigSignal_Seq1, SeqDigSignal_Seq2, SeqDigSignal_Seq3, SeqDigSignal_Seq4, SeqDigSignal_Seq5, SeqDigSignal_Failure;

/* ........................ Declares effect actions ........................ */
static void ToIdleExt0(SeqDigSignal *const me, RKH_EVT_T *pe);
static void IdleToSeq0Ext1(SeqDigSignal *const me, RKH_EVT_T *pe);
static void Seq0ToSeq1Ext3(SeqDigSignal *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */

/* ......................... Declares exit actions ......................... */

/* ............................ Declares guards ............................ */

/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(SeqDigSignal_Idle, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(SeqDigSignal_Seq0, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(SeqDigSignal_Seq1, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(SeqDigSignal_Seq2, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(SeqDigSignal_Seq3, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(SeqDigSignal_Seq4, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(SeqDigSignal_Seq5, NULL, NULL, RKH_ROOT, NULL);
RKH_CREATE_BASIC_STATE(SeqDigSignal_Failure, NULL, NULL, RKH_ROOT, NULL);


RKH_CREATE_TRANS_TABLE(SeqDigSignal_Idle)
	RKH_TRREG(evIn1, NULL, IdleToSeq0Ext1, &SeqDigSignal_Seq0),
	RKH_TRREG(evIn2, NULL, NULL, &SeqDigSignal_Seq2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SeqDigSignal_Seq0)
	RKH_TRREG(evIn0, NULL, Seq0ToSeq1Ext3, &SeqDigSignal_Seq1),
	RKH_TRREG(evIn1, NULL, NULL, &SeqDigSignal_Failure),
	RKH_TRREG(evIn2, NULL, NULL, &SeqDigSignal_Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SeqDigSignal_Seq1)
	RKH_TRREG(evIn2, NULL, NULL, &SeqDigSignal_Seq2),
	RKH_TRREG(evIn0, NULL, NULL, &SeqDigSignal_Failure),
	RKH_TRREG(evIn1, NULL, NULL, &SeqDigSignal_Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SeqDigSignal_Seq2)
	RKH_TRREG(evIn0, NULL, NULL, &SeqDigSignal_Seq3),
	RKH_TRREG(evIn1, NULL, NULL, &SeqDigSignal_Failure),
	RKH_TRREG(evIn2, NULL, NULL, &SeqDigSignal_Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SeqDigSignal_Seq3)
	RKH_TRREG(evIn0, NULL, NULL, &SeqDigSignal_Seq4),
	RKH_TRREG(evIn1, NULL, NULL, &SeqDigSignal_Failure),
	RKH_TRREG(evIn2, NULL, NULL, &SeqDigSignal_Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SeqDigSignal_Seq4)
	RKH_TRREG(evIn0, NULL, NULL, &SeqDigSignal_Seq5),
	RKH_TRREG(evIn1, NULL, NULL, &SeqDigSignal_Failure),
	RKH_TRREG(evIn2, NULL, NULL, &SeqDigSignal_Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SeqDigSignal_Seq5)
	RKH_TRREG(evIn1, NULL, NULL, &SeqDigSignal_Seq0),
	RKH_TRREG(evIn0, NULL, NULL, &SeqDigSignal_Failure),
	RKH_TRREG(evIn2, NULL, NULL, &SeqDigSignal_Failure),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(SeqDigSignal_Failure)
	RKH_TRCOMPLETION(NULL, NULL, &SeqDigSignal_Idle),
RKH_END_TRANS_TABLE



/* ............................. Active object ............................. */
struct SeqDigSignal
{
    RKH_SMA_T sma;      /* base structure */
};

RKH_SMA_CREATE(SeqDigSignal, seqDigSignal, 0, HCAL, &SeqDigSignal_Idle, ToIdleExt0, NULL);
RKH_SMA_DEF_PTR(seqDigSignal);

/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
static void 
ToIdleExt0(SeqDigSignal *const me, RKH_EVT_T *pe)
{
		
	RKH_TR_FWK_AO(me);
	RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
	RKH_TR_FWK_STATE(me, &SeqDigSignal_Idle);
	RKH_TR_FWK_STATE(me, &SeqDigSignal_Seq0);
	RKH_TR_FWK_STATE(me, &SeqDigSignal_Seq1);
	RKH_TR_FWK_STATE(me, &SeqDigSignal_Seq2);
	RKH_TR_FWK_STATE(me, &SeqDigSignal_Seq3);
	RKH_TR_FWK_STATE(me, &SeqDigSignal_Seq4);
	RKH_TR_FWK_STATE(me, &SeqDigSignal_Seq5);
	RKH_TR_FWK_STATE(me, &SeqDigSignal_Failure);
	RKH_TR_FWK_SIG(evIn0);
	RKH_TR_FWK_SIG(evIn1);
	RKH_TR_FWK_SIG(evIn2);
	#if 0
		RKH_TR_FWK_OBJ_NAME(ToIdleExt0, "ToIdleExt0");
		RKH_TR_FWK_OBJ_NAME(IdleToSeq0Ext1, "IdleToSeq0Ext1");
		RKH_TR_FWK_OBJ_NAME(Seq0ToSeq1Ext3, "Seq0ToSeq1Ext3");
	#endif
	
	Init();
}

static void 
IdleToSeq0Ext1(SeqDigSignal *const me, RKH_EVT_T *pe)
{
	GetVIMeasures();
}

static void 
Seq0ToSeq1Ext3(SeqDigSignal *const me, RKH_EVT_T *pe)
{
	GetVIMeasures();
	CalcVIAverages();
}

/* ............................. Entry actions ............................. */
/* ............................. Exit actions .............................. */
/* ................................ Guards ................................. */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
