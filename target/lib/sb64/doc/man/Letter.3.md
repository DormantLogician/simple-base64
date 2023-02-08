% LETTER(3)
% Stephen Aaron Hannon
% February 2023

# NAME
Letter - API class

# LIBRARY
Simple Base 64 library (libsb64, -lsb64).

# SYNOPSIS
class Letter final
{
    public:
        static const unsigned char max_size;

        static std::vector<unsigned char> as_uchars(

            const std::vector<Letter>& input

        );

        static std::vector<Letter> by_eight_bits(

            const std::vector<Letter>& bit_groups

        );

        static std::vector<Letter> by_six_bits(

            const std::vector<Letter>& bit_groups

        );

        Letter(const unsigned char init_stored);
        explicit Letter(const std::vector<bool>& init_stored);

        const std::vector<bool>& bits() const;
        unsigned char to_uchar() const;
};

# DESCRIPTION
Carries bits in a way they can be manipulated - 'by_eight_bits' and 'by_six_bits' functions provide core functionality needed to implement a base 64 encoder/decoder.