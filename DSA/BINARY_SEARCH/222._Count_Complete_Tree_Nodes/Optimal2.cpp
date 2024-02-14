/*
* @Author: lenovo
* @Date:   2024-02-14 22:56:09
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-14 23:10:23
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
    int height(TreeNode* root) {
        return root == NULL ? -1 : 1 + height(root->left);
    }
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        return h < 0 ? 0 :
        height(root->right) == h-1 ? 
            (1 << h) + countNodes(root->right):
            (1 << (h-1)) + countNodes(root->left);
    }
};

/**
 * The height of a tree can be found by just going left. 
 * Let a single node tree have height 0. Find the height h of the whole tree. 
 * If the whole tree is empty, i.e., has height -1, there are 0 nodes.
 * Otherwise check whether the height of the right subtree is just one less than that of the whole tree, 
 * meaning left and right subtree have the same height.
 * 
 * If yes, then the last node on the last tree row is in the right subtree and the left subtree is a full tree of height h-1. 
 * So we take the 2^h-1 nodes of the left subtree plus the 1 root node plus recursively the number of nodes in the right subtree.
 * 
 * If no, then the last node on the last tree row is in the left subtree and the right subtree is a full tree of height h-2. 
 * So we take the 2^(h-1)-1 nodes of the right subtree plus the 1 root node plus recursively the number of nodes in the left subtree.
 *
 * Time complexity : O(log(N)^2)
 * Space complexity : O(1)
 */