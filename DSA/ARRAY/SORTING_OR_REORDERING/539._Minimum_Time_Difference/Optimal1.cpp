/*
* @Author: lenovo
* @Date:   2023-11-22 00:42:28
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-22 00:46:59
*/

class Solution {
public:
    pair<int,int> timeStamp(string time){
        int hr = (time[0]-48)*10 + (time[1]-48);
        int mn = (time[3]-48)*10 + (time[4]-48);
        return {hr,mn};
    }
    int diff(pair<int,int> a, pair<int,int> b) { 
        return ((b.first*60) + b.second) - ((a.first*60) + a.second);
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int,int>> times;
        for(auto c : timePoints) {
            times.push_back(timeStamp(c));
        }
        sort(times.begin(),times.end());
        int ans = INT_MAX;
        for(int i=0; i<times.size()-1; i++) {
            ans = min(ans,diff(times[i],times[i+1]));
        }
        ans = min(ans,1440 - diff(times[0],times[times.size()-1]));

        return ans;
    }
};

/**
 * Since time repeats after 24 hrs the minimum difference
 * can be the differenc in 2 consecutive times
 * or it can be the difference between the largest time and
 * smallest time in anti clockwise fashion. 
 * Which is nothing but the
 * actual difference subtracted from 240.
 *
 * Time Complexity : O(Nlog(N))
 * Space Complexity : O(1)
 */