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
RKH_CREATE_BASIC_STATE(StateA, Example2_enStateA, Example2_exStateA, RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(StateB, NULL, NULL, RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(StateC, Example2_enStateC, NULL, RKH_ROOT, NULL);

RKH_CREATE_BASIC_STATE(StateD, NULL, NULL, &CompState, NULL);

RKH_CREATE_BASIC_STATE(StateE, NULL, NULL, &CompState, NULL);

RKH_CREATE_BASIC_STATE(StateG, NULL, NULL, &StateF, NULL);

RKH_CREATE_HISTORY_STORAGE(CompState);
RKH_CREATE_COMP_REGION_STATE(CompState, Example2_enCompState, Example2_exCompState, RKH_ROOT, &StateD, NULL, RKH_SHISTORY, NULL, NULL, NULL, RKH_GET_HISTORY_STORAGE(CompState));

RKH_CREATE_HISTORY_STORAGE(StateF);
RKH_CREATE_COMP_REGION_STATE(StateF, NULL, NULL, &CompState, &StateG, NULL, RKH_SHISTORY, NULL, Example2_H2ToStateGExt15, &StateG, RKH_GET_HISTORY_STORAGE(StateF));

RKH_CREATE_TRANS_TABLE(StateA)
RKH_TRREG(evB, NULL, NULL, &StateB),
RKH_TRCOMPLETION(NULL, NULL, &StateB),
RKH_TRINT(evA, NULL, Example2_StateAToStateALoc2),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateB)
RKH_TRREG(evA, NULL, Example2_StateBToStateCExt3, &StateC),
RKH_TRREG(evB, NULL, Example2_StateBToStateCExt3, &StateC),
RKH_TRREG(evA, NULL, NULL, &C0),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateC)
RKH_TRREG(evA, Example2_isCondStateCToCompState5, NULL, &CompState),
RKH_TRREG(evB, NULL, Example2_StateCToC1Ext6, &C1),
RKH_TRREG(evC, NULL, Example2_StateCToH1Ext7, &H1),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(CompState)
RKH_TRREG(evB, NULL, Example2_CompStateToStateCExt8, &StateC),
RKH_TRREG(evC, NULL, NULL, &NULL),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateD)
RKH_TRREG(evA, NULL, NULL, &StateE),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateE)
RKH_TRREG(evC, NULL, NULL, &H2),
RKH_TRREG(evA, NULL, Example2_StateEToNULLExt13, &NULL),
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateF)
RKH_END_TRANS_TABLE

RKH_CREATE_TRANS_TABLE(StateG)
RKH_END_TRANS_TABLE

RKH_CREATE_CHOICE_STATE(C0);

RKH_CREATE_CHOICE_STATE(C1);

RKH_CREATE_BRANCH_TABLE(C0)
RKH_BRANCH(Example2_isCondC0ToStateC17, NULL, &StateC),
RKH_BRANCH(Example2_isCondC0ToC118, Example2_C0ToC1Ext18, &C1),
RKH_BRANCH(ELSE, NULL, &StateC),
RKH_END_BRANCH_TABLE

RKH_CREATE_BRANCH_TABLE(C1)
RKH_BRANCH(Example2_isCondC1ToCompState19, Example2_C1ToCompStateExt19, &CompState),
RKH_BRANCH(ELSE, Example2_C1ToStateAExt20, &StateA),
RKH_END_BRANCH_TABLE

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
