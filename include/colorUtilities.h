#pragma once

#include "vec3.h"

#include <ostream>

using Color = Vec3;

auto LinearToGammaSpace(double linearComponent) -> double;
auto writeColor(std::ostream &out, const Color &color) -> void;