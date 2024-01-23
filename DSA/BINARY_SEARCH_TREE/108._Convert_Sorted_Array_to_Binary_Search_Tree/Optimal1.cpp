/*
* @Author: lenovo
* @Date:   2024-01-23 13:29:13
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-23 13:47:14
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
    TreeNode* binaryTreeUtil(int l,int r,vector<int>& nums) {
        if(l>r){
            return NULL;
        }
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode();
        root->val = nums[mid];
        root->left = binaryTreeUtil(l,mid-1,nums);
        root->right = binaryTreeUtil(mid+1,r,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binaryTreeUtil(0,nums.size()-1,nums);
    }
};

/**
 * Use recursions and binary search to decide the current node to be picked. 
 * If we see carefully binary search is nothing but a traversal down the binary search tree
 *
 * So keeping that in mind the mid element represents the current value in the binary Search tree;
 *
 * Time complexity: O(N)
 * Space complexity : O(1)
 */