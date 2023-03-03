#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "utility.h"

class material;

struct hit_record {
	point3 p;   // 相交的点
	vec3 normal;// 相交的射线
	shared_ptr<material> mat_ptr;
	double t;   // 单位法线
	bool front_face;//正面

	inline void set_face_normal(const ray& r, const vec3& outward_normal) {
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class hittable {
public:
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif // !HITTABLE_H
