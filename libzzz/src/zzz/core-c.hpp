/*
 */

#ifndef ZZZ_CORE_C_HPP
#define ZZZ_CORE_C_HPP

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  void* get_core(unsigned int number, char* text);
  unsigned int get_number(void* core);
  unsigned int get_incremented_number(void* core);
  void get_text(void* core, char* text);
  void destroy_core(void *core);

#ifdef __cplusplus
}
#endif

#endif
/* ZZZ_CORE_C_HPP */
