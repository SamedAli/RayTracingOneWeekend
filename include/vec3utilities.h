#pragma once

#include "vec3.h"
#include <ostream>

using Point3 = Vec3;

inline auto operator<<(std::ostream &out, const Vec3 &vector) -> std::ostream &
{
	return out << vector.x() << ' ' << vector.y() << ' ' << vector.z();
}

inline auto operator+(const Vec3 &uVec, const Vec3 &vVec) -> Vec3
{
	return Vec3{uVec.x() + vVec.x(), uVec.y() + vVec.y(), uVec.z() + vVec.z()};
}

inline auto operator-(const Vec3 &uVec, const Vec3 &vVec) -> Vec3
{
	return Vec3{uVec.x() - vVec.x(), uVec.y() - vVec.y(), uVec.z() - vVec.z()};
}

inline auto operator*(const Vec3 &uVec, const Vec3 &vVec) -> Vec3
{
	return Vec3{uVec.x() * vVec.x(), uVec.y() * vVec.y(), uVec.z() * vVec.z()};
}

inline auto operator*(const Vec3 &vec, double scalar) -> Vec3
{
	return Vec3{vec.x() * scalar, vec.y() * scalar, vec.z() * scalar};
}

inline auto operator*(double scalar, const Vec3 &vec) -> Vec3
{
	return Vec3{vec.x() * scalar, vec.y() * scalar, vec.z() * scalar};
}

inline auto dot(const Vec3 &uVec, const Vec3 &vVec) -> double
{
	return (uVec.x() * vVec.x()) + (uVec.y() * vVec.y()) + (uVec.z() * vVec.z());
}

inline auto cross(const Vec3 &uVec, const Vec3 &vVec) -> Vec3
{
	return Vec3{(uVec.y() * vVec.z()) - (uVec.z() * vVec.y()),
	            (uVec.z() * vVec.x()) - (uVec.x() * vVec.z()),
	            (uVec.x() * vVec.y()) - (uVec.y() * vVec.x())};
}

inline auto operator/(const Vec3 &vec, double scalar) -> Vec3
{
	return vec * (1 / scalar);
}

inline auto unit(const Vec3 &vec) -> Vec3
{
	return vec / vec.length();
}