

//Approach 1
class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1) return 1;
        if(k == 1) return n;

        ListNode* head = new ListNode(1);
        ListNode* temp = head;

        for(int i = 2; i <= n; i++){
            ListNode* newNode = new ListNode(i);
            temp->next = newNode;
            temp = temp->next;
        }

        temp->next = head;
        temp = head;

        while(temp->next != temp){
            for(int i = k; i > 2; i--){
                temp = temp->next;
            }

            temp->next = temp->next->next;
            head = temp->next;
            temp = head;
        }

        return temp->val;
    }
};

//Time Complexity: O(n*k)
//Space Complexity: O(n)

//Approach 2
