#include <vector>
#include <cstdint>
#include <string>
#include <cstring>
#include <stdexcept>
#include <array>

#include "base85ed.h"

static const char* ALPHABET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~";

std::vector<uint8_t> base85::encode(std::vector<uint8_t> const &bytes)
{
    std::vector<uint8_t> result;
    result.reserve((bytes.size() * 5 + 3) / 4);

    for (size_t i = 0; i < bytes.size(); )
    {
        uint32_t val = 0;
        int chunk_size = 0;

        for (int j = 0; j < 4; ++j)
        {
            val <<= 8;
            if (i < bytes.size())
            {
                val |= bytes[i++];
                chunk_size++;
            }
        }

        std::array<uint8_t, 5> encoded;
        uint32_t temp = val;
        for (int j = 4; j >= 0; --j)
        {
            encoded[j] = static_cast<uint8_t>(ALPHABET[temp % 85]);
            temp /= 85;
        }

        for (int j = 0; j < chunk_size + 1; ++j)
        {
            result.push_back(encoded[j]);
        }
    }
    return result;
}

std::vector<uint8_t> base85::decode(std::vector<uint8_t> const &b85str)
{
    std::vector<uint8_t> result;
    result.reserve((b85str.size() * 4) / 5);

    for (size_t i = 0; i < b85str.size(); )
    {
        uint64_t val = 0;
        int chunk_size = 0;

        for (int j = 0; j < 5; ++j)
        {
            val *= 85;
            if (i < b85str.size())
            {
                const char* ptr = std::strchr(ALPHABET, b85str[i++]);
                if (!ptr)
                {
                    throw std::runtime_error("Invalid Base85 character");
                }

                val += static_cast<uint32_t>(ptr - ALPHABET);
                chunk_size++;
            }
            else
            {
                val += 84;
            }
        }

        if (chunk_size == 0) break;
        if (chunk_size == 1) throw std::runtime_error("Invalid Base85 length");

        if (val > 0xFFFFFFFFU)
        {
            throw std::runtime_error("Base85 value overflow");
        }

        uint32_t v32 = static_cast<uint32_t>(val);
        for (int j = 0; j < chunk_size - 1; ++j)
        {
            result.push_back(static_cast<uint8_t>((v32 >> (8 * (3 - j))) & 0xFF));
        }
    }
    return result;
}