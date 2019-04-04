/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __SEQDIGSIGNAL_H__
#define __SEQDIGSIGNAL_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"

/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
/* ........................ Declares active object ......................... */
RKH_SMA_DCLR(SeqDigSignal);

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE Idle, Seq0, Seq1, Seq2, Seq3, Seq4, Seq5, Failure;

/* ------------------------------- Data types ------------------------------ */
/* ............................. Active object ............................. */
typedef struct SeqDigSignal SeqDigSignal;
struct SeqDigSignal
{
    RKH_SMA_T sma;      /* base structure */
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
