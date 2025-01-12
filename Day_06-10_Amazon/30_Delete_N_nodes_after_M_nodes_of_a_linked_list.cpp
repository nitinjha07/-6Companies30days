//My Gfg profile link: https://www.geeksforgeeks.org/user/nitinkumaf2c2/
//Gfg problem link: https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* curr = head;

        while(curr != NULL){
            int idx = 1;
            while(curr != NULL && idx < m){
                curr = curr->next;
                idx++;
            }

            if(curr == NULL) return head;

            Node* temp = curr->next;

            int jump = 1;

            while(temp != NULL && jump <= n){
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
                jump++;
            }

            curr->next = temp;
            curr = temp;
        }

        return head;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(1)