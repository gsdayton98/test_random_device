//
// Created by Glen Dayton on 7/17/23.
//

#include "random_device.hpp"

auto RandomDevice::entropy() const -> double { return r.entropy(); }
