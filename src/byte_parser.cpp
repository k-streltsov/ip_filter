#include "byte_parser.h"
#include <algorithm>

bool Byte_parser::is_positive_number(const std::string& byte_str) const
{
    return !byte_str.empty() && std::find_if(
        byte_str.cbegin(),
        byte_str.cend(),
        [](const auto c)
        {
            return !std::isdigit(c);
        }
    ) == byte_str.cend();
}

unsigned char Byte_parser::parse(const std::string& byte_str) const
{
    if (!is_positive_number(byte_str))
        throw std::exception();

    int byte = std::stoi(byte_str);
    if (byte > max_byte_value)
        throw std::exception();

    return static_cast<unsigned char>(byte);
}