/*
* @Author: lenovo
* @Date:   2023-09-29 23:43:44
* @Last Modified by:   lenovo
* @Last Modified time: 2023-09-29 23:47:07
*/
class Solution {
public:
    int count(long k, int A, int B, int C){
        long byA = k/A;
        long byB = k/B;
        long byC = k/C;
        long byAB = k/lcm(A,B);
        long byBC = k/lcm(B,C);
        long byAC = k/lcm(A,C);
        long byABC = k/lcm(A,lcm(B,C));
        return (byA+byB+byC-byAB-byBC-byAC+byABC);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 0, right = 2*(1e9);
        int result = 0;
        while(left<=right){
            int mid = left + ((right-left)/2);
            if(count(mid,a,b,c)>=n){
                result = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return result;
    }
    long gcd(long a, long b){
        if(a%b==0)
            return b;
        return gcd(b,a%b);
    }
    long lcm(long a, long b){
        return (a*b)/gcd(a,b);
    }
};

/**
 * We know that the answer is going to lie in the range of 1 to 2*1e9. 
 * As this is mentioned in the question.
 * For each k we can also determine the number of Ugly numbers less than k.
 * This value is increasing. 
 * Using these 2 hints we can use binary search. 
 * For each k in the range 1 to 2^(1e9) determine the number of ugly numbers less than equal to k.
 * To determine this value we can use theory of inclusing which is implemented in the count function.
 */