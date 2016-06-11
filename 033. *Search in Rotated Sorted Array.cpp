class Solution {
public:
	int search(vector<int>& nums, int target) {
		int first = 0, last = nums.size();
		while (first != last) 
		{
			const int mid = first + (last - first) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[first] <= nums[mid]) 
			{
				if (nums[first] <= target&&nums[mid] > target) 
				{
					last = mid;
				}
				else 
				{
					first = mid + 1;
				}
			}
			else 
			{
				if (nums[mid]<target&&target<=nums[last-1]) 
				{
					first = mid + 1;
				}
				else 
				{
					last = mid;
				}
			}
		}
        return -1;
	}
};
int main()
{
	Solution s;
	//vector<vector<int> > matrix = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 },{ 10, 11, 12 } };
	vector<int> nums{ 4,5,6,7,0,1,2 };
	//cout<<sol.compareVersion("1.1","1.23")<<endl;
	cout<<s.search(nums, 6)<<endl;

	return 0;
}
