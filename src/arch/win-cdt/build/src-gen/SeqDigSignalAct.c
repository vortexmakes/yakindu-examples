/**
 *  \file       SeqDigSignal.c
 *  \brief      Active object's action implementations.
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
#include "signal.h"
#include "SeqDigSignal.h"
#include "SeqDigSignalAct.h"
#include "bsp.h"
#include "SeqDigSignalActRequired.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
void 
SeqDigSignal_ToIdleExt0(SeqDigSignal *const me, RKH_EVT_T *pe)
{
		
	RKH_TR_FWK_AO(me);
	RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
	RKH_TR_FWK_STATE(me, &Idle);
	RKH_TR_FWK_STATE(me, &Seq0);
	RKH_TR_FWK_STATE(me, &Seq1);
	RKH_TR_FWK_STATE(me, &Seq2);
	RKH_TR_FWK_STATE(me, &Seq3);
	RKH_TR_FWK_STATE(me, &Seq4);
	RKH_TR_FWK_STATE(me, &Seq5);
	RKH_TR_FWK_STATE(me, &Failure);
	RKH_TR_FWK_SIG(evIn0);
	RKH_TR_FWK_SIG(evIn1);
	RKH_TR_FWK_SIG(evIn2);
	#if 1
		RKH_TR_FWK_OBJ_NAME(SeqDigSignal_ToIdleExt0, "ToIdleExt0");
		RKH_TR_FWK_OBJ_NAME(SeqDigSignal_IdleToSeq0Ext1, "IdleToSeq0Ext1");
		RKH_TR_FWK_OBJ_NAME(SeqDigSignal_Seq0ToSeq1Ext3, "Seq0ToSeq1Ext3");
	#endif
	
	Init();
}

void 
SeqDigSignal_IdleToSeq0Ext1(SeqDigSignal *const me, RKH_EVT_T *pe)
{
	GetVIMeasures();
}

void 
SeqDigSignal_Seq0ToSeq1Ext3(SeqDigSignal *const me, RKH_EVT_T *pe)
{
	GetVIMeasures();
	CalcVIAverages();
}

/* ............................. Entry actions ............................. */
/* ............................. Exit actions .............................. */
/* ................................ Guards ................................. */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
