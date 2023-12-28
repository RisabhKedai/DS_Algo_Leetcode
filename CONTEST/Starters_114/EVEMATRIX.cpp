/*
* @Author: lenovo
* @Date:   2023-12-28 23:28:06
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-28 23:32:02
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
	for(int t=0; t<test; t++){
	    int n;
	    cin>>n;
        vector<vector<int>> mat(n,vector<int>(n,-1));
	    int r = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mat[i][j] = r++;
            }
        }
	    if(n==2){
	        cout<<-1<<endl;
	    }else if(n>=3){
	        swap(mat[1][1],mat[1][2]);
	        swap(mat[2][0],mat[2][1]);
	        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
	    }else{
	        cout<<1<<endl;
	    }
        
	}
	return 0;
}


/**
* Test cases :
7
1
3
5
2
3
4
6
*/


/**
 * Observation
 * Fill the matrices as 1,2,3,4 ... i.e if n = 1 matrix is [1] if n = 2, matrix is 1 2, 3 4 if n = 3 matrix is 1 2 3, 4 5 6, 7 8 9 now do it till n = 6 to observe a pattern in all the boundary sum of different matrices. You will notice 3 things:
 * 
 * Boundary sum for matrix of submatrix 1,1 is always odd i.e = 1
 * Boundary sum of all other matrices is always even.
 * No matter what you do. if n = 2 you can't satisfy the boundary sum for all submatrices to be odd. ( This is the only case for -1)
 * 
 * Approach
 * Now based on the above approach whenever n>2. 
 * we just need to disturb the current boundary sum of submatrix of size 2,2. 
 * For that we will swap the cornermost element of 2,2 submatrix (arr[1][1]) with the right adjacent(arr[1][2]) 
 * as a result now submatrices 2,2 and 3,3 now satisfy the rule.
 * 
 * Now we need to make submatrices of size>3 follow the rule. 
 * Now look closely and find the common element used in boundary sum of size>3. 
 * You will find the elements as [0,0] [0,1],[0,2],[1,0],[2,0]. 
 * Now we need to again swap one of these in such a way that the rule for n = 1,2,3 doesn't violate. 
 * if we decide to swap arr[2][0] with arr[2][1]. submatrix 3,2,1 will follow the rule and 
 * as we change a common element all the submatrices with size>3 will also follow the rule.
 *
 * Time Complexity: O(N*N)
 */