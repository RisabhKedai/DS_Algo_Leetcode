/*
* @Author: lenovo
* @Date:   2024-03-05 23:25:12
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-05 23:28:17
*/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(123);
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            f[s[i]]++;
        }
        sort(f.begin(),f.end());
        for(int i=121; i>=97; i--){
            if(f[i]==0){
                break;
            }
            if(f[i]>=f[i+1]){
                int temp = f[i];
                f[i] =max(0,f[i+1]-1);
                cnt += abs(temp-f[i]);
            }
        }
        return cnt;
    }
};

/*
{
	Apporach : "
		Store the frequency of each letter and sort in ascending. When 1 char have the frequency more than another make it lower than the other.
		In case it becomes 0 we have to remove the other completely. That is handled in the max check.
	",
	Time complexity : "O(N)",
	Space complexity : "O(1)"
}*/
