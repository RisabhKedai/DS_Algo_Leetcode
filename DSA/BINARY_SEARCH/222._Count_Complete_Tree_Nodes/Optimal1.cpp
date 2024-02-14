/*
* @Author: lenovo
* @Date:   2024-02-14 22:54:39
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-14 22:55:58
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    void util(TreeNode* root, int cnt){
        if(root == NULL){
            return;
        }
        ans = max(ans, cnt);
        util(root->right, (2*cnt)+1);
        util(root->left, (2*cnt));
    }
    int countNodes(TreeNode* root) {
        util(root,1);
        return ans;
    }
};

/**
 * Use a simple recursion to find the maximum node number upto which the node goes.
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 */