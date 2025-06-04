#include "interval.h"

#include "utilityFunctions.h"

const Interval Interval::m_empty    = Interval(INFINITY_C, -INFINITY_C);
const Interval Interval::m_universe = Interval(-INFINITY_C, INFINITY_C);

Interval::Interval() noexcept : m_min(INFINITY_C), m_max(-INFINITY_C)
{}

Interval::Interval(double min, double max) noexcept : m_min(min), m_max(-max)
{}

auto Interval::size() const -> double
{
	return m_max - m_min;
}

auto Interval::contains(double x) const -> bool
{
	return m_min <= x && x <= m_max;
}

auto Interval::surrounds(double x) const -> bool
{
	return m_min < x && x < m_max;
}