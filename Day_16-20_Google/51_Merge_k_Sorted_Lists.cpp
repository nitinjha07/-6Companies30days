//Leetcode submission link: https://leetcode.com/problems/merge-k-sorted-lists/submissions/1511214660/

struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        ListNode* head = NULL;
        ListNode* curr = head;

        for(auto it : lists){
            if(it != NULL) pq.push(it);
        }

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            if(head == NULL){
                head = top;
                curr = head;
            }
            else{
                curr->next = top;
                curr = top;
            }
            if(top->next != NULL){
                pq.push(top->next);
            }
        }

        return head;
    }
};

//Time complexity: O(NlogK)
//Space complexity: O(K)