/*
* @Author: lenovo
* @Date:   2023-12-28 23:23:20
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-28 23:26:02
*/

#include <bits/stdc++.h>
using namespace std;

bool nond(vector<int>& a){
    int f = a[0];
    for(int i=0; i<a.size(); i++){
        if(a[i]<f){
            return false;
        }
        f = a[i];
    }
    return true;
}

int findNext(int prev, vector<int>& arr, int ind){
    int beg = ind + 1;
    int end = arr.size()-1;
    int ans = -1;
    while(beg<=end) {
        int mid = (beg+end)/2;
        if(arr[mid]>=prev){
            end = mid-1;
            ans = mid;
        }else{
            beg = mid+1;
        }
    }
    return ans;
}

int main() {
    int test;
    cin>>test;
	for(int t=0; t<test; t++){
	    int n;
	    cin>>n; 
	    vector<int> a(n);
	    vector<int> cola(n);
	    map<int,vector<int>> elements;
	    map<int,bool> inb;
	    map<int, int> lind;
	    vector<int> b(n);
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	    }
	    for(int i=0; i<n; i++){
	        int x;
	        cin>>x;
	        cola[i] = x;
	        elements[x].push_back(a[i]);
	    }
	    for(int i=0; i<n; i++){
	        cin>>b[i];
	    }
	    
	    for(int i=0; i<n; i++){
	        int x;
	        cin>>x;
	        elements[x].push_back(b[i]);
	        inb[x] = true;
	    }
	    for(auto x: elements){
	        int col = x.first;
	        lind[col] = -1;
	        if(inb[col])
	        sort(elements[col].begin(), elements[col].end());
	    }
	    int prev = -1;
	    for(int i=0; i<n; i++) {
	        if(inb[cola[i]]){
	            int indexInElements = findNext(prev,elements[cola[i]],lind[cola[i]]);
	            if(indexInElements==-1){
	                a[i] = -1;
        	        lind[cola[i]] = elements[cola[i]].size();
	            }else{
        	        a[i] = elements[cola[i]][indexInElements];
        	        lind[cola[i]] = indexInElements;
	            }
	        }else{
	        	a[i] = elements[cola[i]][++lind[cola[i]]];
	        }
	        prev = a[i];
	    }
	    if(nond(a)){
	        cout<<"Yes\n";
	    }else{
	        cout<<"No\n";
	    }
	}
	return 0;
}


/**
 * Consider a fixed index $i$.
 * - If $c_A[i]$ doesn’t appear in $c_B$ at all, the value at this index can’t be swapped using our operation, and is fixed.
 * - If $c_A[i]$ does appear in $c_B$, this color is ‘free’ - all the values at any index with this color can be freely moved around between indices.
 * 
 * Using this observation, let’s try to build a sorted array out of $A$.
 * Let’s go from left to right, i.e, iterate index $i$ from $1$ to $N$.
 * When at index $i$, our aim is to place something there that’s $\geq A_{i-1}$ (for convenience, assume $A_0 = 0$).
 * 
 * For that,
 * If $A_i$ is a ‘fixed’ index as described above, we have no choice and can’t change it
 * 
 * - So, if $A_i \lt A_{i-1}$, the array can’t be sorted.
 * - Otherwise, recall that we can freely choose $A_i$ to be any value that has the same color as $c_A[i]$
 * We want something that’s $\geq A_{i-1}$ of course, but it’s also easy to see that we don’t want it to be too large, for that will make it harder for future elements to be sorted.
 * 
 * So, the optimal strategy is to choose the smallest value that’s $\geq A_{i-1}$.
 * Of course, if such a value doesn’t exist, the array can’t be sorted.
 * 
 * The only slow part here is finding the smallest value that’s $\geq A_{i-1}$.
 * To speed this up, store a sorted list of values corresponding to each color.
 * Then, finding the appropriate element can be done quickly with a simple binary search.
 * You also need to delete the chosen element so it can’t be used again; so the appropriate data structure is a multiset.
 * 
 * It’s also possible to implement this without a multiset or binary search, by maintaining pointers for each list corresponding to the last used element and incrementing them as required.
 *
 * Time Complexity : O(NlogN)
 */