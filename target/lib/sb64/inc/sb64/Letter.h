#ifndef SB64_CL_LETTER_H
#define SB64_CL_LETTER_H

#include <vector>

namespace sb64
{
    /*
     * Primary class that enables bit manipulation for usage with base 64
     * encoders/decoders.
     */
    class Letter final
    {
        private:
            std::vector<bool> stored;

            /*
             * Removes least significate bits so that they are excluded until
             * there is number of bits less than or equal to Letter max size.
             * 
             * @param input Bits to truncate.
             */
            static std::vector<bool> truncate_bits(const std::vector<bool>& input);

            /*
             * Reads list of Letters by the specified number of bits at a time
             * (as if the list of Letters is a stream of bits) and outputs a new
             * list of Letters.
             * 
             * @param bit_groups The list of Letters to read.
             * @param group_max_size Number of bits to read by.
             */
            static std::vector<Letter> by_bits(const std::vector<Letter>& bit_groups,
                                               const long long group_max_size);


            /*
             * Converts a list of Letters into a list of bits representing all
             * bits in list of Letters from left to right.
             * 
             * @param input Letters to concatenate.
             */
            static std::vector<bool> concat_bits(const std::vector<Letter>& input);

        public:
            static const unsigned char max_size;

            /*
             * Converts list of Letters to list of unsigned characters.
             * 
             * @param input List of Letters to convert.
             */
            static std::vector<unsigned char> as_uchars(const std::vector<Letter>& input);

            /*
             * Read specified list of Letters eight bits at a time, producing a
             * new list of Letters with the output.
             * 
             * @param bit_groups The list of Letters to read.
             */
            static std::vector<Letter> by_eight_bits(const std::vector<Letter>& bit_groups);

            /*
             * Read specified list of Letters six bits at a time, producing a
             * new list of Letters with the output.
             * 
             * @param bit_groups The list of Letters to read.
             */
            static std::vector<Letter> by_six_bits(const std::vector<Letter>& bit_groups);

            /*
             * Convert from unsigned character to Letter.
             * 
             * @param init_stored Value to store in Letter.
             */
            Letter(const unsigned char init_stored);

            /*
             * Convert from list of bool to Letter.
             * 
             * @param init_stored Value to store in Letter.
             */
            explicit Letter(const std::vector<bool>& init_stored);

            /*
             * Access bits in Letter.
             */
            const std::vector<bool>& bits() const;

            /*
             * Get Letter as unsigned character.
             */
            unsigned char to_uchar() const;
    };
};

#endif
