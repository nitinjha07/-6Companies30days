//Problem submission link: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/submissions/1522986529/

class DataStream {
    int prevVal;
    int prevFreq;
    int k;
    int val;
public:
    DataStream(int value, int k) {
        this->k = k;
        this->val = value;
        prevVal = -1;
        prevFreq = -1;
    }

    bool consec(int num) {
        if(prevVal == -1){
            prevVal = num;
            if(num == val){
                prevFreq = 1;
                return k == 1;
            }
            else prevFreq = 0;
            return false;
        }

        prevVal = num;
        if(num == val){
            prevFreq++;
            return k <= prevFreq;
        }
        else{
            prevFreq = 0;
        }
        return false;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)