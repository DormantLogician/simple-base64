#ifndef SB64_F_DECODE_B64_H
#define SB64_F_DECODE_B64_H

#include <vector>
#include <optional>
#include <functional>

namespace sb64
{
    /*
     * Decodes base 64 encoded data (with padding, and using regular alphabet).
     *
     * @param reader Yields characters from some arbitrary location until they
     * are depleted.
     * @param writer Writes decoded data words at a time to some arbitrary
     * location.
     */
    void decode_b64(const std::function<std::optional<unsigned char>()>& reader,
                    const std::function<void(const std::vector<unsigned char>& output_text)>& writer);
};

#endif
