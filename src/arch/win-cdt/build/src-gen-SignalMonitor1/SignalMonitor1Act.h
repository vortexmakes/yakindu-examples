/**
 *  \file       SignalMonitor1.h
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
#ifndef __SIGNALMONITOR1ACT_H__
#define __SIGNALMONITOR1ACT_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkh.h"
#include "SignalMonitor1.h"

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
void SignalMonitor1_ToIdleExt0(SignalMonitor1 *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */
void SignalMonitor1_enFailure(SignalMonitor1 *const me);

/* ......................... Declares exit actions ......................... */

/* ............................ Declares guards ............................ */

/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
