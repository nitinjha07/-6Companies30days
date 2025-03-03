//Leetcode submission link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/submissions/1518881186/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();

        int count = 0;
        for(int i = 0; i < n; i++){
            bool flag = false;
            for(int j = 0; j < m; j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    flag = true;
                    break;
                }
            }
            if(!flag) count++;
        }
        return count;
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(1)