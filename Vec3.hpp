#ifndef VEC3_H
#define VEC3_H


#include <math.h>
#include <stdlib.h>
#include <iostream>



class Vec3{
	public:
		Vec3(){}
		Vec3(float e1, float e2, float e3){e[0] = e1; e[1] = e2; e[2] = e3;}
		inline float r() const { return e[0];}
		inline float g() const { return e[1];}
		inline float b() const { return e[2];}
		inline float x() const { return e[0];}
		inline float y() const { return e[1];}
		inline float z() const { return e[2];}

		inline const Vec3& operator+() const { return *this;}
		inline Vec3 operator-() const { return Vec3( -e[0], -e[1], -e[2]);}
		inline float operator[](int i) const {return e[i];}
		inline float& operator[](int i) {return e[i];}


		inline Vec3& operator+=(const Vec3 &v2);
		inline Vec3& operator-=(const Vec3 &v2);
		inline Vec3& operator*=(const Vec3 &v2);
		inline Vec3& operator/=(const Vec3 &v2);
		inline Vec3& operator*=(const float t);
		inline Vec3& operator/=(const float t);

		inline float len() const{
			return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
		}

		inline float squared_len() const{
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}

		inline void creat_unit_vec();

		float e[3];
};

 inline std::istream& operator>>(std::istream &is, Vec3 &t){
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}
 
inline std::ostream& operator<<(std::ostream &os, const Vec3 &t){
	os << t.x() << " " << t.y() << " "  << t.z();
	return os;
}

inline void Vec3::creat_unit_vec(){
	float k = 1 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}


inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2){
	return Vec3(v1.x() + v2.x(), v1.y() + v2.y(),v1.z() + v2.z());
}


inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2){
	return Vec3(v1.x() - v2.x(), v1.y() - v2.y(),v1.z() - v2.z());
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2){
	return Vec3(v1.x() * v2.x(), v1.y() * v2.y(),v1.z() * v2.z());
}

inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2){
	return Vec3(v1.x() / v2.x(), v1.y() / v2.y(),v1.z() / v2.z());
}



inline Vec3 operator*(const Vec3 &v, float t){
	return Vec3(t * v.x(), t * v.y(),t * v.z());
}

inline Vec3 operator*(float t, const Vec3 &v){
	return Vec3(t*v.x(), t * v.y(), t * v.z());
}

inline Vec3 operator/(const Vec3 &v, float t){
	return Vec3(v.x() / t, v.y() / t,v.z() / t);
	
}


inline float dot(const Vec3 &v1, const Vec3 &v2){
	return v1.x()*v2.x() + v1.y()*v2.y() + v1.z()*v2.z();
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2){
	return Vec3(v1.y()*v2.z() - v1.z()*v2.y(),
			(-(v1.x()*v2.z() - v1.z()*v2.x())),
			v1.x()*v2.y() - v1.y()*v2.x());
}


inline Vec3& Vec3::operator+=(const Vec3 &v2){
	e[0] += v2.x();
	e[1] += v2.y();
	e[2] += v2.z();
	return *this;
}

inline Vec3& Vec3::operator-=(const Vec3 &v2){
	e[0] -= v2.x();
	e[1] -= v2.y();
	e[2] -= v2.z();
	return *this;
}

inline Vec3& Vec3::operator*=(const Vec3 &v2){
	e[0] *= v2.x();
	e[1] *= v2.y();
	e[2] *= v2.z();
	return *this;
}


inline Vec3& Vec3::operator/=(const Vec3 &v2){
	e[0] /= v2.x();
	e[1] /= v2.y();
	e[2] /= v2.z();
	return *this;
}


inline Vec3& Vec3::operator*=(const float t){
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline Vec3& Vec3::operator/=(const float t){
	float k = 1/t;
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
	return *this;
}

inline Vec3 unit_vec(Vec3 v){
	return v / v.len();
}
#endif
