/**
 *  \file       SigMon.h
 *  \brief      Active object's action specifications.
 */

/* -------------------------- Development history -------------------------- */
/*
 */

/* -------------------------------- Authors -------------------------------- */
/*
 *
 */

/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __SIGMONACT_H__
#define __SIGMONACT_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkh.h"
#include "SigMon.h"

/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
/* ------------------------------- Data types ------------------------------ */
/* -------------------------- External variables --------------------------- */
/* -------------------------- Function prototypes -------------------------- */
/* ........................ Declares effect actions ........................ */
void SigMon_SigMon_ActiveToNULLExt3(SigMon *const me, RKH_EVT_T *pe);
void SigMon_SigMon_Seq2ToSigMon_Seq3Ext8(SigMon *const me, RKH_EVT_T *pe);
void SigMon_SigMon_ActiveToSigMon_ActiveLoc2(SigMon *const me, RKH_EVT_T *pe);
void SigMon_SigMon_Seq0ToSigMon_Seq0Loc4(SigMon *const me, RKH_EVT_T *pe);
void SigMon_SigMon_Seq2ToSigMon_Seq2Loc5(SigMon *const me, RKH_EVT_T *pe);
void SigMon_SigMon_Seq1ToSigMon_Seq1Loc6(SigMon *const me, RKH_EVT_T *pe);
void SigMon_SigMon_Seq10ToSigMon_Seq10Loc7(SigMon *const me, RKH_EVT_T *pe);
void SigMon_SigMon_Seq8ToSigMon_Seq8Loc8(SigMon *const me, RKH_EVT_T *pe);
void SigMon_SigMon_Seq9ToSigMon_Seq9Loc9(SigMon *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */
void SigMon_enSigMon_Active(SigMon *const me);
void SigMon_enSigMon_Seq0(SigMon *const me);

/* ......................... Declares exit actions ......................... */
void SigMon_exSigMon_Active(SigMon *const me);

/* ............................ Declares guards ............................ */

/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
