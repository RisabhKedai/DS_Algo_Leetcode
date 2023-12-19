/*
* @Author: lenovo
* @Date:   2023-12-20 00:00:38
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-20 00:02:47
*/

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n, greater<int>());
        int ans = arr[0]-arr[n-1];
        for(int i=0; i<n-1; i++){
            if(arr[i]<k){
                continue;
            }
            int maxi = arr[0]-k;
            int mini = arr[i]-k;
            int maxd = arr[i+1]+k;
            int mind = arr[n-1]+k;
            ans = min(ans,max(maxd,maxi)-min(mind,mini));
        }
        return ans;
    }
};

/**
 * Follow the steps below to solve the given problem:
 * - Sort the array 
 * - Try to make each height of the tower maximum by decreasing the height of all the towers to the right by k and increasing all the height of the towers to the left by k. Check whether the current index tower has the maximum height or not by comparing it with a[n]-k. If the tower’s height is greater than the a[n]-k then it’s the tallest tower available.
 * - Similarly, find the shortest tower and minimize the difference between these two towers.  
 *  Handle the case when arr[i]-k<0 because the height can't be negative
 *  
 * Time Complexity : O(n)
 * Space Complexity : O(nlog(n))
 */