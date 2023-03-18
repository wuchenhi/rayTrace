#include "utility.h"

#include <iostream>
#include <iomanip>
#include <math.h>

//�����ܶ�
inline double pdf1(double x) {
    return 0.5*x;
}

/*�κ�ѡ���PDF���ǻ���������ȷ�Ĵ𰸣�
��Խ�ӽ���f(x)��PDF���������ٶȾ�Խ�졣
f(x)�����ϵĻ��� ������ x^2
*/

// һ�ξ�����ȷ��
inline double pdf(double x) {
    return 3*x*x/8;
}

int main() {
    int N = 1;
    auto sum = 0.0;
    for (int i = 0; i < N; i++) {
        // auto x = random_double(0,2); //���ȳ���
        //auto x = sqrt(random_double(0,4));//pdf1 = 0.5*x  �ۼ�P = x^2/4 x = sqrt(4*y) y����(0,1)
        auto x = pow(random_double(0,8), 1./3.);  //pdf 3*x*x/8 �ۼ�P=pow(x,3)/8; x=pow(random_double(0,8), 1./3.);
        sum += x*x / pdf(x);
    }
    std::cout << std::fixed << std::setprecision(12);
    //std::cout << "I = " << 2 * sum/N << '\n'; // sum/N�Ǹ߶� 2�ǿ��
    std::cout << "I = " << sum/N << '\n';//������Ҫ2*sum/N�е��Ǹ�2��--������PDF�����
}