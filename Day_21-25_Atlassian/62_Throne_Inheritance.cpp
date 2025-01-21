//Leetcode submission link: https://leetcode.com/problems/throne-inheritance/submissions/1515379474/

class ThroneInheritance {
    unordered_set<string> deadPeople;
    unordered_map<string, vector<string>> child;
    string king;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        child[parentName].push_back(childName);
    }

    void death(string name) {
        deadPeople.insert(name);
    }

    void dfs(string root, vector<string>& ans){
        if(!deadPeople.count(root)){
            ans.push_back(root);
        }

        for(auto& ch : child[root]){
            dfs(ch, ans);
        }

        return;
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(king, ans);
        return ans;
    }
};

//Time complexity: O(n)
//Space complexity: O(n)