//Leetcode submission link: https://leetcode.com/problems/lru-cache/submissions/1517074288/

class LRUCache {
    unordered_map<int, int> mp;     //key, value
    int recently;                   //recently used key
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
        recently = -1;
    }

    int get(int key) {
        recently = key;
        return mp[key];
    }

    void put(int key, int value) {
        if(size <= mp.size()){
            if(mp.find(recently) != mp.end()) mp.erase(recently);
        }
        mp[key] = value;
        recently = key;
    }
};

//Time complexity: O(1) for both get and put
//Space complexity: O(n) where n is the capacity of the cache