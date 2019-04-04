/**
 *  \file       FailSignal.h
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
#ifndef __FAILSIGNALACT_H__
#define __FAILSIGNALACT_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkh.h"
#include "FailSignal.h"

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
void FailSignal_ToIdleExt0(FailSignal *const me, RKH_EVT_T *pe);
/* ......................... Declares entry actions ........................ */
void FailSignal_enFailure(FailSignal *const me);
/* ......................... Declares exit actions ......................... */
/* ............................ Declares guards ............................ */
/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
