//Leetcode submission link: https://leetcode.com/problems/longest-mountain-in-array/submissions/1499234187/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;
        int idx = 1;
        while(idx < n-1){
            if(arr[idx] > arr[idx-1] && arr[idx] > arr[idx+1]){
                //peak element
                int left = idx-1;
                int right = idx+1;

                while(left > 0 && arr[left] > arr[left-1]){
                    left--;
                }

                while(right < n-1 && arr[right] > arr[right+1]){
                    right++;
                }

                ans = max(ans, right-left+1);

                idx = right+1;
            }
            else idx++;
        }
        return ans;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)