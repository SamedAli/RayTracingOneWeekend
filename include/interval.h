#pragma once

class Interval
{
  public:
	explicit Interval() noexcept;
	explicit Interval(double min, double max) noexcept;

	[[nodiscard]] auto getMin() const noexcept -> double;
	[[nodiscard]] auto getMax() const noexcept -> double;

	[[nodiscard]] auto size() const noexcept -> double;
	[[nodiscard]] auto contains(double val) const noexcept -> bool;
	[[nodiscard]] auto surrounds(double val) const noexcept -> bool;
	[[nodiscard]] auto clamp(double val) const noexcept -> double;

	static const Interval sEmpty;
	static const Interval sUniverse;

  private:
	double m_min;
	double m_max;
};
