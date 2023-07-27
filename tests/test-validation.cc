#include <catch2/catch.hpp>

#include <format>

#include "utils.hpp"

TEST_CASE("validateTag", "[validation]")
{
    REQUIRE(validateTag('A') == true);
    REQUIRE(validateTag('T') == true);
    REQUIRE(validateTag('C') == true);
    REQUIRE(validateTag('G') == true);

    REQUIRE(validateTag('a') == false);
    REQUIRE(validateTag('5') == false);
    REQUIRE(validateTag('n') == false);
    REQUIRE(validateTag('F') == false);
    REQUIRE(validateTag('"') == false);
    REQUIRE(validateTag('\\') == false);
    REQUIRE(validateTag(')') == false);
    REQUIRE(validateTag('~') == false);
}

TEST_CASE("validateStr", "[validation]")
{
    char validTags[] = {'A', 'T', 'C', 'G'};
    for (char c1 : validTags)
        for (char c2 : validTags)
            for (char c3 : validTags)
                for (char c4 : validTags)
                    REQUIRE(validateStr(std::format("{}{}{}{}", c1, c2, c3, c4)) == true);

    REQUIRE(validateStr("") == false);
    REQUIRE(validateStr("AAAAA") == false);
    REQUIRE(validateStr("ATCAGT") == false);
    REQUIRE(validateStr("adshakjdhkjsa") == false);
    REQUIRE(validateStr("aaaa") == false);
    REQUIRE(validateStr("atcg") == false);
    REQUIRE(validateStr(" a a") == false);
    REQUIRE(validateStr(" t c a g") == false);
}

TEST_CASE("validateSequence", "[validation]")
{
    REQUIRE(validateSequence("") == true);
    REQUIRE(validateSequence("A") == true);
    REQUIRE(validateSequence("TG") == true);
    REQUIRE(validateSequence("AAA") == true);
    REQUIRE(validateSequence("ATCG") == true);
    REQUIRE(validateSequence("AAAAA") == true);
    REQUIRE(validateSequence("ATCAGT") == true);
    REQUIRE(validateSequence("ATAGCCCATTAGCCCAGATAGATAGATG") == true);
    REQUIRE(validateSequence("AGTAGCCCTCTCCCTCCCTCAGAGAG") == true);
    REQUIRE(validateSequence("adshakjdhkjsa") == false);
    REQUIRE(validateSequence("aaaa") == false);
    REQUIRE(validateSequence("atcg") == false);
    REQUIRE(validateSequence(" a a") == false);
    REQUIRE(validateSequence(" t c a g") == false);
}
