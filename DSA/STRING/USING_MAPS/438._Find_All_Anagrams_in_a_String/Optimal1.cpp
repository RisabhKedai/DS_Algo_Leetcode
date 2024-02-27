/*
* @Author: lenovo
* @Date:   2024-02-27 06:20:42
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-27 06:21:48
*/

class Solution {
public:
    bool check(map<char,int> mp, map<char,int> mp2){
        for(auto x: mp){
            int k = x.first;
            if(mp[k]!=mp2[k]){
                return false;
            }
        }
        for(auto x: mp2){
            int k = x.first;
            if(mp[k]!=mp2[k]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mp;
        vector<int> ans;
        for(int i=0; i<p.length(); i++){
            mp[p[i]]+=1;
        }
        map<char,int> mp2;
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
 * Sliding window to check whether frequency of window matches p.
 *
 * Time complexity : O(n)
 * Space complexity : O(1)
 */