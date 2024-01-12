/*
* @Author: lenovo
* @Date:   2024-01-12 23:54:22
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-12 23:55:38
*/

class Solution {
public:
    vector<pair<char,int>> mapper(string s){
        vector<pair<char,int>> mp;
        int mps = 1;
        mp.push_back({s[0],1});
        for(int i=1; i<s.length(); i++){
            if(s[i] == mp[mps-1].first){
                mp[mps-1].second++;
            }else{
                mps++;
                mp.push_back({s[i],1});
            }
        }
        return mp;
    }
    bool check(vector<pair<char,int>> s1, vector<pair<char,int>> s2){
        if(s1.size()!=s2.size()){
            return false;
        }
        int n = s2.size();
        for(int i=0; i<n; i++){
            char c2 = s2[i].first;
            int s2c = s2[i].second;
            char c1 = s1[i].first;
            int s1c = s1[i].second;
            if(c1!=c2 || s1c>s2c || (s2c!=s1c && s2c<3)){
                return false;
            }
        }
        return true;
    }
    int expressiveWords(string s, vector<string>& words) {
        int cnt = 0;
        for(auto word: words) {
            cnt += check(mapper(word), mapper(s));
        }
        return cnt;
    }
};

/**
 * Make a map and match the letters in sequence of their occurance.
 * Time complexity : O(N)
 * Space complexity : O(N)
 */