#pragma once
#include "singleton.hpp"

#include <cstdint>
#include <string>
#include <string_view>

namespace uuif {

    class c_hash : public c_singleton<c_hash>
    {
        static constexpr uint32_t m_base = 0x811C9DC5;
        static constexpr uint32_t m_prime = 0x1000193;

    public:
        uint32_t compile_time(const char* data, const uint32_t value = m_base) const
        {
            return (data[0] == '\0') ? value : compile_time(&data[1], (value ^ uint32_t(data[0])) * m_prime);
        }

        uint32_t run_time(std::string& data) const
        {
            int32_t hashed = m_base;
            for (const char& character : data)
            {
                hashed ^= character;
                hashed *= m_prime;
            }

            return hashed;
        }

        constexpr uint32_t const_compile_time(const char* data, const uint32_t value = m_base)
            {
                return (data[0] == '\0') ? value : const_compile_time(&data[1], (value ^ uint32_t(data[0])) * m_prime);
            }
        };

    inline const auto g_hash = c_hash::get();
}
