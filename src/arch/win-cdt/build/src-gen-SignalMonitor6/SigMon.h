/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __SIGMON_H__
#define __SIGMON_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"

/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
/* ........................ Declares active object ......................... */
RKH_SMA_DCLR(sigMon);

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE SigMon_Inactive, SigMon_WaitSyncSeq, SigMon_Seq0, SigMon_Seq2, SigMon_Seq3, SigMon_Seq4, SigMon_Seq5, SigMon_Seq11, SigMon_OutOfSeq, SigMon_Seq1, SigMon_Seq10, SigMon_Seq8, SigMon_Seq7, SigMon_Seq6, SigMon_Seq9;
RKH_DCLR_COMP_STATE SigMon_Active;

/* ------------------------------- Data types ------------------------------ */
/* ............................. Active object ............................. */
typedef struct SigMon SigMon;
struct SigMon
{
    RKH_SMA_T sma;      /* base structure */
    rInt digIn;
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
