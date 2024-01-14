/*
* @Author: lenovo
* @Date:   2024-01-14 18:11:02
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-14 20:25:28
*/


class Solution {
private:
	vector<int> computeLPS(string x) {
		vector<int> lps(x.length());
		int ind = 1;
		int len = 0;
		if(x.length() == 0){
			return lps;
		}
		lps[0] = 0;
		while(ind < x.length()){
			if(x[ind] == x[len]){
				lps[ind] = len + 1;
                len++;
				ind++;
			}else{
				if(len == 0){
					lps[ind] = 0;
					ind++;
				}else{
					len = lps[len-1];
				}
			}
		}
		return lps;
	}
	
	vector<int> KMPSearch(string s, string a){
		vector<int> lps = computeLPS(a);
        // for(auto x : lps){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
		vector<int> ans;
		int i = 0;
		int j = 0;
		while(i<s.length()){
			if(s[i] == a[j]){
				i++;
				j++;
				if(j==a.length()){
					ans.push_back(i-j);
					j = 0;
					continue;
				}
			} else {
				if(j==0){
					i++;
				}else{
					j = lps[j-1];
				}
			}
		}
		return ans;
	}

	int binary(vector<int>& b, int x){
        int beg = 0, end=b.size()-1;
        int ans = -1;
        while(beg<=end){
            int mid = (beg+end)/2;
            if(b[mid] <= x){
                ans = mid;
                beg = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }

public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
		vector<int> a_ind = KMPSearch(s,a);
        vector<int> b_ind = KMPSearch(s,b);
        vector<int> ans;
        // for(auto x : a_ind){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x : b_ind){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(auto x : a_ind){
            int blower = binary(b_ind,x);
            int bupper = lower_bound(b_ind.begin(),b_ind.end(),x) - b_ind.begin();
            if((blower>=0 && x-b_ind[blower]<=k) || (bupper<b_ind.size() && b_ind[bupper]>=x && b_ind[bupper]-x<=k)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};

/**
 * Use KMP algorithm to find all the indices in the parent string
 * which contain the pattern string a, b
 * 
 * Now for each index of a find the b indices that are closest to it. 
 * Find the absolute difference. If it is less than k then add that index to the answer.
 *
 * Time Complexity = O(n + alength + blength) + O(alength* log(blength))
 * Space Complexity = O(n + m)
 */