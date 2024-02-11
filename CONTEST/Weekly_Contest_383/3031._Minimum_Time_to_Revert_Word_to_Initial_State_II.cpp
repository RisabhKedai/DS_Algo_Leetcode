/*
* @Author: lenovo
* @Date:   2024-02-11 12:37:43
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-11 13:32:10
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
    int minimumTimeToInitialState(string word, int k) {
        vector<int> z = zFunction(word);
        // for(auto x: z){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        int n = word.length();
        int ans=1;
        while((k*ans)<n && (n-(k*ans))>z[(k*ans)]){
            ans+=1;
        }
        return ans;
    }
};

/**
 * Z function for a given word returns an array computed on the given word,
 * such that, z[i] for a given index i is the length of the longest substring starting at position i,
 * which is a prefix of the original word
 *
 * After calculating the z function. Find the first index such that the len of remaining portion of 
 * string from i is equal to z[i]. Meaning that the remaining portion is all a prefix of the word 
 * and we can skip it. 
 * Remember we need to remove k letters each time so we need to check this at k intervals each time.
 *
 * Time complexity : O(N)
 * Space complexity : O(N) 
 */