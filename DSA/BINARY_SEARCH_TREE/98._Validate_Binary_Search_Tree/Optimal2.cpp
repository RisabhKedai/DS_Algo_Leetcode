/*
* @Author: lenovo
* @Date:   2024-01-15 21:34:44
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-15 21:51:05
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
	int pre;
    bool isValidBST(TreeNode* root) {
        if(root){
        	if(root->left!=NULL){
        		if(!isValidBST(root->left))
        			return false;
        		if(prev != NULL && prev>=root->val){
        			return false;
        		}
        		prev = root;
        		return isValidBST(root->right)
        	}
        }
        return true;
    }
};

/**
 * Inorder traversal of a binary search tree is in soreted order
 * Left-Root-Right
 * Store the previous element for each node in a variable pre
 * Before moving away from the root , check the previous value, 
 * change prev value to root value;
 * and before entering the node in right check the previous value. 
 *
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 */