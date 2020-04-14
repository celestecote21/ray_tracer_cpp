#ifndef HITABLE_LIST_H
#define HITABLE_LIST_H

#include "Vec3.hpp"
#include "Ray.hpp"
#include "Hitable.hpp"

class Hitable_list: public Hitable{
	public: 
		Hitable_list(){}
		Hitable_list(Hitable **l, int n): list(l), list_size(n){}
		virtual bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
		inline void add(Hitable* o);

	private:
		Hitable** list;
		int list_size;
};



#endif
