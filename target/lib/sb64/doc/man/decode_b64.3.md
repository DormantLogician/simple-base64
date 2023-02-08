% DECODE_B64(3)
% Stephen Aaron Hannon
% February 2023

# NAME
decode_b64 - API function

# LIBRARY
Simple Base 64 library (libsb64, -lsb64).

# SYNOPSIS
void decode_b64(

    const std::function<std::optional<unsigned char>()>& reader,

    const std::function<void(const std::vector<unsigned char>& output_text)>& writer

);

# ARGUMENTS
const std::function<std::optional<unsigned char>()>& reader

    When executed, yields a character from a user-specified location.

const std::function<void(const std::vector<unsigned char>& output_text)>& writer

    When executed, access to the current decoded base 64 word is granted.

# DESCRIPTION
Decodes base 64 encoded data from some user-specified source to a destination.

# ERRORS
If data given by 'reader' is not valid base 64 encoded data, an instance of
'std::invalid_argument' is thrown.