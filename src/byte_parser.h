#ifndef BYTE_PARSER_H
#define BYTE_PARSER_H

#include <string>

class Byte_parser {
public:
    unsigned char parse(const std::string&) const;
private:
    bool is_positive_number(const std::string&) const;
    static const int max_byte_value{ 255 };
};

#endif