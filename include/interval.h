#pragma once

class Interval
{
  public:
	explicit Interval() noexcept;
	explicit Interval(double min, double max) noexcept;

	auto size() const -> double;
	auto contains(double x) const -> bool;
	auto surrounds(double x) const -> bool;

	static const Interval m_empty;
	static const Interval m_universe;

	double m_min;
	double m_max;
};
