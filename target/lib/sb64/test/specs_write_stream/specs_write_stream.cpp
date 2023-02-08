#include <boost/test/unit_test.hpp>
#include "specs_write_stream/TestFixture.h"

#include <stdexcept>

#include "sb64/detail/utility/write_stream.h"
#include "sb64/detail/utility/iterable_reader.h"


BOOST_AUTO_TEST_SUITE(write_stream);

BOOST_FIXTURE_TEST_CASE(Writes_information_using_writer_correctly, specs_write_stream::TestFixture)
{
    const std::vector<long long> input{1, 2, 3, 4, 5};

    sb64::detail::utility::write_stream<long long, long long>(
        2, 
        sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend()),
        writer
    );

    const std::vector<long long> expected{2, 3, 4, 5, 6};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_FIXTURE_TEST_CASE(Writes_information_using_partial_reader, specs_write_stream::TestFixture)
{
    const std::vector<long long> input{1, 2, 3, 4, 5};

    sb64::detail::utility::write_stream<long long, long long>(
        1, 
        sb64::detail::utility::iterable_reader<long long>(input.cbegin() + 1, input.cbegin() + 2),
        writer
    );

    const std::vector<long long> expected{3};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Writes_information_using_partial_writer)
{
    const std::vector<long long> input{1, 2, 3, 4, 5};
    std::vector<long long> output{};

    const auto writer{[&output](const std::vector<long long>& word) -> bool
    {
        for (auto iter{word.cbegin()}; iter < word.cend(); ++iter)
        {
            if (*iter == 3)
            {
                return false;
            };

            output.push_back(*iter + 1);
        };

        return true;
    }};

    sb64::detail::utility::write_stream<long long, long long>(
        1, 
        sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend()),
        writer
    );

    const std::vector<long long> expected{2, 3};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_FIXTURE_TEST_CASE(Writes_information_using_invalid_word_size, specs_write_stream::TestFixture)
{
    const std::vector<long long> input{1, 2, 3, 4, 5};

    BOOST_CHECK_THROW(
        (sb64::detail::utility::write_stream<long long, long long>(
            0, 
            sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend()),
            writer
        )), 
        
        std::invalid_argument
    );
};

BOOST_FIXTURE_TEST_CASE(Can_write_a_single_character, specs_write_stream::TestFixture)
{
    const std::vector<long long> input{1};

    sb64::detail::utility::write_stream<long long, long long>(
        1, 
        sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend()),
        writer
    );

    const std::vector<long long> expected{2};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_FIXTURE_TEST_CASE(Writes_information_using_an_empty_stream, specs_write_stream::TestFixture)
{
    const std::vector<long long> input{};

    sb64::detail::utility::write_stream<long long, long long>(
        1, 
        sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend()),
        writer
    );

    const std::vector<long long> expected{};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_FIXTURE_TEST_CASE(Writes_information_using_large_word_size, specs_write_stream::TestFixture)
{
    const std::vector<long long> input{1, 2, 3, 4, 5};

    sb64::detail::utility::write_stream<long long, long long>(
        100, 
        sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend()),
        writer
    );

    const std::vector<long long> expected{2, 3, 4, 5, 6};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Number_of_characters_available_to_writer_usually_equal_to_word_size)
{
    const std::vector<long long> input{1, 2, 3, 4, 5};
    std::vector<std::size_t> output{};

    const auto writer{[&output](const std::vector<long long>& word) -> bool
    {
        output.push_back(word.size());
        return true;
    }};

    sb64::detail::utility::write_stream<long long, long long>(
        2, 
        sb64::detail::utility::iterable_reader<long long>(input.cbegin(), input.cend()),
        writer
    );

    const std::vector<std::size_t> expected{2, 2, 1};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
