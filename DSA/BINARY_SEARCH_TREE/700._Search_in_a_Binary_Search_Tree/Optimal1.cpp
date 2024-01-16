/*
* @Author: lenovo
* @Date:   2024-01-17 01:45:34
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-17 01:49:24
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root){
            if(root->val == val){
                return root;
            }
            TreeNode* find;
            if(val < root->val)
                find = searchBST(root->left,val);
            else
                find = searchBST(root->right,val);
            if(find) return find;
        }
        return NULL;
    }
};

/**
 * Use recursion to search in the Left and right subtree and if not found 
 * till the last i.e, root then return null.
 *
 * Time Complexity : O(log(N))
 * Space Complexity : O(1)
 * 
 */