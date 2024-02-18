/*
* @Author: lenovo
* @Date:   2024-02-18 12:31:35
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-18 12:34:43
*/

class Solution {
public:
    vector<int> zFunction(string& s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n);
        for(int i = 1; i < n; i++) {
            if(i < r)
                z[i] = min(r - i, z[i - l]);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        long long ans=0;
        unordered_map<string,int> freq;
        set<int> count;
        for(auto &word : words){
            vector<int> zf = zFunction(word);
            zf[0] = word.length();
            string temp = "";
            for(int j=0; j<word.length(); j++){
                temp += word[j];
                if(zf[word.length()-j-1] == j+1 && count.find(temp.length())!=count.end()){
                    ans += freq[temp];
                }
            }
            freq[word]++;
            count.insert(word.size());
        }
        return ans;
    }
};

/**
 * Maintain a map for each words frequency, and a set of counts as a double check
 * Use z function to find all the prefixes for a given string that are also suffix. 
 * In case such a word is present : count array must have that lengthed word.
 * Then add the frequency to the answer.
 * N = size of array
 * M = size of word
 * 
 * Time complexity : O(N*M)
 * Space complexity : O(N+M)
 */