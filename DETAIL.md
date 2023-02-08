# SB64 details for developers

## Outline
### Problem domain research
- Encoder must not use line feed characters in encoded data.
- Decoder must reject encoded data that contains characters not in alphabet being used (possibly also '=' characters not at end of encoded data).
- For encoding, three 8-bit characters are reinterpreted as four 6-bit characters that are each then used as an index to access a corrosponding character (not '=') in the alphabet being used.
- Standard base 64 alphabet contains letters A-Z, a-z, 0-9, +, /, and (for padding) =.
- For encoding, padding may be added to encoded data via '=' character if less than 24 bits available at input data end.
- Able to ignore extra padding characters if found.
- Both encoder and decoder output nothing if given no characters.

### What users can do with software
Allows users to encode data and decode base 64 encoded data that uses padding and the regular base 64 alphabet, and supports checking if data is valid base 64 - it supports reading from and writing data to arbitrary locations for ease of integration with other projects.

### Safety considerations
- Data loss - when data is encoded and then decoded, the decoded data must be equal to the original input to the encoder.
- Encoder output validity - output of base 64 encoder must always be valid base 64 encoded data (with padding and regular alphabet).