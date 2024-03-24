/*
* @Author: lenovo
* @Date:   2024-03-24 22:24:24
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-24 22:26:03
*/

class Solution {
public:
    class Node{
        public:
            int ind;
            Node* child[26];
            Node(int idx) {  
                ind = idx;
                for(int i = 0; i < 26; ++i) child[i] = NULL;
            }
    };
    
    void add(Node* ptr, vector<string>& wordsContainer, int i){
        for(int j = wordsContainer[i].size() - 1; j >= 0; --j){
            int c = wordsContainer[i][j] - 'a';
            if(ptr->child[c] == NULL) ptr->child[c] = new Node(i);
            ptr = ptr->child[c]; 
            if(wordsContainer[ptr->ind].size() > wordsContainer[i].size()) ptr->ind = i;
        }
    }
    
    int search(Node* ptr, string &s){
        int ans = ptr->ind;
        for(int i = s.size()-1; i >= 0; --i){
            ptr = ptr->child[s[i] - 'a'];
            if(!ptr) return ans;
            ans = ptr->ind;
        }
        return ans;
    }
    
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        Node* head = new Node(0);
        for(int i = 0; i < wordsContainer.size(); ++i) {
            if(wordsContainer[head->ind].size() > wordsContainer[i].size()) head->ind = i;
            add(head, wordsContainer, i);
        }
        for(auto q: wordsQuery) ans.push_back(search(head, q));
        return ans;
    }
};

/*
Intuition
=========
	Longest common prefix/suffix search for a collection of strings => Trie data structure
    Typical prix search problem using Trie => but here we need to check each item in reverse order as we need to track the suffix
    At each node store possible solution till that node ( will be more clear once you go through the code and explaination)

Approach
========
	Add all items to the Trie
    addition of each item in the trie should be done in reverse order of the word, as we are suppose to track the suffix of each item.
    While doing so keep tracking the ind of answer possible at that each node
    Also keep tracking the min size word in head ind
    Iterate over the query words and search each item in reverse order.
        At each node that we traverse to, we update the ans with the latest possible ind at that node.
        When we cannot proceed further in the Trie then return ans.

Time complexity : O(N*M)
Space complexity : O(N)
*/