/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    unordered_map<int, int> cache;
    int getValue(MountainArray &mountainArr, const int &index) {
        auto it = cache.find(index);
        if(it == cache.end()) {
            return cache[index] = mountainArr.get(index);
        }
        return it->second;
    }
    int search(MountainArray &mountainArr, const int &target, int l, int r, bool isForw) {
        while(l <= r) {
            int m = (r - l)/2 + l;
            int mid = getValue(mountainArr, m);
            if(mid == target) return m;
            
            if(target < mid) {
                if(isForw) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if(isForw) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
    
        // step 1: find peak
        int l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r-l)/2;
            if(getValue(mountainArr, m) < getValue(mountainArr, m+1))
                l = m + 1;
            else
                r = m;
        }
        int peak = l;
    
        // step 2: search ascending left side first (leftmost guarantee)
        int found = search(mountainArr, target, 0, peak, true);
        if(found != -1) return found;
    
        // step 3: search descending right side
        return search(mountainArr, target, peak+1, n-1, false);
    }
};