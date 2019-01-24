/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef EXAMPLE1
#define EXAMPLE1

/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"
#include "rkhtmr.h"

/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
/* ........................ Declares active object ......................... */
RKH_SMA_DCLR(example1);

/* ................... Declares states and pseudostates .................... */
RKH_DCLR_BASIC_STATE S1, S21, S22;
RKH_DCLR_COMP_STATE S2; 

/* ------------------------------- Data types ------------------------------ */
/* ............................. Active object ............................. */
typedef struct Example1 Example1;
struct Example1
{
    RKH_SMA_T sma;      /* base structure */
    rui8_t cnt;         /* private member */
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
