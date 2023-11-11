/*
* @Author: lenovo
* @Date:   2023-11-01 00:33:27
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-01 00:36:16
*/

class Solution {
public:
vector<int> overlap(vector<int> a, vector<int> b){
    vector<int> x;
    if(a[1]<b[0]){
        x.push_back(-1);
        x.push_back(-1);
    }else{
        x.push_back(min(a[0],b[0]));
        x.push_back(max(a[1],b[1]));   
    }
    return x;
}
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans_ranges;
        int n = intervals.size();
        int beg = 0, end = n-1;
        int ans = 0;
        while(beg <= end){
            int mid = (beg+end)/2;
            if(intervals[mid][1]<newInterval[0]){
                beg = mid+1;
                ans = mid+1;
            }else{
                end = mid-1;
            }
        }
        for(int i=0; i<ans; i++){
            ans_ranges.push_back(intervals[i]);
        }
        cout<<ans;
        while(ans<n){
            vector<int> over = overlap(newInterval,intervals[ans]);
            if(over[0]==-1 && over[1]==-1){
                break;
            }else{
                newInterval = over;
            }
            ans++;
        }
        ans_ranges.push_back(newInterval);
        while(ans<n){
            ans_ranges.push_back(intervals[ans]);
            ans++;
        }
        return ans_ranges;
    }
};

/**
 * Find the first index in the array which is not overlapping with given interval using binary search.
 * Add the intervals safe to add before that point. 
 * Check all the intervals from that point and update the current interval if Overlap is found. 
 * Add remaining secluded intervals to the answer.
 *
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */