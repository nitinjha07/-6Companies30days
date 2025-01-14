//Leetcode submission link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/submissions/1508397926/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int slots = 1;

        int i = 0;
        while(i < n){
            if(slots == 0) return false;

            if(preorder[i] == '#'){
                slots--;
                i++;
            }
            else{
                while(i < n && preorder[i] != ',') i++;
                slots++;    //one consume by curr and two inc for its child so net one inc
            }

            if(i < n && preorder[i] == ',') i++;
        }
        return slots == 0;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)