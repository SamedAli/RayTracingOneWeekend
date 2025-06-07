#pragma once

#include <array>

class Vec3
{
  public:
	using Array3 = std::array<double, 3>;

	explicit Vec3();
	explicit Vec3(double xVal, double yVal, double zVal);

	~Vec3() = default;

	Vec3(const Vec3 &) = default;
	Vec3(Vec3 &&)      = default;

	auto operator=(const Vec3 &) -> Vec3 & = default;
	auto operator=(Vec3 &&) -> Vec3 &      = default;

	[[nodiscard]] auto y() const -> double;
	[[nodiscard]] auto z() const -> double;
	[[nodiscard]] auto x() const -> double;
	auto               value() -> Array3 &;

	[[nodiscard]] auto        length() const -> double;
	[[nodiscard]] auto        lengthSquared() const -> double;
	[[nodiscard]] static auto random() -> Vec3;
	[[nodiscard]] static auto random(double min, double max) -> Vec3;

	auto operator[](std::size_t idx) const -> double;
	auto operator[](std::size_t idx) -> double &;

	auto operator-() const -> Vec3;

	auto operator+=(const Vec3 &vector) -> Vec3 &;
	auto operator*=(double scalar) -> Vec3 &;
	auto operator/=(double scalar) -> Vec3 &;

  private:
	Array3 m_vector;
};