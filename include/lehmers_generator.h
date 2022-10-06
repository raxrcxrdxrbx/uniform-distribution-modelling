#pragma once

#include <algorithm>
#include <cmath>
#include <numeric>
#include <utility>
#include <stdexcept>
#include <vector>

//! A LehmersGenerator class.
/*!
 * \brief Generates and processes random number data.
*/
class LehmersGenerator {
public:
    //! Represents failed result when generator attempts to return random number.
    /*!
     *  \sa GetMinNumber()
     *  \sa GetMaxNumber()
    */
    static constexpr float GENERATOR_FAIL = -1.0f;

    //! Readable access to estimation results stored in vector.
    enum Estimations {
        MEAN = 0,
        VARIANCE,
        STANDARD_DEVIATION
    };

    //! Implements Lehmer random number generator.
    static void Generate();

    //! Initializes the generator with parameters.
    /*!
     *  \param m modulus
     *  \param a multiplier
     *  \param r0 initial seed
    */
    static void SetParams(uint64_t a, uint64_t m, uint64_t r0);

    //! Initializes the generator with size of random number sample.
    /*!
     *  \param size size of random number sample
    */
    static void SetSize(size_t size);

    //! Looks for minimal random number.
    /*!
     *  \return minimal random number or GENERATOR_FAIL
    */
    static float GetMinNumber();

    //! Looks for maximal random number.
    /*!
     *  \return maximal random number or GENERATOR_FAIL
    */
    static float GetMaxNumber();

    //! Gets the size of generated random number sample.
    /*!
     *  \return size of random number sample
    */
    static size_t GetSize();

    //! Calculates the interval length.
    /*!
     *  \param interval_count number of intervals to be dislayed
     *  \return interval length
    */
    static float GetIntervalRange(int interval_count = 5);

    //! Calculates amount of random numbers that fall into each interval
    /*!
     *  \param interval_count number of intervals to be dislayed
     *  \return amounts of random numbers vector
     */
    static std::vector<int> GetFrequencies(int interval_count = 5);

    //! Calculates random number pairs based on the sample.
    /*!
     *  \return random number pairs
     */
    static std::vector<std::pair<float,float>> GetPairs();

    //! Calculates consistent mean, variance and standard deviation.
    /*!
     *  \return consistent estimations
     */
    static std::vector<float> GetConsistentEstimations();

    //! Calculates express mean, variance and standard deviation.
    /*!
     *  \return express estimations
     */
    static std::vector<float> GetExpressEstimations();

    //! Calculates the period length of the sample.
    /*!
     *  \return count of repeating random number
     */
    static int GetPeriodLength();

    //! Calculates the aperiodicity segment length of the sample.
    /*!
     *  \return count of unique random numbers
     */
    static int GetAperiodicitySegment();

private:
    //! Multiplier, generator parameter.
    static uint64_t m_a;

    //! Modulus, generator parameter.
    static uint64_t m_m;

    //! Initial seed, generator parameter.
    static uint64_t m_r0;

    //! Size of random number sample.
    static size_t m_size;

    //! Generated random numbers.
    static std::vector<float> m_random_numbers;

    //! Additionally generated random numbers
    /*!
     *  \sa GetAperiodicitySegment()
     */
    static std::vector<float> m_additional_random_data;
};
