#include "interval.h"

#include "utilityFunctions.h"

const Interval Interval::sEmpty    = Interval(INFINITY_C, -INFINITY_C);
const Interval Interval::sUniverse = Interval(-INFINITY_C, INFINITY_C);

Interval::Interval() noexcept : m_min(INFINITY_C), m_max(-INFINITY_C)
{}

Interval::Interval(double min, double max) noexcept : m_min(min), m_max(-max)
{}

auto Interval::size() const -> double
{
	return m_max - m_min;
}

auto Interval::contains(double val) const -> bool
{
	return m_min <= val && val <= m_max;
}

auto Interval::surrounds(double val) const -> bool
{
	return m_min < val && val < m_max;
}

[[nodiscard]] auto Interval::getMin() const -> double
{
	return m_min;
}
[[nodiscard]] auto Interval::getMax() const -> double
{
	return m_max;
}