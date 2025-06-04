#pragma once

#include "hittable.h"

#include <memory>
#include <vector>

class HittableObjectsList : public Hittable
{
  public:
	explicit HittableObjectsList() noexcept = default;
	explicit HittableObjectsList(std::shared_ptr<Hittable> obj);

	auto clear() -> void;
	auto add(std::shared_ptr<Hittable> obj) -> void;

	auto isHit(const Ray &ray, double rayTmin, double rayTmax, HitPoint &hitpoint) const -> bool override;

  private:
	std::vector<std::shared_ptr<Hittable>> m_objects;
};