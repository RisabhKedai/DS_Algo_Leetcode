/*
* @Author: lenovo
* @Date:   2023-11-12 06:09:49
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-12 06:11:00
*/

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> shops(values.size(),values[0].size()-1);
        for(int i=0; i<values.size(); i++){
            pq.push({values[i][values[0].size()-1],i});
        }
        int d = 1;

        while(!pq.empty()) {
            pair<int,int> k = pq.top();
            pq.pop();
            int li = shops[k.second];
            // cout<<k.first<<" "<<k.second<<" "<<li<<endl;
            shops[k.second]--;
            if(shops[k.second]>=0){
                // cout<<k.first<<" "<<k.second<<" "<<shops[k.second]<<endl;
                pq.push({values[k.second][shops[k.second]],k.second});
            }
            ans += (long long)d*k.first;
            d++;
        }
        return ans;
    }
};


/**
 * maximum money we want to spend
 * and cost = day*val
 * so 2 factors day,val
 * and if we want max we want both to be high
 * so we buy most expensive thing on last day
 * 
 * Since the rows are sorted in non increasing order.
 * we can get the smallest to largest value by just merging 2 rows in sorted order.
 * Similarly merging all the rows.
 * 
 * Can also use priority queue for the same to save space complexity
 *
 * Time Complexity : O(mn log(mn))
 * Space Complexity : O(N) 
 */