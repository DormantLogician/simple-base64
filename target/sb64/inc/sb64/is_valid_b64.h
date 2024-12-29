#ifndef SB64_F_IS_VALID_B64_H
#define SB64_F_IS_VALID_B64_H

#include <functional>
#include <optional>

#include "sb64_export.h"

namespace sb64
{
    /*
     * Validates base 64 encoded data (with padding, and using regular alphabet).
     *
     * @param reader Yields characters from some arbitrary location until they
     * are depleted.
     */
    sb64_EXPORT bool is_valid_b64(const std::function<std::optional<unsigned char>()>& reader);
};

#endif
