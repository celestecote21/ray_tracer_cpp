#ifndef HITABLE_H
#define HITABLE_H

#include "Vec3.hpp"
#include "Ray.hpp"
#include "Material.hpp"

typedef struct{
	float t;
	Vec3 p;
	Vec3 normal;
	Material* mat_ptr;
} hit_record_t;

class Hitable{
	public:
		virtual bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const = 0;
};

#endif
