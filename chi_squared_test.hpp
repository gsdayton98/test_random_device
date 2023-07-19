//
// Created by Glen Dayton on 7/18/23.
//

#ifndef TEST_RANDOM_DEVICE_CHI_SQUARED_TEST_HPP
#define TEST_RANDOM_DEVICE_CHI_SQUARED_TEST_HPP


class ChiSquaredTest {
public:
    auto operator()(const double *histogram, const double *expected, unsigned int numberBins) -> double;
};


#endif //TEST_RANDOM_DEVICE_CHI_SQUARED_TEST_HPP
