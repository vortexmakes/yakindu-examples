/**
 *  \file       Example2.h
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
#ifndef __EXAMPLE2ACT_H__
#define __EXAMPLE2ACT_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkh.h"
#include "Example2.h"

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
void Example2_initial(Example2 *const me);
void Example2_ToStateAExt0(Example2 *const me, RKH_EVT_T *pe);
void Example2_StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe);
void Example2_CompStateToStateCExt5(Example2 *const me, RKH_EVT_T *pe);
void Example2_StateAToStateALoc2(Example2 *const me, RKH_EVT_T *pe);
/* ......................... Declares entry actions ........................ */
void Example2_enStateA(Example2 *const me);
void Example2_enStateC(Example2 *const me);
void Example2_enCompState(Example2 *const me);
/* ......................... Declares exit actions ......................... */
void Example2_exStateA(Example2 *const me);
void Example2_exCompState(Example2 *const me);
/* ............................ Declares guards ............................ */
rbool_t Example2_isCondStateCToCompState4(Example2 *const me, RKH_EVT_T *pe);
/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
