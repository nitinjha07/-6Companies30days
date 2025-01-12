//My Gfg profile link: https://www.geeksforgeeks.org/user/nitinkumaf2c2/
//Gfg problem link: hhttps://www.geeksforgeeks.org/problems/phone-directory4628/1

//Approach-1
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        int m = s.size();
        sort(contact, contact+n);

        vector<vector<string>> ans(m, vector<string>());

        for(int i=0; i<n; ++i) {
            string word = contact[i];
            if(i > 0 and word == contact[i-1])
                continue;
            int j=0;
            while(j < m and j < word.size() and s[j] == word[j])
                ans[j++].push_back(word);
        }
        for(int j=0; j<m; ++j) {
            if(ans[j].empty())
                ans[j].push_back("0");
        }
        return ans;
    }
};

//Time complexity: O(nlogn + m*n)
//Auxiliary Space: O(m*n)


//Approach-2
class TrieNode{
  public:
  char data;
  int count;
  bool isLeaf;
  TrieNode* children[26];


  TrieNode(char data){
      this->data = data;
      this->count =0;
      this->isLeaf = false;

      for(int i=0;i<26;i++){
          this->children[i] = NULL;
      }
  }

};


class Solution{
   void insertNode(TrieNode* &root, string str){
        if(str.length() == 0){
            root->isLeaf = true;
            return;
        }

        int index = str[0] -'a';

        TrieNode * child;

        if(root->children[index] != NULL){
          child = root->children[index];
        }
        else{
            child = new TrieNode(str[0]);
            root->count++;
            root->children[index] = child;
        }

        insertNode(child,str.substr(1));
    }


    void printSugesstion(TrieNode * curr,vector<string> &temp, string prefix){
        if(curr->isLeaf){
            temp.push_back(prefix);
        }


        for(char ch = 'a';ch <= 'z';ch++){
            int index = ch-'a';
            TrieNode *next = curr->children[index];

            if(next!= NULL)
            {
                prefix.push_back(ch);
                printSugesstion(next,temp,prefix);
                prefix.pop_back();
            }

        }
    }


    vector<vector<string>> getSuggestion(TrieNode* root, string query){
        string prefix = "";
        TrieNode *prev= root;
        vector<vector<string>> ans;

        for(int i=0;i<query.length();i++){
            char lastch = query[i];
            prefix.push_back(lastch);

            int index = lastch - 'a';
            TrieNode* curr = prev->children[index];

            if(curr != NULL){
                vector<string> temp;
                printSugesstion(curr,temp,prefix);
                ans.push_back(temp);
                temp.clear();
                prev = curr;

            }

            else{
                break;
            }
        }

        int remaining = query.size()-ans.size();
        for(int i=0;i<remaining;i++){
            ans.push_back({"0"});
        }

        return ans;
    }


public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        TrieNode* root = new TrieNode('\0');
        for(int i=0;i<n;i++){
            insertNode(root,contact[i]);
        }

        return getSuggestion(root,s);
    }
};

//Time complexity: O(n*L) + O(m*26^L)
//Space complexity: O(n*L) + O(m*n)