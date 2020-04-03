#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "ip_parser.h"
#include <vector>
#include <iostream>

class Input_reader {
public:
    std::vector<Ipv4> read_ip_list(std::istream&) const;
private:
    std::string retain_first_field(const std::string&) const;
    static const char field_separator{ '\t' };
    const std::string err_message{ "Wrong input" };
    const Ip_parser ip_parser{};
};

#endif