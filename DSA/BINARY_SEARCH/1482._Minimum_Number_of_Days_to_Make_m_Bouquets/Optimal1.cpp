/*
* @Author: lenovo
* @Date:   2024-02-12 23:27:11
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-12 23:28:55
*/

class Solution {
int bouqs(long long days, vector<int> bloomDay, int k){
    int cnt = 0;
    int temp = 0;
    for(int i=0; i<bloomDay.size(); i++){
        if(bloomDay[i]<=days){
            temp+=1;
        }else{
            cnt += temp>=k;
            temp = 0;
            continue;
        }
        if(temp>=k){
            cnt += 1;
            temp = 0;
        }
    }
    return cnt;
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long beg = *min_element(bloomDay.begin(), bloomDay.end());
        long end = *max_element(bloomDay.begin(), bloomDay.end());
        // cout<<beg<<" "<<end<<endl;
        if((long)m*k > bloomDay.size()){
            return -1;
        }
        while(beg<=end){
            long long mid = (beg+end)/2;
            // cout<<mid<<endl;
            if(bouqs(mid, bloomDay, k)>=m){
                end = mid-1;
            }else{
                beg = mid+1;
            }
        }
        return beg;
    }
};

/**
 * Minimum days to require to bloom a flower is min(arr)
 * Minimum days to require to bloom all the flower is max(arr)
 * Binary search for a sweet spot to find number of days such that required flowers are bloomed
 *
 * Time complexity: O(nLogn)
 * Space complexity : O(1)
 */