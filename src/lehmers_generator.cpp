#include "lehmers_generator.h"

    uint64_t LehmersGenerator::m_a = 0;
    uint64_t LehmersGenerator::m_m = 1;
    uint64_t LehmersGenerator::m_r0 = 0;
    size_t LehmersGenerator::m_size = 0;
    std::vector<float> LehmersGenerator::m_random_numbers;
    std::vector<float> LehmersGenerator::m_additional_random_data;

void LehmersGenerator::Generate() {

    m_random_numbers.clear();
    uint64_t a = m_a;
    uint64_t m = m_m;
    uint64_t r0 = m_r0;
    float tmp = 0.0f;

    for (int idx = 0; idx < m_size; ++idx) {
        r0 = (a * r0) % m;
        tmp = float(r0) / m;
        m_random_numbers.push_back(tmp);
    } 
}

void LehmersGenerator::SetParams(uint64_t a, uint64_t m, uint64_t r0) {

    m_a = a;
    m_m = m;
    m_r0 = r0;
}
void LehmersGenerator::SetSize(size_t size) {

    m_size = size;
    m_random_numbers.reserve(size);
}

float LehmersGenerator::GetMinNumber() {

    auto element_it = std::min_element(m_random_numbers.begin(), m_random_numbers.end());
    if (element_it != m_random_numbers.end()) {

        return *element_it;
    }
    else {

        return GENERATOR_FAIL;
    }

}
float LehmersGenerator::GetMaxNumber() {

    auto element_it = std::max_element(m_random_numbers.begin(), m_random_numbers.end());
    if (element_it != m_random_numbers.end()) {

        return *element_it;
    }
    else {

        return GENERATOR_FAIL;
    }
}
size_t LehmersGenerator::GetSize()  {

    return m_random_numbers.size();
}

float LehmersGenerator::GetIntervalRange(int interval_count) {

    auto min_number = GetMinNumber();
    auto max_number = GetMaxNumber();
    if (max_number != GENERATOR_FAIL && min_number != GENERATOR_FAIL) {

        return (max_number - min_number) / interval_count;
    }
    else {
        return GENERATOR_FAIL;
    }

}
std::vector<int> LehmersGenerator::GetFrequencies(int interval_count) {

    std::vector<int> frequencies(interval_count);

    float min_number = GetMinNumber();
    float frequency_step = GetIntervalRange(interval_count);
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

std::vector<std::pair<float,float>> LehmersGenerator::GetPairs() {

    int unique_numbers_count = GetAperiodicitySegment();
    if (unique_numbers_count > 10000) {

        unique_numbers_count = 10000;
    }
    else {

        if (unique_numbers_count % 2 != 0) {

            --unique_numbers_count;
        }
    }

    std::vector<std::pair<float,float>> pairs;
    for (int idx = 0; idx < unique_numbers_count - 1; idx += 2) {

        pairs.push_back(std::make_pair(m_random_numbers[idx], m_random_numbers[idx + 1]));
    }

    return pairs;
}

std::vector<float> LehmersGenerator::GetConsistentEstimations() {

    std::vector<float> consistent_estimations(3);
    consistent_estimations[Estimations::MEAN] = std::accumulate(m_random_numbers.begin(), m_random_numbers.end(), 0.0) / m_random_numbers.size();

    for (int idx = 0; idx < m_random_numbers.size(); ++idx) {

        consistent_estimations[Estimations::VARIANCE] += (m_random_numbers[idx] - consistent_estimations[Estimations::MEAN]) *
                (m_random_numbers[idx] - consistent_estimations[Estimations::MEAN]);
    }
    consistent_estimations[Estimations::VARIANCE] /= (m_random_numbers.size() - 1);

    consistent_estimations[Estimations::STANDARD_DEVIATION]= std::sqrt(consistent_estimations[Estimations::VARIANCE]);

    return consistent_estimations;
}
std::vector<float> LehmersGenerator::GetExpressEstimations() {

    std::vector<float> express_estimations(3);

    express_estimations[Estimations::VARIANCE] = m_random_numbers[0] * m_random_numbers[0];
    for (int idx = 0; idx < m_random_numbers.size() - 1; ++idx) {

        express_estimations[Estimations::MEAN] =
                (express_estimations[Estimations::MEAN] * idx + m_random_numbers[idx]) / (idx + 1);

        express_estimations[Estimations::VARIANCE] =
                express_estimations[Estimations::VARIANCE] * idx / (idx + 1) +
                (m_random_numbers[idx + 1] - express_estimations[Estimations::MEAN]) *
                (m_random_numbers[idx + 1] - express_estimations[Estimations::MEAN]) / (idx + 2);
    }
    express_estimations[Estimations::MEAN] =
            (express_estimations[Estimations::MEAN] * (m_random_numbers.size() - 1) +
            m_random_numbers[m_random_numbers.size() - 1]) / m_random_numbers.size();

    express_estimations[Estimations::STANDARD_DEVIATION] = std::sqrt(express_estimations[Estimations::VARIANCE]);

    return express_estimations;
}
int LehmersGenerator::GetPeriodLength() {

    std::pair<int, int> period_idx;

    int idx = 0;
    uint64_t r0 = m_r0;
    bool is_first_overlap = false;
    bool is_second_overlap = false;


    auto last_genereted =  m_random_numbers[m_random_numbers.size() - 1];
    while (!is_first_overlap || !is_second_overlap) {

        r0 = m_a * r0 % m_m;
        float rand = float(r0) / m_m;
        m_additional_random_data.push_back(rand);
        if(m_additional_random_data[idx] == last_genereted) {

            if (!is_first_overlap) {

                period_idx.first = idx;
                is_first_overlap = true;
            }
            else {

                period_idx.second = idx;
                is_second_overlap = true;
            }
        }
        ++idx;
    }

    return period_idx.second - period_idx.first;
}
int LehmersGenerator::GetAperiodicitySegment() {

    int period_lenght = GetPeriodLength();
    if (period_lenght >= m_random_numbers.size()) {

        return m_random_numbers.size();
    }
    else {
        for (int idx = 0; idx < m_random_numbers.size() - period_lenght; ++idx) {

            if (m_random_numbers[idx] == m_random_numbers[idx + period_lenght])  {
                return period_lenght + idx;
            }
        }
    }
    return 0;
}
