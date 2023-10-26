/*
* @Author: lenovo
* @Date:   2023-10-25 22:57:19
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-25 22:58:46
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = 1;
        }
        for(int i=1; i<1000000; i++){
            if(mp[i] != 1){
                return i;
            }
        }
        return -1;
    }
};

/**
 * Store all the numbers present in the array in a map;
 * Check from 1 through 100000 if any missing is found 
 * which will obviously be the case,
 * Then return it
 *
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */