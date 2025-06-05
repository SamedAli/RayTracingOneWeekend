#include "colorUtilities.h"

#include "interval.h"

auto writeColor(std::ostream &out, const Color &color) -> void
{
	const auto red_   = color.x();
	const auto green_ = color.y();
	const auto blue_  = color.z();

	// Translate the [0,1] component values to the byte range [0,255].
	constexpr double      MAX_PIXEL_VALUE = 256.0;
	static const Interval intensity(0.000, 0.999);
	const auto            rByte_ = static_cast<std::uint32_t>(MAX_PIXEL_VALUE * intensity.clamp(red_));
	const auto            gByte_ = static_cast<std::uint32_t>(MAX_PIXEL_VALUE * intensity.clamp(green_));
	const auto            bByte_ = static_cast<std::uint32_t>(MAX_PIXEL_VALUE * intensity.clamp(blue_));

	out << rByte_ << ' ' << gByte_ << ' ' << bByte_ << '\n';
}