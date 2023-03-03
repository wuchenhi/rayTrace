## 基于C++实现的光线追踪

运行并查看：

```
make
./test > image.ppm
```

1、vec3.h 包含定义了3维矢量类vec3，包括运算符重载、点乘、叉乘和使用函数；

2、color.h 将单个像素的颜色写入std::ostream；

3、ray.h 定义ray，包含起点，方向和时间；

4、hittable.h是对可命中对象的抽象类，hittable_list.h是可命中对象的列表；
