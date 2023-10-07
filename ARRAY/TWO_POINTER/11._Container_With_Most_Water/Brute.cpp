/*
* @Author: lenovo
* @Date:   2023-10-07 22:41:13
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-07 22:44:03
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans,(j-i)*min(height[i],height[j]));
            }
        }
        return ans;
    }
};
// Trying out all possible solutions
// Time Complexity: O(n^2)
// Space Complexity : O(1)
// Results in TLE