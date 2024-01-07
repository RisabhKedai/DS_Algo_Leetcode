/*
* @Author: lenovo
* @Date:   2024-01-07 11:11:05
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-07 11:12:39
*/
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> vis;
        queue<pair<int, int>> q;
        q.push({x, 0});
        vis.insert(x);
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            int num = curr.first, turn = curr.second;
            if (num == y)
                return turn;
            if (vis.find(num + 1) == vis.end())
            {
                q.push({num + 1, turn + 1});
                vis.insert(num + 1);
            }
            if (vis.find(num - 1) == vis.end() && num - 1 >= 0)
            {
                q.push({num - 1, turn + 1});
                vis.insert(num - 1);
            }
            if (num % 11 == 0 && vis.find(num / 11) == vis.end())
            {
                q.push({num / 11, turn + 1});
                vis.insert(num / 11);
            }
            if (num % 5 == 0 && vis.find(num / 5) == vis.end())
            {
                q.push({num / 5, turn + 1});
                vis.insert(num / 5);
            }
        }
        return -1;
    }
};

/**
 * Intuition
 * Since we need to find minimum number of attempts, we can do BFS as it will store the minimum attempts to reach a particular value
 * 
 * Approach
 * Make a queue of pair of integers to store a particular value and the turns it takes, also initialize a hashSet to keep a record of previously visited values, and just perform BFS.
 * 
 * Similar Problems
 * https://leetcode.com/problems/minimum-operations-to-convert-number/description/
 * 
 * Striver's Video for explanation of this approach
 * https://www.youtube.com/watch?v=_BvEJ3VIDWw&ab_channel=takeUforward
 *
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */