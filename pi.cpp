#include "utility.h"

#include <iostream>
#include <iomanip>

int main() {
    int runs = 0;
    int inside_circle = 0;
    // 分层抽样 低纬度合适
    int inside_circle_stratified = 0;
    int sqrtN = 10000;
    // 显示12位小数
    std::cout << std::fixed << std::setprecision(12);
    for(int i=0; i<sqrtN; ++i) {
        for(int j=0; j<sqrtN; ++j) {
            auto x = random_double(-1,1);
            auto y = random_double(-1,1);
            if(x*x + y*y < 1) 
                ++inside_circle;
            x = 2*((i + random_double()) / sqrtN)-1;//(0,1) -> (-1,1)
            y = 2*((j + random_double()) / sqrtN)-1;
            if(x*x + y*y < 1) 
                ++inside_circle_stratified;
        }
    }
    std::cout << "Regular    Estimate of Pi = " <<
    4*double(inside_circle) / (sqrtN*sqrtN) << std::endl;
    std::cout << "Stratified    Estimate of Pi = " <<
    4*double(inside_circle_stratified) / (sqrtN*sqrtN) << std::endl;
}