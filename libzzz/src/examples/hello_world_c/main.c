/*
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zzz/core-c.hpp"

int main(const int argc, const char **argv)
{

  printf("==> C based example:\n");
  printf("Creating object!\n");
  void *core = get_core(22, "This is a text");

  printf("Getting number: %i\n", get_number(core));
  printf("Getting incremented number: %i\n", get_incremented_number(core));
  char text[100];
  get_text(core, text);
  printf("Getting text: %s\n", text);

  printf("Destroying!\n");
  destroy_core(core);

  return( EXIT_SUCCESS );
}
