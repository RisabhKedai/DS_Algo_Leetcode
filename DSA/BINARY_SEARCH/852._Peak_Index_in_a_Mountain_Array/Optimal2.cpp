/*
* @Author: lenovo
* @Date:   2024-02-01 22:20:31
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-03 10:09:17
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        int beg = 0, end = n-1;
        int x2 = beg + round((end-beg)*0.618);
        int x1 = beg + round((end-beg)*0.382);
        cout<<x1<<" "<<x2<<endl;
        while(x1<x2){
            cout<<beg<<" "<<end<<endl;
            if(arr[x1]>arr[x2]){
                end = x2;
                x2 = x1; 
                x1 = beg + round((end-beg)*0.382);
            }else{
                beg = x1;
                x1 = x2;
                x2 = beg + round((end-beg)*0.618);
            }
        }
        int a=beg;
        int c=end;
        int ans =a;
        for(int i=a;i<=c;i++){
            if(arr[ans]<arr[i]){
                ans =i;
            }
        }
        return ans;
    }
};


/**
 * ReferenceLink:
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/solutions/139848/c-java-python-better-than-binary-search
 * https://medium.datadriveninvestor.com/golden-section-search-method-peak-index-in-a-mountain-array-leetcode-852-a00f53ed4076
 * Use golden search algorithm to rediuce the search space
 * Time Complexity : O(logN)
 * Space Complexity: O(1)
 */