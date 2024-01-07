/*
* @Author: lenovo
* @Date:   2024-01-07 20:24:50
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-07 20:26:19
*/

class Solution {
public:
    unordered_map<long long, int> cache;
    string s;
    int k;

    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        this->k = k;
        // 1 extra because the dp code returns 0 for when the string is over. 
        return dp(0,0,true) + 1;
    }

    int dp(long long index, long long currSet, bool canChange) {
        // Since all of these are integers we can combine them in a single key
        // first x bits are for index
        // next 26 are for character set 
        // last bit for canchange
        long long key  = (index<<27) | (currSet<<1) | canChange;
        if(cache.count(key)){
            return cache[key];
        }

        if(index == s.size()){
            return 0;
        }

        int charIndex = s[index] - 'a';
        int updatedCurrSet = currSet | (1<<charIndex);
        int distinctCount = __builtin_popcount(updatedCurrSet);
        
        int res;
        if(distinctCount > k){
            // start a new set with the current character marked 
            res = (1 + dp(index+1,1<<charIndex,canChange));
        }else{
            res = dp(index+1,updatedCurrSet,canChange);
        }
        if(canChange){
            // if possible to change the letter then iterate trough all the possible alphabets and check replacing each of them
            for(int newCharIndex = 0; newCharIndex<26; newCharIndex++){
                int newCharSet = currSet | (1<<newCharIndex);
                int newDistinct = __builtin_popcount(newCharSet);
                if(newDistinct > k){
                    res = max(res,1 + dp(index+1, (1<<newCharIndex), false));
                }else{
                    res = max(res,dp(index+1, newCharSet, false));
                }
            }
        }
        return cache[key] = res;
    }
};

/**
 * Reference Link : https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/solutions/4520834/c-java-python-clean-bitset-dp/
 *
 * Time Complexity ; O(N^2)
 * Space Complexity : O(N)
 */