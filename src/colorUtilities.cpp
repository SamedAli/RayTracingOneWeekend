#include "colorUtilities.h"

auto writeColor(std::ostream &out, const Color &color) -> void
{
	const auto red_   = color.x();
	const auto green_ = color.y();
	const auto blue_  = color.z();

	constexpr double MAX_PIXEL_VALUE = 255.999;
	const auto       rByte_          = std::uint32_t(MAX_PIXEL_VALUE * red_);
	const auto       gByte_          = std::uint32_t(MAX_PIXEL_VALUE * green_);
	const auto       bByte_          = std::uint32_t(MAX_PIXEL_VALUE * blue_);

	out << rByte_ << ' ' << gByte_ << ' ' << bByte_ << '\n';
}