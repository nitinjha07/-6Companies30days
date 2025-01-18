//Leetcode submission link: https://leetcode.com/problems/maximum-product-after-k-increments/submissions/1512006196/

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums) pq.push(num);

        for(int i = 0; i < k; i++){
            int top = pq.top();
            pq.pop();

            pq.push(top+1);
        }

        long long ans = 1;
        int MOD = 1e9 + 7;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();

            ans = (ans*top) % MOD;
        }

        return ans;
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(n)