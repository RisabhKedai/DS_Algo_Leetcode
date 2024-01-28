/*
* @Author: lenovo
* @Date:   2024-01-28 23:59:54
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-29 00:01:18
*/

class Solution {
public:
    int mySqrt(int x) {
        long long beg=1, end = x+1ll;
        while(beg<end){
            long long mid = (beg+end)/2;
            if(mid*mid <= x){
                beg = mid+1;
            }else{
                end = mid;
            }
        }
        return beg - 1;
    }
};

/**
 * Use binary search to find the maximum number with squre less than x
 *
 * Time complexity : O(logN)
 * Space complexity : O(1)
 */