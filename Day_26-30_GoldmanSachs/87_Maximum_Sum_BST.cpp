//Leetcode submission link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/1524173803/

class TreeType{
    public:
    bool isBST;
    int sum;
    int minVal;
    int maxVal;

    TreeType(bool bs, int s, int mini, int maxi){
        isBST = bs;
        sum = s;
        minVal = mini;
        maxVal = maxi;
    }
};

class Solution {
    int maxSum = 0;
    TreeType solve(TreeNode* node){
        if(node == NULL){
            return TreeType(true, 0, INT_MAX, INT_MIN);
        }
        if(node->left == NULL && node->right == NULL){
            maxSum = max(maxSum, node->val);
            return TreeType(true, node->val, node->val, node->val);
        }

        TreeType leftAns = solve(node->left);
        TreeType rightAns = solve(node->right);

        bool isBST = leftAns.isBST && rightAns.isBST && node->val > leftAns.maxVal && node->val < rightAns.minVal;

        int currSum = 0;
        if(isBST){
            currSum = leftAns.sum + rightAns.sum + node->val;
            maxSum = max(maxSum, currSum);

            return TreeType(true, currSum, min(leftAns.minVal, node->val), max(rightAns.maxVal, node->val));
        }
        else{
            return TreeType(false, max(leftAns.sum, rightAns.sum), node->val, node->val);
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        if(maxSum > 0) return maxSum;
        else return 0;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)