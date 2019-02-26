/**
 *  \file       example1Act.c
 *  \brief      Active object's action implementations.
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
/* ----------------------------- Include files ----------------------------- */
#include "rkhsma.h"
#include "signal.h"
#include "example1.h"
#include "example1Act.h"
#include "bsp.h"

/* ----------------------------- Local macros ------------------------------ */
#define LED_OFF_TIME            RKH_TIME_SEC(2)
#define LED_ON_TIME             RKH_TIME_SEC(2)

/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ............................ Effect actions ............................. */
void
example1_init(Example1 *const me)
{
    RKH_TR_FWK_AO(me);
    RKH_TR_FWK_QUEUE(&RKH_UPCAST(RKH_SMA_T, me)->equeue);
    RKH_TR_FWK_STATE(me, &S1);
    RKH_TR_FWK_STATE(me, &S2);
    RKH_TR_FWK_STATE(me, &S21);
    RKH_TR_FWK_STATE(me, &S22);
    RKH_TR_FWK_SIG(evA);
    RKH_TR_FWK_SIG(evB);
#if 1
    RKH_TR_FWK_OBJ_NAME(example1_init, "init");
    RKH_TR_FWK_OBJ_NAME(example1_initS2, "initS2");
    RKH_TR_FWK_OBJ_NAME(example1_effect1, "effect1");
    RKH_TR_FWK_OBJ_NAME(example1_effect2, "effect2");
    RKH_TR_FWK_OBJ_NAME(example1_effect3, "effect3");
    RKH_TR_FWK_OBJ_NAME(example1_enS1, "enS1");
    RKH_TR_FWK_OBJ_NAME(example1_enS2, "enS2");
    RKH_TR_FWK_OBJ_NAME(example1_enS21, "enS21");
    RKH_TR_FWK_OBJ_NAME(example1_exS1, "exS1");
    RKH_TR_FWK_OBJ_NAME(example1_exS2, "exS2");
    RKH_TR_FWK_OBJ_NAME(example1_exS22, "exS22");
    RKH_TR_FWK_OBJ_NAME(example1_isCond, "isCond");
#endif
}

void 
example1_initS2(Example1 *const me, RKH_EVT_T *pe)
{
    (void)me;
    (void)pe;
}

void
example1_effect1(Example1 *const me, RKH_EVT_T *pe)
{
    (void)pe;
    ++me->cnt;
}

void
example1_effect2(Example1 *const me, RKH_EVT_T *pe)
{
    (void)me;
    (void)pe;
}

void
example1_effect3(Example1 *const me, RKH_EVT_T *pe)
{
    (void)me;
    (void)pe;
}

/* ............................. Entry actions ............................. */
void 
example1_enS1(Example1 *const me)
{
}

void 
example1_enS2(Example1 *const me)
{
}

void 
example1_enS21(Example1 *const me)
{
}

/* ............................. Exit actions .............................. */
void 
example1_exS1(Example1 *const me)
{
}

void 
example1_exS2(Example1 *const me)
{
}

void 
example1_exS22(Example1 *const me)
{
}

/* ................................ Guards ................................. */
rbool_t 
example1_isCond(Example1 *const me, RKH_EVT_T *pe)
{
    return RKH_TRUE;
}

/* ---------------------------- Global functions --------------------------- */
/* ------------------------------ End of file ------------------------------ */
