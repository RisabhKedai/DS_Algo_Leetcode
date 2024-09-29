class Solution
{
private:
    set<pair<int, pair<int, int>>> vis;
    bool fetchSubsequence(int i, int j, int flag, string &word1, string &word2, vector<int> &sol)
    {
        if (j >= word2.length())
            return true;
        if (i >= word1.length())
            return false;
        if (vis.count({i, {j, flag}}))
            return false;

        bool found = false;
        if (word1[i] == word2[j])
        {
            found = fetchSubsequence(i + 1, j + 1, flag, word1, word2, sol);
            if (found)
                sol.push_back(i);
            return found;
        }
        else
        {
            if (flag)
            {
                found = fetchSubsequence(i + 1, j + 1, 0, word1, word2, sol);
                if (found)
                {
                    sol.push_back(i);
                    return true;
                }
            }
            while (i < word1.size() && word1[i] != word2[j])
                i++;
            if (i < word1.size())
            {
                found = fetchSubsequence(i + 1, j + 1, flag, word1, word2, sol);
                if (found)
                {
                    sol.push_back(i);
                    return true;
                }
            }
        }
        vis.insert({i, {j, flag}});
        return found;
    }

public:
    vector<int> validSequence(string word1, string word2)
    {
        vector<int> sol;
        bool found = fetchSubsequence(0, 0, 1, word1, word2, sol);
        if (found)
        {
            reverse(sol.begin(), sol.end());
            if (sol.size() == word2.length())
            {
                return sol;
            }
        }
        return {};
    }
};

/**
 * Intuition
 * The problem is about finding whether word2 can be matched as a subsequence of word1 with at most one mismatch.
 * The idea is to traverse both strings simultaneously, trying to match characters. If a character mismatch occurs,
 *  we have one chance to ignore this mismatch (using a flag). Memoization helps to avoid redundant computations by storing previously visited states.
 *
 * Approach
 * Use a recursive function with memoization (via a set) to avoid reprocessing the same state.
 * The recursive function start() takes three parameters: current indices i (for word1) and j (for word2),
 * and a flag that indicates whether a mismatch is still allowed.
 * If characters at i and j match, move both indices forward. If they don't match, either skip a character in word1 (if the flag allows) or continue searching for the next match.
 * If the entire word2 is matched, return true and store the indices in the solution vector. Reverse the vector at the end to get the correct order of indices.
 * If no valid subsequence is found, return an empty vector.
 *
 * Time Complexity : O(N + Mlog(M))
 * Space complexity : O(M)
 */