#ifndef SB64_TO_B64_H
#define SB64_TO_B64_H

#include <vector>
#include <optional>
#include <functional>

#include "sb64_export.h"

namespace sb64
{
    /*
     * Encodes data into base 64 (with padding, and using regular alphabet).
     *
     * @param reader Yields characters from some arbitrary location until they
     * are depleted.
     * @param writer Writes encoded data words at a time to some arbitrary
     * location.
     */
      sb64_EXPORT void to_b64(const std::function<std::optional<unsigned char>()>& reader,
                              const std::function<void(const std::vector<unsigned char>& output_word)>& writer);
};

#endif
