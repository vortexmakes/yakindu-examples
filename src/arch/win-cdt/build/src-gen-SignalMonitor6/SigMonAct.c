/**
 *  \file       SigMon.c
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
#include "SigMon.h"
#include "SigMonAct.h"
#include "bsp.h"
#include "SigMonActRequired.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
void 
SigMon_SigMon_ActiveToNULLExt3(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

void 
SigMon_SigMon_Seq2ToSigMon_Seq3Ext8(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

void 
SigMon_SigMon_ActiveToSigMon_ActiveLoc2(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

void 
SigMon_SigMon_Seq0ToSigMon_Seq0Loc4(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

void 
SigMon_SigMon_Seq2ToSigMon_Seq2Loc5(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

void 
SigMon_SigMon_Seq1ToSigMon_Seq1Loc6(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

void 
SigMon_SigMon_Seq10ToSigMon_Seq10Loc7(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

void 
SigMon_SigMon_Seq8ToSigMon_Seq8Loc8(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

void 
SigMon_SigMon_Seq9ToSigMon_Seq9Loc9(SigMon *const me, RKH_EVT_T *pe)
{
	me->digIn = 0;
}

/* ............................. Entry actions ............................. */
void 
SigMon_enSigMon_Active(SigMon *const me)
{
	me->digIn = 0;
}

void 
SigMon_enSigMon_Seq0(SigMon *const me)
{
	me->digIn = 0;
}

/* ............................. Exit actions .............................. */
void 
SigMon_exSigMon_Active(SigMon *const me)
{
	me->digIn = 0;
}

/* ................................ Guards ................................. */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
