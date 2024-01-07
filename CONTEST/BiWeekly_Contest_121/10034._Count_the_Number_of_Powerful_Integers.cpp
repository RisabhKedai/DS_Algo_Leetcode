/*
* @Author: lenovo
* @Date:   2024-01-07 21:20:04
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-07 21:21:44
*/


class Solution {
public:
    long long cnt[16] = {};
long long dfs(int i, char limit, const string &n, const string &s) {
    if (n.size() < s.size())
        return 0;
    if (i == n.size() - s.size())
        return n.substr(i) >= s;
    int digits = min(limit, n[i]) - '1' + (i > 0);
    return cnt[n.size() - i - 1] * digits +
        (n[i] < limit ? dfs(i + 1, limit, n, s) : 0);
}
long long numberOfPowerfulInt(long long start, long long finish, int limit, const string &s) {
    string hi = to_string(finish), lo = to_string(start - 1);
    for (int i = s.size(); i < hi.size(); ++i)
        cnt[i] = i == s.size() ? 1 : cnt[i - 1] * (limit + 1);
    return cnt[hi.size() - 1] + dfs(0, '1' + limit, hi, s) 
        - (cnt[lo.size() - 1] + dfs(0, '1' + limit, lo, s));
}
};

/**
 * We solve this problem independently for finish and start - 1, and subtract the results.
 * Let n be a string representation of the right side of the range (either finish or start - 1).
 * For strings with length [len(s), len(n) - 1], we can pre-compute the number of powerful integers:
    cnt[0 + len(s)]: 1
    cnt[1 + len(s)]: (limit + 1) * cnt[0 + len(s)]
    cnt[2 + len(s)]: (limit + 1) * cnt[1 + len(s)].
    ...
    cnt[x + len(s)]: (limit + 1) * cnt[x - 1 + len(s)].

 * So, cnt[i] is the number of powerful integers with lengths in range [len(s), i].
 * Now, for strings with length len(n), we need to make sure that powerful integers do not exceed n.
 * 
 * To do that we can use DFS:
 * 
 * See also an iterative solution below.
 * We count how many digits we can use before hitting limit or n[i].
 * We add cnt[len(n) - i - 1] * digits
 * Note that we can also use 0 if i > 0.
 * If n[i] < limit, we continue with dfs(i + 1).
 * 
 * Complexity Analysis
 * Time complexity : O(log n)
 * Space complexity: O(log n)
 */