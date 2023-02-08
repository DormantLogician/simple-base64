% TO_B64(3)
% Stephen Aaron Hannon
% February 2023

# NAME
to_b64 - API function

# LIBRARY
Simple Base 64 library (libsb64, -lsb64).

# SYNOPSIS
void to_b64(

    const std::function<std::optional<unsigned char>()>& reader,

    const std::function<void(const std::vector<unsigned char>& output_word)>& writer
);

# ARGUMENTS
const std::function<std::optional<unsigned char>()>& reader

    When executed, yields a character from a user-specified location.

const std::function<void(const std::vector<unsigned char>& output_word)>& writer

    When executed, access to the current encoded base 64 word is granted.

# DESCRIPTION
Encodes data from some user-specified source to a destination.