#ifndef SB64_F_ITERABLE_READER_H
#define SB64_F_ITERABLE_READER_H

#include <optional>

namespace sb64::detail::utility
{
    /*
     * Returns function that yields values from beginning to end of the
     * applicable iterable one by one, after which it begins returning an
     * empty value.
     * 
     * @param iter Start iterator.
     * @param end Stop iterator.
     */
    template<typename Value, typename Iterator, typename EndIterator>
    auto iterable_reader(Iterator iter,
                         EndIterator end)
    {
        return [iter, end]() mutable -> std::optional<Value>
        {
            if (iter != end)
            {
                const auto output{iter};
                ++iter;
                return *output;
            }
            else
            {
                return std::nullopt;
            };
        };
    };
};

#endif
