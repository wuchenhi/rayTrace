## 基于C++实现的光线追踪

运行并查看：

```
make
./test > image.ppm #用PPM格式输出
```

### 功能实现：

1. 运动模糊.
2. BVH
3. 方格纹理
4. 柏林噪声
5. 图像纹理映射
6. Volume
7. 物体支持旋转和移动
8. 矩形光源
9. 抗锯齿
10. 漫反射材质、金属材质、玻璃材质等

### 代码：

1. vec3.h 包含定义了3维矢量类vec3，包括运算符重载、点乘、叉乘和使用函数
2. color.h 将单个像素的颜色写入std::ostream
3. ray.h 定义ray，包含起点，方向和时间
4. hittable.h 是对可命中对象的抽象类，hittable_list.h是可命中对象的列表
5. camera.h 是相机类
6. material.h 定义简单的材质
7. utility.h 工具函数
8. aabb.h 轴对齐边界框类
9. perlin.h 柏林噪声
10. moving_sphere.h 运动模糊球体
11. constant_medium.h 雾



致谢：[Ray Tracing in One Weekend Series](https://raytracing.github.io/)
