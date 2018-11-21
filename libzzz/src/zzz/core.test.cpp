/*
 */

#include <test/catch.hpp>

#include <zzz/core.hpp>

TEST_CASE("Core basic constructor", "[core]")
{
  zzz::core core(123, "My text");

  REQUIRE( core.get_number() == 123 );
  REQUIRE( core.get_incremented_number() == 124 );
  REQUIRE( core.get_text() == "My text" );
}
