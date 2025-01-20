//Leetcode submission link: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/submissions/1514321329/

class Solution {
    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& leafNodes){

        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            leafNodes.insert(root);
        }

        if(prev != NULL){
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }

        makeGraph(root->left, root, adj, leafNodes);
        makeGraph(root->right, root, adj, leafNodes);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leafNodes;

        makeGraph(root, NULL, adj, leafNodes);

        int count = 0;

        for(auto leafNode : leafNodes){
            queue<TreeNode*> q;
            q.push(leafNode);

            unordered_set<TreeNode*> visited;
            visited.insert(leafNode);

            for(int level = 0; level <= distance; level++){
                int size = q.size();
                while(size--){
                    TreeNode* node = q.front();
                    q.pop();

                    if(leafNodes.count(node) && node != leafNode){
                        count++;
                    }

                    for(auto& adjNode : adj[node]){
                        if(!visited.count(adjNode)){
                            q.push(adjNode);
                            visited.insert(adjNode);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};

//Time complexity: O(n^2)
//Space complexity: O(n)