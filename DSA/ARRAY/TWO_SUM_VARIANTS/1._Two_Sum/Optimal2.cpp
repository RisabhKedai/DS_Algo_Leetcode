/*
* @Author: lenovo
* @Date:   2023-10-16 07:40:13
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-16 07:41:59
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        mp[nums[0]] = 0;
        for(int i=1; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                return {i,mp[target-nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

/**
 * We store previous occurences of all the numbers in a map
 * As soon as we can find a pair that is present in the array
 * Whose one element is present in the map.
 * We return it.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */