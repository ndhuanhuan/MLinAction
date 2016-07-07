class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > result; 
		vector<int> path; 
		dfs(nums, path, result, target, 0);
		return result;
	}
private:
	void dfs(vector<int>& nums, vector<int>& path, vector<vector<int> > &result,
		int gap, int start) {
		if (gap == 0) { 
			result.push_back(path);
			return;
		}
		int prev = -1;
		for (size_t i = start; i < nums.size(); i++) { 
			if (prev == nums[i]) continue;
			if (gap < nums[i]) return; 
			prev = nums[i];
			path.push_back(nums[i]); 
			dfs(nums, path, result, gap - nums[i], i+1);
			path.pop_back(); 
		}
	}
};
