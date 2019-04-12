/**
 *  \file       SeqDigSignal.h
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
#ifndef __SEQDIGSIGNALACT_H__
#define __SEQDIGSIGNALACT_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkh.h"
#include "SeqDigSignal.h"

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
void SeqDigSignal_ToIdleExt0(SeqDigSignal *const me, RKH_EVT_T *pe);
void SeqDigSignal_IdleToSeq0Ext1(SeqDigSignal *const me, RKH_EVT_T *pe);
void SeqDigSignal_Seq0ToSeq1Ext3(SeqDigSignal *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */

/* ......................... Declares exit actions ......................... */

/* ............................ Declares guards ............................ */

/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
