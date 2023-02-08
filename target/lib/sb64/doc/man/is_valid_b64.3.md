% IS_VALID_B64(3)
% Stephen Aaron Hannon
% February 2023

# NAME
is_valid_b64 - API function

# LIBRARY
Simple Base 64 library (libsb64, -lsb64).

# SYNOPSIS
bool is_valid_b64(const std::function<std::optional<unsigned char>()>& reader);

# ARGUMENTS
const std::function<std::optional<unsigned char>()>& reader

    When executed, yields a character from a user-specified location.

# DESCRIPTION
Verifies that all words yielded by 'reader' are valid base 64 words.

# RETURNS
True if all words given by reader are valid base 64 words.