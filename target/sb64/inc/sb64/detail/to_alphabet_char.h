#ifndef SB64_F_TO_ALPHABET_CHAR_H
#define SB64_F_TO_ALPHABET_CHAR_H

#include <optional>

namespace sb64::detail 
{
    /*
     * Maps an input character to a character in the regular base 64 alphabet.
     * Output will be empty if index is not in range of alphabet.
     * 
     * @param index Character to map to alphabet.
     */
    std::optional<unsigned char> to_alphabet_char(const long long index);
};

#endif
