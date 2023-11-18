/*
* @Author: lenovo
* @Date:   2023-11-17 00:32:07
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-17 00:33:00
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int dx[] = {0,1,0,-1};
       int dy[] = {1,0,-1,0};
       int n = matrix.size();
       int m = matrix[0].size();
       int k = 0;
       int i=0, j=0;
       vector<int> ans;
       while(0<=i && i<n && 0<=j && j<m && matrix[i][j] != -200){
           ans.push_back(matrix[i][j]);
           matrix[i][j] = -200;
           int dr = dx[k];
           int dc = dy[k];
           if(0<=i+dr && i+dr<n && 0<=j+dc && j+dc<m && matrix[i+dr][j+dc]!=-200){
               i += dr;
               j += dc;
               continue;
           }
           k += 1;
           k %= 4;
           dr = dx[k];
           dc = dy[k];
           i += dr;
           j += dc;
       }  
       return ans;
    }
};

/**
 * Simple and self exploratory.
 * Time Complexity: O(N*M)
 * Space Complexity: O(1)
 */