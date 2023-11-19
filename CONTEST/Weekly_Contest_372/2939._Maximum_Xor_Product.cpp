/*
* @Author: lenovo
* @Date:   2023-11-19 21:59:20
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-19 22:06:57
*/

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        for(int i=n-1; i>=0; i--){
            long long abit = a & (1LL<<i);
            long long bbit = b & (1LL<<i);
            if(abit == bbit){
                a = a | (1LL<<i);
                b = b | (1LL<<i);
            } else if(abit==0 && a<b) {
                a = a | (1LL<<i);
                b = b ^ (1LL<<i);
            }else if(bbit==0 && b<a) {
                a = a ^ (1LL<<i);
                b = b | (1LL<<i);
            }
        }
        return (((a)%((int)1e9 + 7)) * ((b)%((int)1e9 + 7))) % ((int)1e9 + 7);
    }
};

/**
 * Reference link : https://leetcode.com/problems/maximum-xor-product/solutions/4305190/proofs-easy-video-explanation-bit-manipulation-c-java-python/
 *
 * Intuition:
 * For product of a and b to be maximum a and b has to be maximum. 
 * But the product is maximum when difference of a and b is minimum. 
 * For example a + b = 10, then
 * A      B
 * 1  *   9 = 9
 * 2  *   8 = 16
 * 3  *   4 = 12
 * 4  *   3 = 12
 * 5  *   5 = 25
 *
 * Notice that maximum product was obtained when a and b had 0 difference.
 *
 * Thus traverse bits from MSB to LSB side for A and B. When both A bit is 0 and B bit is 0, set them both. 
 * Else, give set bit to the lesser of A and B to maintain the balance. 
 *
 *
 * This is also related to why we traverse from MSB to LSB side. 
 * Because changing bits in MSB side will cause massive difference in A and B, which can be balanced by lower significance bits. 
 *
 * Time Complexity : O(N)
 * Space Complexity : O(1) 
 */