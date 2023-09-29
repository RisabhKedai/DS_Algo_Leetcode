/*
* @Author: lenovo
* @Date:   2023-09-29 22:33:46
* @Last Modified by:   lenovo
* @Last Modified time: 2023-09-29 22:44:14
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        return ((n&(n-1))==0);
    }
};

/**
 * The solution is based on property of power of 2. 
 * They have 1 hamming weight. 
 * If you subtract 1 from power of 2 (1000...) they give something sort of 011...
 * When you & both of them it should return 0.
 * However, it is keen to observe that no negative number will be a power of 2 which is positive.
 * We can simply put a small check for that.
 */