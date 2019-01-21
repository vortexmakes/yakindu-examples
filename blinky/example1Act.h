/**
 *  \file       example1Act.h
 *  \brief      Active object's action specifications.
 */

/* -------------------------- Development history -------------------------- */
/*
 *  2019.21.01  LeFr  v1.0.00  Initial version
 */

/* -------------------------------- Authors -------------------------------- */
/*
 *  LeFr  Leandro Francucci  francuccilea@gmail.com
 */

/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __EXAMPLE1ACT_H__
#define __EXAMPLE1ACT_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkh.h"
#include "example1.h"

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
void example1_init(Example1 *const me);
void example1_initS2(Example1 *const me, RKH_EVT_T *pe);
void example1_effect1(Example1 *const me, RKH_EVT_T *pe);
void example1_effect2(Example1 *const me, RKH_EVT_T *pe);
void example1_effect3(Example1 *const me, RKH_EVT_T *pe);

/* ......................... Declares entry actions ........................ */
void example1_enS1(Example1 *const me);
void example1_enS2(Example1 *const me);
void example1_enS21(Example1 *const me);

/* ......................... Declares exit actions ......................... */
void example1_exS1(Example1 *const me);
void example1_exS2(Example1 *const me);
void example1_exS22(Example1 *const me);

/* ............................ Declares guards ............................ */
rbool_t example1_isCond(Example1 *const me, RKH_EVT_T *pe);

/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
