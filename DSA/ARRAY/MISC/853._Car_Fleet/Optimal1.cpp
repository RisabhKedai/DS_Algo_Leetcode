/*
* @Author: lenovo
* @Date:   2023-12-23 23:22:30
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-23 23:24:19
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        int n = position.size();
        vector<pair<int,int>> posped;
        vector<double> times(n);
        for(int i=0; i<n; i++) {
            posped.push_back({position[i],speed[i]});
        }
        sort(posped.begin(),posped.end());
        for(int i=0; i<n; i++){
            int dist = target - posped[i].first;
            int speed = posped[i].second;
            double time = (double)dist/speed;
            cout<<time<<endl;
            times[i] = time;
        }
        for(int i=0; i<n; i++){
            cout<<times[i]<<endl;
            while(!st.empty() && times[i]>=st.top()){
                st.pop();
            }
            st.push(times[i]);
        }
        return st.size();
    }
};

/**
 * Sort the positions of the cars in descending order, also reposition the speed of the respective car. 
 * This can be done by either using dictionary or pair list and sort them.
 * Now calculate the distance needed to be covered by each car .i.e, target - position[i].
 * Calculate time taken by each car to reach destination .i.e., distance[i] / speed[i]. Note: The division should be float not int.
 * Ensure the time list is strictly increasing; if not make it strictly increasing by removing the valley number wherever that is encountered.
 * Return the length of the resulting strictly increasing time list. Note: Strictly increasing : (>) and Increasing : (>=)
 *
 * Time Complexity : O(NlogN)
 * Space Complexity : O(N)
 */