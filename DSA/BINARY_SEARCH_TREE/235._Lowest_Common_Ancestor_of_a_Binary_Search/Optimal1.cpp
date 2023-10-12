/*
* @Author: lenovo
* @Date:   2023-10-11 02:37:23
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-11 02:45:39
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        } 
        if(root==p || root==q){
            return root;
        }
        TreeNode* left =lowestCommonAncestor(root->left,p,q);
        TreeNode* right =lowestCommonAncestor(root->right,p,q);
        
        if(left !=NULL && right!=NULL){
            return root;
        }
        return left!=NULL?left:right;
    }
};

/**
 * For each node if I check that the node is p or q then we return the node,
 * because if both are present in the straight line then this one should be the answer
 * But if while back tracking there is a node where the left path found p and right path found q or vice versa.
 * Then that becomes the new LCA node as checked by the condition on line 30. 
 *
 * However this would fail when there is no P or no Q in the tree. In that case it will return a node
 * Either P or Q whichever is prsest.
 */