#ifndef CAMERA_H
#define CAMERA_H

#include "Vec3.hpp"
#include "Ray.hpp"

class Camera{
	public:
		Camera(){
			lower_left_corner = Vec3(-2.0, -1.0, -1.0);
			horizontal = Vec3(4.0, 0.0, 0.0);
			vertical = Vec3(0.0, 2.0, 0.0);
			origine = Vec3(0.0, 0.0, 0.0);
		}
		Ray get_ray(float u, float v){
			return Ray(origine, lower_left_corner + u*horizontal + v*vertical - origine);
		}
	private:
		Vec3 lower_left_corner;
		Vec3 horizontal;
		Vec3 vertical;
		Vec3 origine;
};

#endif
