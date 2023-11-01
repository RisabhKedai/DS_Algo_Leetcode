/*
* @Author: lenovo
* @Date:   2023-11-01 12:41:13
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-01 12:51:10
*/
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        int j = 0;
        int cnt = 1;
        int ma = 1;
        int i=1;
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                cnt ++;
                i++;
            }else{
                j++;
                cnt--;
            }
         ma = max(ma,cnt);
        }
        return ma;
    }
};


/**
 * Reference link : https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
 *
 * Sort both arrival and departure time arrays in ascending order.
 * The mapping of arrival time to departure doesn't matter here 
 * is because we just only want the platforms to get vacant and occupied.
 *
 * And anyways arrival time is always smaller than departure time
 * hence if array has departure time at a certain index, means corresponding arrival time 
 * will occur before that index only. 
 * But since we want the first vacant platform, the departure array has to be sorted. 
 *
 * Next create 2 pointers i  and j. j points to the departure times. i denotes arrival times.
 * If arrival time is greater than the departure time, the total number of occupied platforms (stored in cnt) can be reduced
 * Also move to the next dpearture time. 
 * Else if the timing is clashing then increase the count of occupied platforms. 
 *
 * At each stage track the maximum number of occupied platforms. 
 * 
 * Time Complexity : O(NlogN)
 * Space Complexity : O(1)
 */