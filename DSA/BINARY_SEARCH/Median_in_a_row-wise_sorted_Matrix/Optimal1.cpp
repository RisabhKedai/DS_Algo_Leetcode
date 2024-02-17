/*
* @Author: lenovo
* @Date:   2024-02-17 08:12:44
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-17 08:15:35
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int beg = matrix[0][0];
        int end = matrix[R-1][C-1];
        for(int i=0;i<R;i++){
            beg = min(beg, matrix[i][0]);
            end = max(end, matrix[i][C-1]);
        }
        while(beg<end){
            int mid = (beg+end)/2;
            int ttl = 0;
            for(int i=0; i<R; i++){
                ttl += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            }
            if(ttl<((R*C) + 1)/2){
                beg = mid+1;
            }else{
                end = mid;
            }
        }
        return beg;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends

/**
 * Intuition
 * =========
 * The idea is that for a number to be median there should be exactly (n/2) numbers that are less than this number. 
 * So, we try to find the count of numbers less than the selected number. We select the number by using binary search.
 * 
 * Implementation
 * ==============
 * Step 1: find the minimum and maximum present in the matrix, which will be used as range of binary search.
 * Step 2: run a loop while min num is less than max num inside the loop
 * Step 3: find mid position, mid = min num + (max num – min num) / 2;
 * Step 4: now for each row, count how many numbers are less than mid,
 * Step 5: if count is less than half of the number update min num = mid +1 else max num = mid loop end return min.
 *
 * Time complexity : O(32*r*log(c))
 * Space complexity : O(1)
 */