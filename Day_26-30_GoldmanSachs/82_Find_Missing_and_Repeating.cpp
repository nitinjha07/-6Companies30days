//Problem Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
//GFG Profile Link: https://www.geeksforgeeks.org/user/nitinkumaf2c2/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        unordered_map<int, int> mp;

        vector<int> ans(2);

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }

        for(int i = 1; i <= arr.size(); i++){
            if(mp.find(i) == mp.end()) ans[1] =  i;
            else if (mp[i] == 2) ans[0] = i;
        }

        return ans;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)