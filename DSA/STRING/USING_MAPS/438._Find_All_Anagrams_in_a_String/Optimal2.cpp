/*
* @Author: lenovo
* @Date:   2024-03-08 04:24:37
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-08 04:25:35
*/


class Solution {
public:
    bool check(vector<int> mp, vector<int> mp2){
        for(int x=0; x<123; x++){
            if(mp[x]!=mp2[x]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(123);
        vector<int> ans;
        for(int i=0; i<p.length(); i++){
            mp[p[i]]+=1;
        }
        vector<int> mp2(123);
        int i=0;
        for(; i<min(s.length(),p.length());i++){
            mp2[s[i]] += 1;
        }
        if(check(mp,mp2)){
            ans.push_back(0);
        }
        while(i<s.length()){
            mp2[s[i]]+=1;
            mp2[s[i-p.length()]]-=1;
            // cout<<i<<" "<<check(mp,mp2)<<endl;
            if(check(mp,mp2)){
                ans.push_back(i-p.length()+1);
            }
            i++;
        }
        return ans;
    }
};

/**
 * The logic is same but insteead of map, a vector is ussed to reduce space complexity.
 *
 * Time complexity : O(n)
 * Space complxity : o(1)
 */