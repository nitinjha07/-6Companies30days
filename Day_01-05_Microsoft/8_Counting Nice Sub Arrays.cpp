//Leetcode Submission Link: https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/1496114604/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> mp;  //<odd_idx, <left_even_count, right_even_count>
        vector<int> oddIdx;

        int prev = -1;
        for(int i = 0; i <= n; i++){
            if(i == n && prev != -1){
                mp[prev].second = i-1-prev;
                break;
            }
            if(nums[i]%2 != 0){
                oddIdx.push_back(i);
                if(prev == -1){
                    mp[i].first = i;
                    prev = i;
                }
                else{
                    mp[prev].second = i-prev-1;
                    mp[i].first = i-prev-1;
                    prev = i;
                }
            }
        }

        if(prev == -1) return 0;

        int i = 0;
        int j = 0;

        int count = 0;
        while(j < oddIdx.size()){
            if(j-i+1 == k){
                count += ((mp[oddIdx[i]].first+1)*(mp[oddIdx[j]].second+1));
                i++;
            }
            j++;
        }
        return count;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)