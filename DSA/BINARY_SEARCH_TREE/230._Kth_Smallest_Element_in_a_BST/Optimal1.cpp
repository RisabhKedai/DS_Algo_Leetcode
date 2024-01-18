/*
* @Author: lenovo
* @Date:   2024-01-19 22:37:19
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-20 11:23:02
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
private:
    map<TreeNode*,int> mp;
    int makeCount(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        mp[root] = 1 + makeCount(root->left) + makeCount(root->right);
        return mp[root];
    }
    TreeNode* util(TreeNode* root, int k) {
        // cout<<root->val<<" "<<mp[root]<<" "<<k<<endl;
        if(root->left != NULL){
            if(k<=mp[root->left]) return util(root->left,k);
            if(k-1 == mp[root->left]){
                return root;
            }
            return util(root->right, k-1-mp[root->left]);
        } else {
            if(k==1){
                return root;
            } 
            return util(root->right,k-1);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        makeCount(root);   
        return util(root,k)->val;
    }
};

/**
 * The count of each subtree is stored on its root node. 
 * Once the count is stored we can use recursive binary search to find the node
 * with the count value.
 * 
 * This optimization would be favourable in case the number of insert operations
 * are quite high. In this problem the tree was already present and the time taken
 * to store the counts was O(N) but if the count value is stored while creating the tree
 * it can be done in O(N)
 *
 * Once that is done, both insert and find operation becomes O(log(N))
 * 
 * Time complexity : O(logN)
 * Space complexity : O(N)
 */