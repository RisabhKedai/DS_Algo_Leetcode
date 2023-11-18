/*
* @Author: lenovo
* @Date:   2023-11-13 22:15:01
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-13 22:16:15
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Transpose 
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //Laterally invert
        for(int i=0; i<n; i++){
            for(int j=0; j< m/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][m-j-1];
                matrix[i][m-j-1] = temp;
            }
        }
    }
};

/**
 * First transpose and then laterallyu invert the image
 *
 * Time Complexity : O(M*N)
 * Space Complexity : O(1)
 */