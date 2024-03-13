/*
* @Author: lenovo
* @Date:   2024-03-14 00:25:43
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-14 00:33:36
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        string ans = "";
        vector<int> lind(123,0);
        vector<bool> vis(123, false);
        for(int i=0; i<s.length(); i++){
            lind[s[i]] = i;
        }
        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
                vis[s[i]] = true;
            }else{
                if(vis[s[i]]){
                    continue;
                }
                while(!st.empty() && st.top()>s[i] && lind[st.top()]>i){
                    vis[st.top()] = false;
                    st.pop();
                }
                st.push(s[i]);
                vis[s[i]] = true;
            }
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

/*
{
	"Approach" : "
		Use monotonic stack to insert characters and if a smaller character is encountered
		Check if it can replace others, if they are occuring somewhere else.
		The items currently present in the stack are not needed and are thus hidden using a vis array
	",
	"Time complexity" : "O(N)",
	"Space complexity" : "O(N)",
}
*/
