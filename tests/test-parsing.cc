#include <catch2/catch.hpp>

#include "utils.hpp"

TEST_CASE("parseSchema", "[parsing]")
{
    REQUIRE_THROWS(parseSchema(""));
    REQUIRE_THROWS(parseSchema("name"));
    REQUIRE_THROWS(parseSchema("name, aatg"));
    REQUIRE_THROWS(parseSchema("name, AATG"));
    REQUIRE_THROWS(parseSchema("name, absdas"));

    REQUIRE_THROWS(parseSchema("name,asdjjd"));
    REQUIRE_THROWS(parseSchema("name,aatcg"));
    REQUIRE_THROWS(parseSchema("name,AATCG"));

    REQUIRE_THROWS(parseSchema("name,AATG,"));

    std::vector<std::string> expected = {"AGAT", "AATG", "TATC"};
    REQUIRE(parseSchema("name,AGAT,AATG,TATC") == expected);
}

TEST_CASE("parsePerson", "[parsing]")
{
    REQUIRE_THROWS(parsePerson("Alice,"));
    REQUIRE_THROWS(parsePerson("Alice,asd"));
    REQUIRE_THROWS(parsePerson("Alice,12 13,14"));
    REQUIRE_THROWS(parsePerson("Alice,12,14,asd"));

    std::pair<std::string, std::vector<size_t>> expected1 = {"Alice", {5, 2, 8}};
    REQUIRE(parsePerson("Alice,5,2,8") == expected1);

    std::pair<std::string, std::vector<size_t>> expected2 = {"Bob", {3, 7, 4}};
    REQUIRE(parsePerson("Bob,3,7,4") == expected2);

    std::pair<std::string, std::vector<size_t>> expected3 = {"Charlie", {6, 1, 5}};
    REQUIRE(parsePerson("Charlie,6,1,5") == expected3);
}
