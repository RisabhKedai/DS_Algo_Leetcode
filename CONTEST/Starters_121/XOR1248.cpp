/*
* @Author: lenovo
* @Date:   2024-02-18 17:59:56
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-18 18:02:54
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
	for(int t=0; t<test; t++){
	    vector<int> freq(60);
	    int n;
	    cin>>n;
	    vector<long> v(n);
	    for(int i=0; i<n; i++){
	        cin>>v[i];
	    }
	    for(int i=0; i<n; i++){
	        long m=v[i];
	        int pow = 0;
	        while(m){
	            freq[pow] += m%2;
	            pow++;
	            m /= 2;
	        }
	    }
	    bool check = false;
	    long ans=0;
	    for(int i=59; i>0; i--){
	       // cout<<freq[i]<<" ";
	       if(freq[i]&1){
	           //cout<<i<<" ";
	           ans |= 1ll<<i;
	           continue;
	       }
	       if(freq[i]>0 && freq[i]%2==0){
	            check = true;
	       }
	       if(check){
	           //cout<<i<<" ";
   	           ans |= 1ll<<i;
	       }
	    }
	    if(freq[0]&1){
	        ans |= 1;
	    }
	    cout<<ans;
	    cout<<endl;
	    
	}
	return 0;
}
/*
4
3
5 7 7
3
5 5 7
6
0 1 2 4 8 16
5
4 5 9 4 8
*/

/**
 * https://www.codechef.com/viewsolution/1045265361
 * Whenever an even frequency of set bits occur at a position
 * All the positions ahead of it can be changed from even to odd 
 * 2^x = 2^(x-1) + 2^(x-1)
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 */