
#include "Sphere.hpp"


bool Sphere::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const {
	
	Vec3 oc = r.origine() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(r.direction(), oc);
	float c = dot(oc, oc) - rayon*rayon;
	float determinant = b*b - 4.0*a*c;
	if(determinant < 0){
		return false;
	}else{
		float temp = (- b - sqrt(determinant)) / (2 * a);
		if(t_min < temp && temp < t_max){
			rec.t = temp;
			rec.p = r.point_at_t(temp);
			rec.normal = (rec.p - center) / rayon; // on divise par le rayon pour avoir un unit vector
			return true;
		}
		temp = (- b + sqrt(determinant)) / (2 * a);
		if(t_min < temp && temp < t_max){
			rec.t = temp;
			rec.p = r.point_at_t(temp);
			rec.normal = (rec.p - center) / rayon; // on divise par le rayon pour avoir un unit vector
			return true;
		}
	}
	return false;
}
