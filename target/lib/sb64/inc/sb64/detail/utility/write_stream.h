#ifndef SB64_F_MAKE_WORD_READER_H
#define SB64_F_MAKE_WORD_READER_H

#include <vector>
#include <functional>
#include <optional>
#include <stdexcept>

namespace sb64::detail::utility
{
    /*
     * Reads a stream of input from a reader function by word size at a time.
     * 
     * @param word_size Number of items to read before giving word to on_input
     * function.
     * @param reader Function that reads next character from stream when
     * executed.
     * @param on_input Gives access to a completed word, or the remaining items
     * in stream if less than word size - returns whether to continue reading
     * from stream.
     */
    template<typename Input, typename Output>
    void write_stream(const long long word_size,
                      const std::function<std::optional<Input>()>& reader,
                      const std::function<bool(const std::vector<Output>& output_word)>& on_input)
    {
        std::vector<Output> items{};
        if (word_size <= 0)
        {
            throw std::invalid_argument{"Word size must be greater than zero."};
        };

        std::optional<Input> current{reader()};
        while (current.has_value())
        {
            items.push_back(*current);
            if (items.size() >= word_size)
            {
                const bool should_continue{on_input(items)};
                if (!should_continue)
                {
                    return void();
                };

                items.clear();
            };

            current = reader();
        };

        if (!items.empty())
        {
            on_input(items);
        };
    };
};

#endif
