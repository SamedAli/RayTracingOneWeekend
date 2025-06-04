#pragma once

#include <array>

class Vec3
{
  public:
	using Array3 = std::array<double, 3>;

	explicit Vec3();
	explicit Vec3(double x, double y, double z);

	~Vec3() = default;

	auto x() const -> double;
	auto y() const -> double;
	auto z() const -> double;
	auto value() -> Array3 &;

	auto length() const -> double;
	auto lengthSquared() const -> double;

	auto operator[](std::size_t i) const -> double;
	auto operator[](std::size_t i) -> double &;

	auto operator-() const -> Vec3;

	auto operator+=(const Vec3 &v) -> Vec3 &;
	auto operator*=(double scalar) -> Vec3 &;
	auto operator/=(double scalar) -> Vec3 &;

  private:
	Array3 m_vector;
};