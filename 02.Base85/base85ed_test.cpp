#include <gtest/gtest.h>

#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <string.h>

#include "base85ed.h"

const std::vector<std::pair<const char *, const char * >> short_cases =
{
    { "",     ""     },
    { "F#",   "1"    },
    { "F){",  "12"   },
    { "F)}j", "123"  },
    { "F)}kW","1234" }
};

static std::vector<uint8_t> cstr2v(const char *s)
{
    return std::vector<uint8_t>(
               s,
               s + std::string(s).size()
           );
}

// Тесты encode
TEST(Base85ShortsEncode, TrivialShortEncodes)
{
    for (const auto &p : short_cases)
    {
        EXPECT_EQ(base85::encode(cstr2v(p.second)), cstr2v(p.first));
    }
}

// Тесты decode
TEST(Base85ShortsDecode, TrivialShortDecodes)
{
    for (const auto &p : short_cases)
    {
        EXPECT_EQ(base85::decode(cstr2v(p.first)), cstr2v(p.second));
    }
}

TEST(Base85Diversity, BinaryData)
{
    std::vector<uint8_t> zeros = {0, 0, 0, 0};
    EXPECT_EQ(base85::encode(zeros), cstr2v("00000"));
    EXPECT_EQ(base85::decode(cstr2v("00000")), zeros);

    std::vector<uint8_t> max_bytes = {0xFF, 0xFF, 0xFF, 0xFF};
    std::vector<uint8_t> expected_max_b85 = {'|', 'N', 's', 'C', '0'};

    EXPECT_EQ(base85::encode(max_bytes), expected_max_b85);
    EXPECT_EQ(base85::decode(expected_max_b85), max_bytes);
}

TEST(Base85Diversity, ErrorHandling)
{
    EXPECT_THROW(base85::decode(cstr2v("F #")), std::runtime_error);

    EXPECT_THROW(base85::decode(cstr2v("F")), std::runtime_error);

    EXPECT_THROW(base85::decode(cstr2v("~~~~~")), std::runtime_error);
}

TEST(Base85Diversity, EmptyInput)
{
    EXPECT_TRUE(base85::encode({}).empty());
    EXPECT_TRUE(base85::decode({}).empty());
}