//
// Created by Glen Dayton on 7/18/23.
//

#include "chi_squared_test.hpp"

auto ChiSquaredTest::operator()(const double *histogram,
        const double *expected, unsigned int numberBins) -> double {
    auto chiSquared = 0.0;

    for (auto k = 0; k < numberBins; ++k) {
        auto expectedReciprocal = *expected;
        if (expectedReciprocal > 0.0) {
            expectedReciprocal = 1.0 / expectedReciprocal;
        } else {
            expectedReciprocal = 1.0;
        }

        auto term = (*histogram - *expected)*expectedReciprocal;
        chiSquared += term * term;

        ++histogram;
        ++expected;
    }
    return chiSquared;
}
