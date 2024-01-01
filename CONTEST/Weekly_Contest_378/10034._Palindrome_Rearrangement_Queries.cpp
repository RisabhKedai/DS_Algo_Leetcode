/*
* @Author: lenovo
* @Date:   2023-12-31 17:02:55
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-01 07:52:17
*/


class Solution {
public:
    int n;
    vector<vector<int>> runningSum1;
    vector<vector<int>> runningSum2;
    vector<int> diff;
    pair<string,string> ss;
    string smain;
    string s1;
    string s2;
    void breakString(){
        int n = smain.length();
        s1 = "";
        s2 = "";
        int i = 0;
        for(i=0; i<n/2; i++){
            s1 += smain[i];
        }
        for(;i<n; i++){
            s2 += smain[i];
        }
        reverse(s2.begin(),s2.end());
    }
    bool checkCorrect(int a, int b, int c, int d) {
		int maxLo = max(a,c);
		int minLo = min(a,c);
		int maxHi = max(b,d);
		int minHi = min(b,d);
        // If there diffs outside of [loMin, hiMax), s1 and s2 cannot be made equal.
        if(minLo>0 && diff[minLo-1]>0){
            // cout<<"cond1\n";
            return false;
        }
        if(diff[n-1] > diff[maxHi]){
            // cout<<"cond2\n";
            return false;
        } 
        // if the 2 ranges are disjoint make sure the area between them is sorted
        if(minHi < maxLo){
            if(diff[maxLo-1] - diff[minHi] > 0) {
                // cout<<"cond4i\n";
                return false;
            }else{
                // cout<<"cond4j\n";
            	for(int i=0; i<26; i++){
            		int p1cntI = runningSum1[i][minHi] - (minLo>0?runningSum1[i][minLo-1]:0);
            		int p2cntI = runningSum2[i][minHi] - (minLo>0?runningSum2[i][minLo-1]:0);
            		if(p1cntI != p2cntI){
            			return false;
            		}
            	}
                for(int i=0; i<26; i++){
            		int p1cntI = runningSum1[i][maxHi] - (maxLo>0?runningSum1[i][maxLo-1]:0);
            		int p2cntI = runningSum2[i][maxHi] - (maxLo>0?runningSum2[i][maxLo-1]:0);
            		if(p1cntI != p2cntI){
            			return false;
            		}
            	}
            }
        } else if((a==maxLo)==(b==minHi)) {
            // cout<<" cond3\n";
        	// If one of the range completely masks the other then the outer range matters and the character count should be same
        	// since we have already checked before minLow, we can just check for total character count till maxHi is same  
        	for(int i=0; i<26; i++){
        		if(runningSum1[i][maxHi] != runningSum2[i][maxHi]){
        			return false;
        		}
        	}
        } else {
        	// if both ranges overlap but not completely then every character up to maxLo in
            // the corresponding string must be in minHi of the other
            // string.
            for(int i=0; i<26; i++){
                if(maxLo == a){
                    if(maxLo>0 && runningSum1[i][maxLo-1] > runningSum2[i][minHi])
                        return false;
                }else{
                    if(maxLo>0 && runningSum2[i][maxLo-1] > runningSum1[i][minHi])
                        return false;
                }
            }
        }
        return true;
    }
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        smain = s;
        n = s.length()/2;
        runningSum1 = vector<vector<int>>(26,vector<int>(n,0));
        runningSum2 = vector<vector<int>>(26,vector<int>(n,0));
        diff = vector<int>(n,0);
        vector<bool> ans; 
        breakString();
        runningSum1[s1[0]-'a'][0]++;
        runningSum2[s2[0]-'a'][0]++;
        diff[0] = s1[0]!=s2[0];
        for(int i=1; i<n; i++){
            for(int j = 0; j<26; j++){
                runningSum1[j][i] = runningSum1[j][i-1]; 
            }
            runningSum1[s1[i]-'a'][i]++;

            for(int j = 0; j<26; j++){
                runningSum2[j][i] = runningSum2[j][i-1]; 
            }
            runningSum2[s2[i]-'a'][i]++;
            diff[i] = diff[i-1]+(s1[i]!=s2[i]);
            // cout<<diff[i]<<"\n";
        }

        for(auto query : queries){
            int a = query[0];
            int b = query[1];
            int c = (2*n) - 1 - query[3];
            int d = (2*n) - 1 - query[2];
            // cout<<s1<<" "<<s2<<endl;
            // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            ans.push_back(checkCorrect(a,b,c,d));
        }
        return ans;
    }
};

/**
 * Reference Link : 
 * https://leetcode.com/problems/palindrome-rearrangement-queries/solutions/4481115/prefix-sum-and-substring-equal-index-beats-100-time-and-mem/
 * https://leetcode.com/problems/palindrome-rearrangement-queries/solutions/4481740/python3-o-n-using-cumulative-letter-counts/
 * 
 */
