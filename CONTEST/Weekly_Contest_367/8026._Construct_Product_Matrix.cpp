class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> less(n,vector<int>(m,1));
        vector<vector<int>> more(n,vector<int>(m,1));
        vector<vector<int>> ans(n,vector<int>(m,1));
        
        int curr_r = -1;
        int curr_c = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(curr_r==-1){
                    less[i][j] = grid[i][j] * 1; 
                }else{
                    less[i][j] *= grid[i][j];
                    less[i][j] %= 12345;
                    less[i][j] *= less[curr_r][curr_c];
                    less[i][j] %= 12345;
                }
                curr_r = i;
                curr_c = j;
                less[i][j] %= 12345;
            }
        }
        curr_r = -1;
        curr_c = -1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(curr_r==-1){
                    more[i][j] = grid[i][j] * 1; 
                }else{
                    more[i][j] *= grid[i][j];
                    more[i][j] %= 12345;
                    more[i][j] *= more[curr_r][curr_c];
                    more[i][j] %= 12345;
                }
                curr_r = i;
                curr_c = j;
                more[i][j] %= 12345;
            }
        }
        curr_r = -1;
        curr_c = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int nextc = j+1;
                int nextr = i;
                if(nextc%m==0){
                    nextr++;
                    nextc = 0;
                }
                if(curr_r!=-1)
                ans[i][j] *= less[curr_r][curr_c];
                ans[i][j] %= 12345;
                if(!(i==n-1 && j==m-1))
                ans[i][j] *= more[nextr][nextc];
                ans[i][j] %= 12345;
                curr_r = i;
                curr_c = j;
                
            }
        }
        return ans;
    }
};

/**
 * We can compute 2 m x n matrices less and greater such that
 * less[j][k] = product of elements in grid before [j,k], and 
 * greater[j][k] = product of elements in grid after [j,k]. 
 * Here "before" and "after" refers to the standard row major ordering of the elements in a 2d array.
 * Then just compute ans[j][k] = less[j][k] * greater[j][k]
 * Take everything mod 12345 to avoid integer overflow.
 */