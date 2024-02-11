/*
* @Author: lenovo
* @Date:   2024-02-06 20:53:01
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-11 16:24:35
*/


class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int res= 0;
        for(int i=0; i<n; i++){
            points[i][1] *= -1;
        }
        sort(points.begin(), points.end());
        for(int i=0; i<n; i++){
            int y = INT_MIN;
            int x1 = points[i][0];
            int y1 = -1*points[i][1];
            for(int j=i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = -1*points[j][1];
                if(y2<=y1 && y2>y){
                    y = y2;
                    res += 1;
                }
            }
        }
        return res;
    }
};

/**
 * With 1000 points, a quadratic solution would do. We just need an efficient way to check for points in between.
 * First, we sort our points by x.
 * 
 * For each point x1, y1, we consider points x2, y2 on the rigth with y1 >= y2.
 * Note that x1 <= x2 because points are sorted.
 * We track the largest y so far, and if y < y2, Chisato and Takina are alone.
 *
 * Time complexity : O(N^2)
 * Space complexity : O(1)
 */