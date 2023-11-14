/*
* @Author: lenovo
* @Date:   2023-11-14 20:05:44
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-14 20:07:30
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int c = m-1;
        int r = 0;
        while(r<n && c>=0){
            if(matrix[r][c]== target){
                return true;
            }
            if(matrix[r][c]>target)
            c--;
            else
            r++;
        }
        return false;
    }
};

/**
 * Start from the top right of the matrix. 
 * If the element is less than the targe shift to bottom row as that would increase the value.
 * If element is more then shift to left (column - 1) because that would reduce the value. 
 * If found return true;
 *
 * Time Complexity : O(N*M)
 * Space Complexity : O(1)
 */