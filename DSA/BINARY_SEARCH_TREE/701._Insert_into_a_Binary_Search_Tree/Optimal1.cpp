/*
* @Author: lenovo
* @Date:   2024-01-13 19:30:40
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-13 19:36:56
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        if(val < root->val){
            root->left = insertIntoBST(root->left,val);
        }
        if(val>root->val){
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};

/**
 * Use recurssion to check if the value is less than root then
 * Go to left tree, go to right tree
 * If root is null then insert into that position and current  value becomes the root
 *
 * Time complexity : O(NlogN)
 * Space complexity : O(1)
 * 
 */