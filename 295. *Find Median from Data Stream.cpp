
//https://www.hrwhisper.me/leetcode-find-median-from-data-stream/
最大堆取最大，最小堆取最小


class MedianFinder {
	priority_queue<int> small, large;
public:
	// Adds a number into the data structure.
	void addNum(int num) {
		if (!large.empty() && -large.top() < num)
			large.push(-num);
		else
			small.push(num);
 
		if (small.size() - large.size() == 2) {
			large.push(-small.top());
			small.pop();
		}
		else if (small.size() - large.size() == -2) {
			small.push(-large.top());
			large.pop();
		}
	}
 
	// Returns the median of current data stream
	double findMedian() {
		if (small.size() > large.size()) return small.top();
		else if (small.size() < large.size()) return -large.top();
		return (small.top() - large.top()) / 2.0;
	}
};
