#ifndef IP_PARSER_H
#define IP_PARSER_H

#include "ipv4.h"
#include "byte_parser.h"

class Ip_parser {
public:
    Ipv4 parse(const std::string&) const;
private:
    void validate_byte_len(const std::size_t len) const;
    static const char bytes_separator{ '.' };
    const Byte_parser byte_parser{};
};

#endif