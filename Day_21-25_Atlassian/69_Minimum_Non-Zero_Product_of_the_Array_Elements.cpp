//Leetcode submission link: https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/submissions/1517675252/

class Solution {
    long long MOD = 1e9 + 7;
    long long exp(long long a, long long b){
        long long result = 1;
        while(b > 0){
            if(b & 1){  //if b is odd we will mulitply with a
                result = (result*a)%MOD;
            }
            a = ((a%MOD)*(a%MOD))%MOD;
            b >>= 1;
        }
        return result;
    }
public:
    int minNonZeroProduct(int p) {
        long long maxVal = (1LL<<p) - 1;
        long long k = maxVal/2;         //we can make maxVal/2 numbers equal to '1' and 'maxVal-1'
        long long n = maxVal-1;

        long long ans = exp(n, k);       //multiplying n to k times
        return ans*(maxVal%MOD)%MOD;
    }
};

//Time complexity: O(log(p))
//Space complexity: O(1)