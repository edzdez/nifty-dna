#include <catch2/catch.hpp>

#include "utils.hpp"

TEST_CASE("findMaxConsecutiveRepeats", "[match]")
{
    REQUIRE(findMaxConsecutiveRepeats("ATGCATGCATGC", "ATGC") == 3);
    REQUIRE(findMaxConsecutiveRepeats("ATATATATATAT", "ATAT") == 3);
    REQUIRE(findMaxConsecutiveRepeats("AAAAAAAAAAAAAAAAAAAAAAAA", "AAAA") == 6);
}
