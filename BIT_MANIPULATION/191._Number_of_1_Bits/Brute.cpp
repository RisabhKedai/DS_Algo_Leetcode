/*
* @Author: lenovo
* @Date:   2023-09-26 20:38:03
* @Last Modified by:   lenovo
* @Last Modified time: 2023-09-26 20:39:30
*/

class Solution {
public:
    // APPROACH 1 - Uaing traditional calculation technique
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0){
            ans += n%2;
            n/=2;
        }
        return ans;
    }
    // APPROACH 2 - Using builtin function
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
    // APPROACH 3 - Using bitwise shifting operator to reduce N;
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0){
            ans += n%2;
            n>>=1;
        }
        return ans;  
    }
}

/**
 * Time Complexity : O(logN)
 * Space Complexity: O(1)
 */