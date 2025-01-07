//My Gfg profile link: https://www.geeksforgeeks.org/user/nitinkumaf2c2/
//Gfg problem link: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        int n = arr.size();

        int i = 0;
        int j = 0;

        map<int, int> mp;

        while(j < n){
            mp[arr[j]]++;

            if(j-i+1 == k){
                auto it = mp.end();
                ans.push_back(it->first);

                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            j++;
        }

        return ans;
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(n)