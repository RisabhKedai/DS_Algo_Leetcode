/*
* @Author: lenovo
* @Date:   2024-01-14 20:27:26
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-14 23:05:55
*/


class Solution {
public:
    int countBits(long long num){
        // cout<<num<<endl;
        int cnt = 0;
        while(num){
            cnt++;
            num /= 2;
        }
        return cnt;
    }
    long long calc(long long num, int x) {
        long long price = 0;
        // cout<<num<<" "<<countBits(num)<<endl;
        for(long long i=1; i<=countBits(num); i++){
            if(i%x != 0)
                continue;
            long long numModTwoTimesI = num % (1LL<<(i));
            price += (num - numModTwoTimesI) / 2LL;
            price += max(0LL, numModTwoTimesI - (1LL<<(i-1)));
            // cout<<num<<" "<<i<<" "<<price<<endl;
        }
        // cout<<num<<" "<<price<<endl;
        return price;
    }
    long long findMaximumNumber(long long k, int x) {
        long long beg = 1, end = 1e15;
        long long ans = -1;
        while(beg <= end) {
            long long  mid = beg + ((end-beg)/2);
            if(calc(mid,x) <= k){
                ans = mid;
                beg = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans-1;
    }
};

/**
 * Reference : https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/solutions/4561717/binary-search-over-answer/
 * Intuition
 * Let price(num) denote the sum of prices from 1 to num for some num.
 * 
 * It is easier to calculate price(num) given num than to do it the other way around. In addition, note that price is increasing.
 * 
 * Thus, we can binary search over the answer.
 * 
 * Approach
 * ========
 * Given some num, how do we find the sum of prices for all integers in [1, num)? Look at the bits.
 * For this example, we use num = 14 (i.e. we list the numbers up to 13). We will include 0 to make the explanation nicer.
 * 
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101

 * How many set bits are in the ith bit (0-indexed)? Let's look at the 4's place as an example.
 * The 4's place has this pattern in the listing above: 00001111000011. We see there are groups of 00001111, with a trailing 000011.
 * 
 * Thus, the number of 1's is the number of 1s in the groups of 00001111 (i.e. num // 8 * 4) plus the 1's in the trailing part 000011 (i.e. max(num % 8 - 4, 0)).
 * 
 * In general, with a bit of maniuplation, we can get that the number of 1's for a given place 1 << i is
 * ((num - numModTwoTimesI) // 2) + max(numModTwoTimesI - (1 << i), 0),
 * where numModTwoTimesI := num % (1 << (i + 1)).
 * 
 * Complexity
 * ==========
 * Time complexity: O((lg⁡2k)/x)O((\lg^2 k) / x)O((lg2k)/x)
 * Space complexity: O(1)O(1)O(1)
 */