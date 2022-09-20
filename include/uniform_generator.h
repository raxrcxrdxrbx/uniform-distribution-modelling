#pragma once

#include <algorithm>
#include <vector>
#include <cmath>

class UniformGenerator {
public:
    static constexpr float GENERATOR_FAIL = -1.0f;
    static void Generate();

    static void SetParams(int a, int m, int r0);
    static void SetSize(size_t size);

    static float GetMinNumber();
    static float GetMaxNumber();
    static size_t GetSize();

    static float GetIntervalRange(int interval_count = 5);
    static std::vector<int> GetFrequencies(int interval_count = 5);

    static float GetMean();
    static float GetVariance();
    static float GetStandardDeviation();

private:
    static int m_a;
    static int m_m;
    static int m_r0;
    static size_t m_size;
    static std::vector<float> m_random_numbers;
};
