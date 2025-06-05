#pragma once

#include "vec3.h"

#include <ostream>

using Color = Vec3;

auto writeColor(std::ostream &out, const Color &c) -> void;