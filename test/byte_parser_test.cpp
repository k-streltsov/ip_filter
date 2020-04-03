#include "byte_parser.h"
#include <gtest/gtest.h>

class ByteParserTest : public ::testing::Test {
protected:
    const Byte_parser parser{};
};

TEST_F(ByteParserTest, ParseThrowsIfByteStringContainsNonDigitSymbols) {
    EXPECT_ANY_THROW(parser.parse("1.2"));
    EXPECT_ANY_THROW(parser.parse("3,4"));
    EXPECT_ANY_THROW(parser.parse("5!6"));
    EXPECT_ANY_THROW(parser.parse("abcd"));
}

TEST_F(ByteParserTest, ParseThrowsIfByteIsLessThenZero) {
    ASSERT_ANY_THROW(parser.parse("-1"));
}

TEST_F(ByteParserTest, ParseThrowsIfByteIsGreaterThen255) {
    ASSERT_ANY_THROW(parser.parse("256"));
}

TEST_F(ByteParserTest, ParseWorks) {
    ASSERT_EQ(255, parser.parse("255"));
}