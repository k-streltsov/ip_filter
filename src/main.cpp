#include "input_reader.h"
#include <algorithm>
#include <iterator>

void filter(int byte, const std::vector<Ipv4>& pool, std::ostream& os)
{
    std::copy_if(
        pool.cbegin(),
        pool.cend(),
        std::ostream_iterator<Ipv4>(os, "\n"),
        [byte](const Ipv4& ip)
        {
            return ip.get_byte(Ipv4::Byte_number::first) == 1;
        }
    );
}

void filter(int bt1, int bt2, const std::vector<Ipv4>& pool, std::ostream& os)
{
    std::copy_if(
        pool.cbegin(),
        pool.cend(),
        std::ostream_iterator<Ipv4>(os, "\n"),
        [bt1, bt2](const Ipv4& ip)
        {
            return ip.get_byte(Ipv4::Byte_number::first) == bt1
                && ip.get_byte(Ipv4::Byte_number::second) == bt2;
        }
    );
}

void filter_any(int byte, const std::vector<Ipv4>& pool, std::ostream& os)
{
    std::copy_if(
        pool.cbegin(),
        pool.cend(),
        std::ostream_iterator<Ipv4>(os, "\n"),
        [byte](const Ipv4& ip)
        {
            return ip.contains(byte);
        }
    );
}

int main()
{
    std::vector<Ipv4> ip_pool = Input_reader{}.read_ip_list(std::cin);
    std::sort(
        ip_pool.begin(),
        ip_pool.end(),
        [](const auto& ip1, const auto& ip2)
        {
            return ip1 > ip2;
        }
    );

    for (const auto& ip : ip_pool)
        std::cout << ip << std::endl;

    filter(1, ip_pool, std::cout);
    filter(46, 70, ip_pool, std::cout);
    filter_any(46, ip_pool, std::cout);
}