#include "vec3.h"
#include <cmath>

Vec3::Vec3() :
    m_vector{0, 0, 0}
{}

Vec3::Vec3(double x, double y, double z) :
    m_vector{x, y, z}
{}

auto Vec3::x() const -> double
{
	return m_vector[0];
}

auto Vec3::y() const -> double
{
	return m_vector[1];
}

auto Vec3::z() const -> double
{
	return m_vector[2];
}

auto Vec3::value() -> Array3 &
{
	return m_vector;
}

auto Vec3::length() const -> double
{
	return std::sqrt(lengthSquared());
}

auto Vec3::lengthSquared() const -> double
{
	return m_vector[0] * m_vector[0] + m_vector[1] * m_vector[1] + m_vector[2] * m_vector[2];
}

auto Vec3::operator[](std::size_t i) const -> double
{
	return m_vector[i];
}

auto Vec3::operator[](std::size_t i) -> double &
{
	return m_vector[i];
}

auto Vec3::operator-() const -> Vec3
{
	return Vec3{
	    -m_vector[0],
	    -m_vector[1],
	    -m_vector[2],
	};
}

auto Vec3::operator+=(const Vec3 &v) -> Vec3 &
{
	m_vector[0] += v.x();
	m_vector[1] += v.y();
	m_vector[2] += v.z();
	return *this;
}

auto Vec3::operator*=(double scalar) -> Vec3 &
{
	m_vector[0] *= scalar;
	m_vector[1] *= scalar;
	m_vector[2] *= scalar;
	return *this;
}

auto Vec3::operator/=(double scalar) -> Vec3 &
{
	return *this *= scalar;
}