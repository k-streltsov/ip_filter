#include "input_reader.h"

std::vector<Ipv4> Input_reader::read_ip_list(std::istream& is) const
{
    std::vector<Ipv4> ip_vec;
    for (std::string line; std::getline(is, line);) {
        try {
            ip_vec.push_back(ip_parser.parse(retain_first_field(line)));
        }
        catch (const std::exception&) {
            throw std::invalid_argument(err_message);
        }
    }

    return ip_vec;
}

std::string Input_reader::retain_first_field(const std::string& line) const
{
    auto idx = line.find_first_of(field_separator);
    if (idx == std::string::npos)
        throw std::exception();

    return line.substr(0, idx);
}