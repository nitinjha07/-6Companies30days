//Leetcode submission link: https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/1514283204/

class TrieNode{
    public:
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode(){
        children = vector<TrieNode*>(26, NULL);
        isEnd = false;
    }
};

class WordDictionary {
    TrieNode* root;

    bool helper(string word, int idx, TrieNode* root){
        if(idx == word.size()) return root->isEnd;

        char ch = word[idx];

        if(ch == '.'){
            for(TrieNode* child : root->children){
                if(child && helper(word, idx+1, child)){
                    return true;
                }
            }
            return false;
        }
        else{
            if(root->children[ch-'a']){
                return helper(word, idx+1, root->children[ch-'a']);
            }
            else return false;
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for(auto ch : word){
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        return;
    }

    bool search(string word) {
        return helper(word, 0, root);
    }
};

//Time complexity: o(l) where l is the length of maximum sized word
//Space complexity: o(l)