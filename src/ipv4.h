#ifndef IPV4_H
#define IPV4_H

#include <array>
#include <string>

class Ipv4 {
public:
    static const int bytes_number = 4;
    using Byte = unsigned char;
    using Bytes = std::array<Byte, bytes_number>;
    enum Byte_number { first, second, third, fourth };

    Ipv4(const std::array<Byte, bytes_number>&) noexcept;
    bool operator==(const Ipv4&) const noexcept;
    bool operator>(const Ipv4&) const noexcept;
    Byte get_byte(const Byte_number) const noexcept;
    bool contains(Byte byte) const noexcept;
    std::string to_str() const noexcept;
private:
    Bytes bytes_;
};

std::ostream& operator<<(std::ostream&, const Ipv4&) noexcept;

#endif