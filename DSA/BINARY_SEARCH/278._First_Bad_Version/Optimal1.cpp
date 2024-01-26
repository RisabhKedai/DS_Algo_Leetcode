/*
* @Author: lenovo
* @Date:   2024-01-26 13:38:49
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-26 13:44:15
*/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int beg = 1;
        int end = n;
        int ans = -1;
        while(beg<=end){
            int mid = beg + (end-beg)/2;
            if(isBadVersion(mid)){
                ans = mid;
                end = mid-1;
            }else{
                beg = mid+1;
            }
        }
        return ans;
    }
};

/**
 * Keep reducing mid until you reach a point where it is correct version
 * Then increase again. 
 * Osscilate back and forth till you reach a fixed number 
 * This is nothing but the maximum good version
 * 
 * Time complexity : O(logN)
 * Space complexity : O(1)
 */