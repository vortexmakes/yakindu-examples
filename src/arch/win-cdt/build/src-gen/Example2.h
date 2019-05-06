/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __EXAMPLE2_H__
#define __EXAMPLE2_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"

/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
/* ........................ Declares active object ......................... */
RKH_SMA_DCLR(example2);

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE StateA, StateB, StateC, StateD, StateE, StateG, CompState21;
RKH_DCLR_COMP_STATE CompState, StateF, CompState2;
RKH_DCLR_CHOICE_STATE C0, C1;
RKH_DCLR_SHIST_STATE H1, H2;

/* ------------------------------- Data types ------------------------------ */
/* ............................. Active object ............................. */
typedef struct Example2 Example2;
struct Example2
{
    RKH_SMA_T sma;      /* base structure */
    rInt intVar;
    rbool_t boolVar;
    rInt uninitializedIntVar;
    rbool_t uninitializedBoolVar;
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
