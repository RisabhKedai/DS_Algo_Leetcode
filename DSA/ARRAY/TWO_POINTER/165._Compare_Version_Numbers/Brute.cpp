/*
* @Author: lenovo
* @Date:   2023-10-16 07:33:10
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-16 07:33:58
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int c1 = 0;
        int c2 = 0;
        while(c1<version1.length() or c2<version2.length()){
            string vers1 = "0";
            string temp1 = "";
            while(c1<version1.length() && version1[c1]!='.'){
                if(version1[c1]=='0'){
                    if(temp1.size()!=0){
                        temp1 += version1[c1];
                    }                  
                }else{
                    temp1 += version1[c1];
                }
                c1++;
            }
            if(temp1!=""){
                vers1 = temp1;
            }
            string vers2 = "0";
            string temp2 = "";
            while(c2<version2.length() && version2[c2]!='.'){
                if(version2[c2]=='0'){
                    if(temp2.size()!=0){
                        temp2 += version2[c2];
                    }               
                } else {
                    temp2 += version2[c2];
                }
                c2++;
            }
            if(temp2!=""){
                vers2 = temp2;
            }
            c1++;
            c2++;
            cout<<vers1<<" "<<vers2<<endl;
            if(stoi(vers1)<stoi(vers2)){
                return -1;
            }else if(stoi(vers1)>stoi(vers2)){
                return 1;
            }
        }
        return 0;
    }
};

/**
 * Bare implementation
 * Time Complexity : O(max(n1,n2))
 * Space Complexity : O(1)
 */