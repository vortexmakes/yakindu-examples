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
void Example2_ToStateAExt0(Example2 *const me, RKH_EVT_T *pe);
void Example2_StateBToStateCExt3(Example2 *const me, RKH_EVT_T *pe);
void Example2_StateCToExample2_C1Ext8(Example2 *const me, RKH_EVT_T *pe);
void Example2_StateCToH1Ext9(Example2 *const me, RKH_EVT_T *pe);
void Example2_CompStateToStateCExt10(Example2 *const me, RKH_EVT_T *pe);
void Example2_StateEToCompState_FinalExt15(Example2 *const me, RKH_EVT_T *pe);
void Example2_ToStateGExt17(Example2 *const me, RKH_EVT_T *pe);
void Example2_H2ToStateGExt18(Example2 *const me, RKH_EVT_T *pe);
void Example2_ToStateF11Ext19(Example2 *const me, RKH_EVT_T *pe);
void Example2_Example2_C0ToExample2_C1Ext22(Example2 *const me, RKH_EVT_T *pe);
void Example2_Example2_C1ToCompStateExt23(Example2 *const me, RKH_EVT_T *pe);
void Example2_Example2_C1ToStateAExt24(Example2 *const me, RKH_EVT_T *pe);
void Example2_StateAToStateALoc2(Example2 *const me, RKH_EVT_T *pe);
void Example2_CompState21ToCompState21Loc6(Example2 *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */
void Example2_enStateA(Example2 *const me);
void Example2_enStateB(Example2 *const me);
void Example2_enStateC(Example2 *const me);
void Example2_enCompState(Example2 *const me);
void Example2_enCompState21(Example2 *const me);

/* ......................... Declares exit actions ......................... */
void Example2_exStateA(Example2 *const me);
void Example2_exStateB(Example2 *const me);
void Example2_exCompState(Example2 *const me);
void Example2_exCompState21(Example2 *const me);

/* ............................ Declares guards ............................ */
rbool_t Example2_isCondStateCToCompState7(Example2 *const me, RKH_EVT_T *pe);
rbool_t Example2_isCondExample2_C0ToStateC21(Example2 *const me, RKH_EVT_T *pe);
rbool_t Example2_isCondExample2_C0ToExample2_C122(Example2 *const me, RKH_EVT_T *pe);
rbool_t Example2_isCondExample2_C1ToCompState23(Example2 *const me, RKH_EVT_T *pe);

/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
