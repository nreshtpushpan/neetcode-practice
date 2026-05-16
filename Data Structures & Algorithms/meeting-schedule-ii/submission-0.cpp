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
        vector<pair<int,int>> timeSlots;
        for(auto interval : intervals) {
            timeSlots.push_back({interval.start, 1});
            timeSlots.push_back({interval.end, -1});
        }
        sort(timeSlots.begin(), timeSlots.end());
        int maxRooms = 0;
        int curCapacity = 0;
        for(auto time : timeSlots) {
            curCapacity += time.second;
            maxRooms = max(maxRooms, curCapacity);
        }
        return maxRooms;
    }
};
