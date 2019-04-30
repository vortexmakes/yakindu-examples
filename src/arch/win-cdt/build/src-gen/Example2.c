/**
 *  \file       example2.c
 *  \brief      Active object implementation.
 */

/* -------------------------- Development history -------------------------- */
/*
 */

/* -------------------------------- Authors -------------------------------- */
/*
 */

/* --------------------------------- Notes --------------------------------- */
/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"
#include "signal.h"
#include "Example2.h"
#include "Example2Act.h"

/* ----------------------------- Local macros ------------------------------ */
/* ........................ States and pseudostates ........................ */
RKH_CREATE_BASIC_STATE(StateA ,Example2_enStateA ,Example2_exStateA ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(StateB ,NULL ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(StateC ,Example2_enStateC ,NULL ,RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(StateD ,NULL ,NULL ,&CompState, NULL);

RKH_CREATE_BASIC_STATE(StateE ,NULL ,NULL ,&CompState, NULL);

RKH_CREATE_BASIC_STATE(StateG ,NULL ,NULL ,&StateF, NULL);

RKH_CREATE_COMP_REGION_STATE(CompState ,Example2_enCompState ,Example2_exCompState ,RKH_ROOT, &StateD, NULL, RKH_NO_HISTORY, NULL, NULL, NULL, NULL);

RKH_CREATE_COMP_REGION_STATE(StateF ,NULL ,NULL ,&CompState, &StateG, NULL, RKH_NO_HISTORY, NULL, NULL, NULL, NULL);

RKH_CREATE_TRANS_TABLE(StateA)
RKH_TRREG(evB, NULL, NULL, &StateB),
RKH_TRCOMPLETION(NULL, NULL, &StateB),
RKH_TRINT(evA, NULL, Example2_StateAToStateALoc2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateB)
RKH_TRREG(evA, NULL, Example2_StateBToStateCExt3, &StateC),
RKH_TRREG(evB, NULL, Example2_StateBToStateCExt3, &StateC),
RKH_TRREG(evA, NULL, NULL, &NULL),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateC)
RKH_TRREG(evA, Example2_isCondStateCToCompState5, NULL, &CompState),
RKH_TRREG(evB, NULL, Example2_StateCToExt6, &NULL),
RKH_TRREG(evC, NULL, Example2_StateCToH1Ext7, &NULL),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(CompState)
RKH_TRREG(evB, NULL, Example2_CompStateToStateCExt8, &StateC),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateD)
RKH_TRREG(evA, NULL, NULL, &StateE),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateE)
RKH_TRREG(evC, NULL, NULL, &NULL),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateF)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateG)
RKH_END_TRANS_TABLE

/* ............................. Active object ............................. */
RKH_SMA_CREATE(Example2, example2, 0, HCAL, &StateA, Example2_ToStateAExt0, NULL);
RKH_SMA_DEF_PTR(example2);

/* ------------------------------- Constants ------------------------------- */

/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
