/*
* @Author: lenovo
* @Date:   2023-11-01 10:34:12
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-01 10:35:20
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> curr = {-1,-1};
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            cout<<curr[0]<<" "<<curr[1]<<endl;
            if(intervals[i][0]>curr[1]){
            if(curr[0]!=-1)
                ans.push_back(curr);
                curr = intervals[i];
            }else{
                curr[0] = min(curr[0],intervals[i][0]);
                curr[1] = max(curr[1],intervals[i][1]);
            }
        }
        ans.push_back(curr);
        return ans;
    }
};

/**
 * Sort the entire array by start.
 * For each adjacent interval check if that can be merged
 * into its previous interval. 
 *
 * Time complexity : O(nlog(n))
 * Space complexity : O(n)
 */