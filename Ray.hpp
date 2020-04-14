#ifndef RAY_H
#define RAY_H

#include "Vec3.hpp"

class Ray{
	public:
		Ray(){}
		Ray(const Vec3& a, const Vec3& b): A(a), B(b){}
		Vec3 origine() const {return A;}
		Vec3 direction() const {return B;}
		Vec3 point_at_t(float t) const {return A + t*B;}



	private:
		Vec3 A;
		Vec3 B;
};


#endif
