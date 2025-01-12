//Leetcode submission link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/1502609216/

class Codec {
public:

    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        queue<TreeNode*> q;
        q.push(root);

        string s = "";

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) s.append("#,");
            else{
                s.append(to_string(node->val) + ',');
            }

            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(node->left);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(node->right);
            }
        }

        return root;
    }
};

//Time complexity: O(n)
//Space complexity: O(n)
