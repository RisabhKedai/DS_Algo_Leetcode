/*
* @Author: lenovo
* @Date:   2023-11-26 14:20:28
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-26 14:22:36
*/
class Solution {
public:
    bool vowel(char a) {
        return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
    }
    long long beautifulSubstrings(string s, int k) {
        int l;
        int v = 0;
        int n = s.length();
        for(l=1; (l*l)%(k*4); l++);

        vector<unordered_map<int,int>> seen(l+1);
        seen[0][0] = 1;
        long long res = 0;
    
        for(int i=0; i<n; i++){
            v += vowel(s[i])?1:-1;
            res += seen[(i+1)%l][v];
            seen[(i+1)%l][v]+=1;
        }
        return res;
    }
};

/**
 * Need to know
 * If we only have the condition vowels == consonants,
 * we can count the difference between vowels and consonants in prefix substring,
 * and count the count in a hashmap,
 * to find out the number of substring with diff 0.

 * Explanation
 * In this problem, we have one more constrain of
 * (vowels * consonants) % k == 0.
 * Assume the length is l and vowels == consonants
 * so (l / 2) * (l / 2) k == 0
 * so l * l % (k * 4) == 0.
 * We only need to find out the smallest l satifying the above equation,
 * and only need to consider the substring with length l, 2l, 3l ...
 * In additional to the solution in "need to know" section,
 * we count the index in bucket with different modulos of l.
 *
 * Time Complexity : O(N)
 * Space Complexity: O(n*l)
 */