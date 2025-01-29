//Leetcode submission link: https://leetcode.com/problems/k-divisible-elements-subarrays/submissions/1524054333/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        set<vector<int>> st;
        int count = 0;  //current subarray divisible element count

        while(j < n){
            if(nums[j]%p == 0){
                count++;
            }

            while(i < n && count > k){
                if(nums[i]%p == 0){
                    count--;
                }
                i++;
            }

            for(int x = i; x <= j; x++){
                st.insert(vector<int>(nums.begin()+x, nums.begin()+j+1));
            }

            j++;
        }

        return st.size();
    }
};

// Time Complexity: O(n^3)
// Space Complexity: O(n^3)