//Leetcode submission link: https://leetcode.com/problems/wiggle-sort-ii/submissions/1498296703/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int mid = (n-1)/2;
        int end = n-1;
        for(int i = 0; i < n; i++){
            nums[i] = (i%2 == 0) ? sorted[mid--] : sorted[end--];
        }

        return;
    }
};

//Time complextiy: O(nlogn)
//Space complexity: O(n)