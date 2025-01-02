

//Approach 1: Brute Force

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        int moves = INT_MAX;
        for(int i = mini; i <= maxi; i++){
            int curr = 0;
            for(int j = 0; j < n; j++){
                curr += abs(nums[j] - i);
            }
            moves = min(moves, curr);
        }
        return moves;
    }
};

//Time Complexity: O(n^2)

//Approach-2
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int median = nums[n/2];
        if(n%2 == 0){
            median += nums[(n/2)-1];
            median /= 2;
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(median - nums[i]);
        }

        return ans;
    }
};

//Time Complexity: O(nlogn)


//Approach-3
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n-1;

        int ans = 0;
        while(i < j){
            ans += abs(nums[j] - nums[i]);
            i++;
            j--;
        }

        return ans;
    }
};

//Time Complexity: O(nlogn)