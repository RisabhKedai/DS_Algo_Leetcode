class Solution {
public:
int size;
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        size = img1.size()-1;
        int ans = INT_MIN;
        for(int i=-size; i<=size; i++){
            for(int j=-size; j<=size; j++){
                ans = max(ans, overlap(img1,img2,i,j));
            }
        }
        return ans;
    }
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int i, int j){
        //calculating iteration boundaries for the second image
        int left2 = max(j, 0);
        int right2 = min(j + size, size);
        int top2 = max(i, 0);
        int bottom2 = min(i + size, size);
        cout<<"1 :"<<top2<<" "<<left2<<" "<<right2<<" "<<bottom2;
        cout<<"\n";
        //calculating iteration boundaries for the first image
        int top1 = size - bottom2;
        int bottom1 = size - top2;
        int left1 = size - right2;
        int right1 = size - left2;
        // cout<<"2 :"<<top1<<" "<<left1<<" "<<right1<<" "<<bottom1;
        // cout<<"\n";
        int sum = 0;
        for (int i2 = top2, i1 = top1; i2 <= bottom2 && i1 <= bottom1; i1++, i2++) {
            for (int j2 = left2, j1 = left1; j2 <= right2 && j1 <= right1; j1++, j2++) {
                sum += img1[i1][j1] & img2[i2][j2];
            }
        }
        cout<<"Sum = "<<sum<<endl;
        return sum;

    }
};

// reference : https://leetcode.com/problems/image-overlap/solutions/2749294/java-with-explanation-possible-to-understand/

/**
 * Time Complexity : O(N^4)
 * Space Complexity : O(1)
 */