/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __CLOCKSIGNAL_H__
#define __CLOCKSIGNAL_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"

/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
/* ........................ Declares active object ......................... */
RKH_SMA_DCLR(clockSignal);

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE Idle, WaitFallEdge, WaitRisEdge;

/* ------------------------------- Data types ------------------------------ */
/* ............................. Active object ............................. */
typedef struct ClockSignal ClockSignal;
struct ClockSignal
{
    RKH_SMA_T sma;      /* base structure */
    rInt currInput;
    rInt lastInput;
};

/* -------------------------- External variables --------------------------- */
/* -------------------------- Function prototypes -------------------------- */
/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
