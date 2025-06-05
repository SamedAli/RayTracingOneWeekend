#pragma once

#include <limits>
#include <numbers>

constexpr double INFINITY_C = std::numeric_limits<double>::infinity();
constexpr double PI_C       = std::numbers::pi_v<double>;

constexpr auto degreesToRadians(double degrees) -> double
{
	return degrees * PI_C / 180.0;
}