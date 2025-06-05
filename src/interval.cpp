#include "interval.h"

#include "utilityFunctions.h"

#include <cassert>

const Interval Interval::sEmpty    = Interval(INFINITY_C, -INFINITY_C);
const Interval Interval::sUniverse = Interval(-INFINITY_C, INFINITY_C);

Interval::Interval() noexcept : m_min(-INFINITY_C), m_max(INFINITY_C)
{}

Interval::Interval(double min, double max) noexcept : m_min(min), m_max(max)
{}

auto Interval::size() const noexcept -> double
{
	return m_max - m_min;
}

auto Interval::contains(double val) const noexcept -> bool
{
	return m_min <= val && val <= m_max;
}

auto Interval::surrounds(double val) const noexcept -> bool
{
	return m_min < val && val < m_max;
}

[[nodiscard]] auto Interval::getMin() const noexcept -> double
{
	return m_min;
}

[[nodiscard]] auto Interval::getMax() const noexcept -> double
{
	return m_max;
}

[[nodiscard]] auto Interval::clamp(double val) const noexcept -> double
{
	assert(m_min <= m_max && "Interval clamp() requires m_min <= m_max");
	return std::clamp(val, m_min, m_max);
}