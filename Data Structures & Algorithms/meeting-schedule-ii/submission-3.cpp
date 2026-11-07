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
        const int n = (int)intervals.size();
        if(n == 1) return n;
        vector<pair<int,int>> events;
        events.reserve(2*n);
        for(int i = 0; i < n; i++) {
            events.emplace_back(intervals[i].start, 1);
            events.emplace_back(intervals[i].end, -1);
        }
        sort(events.begin(), events.end());
        int cur_room = 0, max_room = 0;
        for(const auto &[_, delta] : events) {
            cur_room += delta;
            max_room = max(max_room, cur_room);
        }
        return max_room;
    }
};
