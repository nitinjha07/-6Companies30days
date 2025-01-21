//Leetcode submission link: https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/1352863620/

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

//Time complexity: O(nlogk)
//Space complexity: O(k)