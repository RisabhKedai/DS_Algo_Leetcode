/*
* @Author: lenovo
* @Date:   2023-12-21 22:20:09
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-21 22:24:04
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> profit(n);
        for(int i=0; i<n; i++)
        profit[i] = gas[i] - cost[i];

        int ind = 0;
        int ans = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            ans += profit[i];
            sum += profit[i];
            if(ans<0){
                ans = 0;
                ind = i+1;
            }
        }
        if(sum<0){
            return -1;
        }
        return ind;
    }
};

/**
 *  Create an array profit[i]=gas[i]-cost[i]. Okay, now when will I fail to take a full round around the station ?
 *  Approach
 *  When the profit is negative it means we have spent fuel more than there in tank. 
 *  Similarly a positive profit means that we have still fuel to spend. 
 *  A negative profit will also mean that we cant go to the next station if we start from here. 
 *  So this is obvious that we will start from a positive profit . Okay now here we apply Kadane's Algorithm. 
 *  We add all the profits until we are postive. 
 *  As we become negative, it means we cant move forward. 
 *  So this means the starting point we had choosen was wrong so we will change the starting point to the next postion. \
 *  This way if the starting point becomes equal to n it means we have no good starting point. 
 *  But also the sum of whole profit array must be >=0
 *  Because supposing we start from a index j between 0 to n, and reach to n without getting negative profit. 
 *  We must also check that the profit remaining after that it enough to carry the car from 0 to j index.
 *
 *	Time Complexity : O(N)
 *	Space Complexity : O(1)

 */