//Leetcode submission link: https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/submissions/1521305620/

class Solution {
    bool valid(long long mid, long long d1, long long d2, long long c1, long long c2)
    {
        long long valid1 = mid-mid/d1; // numbers which are not divisible by d1
        long long valid2 = mid-mid/d2; // numbers which are not divisible by d2
        long long lcm = (d1*1LL*d2)/__gcd(d1, d2);

        long long validboth = mid-mid/lcm; // number which are not divisible by both d1 and d2
        return validboth>=c1+c2 and valid1>=c1 and valid2>=c2;
    }

public:
    int minimizeSet(int d1, int d2, int c1, int c2) {
        int low = 0;
        long long high = 1e12;

        int ans = -1;

        while(low <= high)
        {
            long long mid = low+(high-low)/2;
            if(valid(mid, d1, d2, c1, c2))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};

//Time complexity: O(log(1e12))
//Space complexity: O(1)