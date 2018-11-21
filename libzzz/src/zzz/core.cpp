/*
 */

#include <iostream>

#include <zzz/core.hpp>

namespace zzz {

  core::core(const unsigned int number,
	     const std::string text)
    : _number(number)
    , _text(text)
  {
    std::cout << "Object created!" << std::endl;
  }

  unsigned int
  core::get_number(void)
  {
    return _number;    
  }

  unsigned int
  core::get_incremented_number(void)
  {
    return _number + 1;
  }

  std::string
  core::get_text(void)
  {
    return _text;
  }

}
