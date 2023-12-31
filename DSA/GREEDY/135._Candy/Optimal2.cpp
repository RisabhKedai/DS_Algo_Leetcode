/*
* @Author: lenovo
* @Date:   2023-12-31 15:54:47
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-31 16:34:00
*/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int tot = 1;
        int vel = 1;
        int dec = 0;
        int peak = 0;
        int current;
        int last = ratings[0];
        for(int i=1; i<n; i++){
            current = ratings[i];
            if(current>last){
                vel += 1;
                tot += vel;
                peak = vel;
                dec = 0;
            }else if(current == last){
                vel = 1;
                tot += vel;
                peak = 0;
                dec = 0;
            }else {
                if(vel>1){
                    vel = 1;
                    tot += vel;
                }else {
                    dec += 1;
                    if(dec+1==peak) dec++;
                    tot += dec+1;
                }
            }
            last = current;
        }
        return tot;
    }
};


/**
 * Reference : https://leetcode.com/problems/candy/solutions/4468623/aimd-o-1-memory-approach/
 * There were 3 vars of interest I decided to keep track of, besides the total of course:
 * - vel is the current AIMD 'velocity' of candies to give out
 * - peak was the last highest vel of candies before decrease started. This way we could keep track of the edge case when we need to give extra candies to the child just before the decrease streak.
 * - dec_streak or 'decrease streak' keeps track of the number of subsequent decreases in rating after the velocity has been 1. For each consecutive decrease, 
 *   an extra candy needs to be given to the previous dec_streak children to follow the problem statement rules.
 *   When dec_streak would equal one less than peak, we increase it once more to cover the edge case.
 *   
 * Following these rules we can see that tot=∑vel+dec_streaktot = \sum{vel+dec\_streak}tot=∑vel+dec_streak, 
 * and we use this equation to increment tot and return to correct answer.
 *   
 * Time complexity: O(n)
 * Space complexity: O(1)
 */