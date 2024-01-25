/*
* @Author: lenovo
* @Date:   2024-01-25 23:19:26
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-26 00:12:39
*/
/*
* @Author: lenovo
* @Date:   2024-01-25 23:19:26
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-26 00:09:36
*/

class PairTreeNode {
public:
    PairTreeNode* left;
    PairTreeNode* right;
    pair<int,int> val;
    PairTreeNode(pair<int,int> val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    PairTreeNode() {
        this->left = NULL;
        this->right = NULL;
    }
};
class MyCalendar {
private:
    PairTreeNode* root;
    bool ans;
    PairTreeNode* insert(PairTreeNode* root, int st, int en){
        if(root == NULL){
            return new PairTreeNode({st,en});
        }
        if(en<=root->val.first){
            root->left = insert(root->left, st, en);
        } else if(st>=root->val.second){
            root->right = insert(root->right, st, en);
        }else{
            ans = false;
        }
        return root;
    }
public:
    MyCalendar() {
        this->root = new PairTreeNode();
    }
    
    bool book(int start, int end) {
        this->ans = true;
        insert(this->root, start, end);
        return this->ans;
    }

};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/**
 * Use a BST to store the ranges and check that no 2 ranges / nodes overlap
 * Each node contains a pair containing a range
 * 
 * Time complexity : O(logN)
 * Space complexity : O(N)
 */