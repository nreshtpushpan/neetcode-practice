/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for(auto interval : intervals) {
            mp[interval.start] += 1;
            mp[interval.end] -= 1;
        }
        int count = 0, maxCount = 0;
        for(auto it : mp) {
            count += it.second;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
