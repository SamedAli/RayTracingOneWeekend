#pragma once

#include "hittable.h"

#include <memory>
#include <vector>

class HittableObjectsList : public Hittable
{
  public:
	explicit HittableObjectsList() noexcept = default;
	explicit HittableObjectsList(const std::shared_ptr<Hittable> &obj);

	auto clear() -> void;
	auto add(const std::shared_ptr<Hittable> &obj) -> void;

	[[nodiscard]] auto isHit(const Ray &ray, Interval rayT, HitPoint &hitpoint) const -> bool override;

  private:
	std::vector<std::shared_ptr<Hittable>> m_objects;
};