#include <boost/test/unit_test.hpp>

#include "sb64/detail/utility/iterable_reader.h"

BOOST_AUTO_TEST_SUITE(iterable_reader);

BOOST_AUTO_TEST_CASE(Output_function_yields_correct_return_values)
{
    const std::vector<long long> input{1, 2, 3};

    auto reader{sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend())};

    BOOST_CHECK_EQUAL(reader().value(), 1);
    BOOST_CHECK_EQUAL(reader().value(), 2);
    BOOST_CHECK_EQUAL(reader().value(), 3);
    BOOST_TEST(!reader().has_value());
};

BOOST_AUTO_TEST_CASE(Output_function_yields_empty_output_when_end_equal_to_begin)
{
    const std::vector<long long> input{1, 2, 3};

    auto reader{sb64::detail::utility::iterable_reader<long long>(input.cbegin() + 1, input.cbegin() + 1)};

    BOOST_TEST(!reader().has_value());
};

BOOST_AUTO_TEST_CASE(Output_function_yields_empty_output_with_empty_list)
{
    const std::vector<long long> input{};

    auto reader{sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend())};

    BOOST_TEST(!reader().has_value());
};

BOOST_AUTO_TEST_SUITE_END();
