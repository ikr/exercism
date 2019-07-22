#include "prime_factors.h"
#include "test/catch.hpp"

TEST_CASE("_1_yields_empty")
{
    const std::vector<int> expected{};

    const std::vector<int> actual{prime_factors::of(1)};

    REQUIRE(expected == actual);
}

TEST_CASE("_2_yields_2")
{
    const std::vector<int> expected{2};

    const std::vector<int> actual{prime_factors::of(2)};

    REQUIRE(expected == actual);
}

TEST_CASE("_3_yields_3")
{
    const std::vector<int> expected{3};

    const std::vector<int> actual{prime_factors::of(3)};

    REQUIRE(expected == actual);
}

TEST_CASE("_4_yields_2_2")
{
    const std::vector<int> expected{2, 2};

    const std::vector<int> actual{prime_factors::of(4)};

    REQUIRE(expected == actual);
}

TEST_CASE("_6_yields_2_3")
{
    const std::vector<int> expected{2, 3};

    const std::vector<int> actual{prime_factors::of(6)};

    REQUIRE(expected == actual);
}

TEST_CASE("_8_yields_2_2_2")
{
    const std::vector<int> expected{2, 2, 2};

    const std::vector<int> actual{prime_factors::of(8)};

    REQUIRE(expected == actual);
}

TEST_CASE("_9_yields_3_3")
{
    const std::vector<int> expected{3, 3};

    const std::vector<int> actual{prime_factors::of(9)};

    REQUIRE(expected == actual);
}

TEST_CASE("_27_yields_3_3_3")
{
    const std::vector<int> expected{3, 3, 3};

    const std::vector<int> actual{prime_factors::of(27)};

    REQUIRE(expected == actual);
}

TEST_CASE("_625_yields_5_5_5_5")
{
    const std::vector<int> expected{5, 5, 5, 5};

    const std::vector<int> actual{prime_factors::of(625)};

    REQUIRE(expected == actual);
}

TEST_CASE("_901255_yields_5_17_23_461")
{
    const std::vector<int> expected{5, 17, 23, 461};

    const std::vector<int> actual{prime_factors::of(901255)};

    REQUIRE(expected == actual);
}

TEST_CASE("_461_yields_461")
{
    const std::vector<int> expected{461};

    const std::vector<int> actual{prime_factors::of(461)};

    REQUIRE(expected == actual);
}

TEST_CASE("_23757_yields_3_7919")
{
    const std::vector<int> expected{3, 7919};

    const std::vector<int> actual{prime_factors::of(23757)};

    REQUIRE(expected == actual);
}

TEST_CASE("_30971726_yields_2_15485863")
{
    const std::vector<int> expected{2, 15485863};

    const std::vector<int> actual{prime_factors::of(30971726)};

    REQUIRE(expected == actual);
}
