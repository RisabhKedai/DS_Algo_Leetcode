/*
* @Author: lenovo
* @Date:   2023-12-31 15:51:14
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-31 15:54:37
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n,1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1] && ans[i]<=ans[i-1]){
                ans[i] = ans[i-1]+1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1] && ans[i]<=ans[i+1]){
                ans[i] = ans[i+1]+1;
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};

/** 
 * Initially all the children have one candy and then after traversal from 
 * left to right, each time one child has higher rating than previous child 
 * and has same candies he is assigned one more than him 
 *
 * Then we traverse right to left and each time has higher rating but less
 * number of candies we assign one more than the right child
 *
 * Finally return the sum of all the candies. 
 *
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */