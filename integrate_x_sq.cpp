#include "utility.h"

#include <iostream>
#include <iomanip>
#include <math.h>

//概率密度
inline double pdf1(double x) {
    return 0.5*x;
}

/*任何选择的PDF总是会收敛到正确的答案，
但越接近于f(x)的PDF它的收敛速度就越快。
f(x)是域上的积分 这里是 x^2
*/

// 一次就是正确答案
inline double pdf(double x) {
    return 3*x*x/8;
}

int main() {
    int N = 1;
    auto sum = 0.0;
    for (int i = 0; i < N; i++) {
        // auto x = random_double(0,2); //均匀抽样
        //auto x = sqrt(random_double(0,4));//pdf1 = 0.5*x  累计P = x^2/4 x = sqrt(4*y) y属于(0,1)
        auto x = pow(random_double(0,8), 1./3.);  //pdf 3*x*x/8 累计P=pow(x,3)/8; x=pow(random_double(0,8), 1./3.);
        sum += x*x / pdf(x);
    }
    std::cout << std::fixed << std::setprecision(12);
    //std::cout << "I = " << 2 * sum/N << '\n'; // sum/N是高度 2是宽度
    std::cout << "I = " << sum/N << '\n';//不再需要2*sum/N中的那个2了--那是由PDF处理的
}