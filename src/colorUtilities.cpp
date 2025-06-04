#include "colorUtilities.h"

auto writeColor(std::ostream &out, const Color &c) -> void
{
	const auto r_ = c.x();
	const auto g_ = c.y();
	const auto b_ = c.z();

	constexpr double MAX_PIXEL_VALUE = 255.999;
	const auto       rByte_          = std::uint32_t(MAX_PIXEL_VALUE * r_);
	const auto       gByte_          = std::uint32_t(MAX_PIXEL_VALUE * g_);
	const auto       bByte_          = std::uint32_t(MAX_PIXEL_VALUE * b_);

	out << rByte_ << ' ' << gByte_ << ' ' << bByte_ << '\n';
}