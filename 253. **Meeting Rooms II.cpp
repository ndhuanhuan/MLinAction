http://blog.csdn.net/pointbreak1/article/details/48840671
//https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/meeting-rooms-ii.cpp
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (const auto& i : intervals) {
            starts.emplace_back(i.start);
            ends.emplace_back(i.end);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int min_rooms = 0, cnt_rooms = 0;
        int s = 0, e = 0;
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                ++cnt_rooms;  // Acquire a room.
                // Update the min number of rooms.
                min_rooms = max(min_rooms, cnt_rooms);
                ++s;
            } else {
                --cnt_rooms;  // Release a room.
                ++e;
            }
        }
        return min_rooms;
    }
};
