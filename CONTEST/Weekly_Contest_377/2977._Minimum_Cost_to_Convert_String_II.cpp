/*
* @Author: lenovo
* @Date:   2023-12-24 16:29:12
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-24 16:41:29
*/
const int N = 300;
const long long INF = 0x3F3F3F3F3F3F3FLL;

long long dis[N][N];

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        map<string, int> label;
        for (auto& v : original) {
            label[v];
        }
        for (auto& v : changed) {
            label[v];
        }
        int total = 0;
        for (auto& it : label) {
            it.second = total++;
        }
        
        for (int i = 0; i < total; ++i) {
            for (int j = 0; j < total; ++j) {
                dis[i][j] = INF;
            }
            dis[i][i] = 0;
        }
        
        for (int i = 0; i < original.size(); ++i) {
            int u = label[original[i]];
            int v = label[changed[i]];
            
            dis[u][v] = min(dis[u][v], (long long) cost[i]);
        }
        for (int k = 0; k < total; ++k) {
            for (int i = 0;i < total; ++i) {
                for (int j = 0; j < total; ++j) {
                    if (i != j && j != k && k != i) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }
        
        vector<int> lens;
        for (auto& v : original) {
            lens.push_back(v.size());
        }
        sort(lens.begin(), lens.end());
        lens.erase(unique(lens.begin(), lens.end()), lens.end());
        
        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            for (int l : lens) {
                if (i - l + 1 >= 0) {
                    string s = source.substr(i - l + 1, l);
                    string t = target.substr(i - l + 1, l);
                    auto u = label.find(s);
                    auto v = label.find(t);
                    if (u != label.end() && v != label.end()) {
                        dp[i + 1] = min(dp[i + 1], dp[i - l + 1] + dis[u->second][v->second]);
                    }
                }
            }
        }
        if (dp[n] >= INF) {
            return -1;
        }
        return dp[n];
    }
};


/**
 * Use Floyd Warshall algortithm to find the shortest path between each of the given substring pairs. 
 * Now for finding the minimum cost use DP. The dp function finds the minimum cost starting at a given index. 
 * If the index is equal then the cost will same as dp(ind+1) because no cost is incurred in converting the given charactr. 
 * But anyways we'll look for cost if we convert substring i..j. Then cost will be PathCost(i..j) + dp(j+1)
 * We'll find the solutions starting at all i and then return dp[0].
 *
 * Reference video : https://leetcode.com/problems/minimum-cost-to-convert-string-ii/solutions/4451181/video-explanation-every-proof-involved-o-n-n-c-an-optimised-solution-using-rabin-karp/
 *
 * Time Complexity : O((N * N * C) + (C * C * C))
 * Space Complexity : O(N*N)
 */