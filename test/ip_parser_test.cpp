#include "ip_parser.h"
#include <gtest/gtest.h>

class IpParserTest : public ::testing::Test {
protected:
    const Ip_parser parser{};
    const std::string ip_str{ "251.62.13.4" };
};

TEST_F(IpParserTest, CorrectParseFirstByte) {
    ASSERT_EQ(251, parser.parse(ip_str).get_byte(Ipv4::Byte_number::first));
}

TEST_F(IpParserTest, CorrectParseSecondByte) {
    ASSERT_EQ(62, parser.parse(ip_str).get_byte(Ipv4::Byte_number::second));
}

TEST_F(IpParserTest, CorrectParseThirdByte) {
    ASSERT_EQ(13, parser.parse(ip_str).get_byte(Ipv4::Byte_number::third));
}

TEST_F(IpParserTest, CorrectParseFourthByte) {
    ASSERT_EQ(4, parser.parse(ip_str).get_byte(Ipv4::Byte_number::fourth));
}

TEST_F(IpParserTest, ParseThrowsIfStringContainsMoreThanFourBytes) {
    ASSERT_ANY_THROW(parser.parse("1.2.3.4.5"));
}

TEST_F(IpParserTest, ParseThrowsIfStringContainsLessThanFourBytes) {
    EXPECT_ANY_THROW(parser.parse("1"));
    EXPECT_ANY_THROW(parser.parse("1.2"));
    EXPECT_ANY_THROW(parser.parse("1.2.3"));
}