#pragma once

class Interval
{
  public:
	explicit Interval() noexcept;
	explicit Interval(double min, double max) noexcept;

	[[nodiscard]] auto size() const -> double;
	[[nodiscard]] auto contains(double val) const -> bool;
	[[nodiscard]] auto surrounds(double val) const -> bool;

	static const Interval sEmpty;
	static const Interval sUniverse;

	[[nodiscard]] auto getMin() const -> double;
	[[nodiscard]] auto getMax() const -> double;

  private:
	double m_min;
	double m_max;
};
