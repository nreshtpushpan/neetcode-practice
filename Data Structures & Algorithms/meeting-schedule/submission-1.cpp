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
    bool pushInterval(vector<pair<int,int>> &intervals, const Interval &interval) {
        if(intervals.empty() || intervals.back().second <= interval.start) {
            intervals.push_back({interval.start, interval.end});
            return true;
        }
        return false;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>> intervalMerged;
        sort(intervals.begin(), intervals.end(), [&](const Interval &a, const Interval &b) {
            return a.start <= b.start;
        });
        for(auto interval : intervals) {
            if(!pushInterval(intervalMerged, interval)) return false;
        }
        return true;
    }
};
