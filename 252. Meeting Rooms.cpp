
//http://blog.csdn.net/u012290414/article/details/49356139
class Solution {  
public:  
    bool canAttendMeetings(vector<Interval>& intervals) {  
        int sz = intervals.size();  
        if (sz <= 1) {  
            return true;  
        }  
        sort(intervals.begin(), intervals.end(), comparator);  
        for (int i = 0; i < sz - 1; ++i) {  
            if (intervals[i].start == intervals[i+1].start or intervals[i].end > intervals[i+1].start) {  
                return false;  
            }  
        }  
        return true;  
    }  
private:  
    static bool comparator(Interval i1, Interval i2) {  
        return i1.start < i2.start;  
    }  
};  
