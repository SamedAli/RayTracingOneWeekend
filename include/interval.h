#pragma once

class Interval
{
  public:
	explicit Interval() noexcept;
	explicit Interval(double min, double max) noexcept;

	[[nodiscard]] auto size() const -> double;
	[[nodiscard]] auto contains(double val) const -> bool;
	[[nodiscard]] auto surrounds(double val) const -> bool;

	static const Interval m_empty;
	static const Interval m_universe;

	double m_min;
	double m_max;
};
