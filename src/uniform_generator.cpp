#include "include/uniform_generator.h"

void UniformGenerator::Generate() {

    for (int idx = 0; idx < m_size; ++idx) {
        m_r0 = (m_a * m_r0) % m_m;
        m_random_numbers.push_back(float((m_r0)) / m_m);
    }

    std::sort(m_random_numbers.begin(), m_random_numbers.end());
}

float UniformGenerator::GetMean() const {

    return 1;
}
float UniformGenerator::GetVariance() const {

    return 1;
}
float UniformGenerator::GetStandardDeviation() const {

    return 1;
}
float UniformGenerator::GetMinNumber() const {

    return m_random_numbers.front();
}
float UniformGenerator::GetMaxNumber() const {

    return m_random_numbers.back();
}
float UniformGenerator::GetIntervalRange(int interval_count) {

    return (float(GetMaxNumber() - GetMinNumber())) / interval_count;

}
int UniformGenerator::GetFreaquency(float min_boarder, float max_boarder) {

    auto min_interval_it = std::lower_bound(m_random_numbers.begin(), m_random_numbers.end(), min_boarder);
    auto max_interval_it = std::upper_bound(m_random_numbers.begin(), m_random_numbers.end(), max_boarder);
    return max_interval_it - min_interval_it;
}
size_t UniformGenerator::GetSize() const {
    return m_random_numbers.size();
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
