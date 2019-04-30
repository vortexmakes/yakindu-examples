/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __SIGNALMONITOR1_H__
#define __SIGNALMONITOR1_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"

/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
/* ........................ Declares active object ......................... */
RKH_SMA_DCLR(signalMonitor1);

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE Idle, Success, Failure;

/* ------------------------------- Data types ------------------------------ */
/* ............................. Active object ............................. */
typedef struct SignalMonitor1 SignalMonitor1;
struct SignalMonitor1
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
