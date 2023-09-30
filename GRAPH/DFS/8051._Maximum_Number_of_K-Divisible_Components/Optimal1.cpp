/*
* @Author: lenovo
* @Date:   2023-10-01 00:22:06
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-01 00:31:07
*/
class Solution {
public:
    pair<int,int> dfs(int node, vector<int>& values, vector<vector<int>>& adj, vector<bool>& vis, int k){
        int value = values[node];

        vis[node] = true;
        int comps = 0;
        for(int i=0; i<adj[node].size(); i++){
            if(!vis[adj[node][i]]){
                pair<int,int> ret = dfs(adj[node][i], values ,adj,vis,k);
                if(ret.first%k!=0){
                    value += ret.first;
                }
                comps += ret.second;
            }
        }
        comps += value%k==0;
        return {value,comps};
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int st = 0;
        for(int i=0; i<n; i++){
            if(adj[i].size() == 1){
                st = i;
                break;
            }
        }
        vector<bool> vis(n,false);
        pair<int,int> ans =  dfs(st,values,adj,vis,k);
        return ans.second;
    }
};

/**
 * The problem is solved using DFS. Starting from the leaf nodes, DFS explores the tree. When the function returns, it checks if the sum of the DFS is divisible by kk. If true, it increments the component count and doesn't include the current node's sum in the component sum.
 * If the DFS sum isn't divisible by kk, it means another node must be connected to make it divisible. In this case, the current node's sum is added to the DFS sum. If the total sum is divisible by kk, it signifies an additional component, increasing the component count.
 * Finally, when DFS returns to the root node, the sum is always divisible by kk, indicating the total components the graph can be divided into. The DFS function returns a pair of total sum and component count.
 */