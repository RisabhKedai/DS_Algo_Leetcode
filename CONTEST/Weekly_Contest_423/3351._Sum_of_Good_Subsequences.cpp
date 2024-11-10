class Solution
{
public:
    int sumOfGoodSubsequences(vector<int> &nums)
    {
        unordered_map<int, long long> noSubsequenceEndingAtX;
        unordered_map<long, long long> sumEndingAtX;
        long mod = 1e9 + 7;
        int n = nums.size();
        noSubsequenceEndingAtX[nums[0]] = 1;
        sumEndingAtX[nums[0]] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int x = nums[i];
            noSubsequenceEndingAtX[x] += 1 + noSubsequenceEndingAtX[x - 1] + noSubsequenceEndingAtX[x + 1];
            noSubsequenceEndingAtX[x] %= mod;
            sumEndingAtX[x] += sumEndingAtX[x - 1] % mod;
            sumEndingAtX[x] %= mod;
            sumEndingAtX[x] += sumEndingAtX[x + 1] % mod;
            sumEndingAtX[x] %= mod;
            sumEndingAtX[x] += (x % mod) * (long)((1 + (noSubsequenceEndingAtX[x - 1] % mod) + (noSubsequenceEndingAtX[x + 1] % mod)) % mod);
            sumEndingAtX[x] %= mod;
        }
        long total = 0;
        for (auto it = sumEndingAtX.begin(); it != sumEndingAtX.end(); it++)
        {
            // cout << it->first << ", " << it->second << endl;
            total += it->second % mod;
            total %= mod;
        }
        return (int)(total % mod);
    }
};

/**
 * For each value v in the array,
 * store the number of subsequences ending at v,
 * as well as the sum of the subsequences ending at v in 2 separate hashtables.
 *
 * Update the count of v by adding the counts of all subseqs ending at v-1 and v+1, as well as 1 for the number itself.
 * Update the sum of v by adding the sums of all subseqs ending at v-1 and v+1, as well as the added count of v
 *
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */