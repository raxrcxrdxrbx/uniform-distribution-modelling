#include "include/uniform_generator.h"

    int UniformGenerator::m_a = 0;
    int UniformGenerator::m_m = 0;
    int UniformGenerator::m_r0 = 0;
    size_t UniformGenerator::m_size = 0;
    std::vector<float> UniformGenerator::m_random_numbers;

void UniformGenerator::Generate() {

    for (int idx = 0; idx < m_size; ++idx) {
        m_r0 = (m_a * m_r0) % m_m;
        m_random_numbers.push_back(float((m_r0)) / m_m);
    } 
}

void UniformGenerator::SetParams(int a, int m, int r0) {

    m_a = a;
    m_m = m;
    m_r0 = r0;
}
void UniformGenerator::SetSize(size_t size) {

    m_size = size;
    m_random_numbers.reserve(size);
}

float UniformGenerator::GetMinNumber() {

    auto element_it = std::min_element(m_random_numbers.begin(), m_random_numbers.end());
    if (element_it != m_random_numbers.end()) {

        return *element_it;
    }
    else {

        return GENERATOR_FAIL;
    }

}
float UniformGenerator::GetMaxNumber() {

    auto element_it = std::max_element(m_random_numbers.begin(), m_random_numbers.end());
    if (element_it != m_random_numbers.end()) {

        return *element_it;
    }
    else {

        return GENERATOR_FAIL;
    }
}
size_t UniformGenerator::GetSize()  {

    return m_random_numbers.size();
}

float UniformGenerator::GetIntervalRange(int interval_count) {

    auto min_number = GetMinNumber();
    auto max_number = GetMaxNumber();
    if (max_number != GENERATOR_FAIL && min_number != GENERATOR_FAIL) {

        return (max_number - min_number) / interval_count;
    }
    else {
        return GENERATOR_FAIL;
    }

}
std::vector<int> UniformGenerator::GetFrequencies(int interval_count) {

    std::vector<int> frequencies(interval_count);

    float min_number = GetMinNumber();
    float frequency_step = GetIntervalRange();
    for (const auto& number : m_random_numbers) {

        int interval_number = std::trunc((number - min_number) / frequency_step);
        if (interval_number != frequencies.size()) {

            ++frequencies[interval_number];
        }
        else {
            ++frequencies[frequencies.size() - 1];
        }
    }

    return frequencies;
}

float UniformGenerator::GetMean() {

    return 1;
}
float UniformGenerator::GetVariance() {

    return 1;
}
float UniformGenerator::GetStandardDeviation() {

    return 1;
}

