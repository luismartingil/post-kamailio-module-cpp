/*
 */

#ifndef ZZZ_CORE_C_CPP
#define ZZZ_CORE_C_CPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdint.h>

#include <zzz/core.hpp>
#include "core-c.hpp"

void*
get_core( unsigned int number, char* text )
{
  zzz::core *tmp( new zzz::core(number, text));
  return( reinterpret_cast< void* >( tmp ) );
}

unsigned int
get_number( void* core )
{
  zzz::core *tmp = reinterpret_cast< zzz::core* >( core );
  return tmp->get_number();
}

unsigned int
get_incremented_number( void* core )
{
  zzz::core *tmp = reinterpret_cast< zzz::core* >( core );
  return tmp->get_incremented_number();
}

void
get_text( void* core, char* text )
{
  zzz::core *tmp = reinterpret_cast< zzz::core* >( core );
  std::string tmp_str = tmp->get_text();
  strcpy(text, tmp_str.c_str());
}

void
destroy_core( void* core )
{
   delete( reinterpret_cast< zzz::core* >( core ) );
}

#endif // ZZZ_CORE_C_CPP
