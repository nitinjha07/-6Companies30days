//Leetcode submission link: https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/1506349669/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<pair<int, int>, int> m;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j])==k and m.find({nums[j], nums[i]})==m.end())
                    m[{nums[i], nums[j]}]++;
            }
        }
        return m.size();
    }
};

//Time Complexity: O(N^2)
//Space Complexity: O(N^2)