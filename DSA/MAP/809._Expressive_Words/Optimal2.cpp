/*
* @Author: lenovo
* @Date:   2024-01-12 23:56:01
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-13 00:16:50
*/


class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (auto &W : words) if (check(S, W)) res++;
        return res;
    }

    bool check(string S, string W) {
        int n = S.size(), m = W.size(), j = 0;
        for (int i = 0; i < n; i++)
            if (j < m && S[i] == W[j]) j++;
            else if (i > 1 && S[i - 2] == S[i - 1] && S[i - 1] == S[i]);
            else if (0 < i && i < n - 1 && S[i - 1] == S[i] && S[i] == S[i + 1]);
            else return false;
        return j == m;
    }
};

/**
 * Maintain 2 pointers each for the 2 strings and compare them.
 * When j pointer has crossed one zone check if i pointer is still continuing
 * But when i transitions the j pointer should again become equal and progress
 *
 * Time complexity :O(N)
 * Space complexity : O(1)
 */