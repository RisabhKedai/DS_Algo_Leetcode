/*
* @Author: lenovo
* @Date:   2023-10-24 21:34:29
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-24 22:15:56
*/

/*================================ QUESTION =======================================
Given a sorted integer array nums, where the range of elements are in the inclusive
 range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
=================================================================================*/

#include<bits/stdc++.h>
using namespace std;

vector<string> findMissingRanges(vector<int> arr, int lower, int upper) {
    vector<pair<int,int>> vp; 
    int next = 0;
    while(next<arr.size()){
        if(lower<arr[next]){
            vp.push_back({lower,min(arr[next]-1,upper-1)});
        }
        lower = arr[next]+1;
        next++;
    }
    if(lower <= upper){
        vp.push_back({lower,upper});
    }
    vector<string> ans;
    for(auto x: vp){
        if(x.first!=x.second)
        ans.push_back(to_string(x.first)+ "->" + to_string(x.second));
        else
            ans.push_back(to_string(x.first));
    }
    return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int lower,upper;
	cin>>lower>>upper;
	 vector<string> ans = findMissingRanges(arr,lower,upper);
    for(auto x: ans){
        cout<<x<<" ";
    }
	return 0;
}

/**
 * The variable lower keeps mark of the lower element in the pairs of ranges
 * It is checked id lower < current numer in the array denoted by arr[next]
 * Then only add the range {lower -> arr[next]-1}.
 *
 * lower is moved to arr[next]+1 and next is increased.
 * Loop is continued till we reach the last element of the array
 *
 * After we finished the above loop, we need to double check the final next value.
 * If next ≤ upper, we still have a missing range [next, upper] to add.
 */