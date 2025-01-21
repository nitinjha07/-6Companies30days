
//Approach 1
//Leetcode submission link: https://leetcode.com/problems/assign-cookies/submissions/1515333707/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int> child;
        priority_queue<int> cookie;

        for(auto ch : g) child.push(ch);
        for(auto ele : s) cookie.push(ele);

        int count = 0;
        while(!child.empty() && !cookie.empty()){
            int topChild = child.top();
            child.pop();

            int topCookie = cookie.top();
            if(topCookie >= topChild){
                cookie.pop();
                count++;
            }
        }

        return count;
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(n)


//Approach 2
//Leetcode submission link: https://leetcode.com/problems/assign-cookies/submissions/1515337761/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int i = 0, j = 0;

        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]) j++;
            i++;
        }

        return j;
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(1)