#include "vec3.h"

#include "utilityFunctions.h"

#include <cmath>

Vec3::Vec3() :
    m_vector{0, 0, 0}
{}

Vec3::Vec3(double xVal, double yVal, double zVal) :
    m_vector{xVal, yVal, zVal}
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
	return (m_vector.at(0) * m_vector.at(0)) + (m_vector.at(1) * m_vector.at(1)) + (m_vector.at(2) * m_vector.at(2));
}

auto Vec3::operator[](std::size_t idx) const -> double
{
	return m_vector.at(idx);
}

auto Vec3::operator[](std::size_t idx) -> double &
{
	return m_vector.at(idx);
}

auto Vec3::operator-() const -> Vec3
{
	return Vec3{
	    -m_vector[0],
	    -m_vector[1],
	    -m_vector[2],
	};
}

auto Vec3::operator+=(const Vec3 &vector) -> Vec3 &
{
	m_vector[0] += vector.x();
	m_vector[1] += vector.y();
	m_vector[2] += vector.z();
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

auto Vec3::random() -> Vec3
{
	return Vec3(randomDouble(), randomDouble(), randomDouble());
}

auto Vec3::random(double min, double max) -> Vec3
{
	return Vec3(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
}