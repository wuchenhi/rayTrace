#ifndef CAMERA_H
#define CAMERA_H

#include "utility.h"

class camera {
public:
    // 放置相机的位置：lookfrom，查看的点：lookat
    camera(point3 lookfrom, point3 lookat, vec3 vup,  // vup和w来确定u v
           double vfov, double aspect_ratio,          // vertical field-of-view in degrees视场 aspect_ratio 宽高比
           double aperture, double focus_dist,        // aperture 光圈直径 focus_dist 焦距
           double time0_ = 0,
           double time1_ = 0
           ) {  
        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta/2);
        auto viewport_height = 2.0 * h;                      // 视口高度
        auto viewport_width = aspect_ratio * viewport_height;// 视口宽度

        auto w = unit_vector(lookfrom - lookat);
        auto u = unit_vector(cross(vup,w));
        auto v = cross(w, u);

        origin = lookfrom;
        
        horizontal = focus_dist * viewport_width * u;
        vertical = focus_dist * viewport_height * v;
        lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w; // 左下角
        
        lens_radius = aperture / 2;

        time0 = time0_;
        time1 = time1_;

    }
    // u v 对应的光线
    ray get_ray(double s, double t) const {
        vec3 rd = lens_radius * random_in_unit_disk();
        vec3 offset = u * rd.x() + v * rd.y();
        return ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset, 
                random_double(time0, time1));
    }

private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;  // 横向
    vec3 vertical;    // 纵向
    vec3 u, v, w;
    double lens_radius; // 镜头半径
    double time0, time1; // 快门打开/关闭时间
};
#endif