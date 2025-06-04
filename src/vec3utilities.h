#pragma once

#include "vec3.h"
#include <ostream>

using Point3 = Vec3;

inline auto operator<<(std::ostream &out, const Vec3 &v) -> std::ostream &
{
	return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline auto operator+(const Vec3 &u, const Vec3 &v) -> Vec3
{
	return Vec3{u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};
}

inline auto operator-(const Vec3 &u, const Vec3 &v) -> Vec3
{
	return Vec3{u.x() - v.x(), u.y() - v.y(), u.z() - v.z()};
}

inline auto operator*(const Vec3 &u, const Vec3 &v) -> Vec3
{
	return Vec3{u.x() * v.x(), u.y() * v.y(), u.z() * v.z()};
}

inline auto operator*(const Vec3 &v, double scalar) -> Vec3
{
	return Vec3{v.x() * scalar, v.y() * scalar, v.z() * scalar};
}

inline auto operator*(double scalar, const Vec3 &v) -> Vec3
{
	return Vec3{v.x() * scalar, v.y() * scalar, v.z() * scalar};
}

inline auto dot(const Vec3 &u, const Vec3 &v) -> double
{
	return u.x() * v.x() + u.y() + v.y() + u.z() * v.z();
}

inline auto cross(const Vec3 &u, const Vec3 &v) -> Vec3
{
	return Vec3{u.y() * v.z() - u.z() * v.y(),
	            u.z() * v.x() - u.x() * v.z(),
	            u.x() * v.y() - u.y() * v.x()};
}

inline auto operator/(const Vec3 &v, double scalar) -> Vec3
{
	return v * (1 / scalar);
}

inline auto unit(const Vec3 &v) -> Vec3
{
	return v / v.length();
}