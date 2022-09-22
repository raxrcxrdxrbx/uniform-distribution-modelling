#pragma once

#include <algorithm>
#include <cmath>
#include <numeric>
#include <utility>
#include <vector>

class LehmersGenerator {
public:
    static constexpr float GENERATOR_FAIL = -1.0f;
    enum Estimations {
        MEAN = 0,
        VARIANCE,
        STANDARD_DEVIATION
    };

    static void Generate();

    static void SetParams(int a, int m, int r0);
    static void SetSize(size_t size);

    static float GetMinNumber();
    static float GetMaxNumber();
    static size_t GetSize();

    static float GetIntervalRange(int interval_count = 5);
    static std::vector<int> GetFrequencies(int interval_count = 5);

    static std::vector<std::pair<float,float>> GetPairs();
    static std::vector<float> GetConsistentEstimations();
    static std::vector<float> GetExpressEstimations();
    static int GetPeriodLength();
    static int GetAperiodicitySegment();

private:
    static uint64_t m_a;
    static uint64_t m_m;
    static uint64_t m_r0;
    static size_t m_size;
    static std::vector<float> m_random_numbers;
    static std::vector<float> m_additional_random_data;
};
