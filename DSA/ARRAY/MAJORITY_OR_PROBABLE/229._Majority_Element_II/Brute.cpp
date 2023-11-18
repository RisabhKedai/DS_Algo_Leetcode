/*
* @Author: lenovo
* @Date:   2023-11-18 22:05:08
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-18 22:06:27
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        for(auto x: nums) {
            mp[x] ++;
        }
        for(auto y : mp){
            if(y.second> n/3){
                ans.push_back(y.first);
            }
        }
        return ans;
    }
};

/**
 * Check the frequency of each element and check which 
 * one has frequency more than n/3. Add that to answer array and push it
 *
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 */