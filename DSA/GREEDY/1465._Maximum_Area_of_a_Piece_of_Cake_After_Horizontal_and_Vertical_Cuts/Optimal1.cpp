/*
* @Author: lenovo
* @Date:   2024-01-01 20:50:52
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-01 20:54:55
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxh = 0;
        int maxw = 0;
        for(int i=0; i<horizontalCuts.size()-1; i++){
            maxh = max(maxh, horizontalCuts[i+1] - horizontalCuts[i]);
        }

        for(int i=0; i<verticalCuts.size()-1; i++){
            maxw = max(maxw, verticalCuts[i+1] - verticalCuts[i]);
        }
        int mod = 1e9+7;
        return ((long long)maxh*maxw)%mod;
    }
};

/**
 * For the cut area to be maximum the uncut length and uncut width should be maximum.
 * For that sort both the given arrays and take consecutive differences to find the maximum difference in width and height
 * Dont forget to add the by default cuts (borders of the cake)
 *
 * Time complexity : O(max(H,W)log(max(H,W)))
 * Space Complexity :O(1)
 */