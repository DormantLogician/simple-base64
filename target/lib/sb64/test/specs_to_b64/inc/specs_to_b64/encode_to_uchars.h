#ifndef SPECS_TO_B64_F_ENCODE_TO_UCHARS_H
#define SPECS_TO_B64_F_ENCODE_TO_UCHARS_H

#include <vector>

namespace specs_to_b64
{
    std::vector<unsigned char> encode_to_uchars(const std::vector<unsigned char>& input);
};

#endif
