/*
* @Author: lenovo
* @Date:   2023-09-29 22:33:46
* @Last Modified by:   lenovo
* @Last Modified time: 2023-09-29 22:36:52
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        if(n%2!=0 || n==0){
            return false;
        }
        return isPowerOfTwo(n/2);
    }
};

/**
 * The solution is based on recursion.
 * There are 2 base cases:
 * - If n is 1 means it is 2^0. We can stop and confirm it is power of 2
 * - If the number is not divisible by 2 / number is 0. It is in no way power of 2.
 * Finally we keep dividing the number by 2 and keep checking whether it is power of 2.
 */