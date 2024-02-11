/*
* @Author: lenovo
* @Date:   2024-02-11 16:44:07
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-11 16:45:03
*/

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> freq(123,0);
        vector<int> lens;
        int pairs = 0;
        int ans = 0;
        for(auto s : words){
            for(auto a: s){
                freq[a]+=1;
            }
            lens.push_back(s.length());
        }
        for(auto f : freq){
            if(f>0){
                pairs += f/2;
            }
        }
        sort(lens.begin(),lens.end());
        for(auto z: lens){
            pairs -= z/2;
            ans += pairs>=0;
        }
        return ans;
    }
};

/**
 * We count all characters in all words.
 * If we have two of the same character, we have a pair.
 * If we have n pairs, we can make a palindrome of size 2 * n, or 2 * n + 1.
 * To make as many palindromes as possible, we sort our words by size (shortest to longest).
 * Then, we count how many palindromes we can make before we run out of pairs.
 * It actually does not matter if the string size is even or odd. After we finish making palindromes, we can use remaning chars to fit the middle of odd strings.
 * We will always have enough remainign chars, as the total number of chars does not change.
 *
 * Time complexity : O(N)
 * Space complexity : O(N)
 */