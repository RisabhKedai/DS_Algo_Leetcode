/*
* @Author: lenovo
* @Date:   2023-11-12 06:42:31
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-12 06:42:31
*/

class Solution:
    def stringCount(self, n: int) -> int:
        MOD = int(1e9) + 7
        
        # all strings of length n (alphabet length is 26)
        res = 26**n
        res %= MOD

        # strings with 0e, 0l, 0t, 1e
        res -= 25**n * 3 + 25**(n-1) * n
        res %= MOD

        # strings with 0e 0l, 0e 0t, 0l 0t, 1e 0l, 1e 0t
        res += 24**n * 3 + 24**(n-1) * 2 * n
        res %= MOD

        # strings with 0e 0l 0t, 1e 0l 0t
        res -= 23**n + 23**(n-1) * n
        res %= MOD
        
        return res


'''
Explanation

"strings with 0e": strings that contain zero letters e
The number of such (of length n) is 25n25^n25n, since we can choose any of the 25 letters (all letters except the letter e) for n places in our string.

"strings with 1e": strings containing one letter e
There are n∗25(n−1)n * 25^{(n-1)}n∗25(n−1) such strings, since we can place the letter e in one of n places in our string, and fill the rest of places with 25 other letters.

"strings with 0e 0l": strings containing zero letters e AND zero letters l
There are 24n24^{n}24n such strings, since we can place any of 24 remaining letters (26 - e - l) in n places.

"strings with 1e 0l": strings containing zero letters e AND zero letters l
Choose one from n places to put e, fill rest with 24 possible letters each, resulting in n∗24(n−1)n * 24^{(n-1)}n∗24(n−1).

"strings with 0e 0l 0t": strings containing zero letters e AND zero letters l
Same logic as above, 23n23^n23n.

"strings with 1e 0l 0t": strings containing zero letters e AND zero letters l
Same logic as above, n∗23(n−1)n * 23^{(n-1)}n∗23(n−1).

Time COmplexity: O(log(N))
Space Complexity : O(1)
'''