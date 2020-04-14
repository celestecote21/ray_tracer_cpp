#include <iostream>

#include "Vec3.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Hitable_list.hpp"
#include <float.h>


Vec3 random_vec(){
	return Vec3(drand48(), drand48(), drand48());
}

Vec3 color(const Ray& r, Hitable* world){
	hit_record_t rec;
	if(world->hit(r, 0.001, MAXFLOAT, rec)){
		Vec3 v_renvoie;
		do{
			v_renvoie = random_vec();
		}while(v_renvoie.len() < rec.normal.len());
		Ray new_ray(rec.p, rec.normal - v_renvoie); // on prend un nouveau Ray qui part du point et qui part dans une direction au hasard
		return 0.5 * color(new_ray, world); // on prend donc la moitier de la couleur qui est renvoyer par ce rayon
	}
	float t = 0.0;
	Vec3 unit_direction = unit_vec(r.direction());
	t = 0.5*(unit_direction.y() + 1.0);
	return  (1.0-t)*Vec3(1.0, 1.0, 1.0) + t*Vec3(0.5, 1.0, 1.0);
}


int main(){

	int nx = 2000;
	int ny = 1000;
	int ns = 2;

	std::cout << "P3\n" << nx << " " << ny << "\n255\n";

	Vec3 lower_left_corner(-2.0, -1.0, -1.0);
	Vec3 horizontal(4.0, 0.0, 0.0);
	Vec3 vertical(0.0, 2.0, 0.0);
	Vec3 origine(0.0, 0.0, 0.0);

	Hitable* list[2];
	list[0] = new Sphere(Vec3(0.0,0.0,-1.0), 0.5);
	list[1] = new Sphere(Vec3(0.0,-100.5,-1.0), 100.0);
	Hitable* world = new Hitable_list(list, 2);
	Camera camera;

	float taille_sphere = 0.3;

	for(int y = ny - 1; y >= 0; y--){
		for(int x = 0; x < nx; x++){
			Vec3 c(0.0, 0.0, 0.0);
			for(int s = 0; s < ns; s++){
				float u = float(x + drand48()) / float(nx);
				float v = float(y + drand48()) / float(ny);
				// Ray r(origine, lower_left_corner + u*horizontal + v*vertical);
				c += color(camera.get_ray(u, v), world);
			}
			c /= float(ns);
			c = Vec3(sqrt(c[0]),sqrt(c[0]), sqrt(c[0]));

			int ir = int(255.99 * c.r());
			int ig = int(255.99 * c.g());
			int ib = int(255.99 * c.b());

			std::cout << ir << " " << ig << " " << ib << "\n";
		}

	}


}
