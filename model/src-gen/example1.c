/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"
#include "signal.h"
#include "example1.h»"
#include "example1Act.h"

/* ----------------------------- Local macros ------------------------------ */
/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(S1, example1_enS1, example1_exS1, RKH_ROOT, NULL);
RKH_CREATE_TRANS_TABLE(S1)
    RKH_TRREG(evA, NULL, example1_effect1, &S2),
RKH_END_TRANS_TABLE

RKH_CREATE_COMP_REGION_STATE(S2, example1_enS2, example1_exS2, RKH_ROOT, &S21, 
                             example1_initS2,
                             RKH_NO_HISTORY, NULL, NULL, NULL, NULL);
RKH_CREATE_TRANS_TABLE(S2)
    RKH_TRREG(evB, NULL, NULL, &S1),
RKH_END_TRANS_TABLE

RKH_CREATE_BASIC_STATE(S21, example1_enS21, NULL, &S2, NULL);
RKH_CREATE_TRANS_TABLE(S21)
    RKH_TRINT(evB, NULL, example1_effect3),
    RKH_TRREG(evA, example1_isCond, example1_effect2, &S22),
RKH_END_TRANS_TABLE

RKH_CREATE_BASIC_STATE(S22, NULL, example1_exS22, &S2, NULL);
RKH_CREATE_TRANS_TABLE(S22)
    RKH_TRREG(evA, NULL, NULL, &S21),
RKH_END_TRANS_TABLE

/* ............................. Active object ............................. */
RKH_SMA_CREATE(Example1, example1, 0, HCAL, &S1, example1_init, NULL);
RKH_SMA_DEF_PTR(example1);

/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
