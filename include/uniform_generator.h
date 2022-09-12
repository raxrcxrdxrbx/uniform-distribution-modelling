
#include <algorithm>
#include <vector>

class UniformGenerator {
public:
    UniformGenerator() = default;

    void Generate();

    float GetMean() const;
    float GetVariance() const;
    float GetStandardDeviation() const;

    float GetMinNumber() const;
    float GetMaxNumber() const;
    size_t GetSize() const;

    float GetIntervalRange(int interval_count = 5);
    int GetFreaquency(float min_boarder, float max_boarder);

    void SetParams(int a, int m, int r0);
    void SetSize(size_t size);

private:
    int m_a = 3;
    int m_m = 5;
    int m_r0 = 1;
    size_t m_size;
    std::vector<float> m_random_numbers;
};
