#pragma once

#include <limits>
#include <numbers>
#include <random>

constexpr double INFINITY_C = std::numeric_limits<double>::infinity();
constexpr double PI_C       = std::numbers::pi_v<double>;

constexpr auto degreesToRadians(double degrees) -> double
{
	return degrees * PI_C / 180.0;
}

inline auto randomDouble() -> double
{
	// Returns a random real in [0,1).
	static thread_local std::mt19937       rng_{std::random_device{}()};
	std::uniform_real_distribution<double> dist_(0.0, 1.0);
	return dist_(rng_);
}

inline auto randomDouble(double min, double max) -> double
{
	// Returns a random real in [min,max).
	return min + ((max - min) * randomDouble());
}