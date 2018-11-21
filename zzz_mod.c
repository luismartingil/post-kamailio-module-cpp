/*
 * zzz_mod.c
 *
 *
 */
/*!
 * \file
 * \brief Module interface
 * \ingroup zzz
 * Module: \ref zzz
 */

/**
 * @defgroup zzz zzz :: Kamailio zzz module
 * @brief Kamailio zzz module
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Importing zzz library */
#include "zzz/core-c.hpp"

#include "../../core/mod_fix.h"
#include "../../core/lvalue.h"
#include "../../core/dprint.h"
#include "../../core/mem/mem.h"

MODULE_VERSION

/* module params */
static unsigned int number = 99;
static char* text = "This is a default param text";

void *core = NULL;

/* Module management function prototypes */
static int  mod_init(void);
static void destroy(void);

static int fixup_get_params(void** param, int param_no);
static int fixup_get_params_free(void** param, int param_no);
static int get_incremented_number_mod_f (struct sip_msg *msg,
					 char* result);

/* Exported functions */
static cmd_export_t cmds[] = {
  {"get_incremented_number_mod",   (cmd_function)get_incremented_number_mod_f,   1,
   fixup_get_params, fixup_get_params_free, ANY_ROUTE},
  {0, 0, 0, 0, 0}
};

/* Exported parameters */
static param_export_t params[] = {
  {"number", PARAM_INT, &number},
  {"text", PARAM_STRING, &text},
  {0, 0, 0}
};

/* Module interface */
struct module_exports exports = {
  "zzz",
  DEFAULT_DLFLAGS, /* dlopen flags */
  cmds,      /* Exported functions */
  params,    /* Exported parameters */
  0,         /* exported statistics */
  0,         /* exported MI functions */
  0,         /* exported pseudo-variables */
  0,         /* extra processes */
  mod_init,  /* module initialization function */
  0,         /* response function*/
  destroy,   /* destroy function */
  0          /* per-child init function */
};

/* Module initialization function - The main initialization function will be called
   before any other function exported by the module. The function will be called only once,
   before the main process forks. This function is good for initialization that is common
   for all the children (processes). The function should return 0 if everything went OK
   and a negative error code otherwise. Server will abort if the function returns a negative value.
*/
static int mod_init(void)
{
  void *core = get_core(number, text);
  return 0;
}

static void destroy(void)
{
  destroy_core(core);
  return;
}

static int fixup_get_params(void** param, int param_no)
{
  if (param_no == 1) {
    return fixup_pvar_null(param, 1);
  }
  LM_ERR("invalid parameter number <%d>\n", param_no);
  return -1;
}

static int fixup_get_params_free(void** param, int param_no)
{
  if (param_no == 1) {
    return fixup_free_pvar_null(param, 1);
  }
  LM_ERR("invalid parameter number <%d>\n", param_no);
  return -1;
}

// **********************************************************
// get_incremented_number_mod_f
// **********************************************************
static int get_incremented_number_mod_f (struct sip_msg *msg,
					 char* result) {

  pv_spec_t *dst_pv;
  pv_value_t dst_val;
  dst_pv = (pv_spec_t *)result;

  // Accessing our c-library-interface incremented function
  dst_val.ri = get_incremented_number_mod(core);
  dst_val.flags = PV_TYPE_INT|PV_VAL_INT;
  dst_pv->setf(msg, &dst_pv->pvp, (int)EQ_T, &dst_val);
  LM_INFO("Returning maintenance message value to cfg script\n");

  return 1;
}
// get_incremented_number_mod********************************
