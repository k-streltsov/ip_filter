#include "ip_parser.h"

Ipv4 Ip_parser::parse(const std::string& ip_str) const
{
    Ipv4::Bytes bytes;

    auto byte_len = ip_str.find_first_of(bytes_separator);
    decltype(byte_len) byte_start = 0;
    validate_byte_len(byte_len);
    bytes.at(0) = byte_parser.parse(ip_str.substr(byte_start, byte_len));

    for (auto idx = 1; idx < bytes.size(); ++idx) {
        byte_start += (byte_len + 1);
        if (idx == bytes.size() - 1)
            bytes.at(idx) = byte_parser.parse(ip_str.substr(byte_start));
        else {
            byte_len = ip_str.substr(byte_start).find_first_of(bytes_separator);
            validate_byte_len(byte_len);
            bytes.at(idx) = byte_parser.parse(ip_str.substr(byte_start, byte_len));
        }
    }

    return Ipv4{ bytes };
}

void Ip_parser::validate_byte_len(const std::size_t len) const
{
    if (len == std::string::npos)
        throw std::exception();
}