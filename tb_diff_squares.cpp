#include <iostream>
#include <ap_int.h>
using namespace std;

void compute_c(ap_uint<16> a, ap_uint<16> b, ap_uint<32> &c_sq, ap_uint<16> &c);

int main() {
    ap_uint<16> a, b, c;
    ap_uint<32> c_sq;

    for (int i = 1; i < 8; i++) {
        a = 2*i;
        b = i;

        compute_c(a, b, c_sq, c);

        std::cout << "a=" << a << ", b=" << b << ", c_sq=" << c_sq << " => c=" << c << std::endl;
        }

    return 0;
}
