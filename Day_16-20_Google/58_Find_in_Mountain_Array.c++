//Leetcode submission link: https://leetcode.com/problems/find-in-mountain-array/submissions/1514255952/

class Solution {
    int binarySearchInc(int l, int r, int target, MountainArray &mountainArr){
        while(l <= r){
            int mid = l + (r-l)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                l = mid+1;
            }
            else r = mid-1;
        }
        return -1;
    }

    int binarySearchDec(int l, int r, int target, MountainArray &mountainArr){
        while(l <= r){
            int mid = l + (r-l)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                r = mid-1;
            }
            else l = mid+1;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int l = 0;
        int r = len-1;

        while(l < r){
            int mid = l + (r-l)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid + 1;
            }
            else r = mid;
        }

        int maxIdx = l;

        int IncPart = binarySearchInc(0, maxIdx, target, mountainArr);
        if(IncPart != -1) return IncPart;

        return binarySearchDec(maxIdx+1, len-1, target, mountainArr);
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)