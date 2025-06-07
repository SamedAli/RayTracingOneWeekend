#include "colorUtilities.h"

#include "interval.h"

#include <cmath>

auto LinearToGammaSpace(double linearComponent) -> double
{
	if (linearComponent > 0)
	{
		return std::sqrt(linearComponent);
	}
	return 0;
}

auto writeColor(std::ostream &out, const Color &color) -> void
{
	auto red_   = color.x();
	auto green_ = color.y();
	auto blue_  = color.z();

	red_   = LinearToGammaSpace(red_);
	green_ = LinearToGammaSpace(green_);
	blue_  = LinearToGammaSpace(blue_);

	// Translate the [0,1] component values to the byte range [0,255].
	constexpr double      MAX_PIXEL_VALUE = 256.0;
	static const Interval intensity(0.000, 0.999);
	const auto            rByte_ = static_cast<std::uint32_t>(MAX_PIXEL_VALUE * intensity.clamp(red_));
	const auto            gByte_ = static_cast<std::uint32_t>(MAX_PIXEL_VALUE * intensity.clamp(green_));
	const auto            bByte_ = static_cast<std::uint32_t>(MAX_PIXEL_VALUE * intensity.clamp(blue_));

	out << rByte_ << ' ' << gByte_ << ' ' << bByte_ << '\n';
}