/*
* @Author: lenovo
* @Date:   2024-01-05 22:32:49
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-05 22:44:49
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        for(int i=0; i<n; i++){
            costs[i][0] = costs[i][0]-costs[i][1];
        }
        sort(costs.begin(),costs.end());
        int cost = 0;
        for(int i=0; i<n/2; i++){
            cost += costs[i][0]+costs[i][1];
        }
        for(int i=n/2; i<n; i++){
            cost += costs[i][1];
        }
        return cost;
    }
};

/**
 * lets consider 2 users with costs [x1,y1], [x2,y2].
 * Lets say this is [x1,x1 + x1'], [x2,x2 + x2'].
 * Either first will go to A and second to B or vice versa.
 * So the cost can either be x1+x2+x2' or x1+x2+x1'
 * So it boils down to the difference between the 2 costs.
 * based on the costs difference sort the array.
 * Now just assign the first half of the array to a and second array to b. 
 * If the cost to b is higher the difference will be smaller and thus will occupy first half.
 * Thus we will end up sending it to A for a lesser cost.
 * 
 * Time complexity : O(nlog(n))
 * Space complexity : O(1)
 */