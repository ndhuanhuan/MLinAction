class Solution {
public:
	int longestConsecutive(const vector<int> &nums) {
		unordered_map<int, bool> used;
		for (auto i : nums) used[i] = false;
		int longest = 0;
		for (auto i : nums) {
			if (used[i]) continue;
			int length = 1;
			used[i] = true;
			for (int j = i + 1; used.find(j) != used.end(); ++j) {
				used[j] = true;
				++length;
			}
			for (int j = i - 1; used.find(j) != used.end(); --j) {
				used[j] = true;
				++length;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};



class Solution {
public:
    // using map
    /*
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>m;
        int ans = -1;
        for(int i : nums){
            if(m.find(i) == m.end()){
                int leftnum = (m.find(i - 1) != m.end() ? m[i - 1] : 0);
                int rightnum = (m.find(i + 1) != m.end() ? m[i + 1] : 0);
                m[i] = leftnum + rightnum + 1;
                m[i - leftnum] = m[i];
                m[i + rightnum] = m[i];
                ans = max(ans, m[i]);
            }
        }
        return ans;
    }
    */
    //using union find
    vector<int> size;
    vector<int> p;
    int ans;
    int find(int x){
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void unionFind(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb){ //if already union, return
            return;
        }
        p[pa] = pb;
        size[pb] += size[pa];
        ans = max(ans, size[pb]);
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        ans = 1;
        p = vector<int>(nums.size());
        size = vector<int>(nums.size(), 1);
        iota(p.begin(), p.end(), 0);
        unordered_map<int, int>m;
        int idx = -1;
        for(int i : nums){
            ++idx;
            if(m.find(i) == m.end()){
                m[i] = idx;
                if(m.find(i - 1) != m.end()){
                    unionFind(idx, m[i - 1]); //union two indexes
                }
                if(m.find(i + 1) != m.end()){
                    unionFind(idx, m[i + 1]);
                }
            }
        }
        return ans;
    }
};
