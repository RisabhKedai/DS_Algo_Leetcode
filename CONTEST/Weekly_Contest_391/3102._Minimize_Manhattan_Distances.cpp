/*
* @Author: lenovo
* @Date:   2024-03-31 16:35:22
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-31 16:39:03
*/

class Solution {
private:
    int manhattan(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    
    pair<int, int> maxManhattanDistance(vector<vector<int>>& points, int remove = -1) {
        int n = points.size();
        int maxSum = INT_MIN, minSum = INT_MAX, maxDiff = INT_MIN, minDiff = INT_MAX;
        int maxSumIndex, minSumIndex, maxDiffIndex, minDiffIndex;
        for (int i = 0; i < n; i++) {
            if (i != remove) {
                int sum = points[i][0] + points[i][1],
                    diff = points[i][0] - points[i][1];
                if (sum > maxSum) {
                    maxSumIndex = i;
                    maxSum = sum;
                }
                if (sum < minSum) {
                    minSumIndex = i;
                    minSum = sum;
                }
                if (diff > maxDiff) {
                    maxDiffIndex = i;
                    maxDiff = diff;
                }
                if (diff < minDiff) {
                    minDiffIndex = i;
                    minDiff = diff;
                }
            }
        }
        return max(maxSum - minSum, maxDiff - minDiff) == maxSum - minSum
            ? make_pair(maxSumIndex, minSumIndex)
            : make_pair(maxDiffIndex, minDiffIndex);
    }
    
public:
    int minimumDistance(vector<vector<int>>& points) {
        auto [mi, mj] = maxManhattanDistance(points);
        auto [mi1, mj1] = maxManhattanDistance(points, mi); // remove mi
        auto [mi2, mj2] = maxManhattanDistance(points, mj); // remove mj
        return min(
            manhattan(points, mi1, mj1),
            manhattan(points, mi2, mj2)
        );
    }
};

/**
 * Explanation : 
 * https://leetcode.com/problems/minimize-manhattan-distances/solutions/4949614/c-java-python-sums-and-differences-time-o-n-space-o-1/
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 */