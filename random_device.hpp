////
// Copyright 2023. Glen S. Dayton. Rights reserved according to included license.
// Created by Glen Dayton on 7/17/23.
//
//  RandomDevice
//
//  Implementation specific wrapper around C++ random_device.
//  C++ random_device may block.
//
#ifndef TEST_RANDOM_DEVICE_RANDOM_DEVICE_HPP
#define TEST_RANDOM_DEVICE_RANDOM_DEVICE_HPP
#include <random>

class RandomDevice {
private:
    std::random_device r;

public:
    RandomDevice() : r{"/dev/random"} {}

    unsigned int operator()() { return r(); }

    [[nodiscard]] auto entropy() const -> double;

    static constexpr unsigned int min() { return std::random_device::min(); }

    static constexpr unsigned int max() { return std::random_device::max(); }

};


#endif //TEST_RANDOM_DEVICE_RANDOM_DEVICE_HPP
