#include "input_reader.h"
#include <gtest/gtest.h>

class InputReaderTest : public ::testing::Test {
protected:
    const Input_reader reader{};
    const std::string extra_line{ "\ttext2\ttext3" };

    const std::string first_line{ "255.101.15.5" + extra_line + '\n' };
    const Ipv4 ip{ {255, 101, 15, 5} };

    const std::string second_line{ "24.55.101.32" + extra_line + '\n' };
    const Ipv4 ip1{ {24, 55, 101, 32} };

    const std::string third_line{ "2.54.111.2" + extra_line + '\n' };
    const Ipv4 ip2{ {2, 54, 111, 2} };
};

TEST_F(
    InputReaderTest,
    ReadIpListThrowsIfInputLineDoesNotContainFieldSeparator
)
{
    std::istringstream is("str\n");
    ASSERT_ANY_THROW(reader.read_ip_list(is));
}

TEST_F(InputReaderTest, WorksWithSingleInputLine) {
    std::istringstream is(first_line);
    ASSERT_EQ(std::vector<Ipv4>{ip}, reader.read_ip_list(is));
}

TEST_F(InputReaderTest, WorksWithMultipleInputLines) {
    std::istringstream is(first_line + second_line + third_line);
    std::vector<Ipv4> expected{ ip, ip1, ip2 };
    ASSERT_EQ(expected, reader.read_ip_list(is));
}