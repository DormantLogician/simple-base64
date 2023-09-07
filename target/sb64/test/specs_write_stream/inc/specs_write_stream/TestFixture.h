#ifndef SPECS_WRITE_STREAM_CL_TEST_FIXTURE_H
#define SPECS_WRITE_STREAM_CL_TEST_FIXTURE_H

#include <functional>
#include <vector>

namespace specs_write_stream
{
    class TestFixture
    {
        public:
            std::vector<long long> output;
            std::function<bool(const std::vector<long long>& word)> writer;

            TestFixture();
    };
};

#endif
