/*
 */

#include <zzz/core.hpp>

int main(int, char const**)
{

  std::cout << "==> C++ based example:" << std::endl;
  std::cout << "Creating object!" << std::endl;
  zzz::core my_core(22, "This is a text");

  std::cout << "Getting number: " << my_core.get_number() << std::endl;
  std::cout << "Getting incremented number: " << my_core.get_incremented_number() << std::endl;
  std::cout << "Getting text: " << my_core.get_text() << std::endl;

  std::cout << "Destroying!" << std::endl;
  return 0;

}
