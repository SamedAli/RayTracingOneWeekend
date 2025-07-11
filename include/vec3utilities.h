#pragma once

#include "vec3.h"

#include "utilityFunctions.h"

#include <cmath>
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

/*
    Generate a random vector inside a unit sphere.
    Pick a vector v(x,y,z). If length is inside unit sphere < 1.
*/
inline auto randomUnitVector() -> Vec3
{
	while (true)
	{
		const auto randomVector_        = Vec3::random(-1, 1);
		const auto lengthSquaredVector_ = randomVector_.lengthSquared();
		if (1e-160 < lengthSquaredVector_ && lengthSquaredVector_ <= 1)
		{
			return randomVector_ / std::sqrt(lengthSquaredVector_);
		}
	}
}

inline auto randomVectorOnHemisphere(const Vec3 &normal) -> Vec3
{
	const Vec3 VecOnUnitSphere_ = randomUnitVector();
	if (dot(VecOnUnitSphere_, normal) > 0.0)
	{
		return VecOnUnitSphere_;
	}
	return -VecOnUnitSphere_;
}

inline auto reflect(const Vec3 &vector, const Vec3 &normal) -> Vec3
{
	return vector - 2 * dot(vector, normal) * normal;
}

inline auto refract(const Vec3 &rayInUnit, const Vec3 &refractiveIndex, double refractionIndexRatio) -> Vec3
{
	const auto cosTheta_            = std::fmin(dot(-rayInUnit, refractiveIndex), 1.0);
	const auto rayOutPerpendicular_ = refractionIndexRatio * (rayInUnit + cosTheta_ * refractiveIndex);
	const auto rayOutParallel_      = -std::sqrt(std::fabs(1.0 - rayOutPerpendicular_.lengthSquared())) * refractiveIndex;
	return rayOutPerpendicular_ + rayOutParallel_;
}

inline auto randomUnitDisk() -> Vec3
{
	while (true)
	{
		auto p_ = Vec3(randomDouble(-1, 1), randomDouble(-1, 1), 0);
		if (p_.lengthSquared() < 1)
		{
			return p_;
		}
	}
}