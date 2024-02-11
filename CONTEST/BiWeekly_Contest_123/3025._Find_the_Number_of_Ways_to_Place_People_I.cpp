/*
* @Author: lenovo
* @Date:   2024-02-06 20:52:49
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-06 20:54:00
*/

class Solution {
public:
    
    bool checkPossible(int tl, int br, vector<vector<int>>& points){
        int n=points.size();
        int minx = points[tl][0];
        int miny = points[br][1];
        int maxx = points[br][0];
        int maxy = points[tl][1];
        for(int i=0; i<n; i++){
            if(i==tl || i==br){
                continue;
            }
            vector<int> point = points[i];
            if((minx<=point[0] && point[0]<=maxx) && (miny<=point[1] && point[1]<=maxy))
                return false;
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                vector<int> p1 = points[i];
                vector<int> p2 = points[j];
                if(p1[0]<=p2[0] && p1[1]>=p2[1]){
                    cnt += checkPossible(i,j,points);
                }else if(p2[0]<=p1[0] && p2[1]>=p1[1]){
                    cnt += checkPossible(j,i,points);
                }else{
                    continue;
                }
            }
        }
        return cnt;
    }
};

/**
 * Brute force
 *
 * Time complexity : O(n^3)
 * Space complexity : O(1)
 */