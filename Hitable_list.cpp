
#include "Hitable_list.hpp"


 bool Hitable_list::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const{
	hit_record_t rec_temp;
	bool hit_something = false;
	float the_most_far = t_max;
	for(int i = 0; i < list_size; i++){
		if(list[i]->hit(r, t_min, the_most_far, rec_temp)){
			hit_something = true;
			the_most_far = rec_temp.t;
			rec = rec_temp;
		}
	}
	return hit_something;
}


inline void Hitable_list::add(Hitable* obj){
	//TODO: un coup de realloc
}
