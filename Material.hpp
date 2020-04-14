#ifndef MATERIAL_H
#define MATERIAL_H

#include "Vec3.hpp"
#include "Ray.hpp"
#include "Hitable.hpp"


// abstract class, une methode qui prend la ray recu, le dernier record (pour avoir le point, la normal..)
// une ref vers un Vec pour l'attenuation  et une ref vers la ray qui va sortir
class Material{
	public:
		virtual bool scatter(Ray& r_in, const hit_record_t& rec, Vec3& attenuation, Ray& new_ray) const = 0;
};

#endif
