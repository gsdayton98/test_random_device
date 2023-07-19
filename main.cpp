////
// Copyright 2023 Glen S. Dayton. Rights reserved according to included license.
//
// Show characteristics and chi-squared test against uniform distribution of the C++ random engine.
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "chi_squared_test.hpp"
#include "random_device.hpp"


int main(int, char *argv[]) {
    int returnCode = EXIT_FAILURE;

    try {
        RandomDevice randomDevice;
        constexpr unsigned int NumberTrials = 1'000'000U;
        std::vector<unsigned int> samples;
        samples.reserve(NumberTrials);

        std::cout << "Random Device min(): " << RandomDevice::min() << std::endl;
        std::cout << "Random Device max(): " << RandomDevice::max() << std::endl;
        std::cout << "Random Device entropy estimate: " << randomDevice.entropy() << std::endl;

        for (auto trial=0; trial < NumberTrials; ++trial) {
            samples.push_back(randomDevice());
        }

        // std::random_device expected to produce uniformly distributed numbers in the closed interval [min(), max()].
        constexpr unsigned int NumberBins = 1'000Ul;
        std::vector<double> bins(NumberBins);
        std::vector<double> expected(NumberBins);
        ChiSquaredTest chiSquaredTest;

        bins.reserve(NumberBins);
        expected.reserve(NumberBins);

        for (auto k = 0; k < NumberBins; ++k) {
            bins[k] = 0.0;
            expected[k] =  static_cast<double>(NumberTrials)/static_cast<double>(NumberBins);

        }

        auto range = RandomDevice::max() - RandomDevice::min();
        auto binWidth = range/NumberBins;

        std::cout << "Number of bins in histogram: " << NumberBins << std::endl;
        std::cout << "Expected count in each bin: " << expected[0] << std::endl;

        for (auto const sample : samples) {
            auto binNumber = (sample - RandomDevice::min())/binWidth;
            ++bins[binNumber];
        }

        auto chiSquared = chiSquaredTest(&bins[0], &expected[0], NumberBins);

        std::cout << "Chi-squared statistic: " << chiSquared << std::endl;

        returnCode = EXIT_SUCCESS;
    }
    catch (const std::exception &ex) {
        std::cerr << argv[0] << ": Exception " << ex.what() << std::endl;
    }

    return returnCode;
}
