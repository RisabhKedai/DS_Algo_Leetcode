/*
* @Author: lenovo
* @Date:   2023-12-24 15:11:39
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-24 15:29:11
*/


class Solution {
public:
    vector<long long> ans;
    vector<int> sz;
    vector<vector<int>> tops;
    int n;
    pair<vector<long long>, vector<long long>> dfs(vector<vector<int>>& adj, int node, vector<int>& cost, int par){
        vector<long long> p,n;
        if(cost[node] >= 0)
        p.push_back(cost[node]);
        else
        n.push_back(cost[node]);
        sz[node] = 1;
        if(adj[node].size()==0){
            ans[node] = 1;
        }
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i] == par){
                continue;
            }
            auto all = dfs(adj,adj[node][i],cost,node);
            for(auto it : all.first){
                p.push_back(it);
            }
            for(auto it : all.second){
                n.push_back(it);
            }
            sz[node] += sz[adj[node][i]];
        }
        sort(p.rbegin(),p.rend());
        sort(n.begin(),n.end());
        while(p.size()>3){
            p.pop_back();
        }
        while(n.size()>2){
            n.pop_back();
        }
        ans[node] = -1LL;
        if(p.size()>=3){
            ans[node] = max(p[0]*p[1]*p[2],ans[node]);
        }
        if(sz[node] >= 3){
            if(p.size() >= 1 && n.size() >= 2) 
                ans[node] = max(ans[node], p[0] * n[0] * n[1]);
        }else{
            ans[node] = 1LL;
        }
        ans[node] = max(0LL, ans[node]);
        return {p,n};
    }
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        n = cost.size();
        vector<vector<int>> adj(n);
        for(auto x: edges) { 
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        ans = vector<long long>(n,0);
        sz = vector<int>(n,0);
        dfs(adj,0,cost,-1);
        return ans;
    }
};

/**
 * For each node we need to find the top 3 maximums and minimum 2 negatives in the subtree
 * for evaluating the max product for a given node. 
 *
 * DFS for each node and identify succh a set for each node and evaluate.
 *
 * Time Complexity : O(NlogN)
 * Space Complexity : O(N)
 * 
 */