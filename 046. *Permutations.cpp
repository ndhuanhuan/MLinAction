class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> result;
		vector<int> path;
		dfs(nums, path, result);
		return result;
	}

	void dfs(const vector<int>& nums, vector<int> &path, vector<vector<int> > &result)
	{
		if (path.size() == nums.size()) 
		{
			result.push_back(path);
			return;
		}
		for (auto i : nums) 
		{
			auto pos = find(path.begin(), path.end(), i);
			if (pos == path.end()) 
			{
				path.push_back(i);
				dfs(nums, path, result);
				path.pop_back();
			}
		}
	
	}

};
