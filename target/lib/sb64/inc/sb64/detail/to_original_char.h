#ifndef SB64_F_TO_ORIGINAL_CHAR_H
#define SB64_F_TO_ORIGINAL_CHAR_H

#include <optional>

namespace sb64::detail
{
    /*
     * Returns index of input character in base 64 alphabet.
     * Output will be empty if no existing alphabet character is equal to input
     * character.
     * 
     * @param character Character we must find index of in alphabet.
     */
    std::optional<unsigned char> to_original_char(const unsigned long long character);
};

#endif
