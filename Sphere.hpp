#ifndef SPHERE_H
#define SPHERE_H

#include "Vec3.hpp"
#include "Ray.hpp"
#include "Hitable.hpp"

class Sphere: public Hitable{
	public:
		Sphere(){}
		Sphere(Vec3 cen, float ra): center(cen), rayon(ra){}
		virtual bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
	private:
		float rayon;
		Vec3 center;
};

#endif 
