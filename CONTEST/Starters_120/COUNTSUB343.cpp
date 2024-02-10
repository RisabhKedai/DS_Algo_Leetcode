/*
* @Author: lenovo
* @Date:   2024-02-10 21:40:10
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-10 21:44:29
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
	for(int t=0; t<test; t++){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    vector<long long> pref(n+1,0);
	    vector<int> ans(n+1,0);
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	        pref[i+1] = arr[i]+pref[i];
	    }
	    for(int i=1; i<n; i++){
	        arr[i] += arr[i-1];
	    }
	    for(int i=0; i<n; i++){
	        int beg = i+1;
	        int end = n;
	        int an = -1;
	        while(beg<=end){
	            int mid = (beg+end)/2;
	            if(pref[mid]-pref[i] <= n){
	                an = mid;
	                beg = mid+1;
	            }else{
	                end = mid-1;
	            }
	        }
	        while(an>i){
	            ans[pref[an]-pref[i]]+=1;
	            an--;
	        }
	    }
	    for(int i=1;i<=n;i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}


/**
 * Use brute force similar approach to find the prefix sum of the array. 
 * For each index determine the maximum index till which the sum of subarray is less than n.
 * Derive the sums below that index to start index.
 * Store this count in the answer array. 
 *
 * The overall time complexity would stay below N*(root N) because the sum will be maximum in case of
 * 1+2..+X <= N
 * X will be equivalent to root N
 *  
 * Time complexity : O(Nroot(N))
 * Space complexity : O(1)
 */