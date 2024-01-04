/*
* @Author: lenovo
* @Date:   2024-01-04 21:22:56
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-04 21:24:47
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> temp;
        vector<string> ans;
        int wordstn = 0;
        int lengthtn = 0;
        int ind = 0;
        while(ind < words.size()){
            if((wordstn + lengthtn + words[ind].length()) <= maxWidth) { 
                temp.push_back(words[ind]);
                wordstn++;
                lengthtn += words[ind].size();
                ind++;
            }else{
                string ms = "";
                ms += temp[0];
                if(temp.size()==1){
                    while(ms.length()<maxWidth){
                        ms += " ";
                    }
                    ans.push_back(ms);
                    temp.clear();
                    lengthtn = 0;
                    wordstn = 0;
                    continue;                  
                }
                double perspace = (double)(maxWidth-lengthtn)/(wordstn-1); 
                int ext = (maxWidth-lengthtn)%(wordstn-1);

                // cout<<perspace<<" ";
                for(int i=1; i<temp.size(); i++) {
                    for(int j=0; j<floor(perspace); j++){
                        ms += " ";
                    }
                    if(ext>0){
                        ms += " ";
                        ext--;
                    }
                    ms += temp[i];
                }
                ans.push_back(ms);
                temp.clear();
                lengthtn = 0;
                wordstn = 0;

            }
        }
        string ms = "";
        for(int i=0; i<temp.size(); i++) {
            ms += temp[i];
            if(ms.length()<maxWidth){
                ms += " ";
            }
        }
        while(ms.length()<maxWidth){
            ms+=" ";
        }
        ans.push_back(ms);
        return ans;
    }
};


/**
 * Core implementation.
 * However you can do mod to find the evenly distributed spaces
 *
 * Time complexity : O(N)
 * Space complexity : O(N)
 */