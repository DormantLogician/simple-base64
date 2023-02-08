#include <functional>
#include <vector>

#include "specs_write_stream/TestFixture.h"

namespace specs_write_stream
{
    TestFixture::TestFixture()
        : output{},
          writer{[this](const std::vector<long long>& word) -> bool
            {
                for (auto iter{word.cbegin()}; iter < word.cend(); ++iter)
                {
                    output.push_back(*iter + 1);
                };

                return true;
            }
        }
    {};
};
