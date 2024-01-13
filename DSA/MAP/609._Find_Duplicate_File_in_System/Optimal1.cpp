/*
* @Author: lenovo
* @Date:   2024-01-13 18:42:51
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-13 18:53:36
*/
 
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        mp = {}
        ans = []
        for path in paths:
            pathl = list(path.split()) 
            dirs = pathl[0]
            files = pathl[1::]
            for file in files:
                name, cont = file.split('(')
                cont = cont[:-1:]
                try :
                    mp[cont].append(dirs+'/'+name)
                except:
                    mp[cont] = [dirs+'/'+name]
        for vals in mp.values():
            if(len(vals) > 1):
                ans.append(vals)
        return ans


/**
 * This is normal implementation of the hashing using dictionary in python
 * For each directory identify the file and its content. 
 * Create a map on the file content as key and list of files with that content
 * The file path can be created using file name and path 
 * 
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */