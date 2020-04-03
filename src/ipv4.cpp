#include "ipv4.h"
#include <algorithm>

Ipv4::Ipv4(const std::array<Byte, bytes_number>& bytes) noexcept
    : bytes_(bytes)
{}

bool Ipv4::operator==(const Ipv4& rhs) const noexcept
{
    return bytes_ == rhs.bytes_;
}

bool Ipv4::operator>(const Ipv4& rhs) const noexcept
{
    return bytes_ > rhs.bytes_;
}

Ipv4::Byte Ipv4::get_byte(Byte_number bn) const noexcept
{
    return bytes_.at(bn);
}

bool Ipv4::contains(Byte byte) const noexcept
{
    return std::find(bytes_.cbegin(), bytes_.cend(), byte) != bytes_.cend();
}

std::string Ipv4::to_str() const noexcept
{
    return std::to_string(bytes_.at(first))
        + "." + std::to_string(bytes_.at(second))
        + "." + std::to_string(bytes_.at(third))
        + "." + std::to_string(bytes_.at(fourth));
}

std::ostream& operator<<(std::ostream& os, const Ipv4& ip) noexcept
{
    os << ip.to_str();
    return os;
}