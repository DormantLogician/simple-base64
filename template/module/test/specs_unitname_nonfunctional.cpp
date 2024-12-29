#include <benchmark/benchmark.h>

namespace specs_unitname
{
    static void bench_case(benchmark::State& state)
    {
        for (auto _ [[maybe_unused]] : state)
        {
            // Place code to analyze here.
        };
    };
};

BENCHMARK(specs_unitname::bench_case)->Repetitions(5)->Complexity(benchmark::o1);


