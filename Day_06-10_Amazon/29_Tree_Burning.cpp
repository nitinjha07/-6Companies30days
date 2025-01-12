//Leetcode submission link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/submissions/1503767895/

class Solution {
    TreeNode* getParents(TreeNode* root, unordered_map<int, TreeNode*>& parent, int& start){
        TreeNode* startNode = NULL;
        parent[root->val] = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start) startNode = node;

            if(node->left){
                q.push(node->left);
                parent[node->left->val] = node;
            }

            if(node->right){
                q.push(node->right);
                parent[node->right->val] = node;
            }
        }
        return startNode;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> parent;
        TreeNode* startNode = getParents(root, parent, start);

        int totalTime = 0;

        queue<pair<TreeNode*, int>> q;
        q.push({startNode, totalTime});

        unordered_map<int, bool> vis;
        vis[start] = 1;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int time = q.front().second;
            totalTime = time;
            q.pop();

            if(parent[node->val] && !vis[parent[node->val]->val]){
                vis[parent[node->val]->val] = 1;
                q.push({parent[node->val], time+1});
            }

            if(node->left && !vis[node->left->val]){
                vis[node->left->val] = 1;
                q.push({node->left, time+1});
            }

            if(node->right && !vis[node->right->val]){
                vis[node->right->val] = 1;
                q.push({node->right, time+1});
            }
        }

        return totalTime;
    }
};

//Time complexity: O(n) where n is the number of nodes in the tree
//Space complexity: O(n)