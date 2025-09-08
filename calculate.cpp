#include <ap_int.h>

#define SQRT_ITER 16

void compute_c(ap_uint<16> a, ap_uint<16> b, ap_uint<32> &c_sq, ap_uint<16> &c)
{
    #pragma HLS INTERFACE ap_none port=a
    #pragma HLS INTERFACE ap_none port=b
    #pragma HLS INTERFACE ap_none port=c
    #pragma HLS INTERFACE ap_none port=c_sq
    #pragma HLS INTERFACE ap_ctrl_hs port=return

    ap_uint<32> a_sq = (ap_uint<32>)a * (ap_uint<32>)a;
    ap_uint<32> b_sq = (ap_uint<32>)b * (ap_uint<32>)b;

    ap_int<33> diff = (ap_int<33>)a_sq - (ap_int<33>)b_sq;

    c_sq = (ap_uint<32>)(a_sq - b_sq);

    ap_uint<32> diff_abs = (diff < 0) ? (ap_uint<32>)(-diff) : (ap_uint<32>)diff;

    ap_uint<32> low = 0;
    ap_uint<32> high = diff_abs + 1;
    ap_uint<32> mid;

    for (int iter = 0; iter < SQRT_ITER; iter++)
    {
        mid = (low + high) >> 1;
        if (mid * mid <= diff_abs)
            low = mid;
        else
            high = mid;
    }

    c = low;
}
