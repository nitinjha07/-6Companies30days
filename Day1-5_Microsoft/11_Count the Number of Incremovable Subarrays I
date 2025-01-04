// Leetcode submission link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/submissions/1497007048/

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                bool check = true;
                int last = -1;

                for(int k = 0; k < n; k++){
                    if(k >= i && k <= j){
                        continue;
                    }
                    if(last >= nums[k]){
                        check = false;
                        break;
                    }
                    last = nums[k];
                }
                if(check) count++;
            }
        }

        return count;
    }
};

//Time complexity: O(n^3)
//Space complexity: O(1)