#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//4 5 6 7 0 1 2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right = nums.size()-1;

        while(left<right && nums[left] >= nums[right])
        {
            int mid = left+(right-left)/2;
            if(nums[mid]<nums[left])
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }

        return nums[left];

    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{4,5,6,7,0,1,2};
    cout << sol.findMin(v) << endl;
//    cout << sol.findKthLargest(v, 2) << endl;
//    cout << sol.findKthLargest(v, 3) << endl;
//    cout << sol.findKthLargest(v, 4) << endl;
//    cout << sol.findKthLargest(v, 5) << endl;
//    cout << sol.findKthLargest(v, 6) << endl;

    return 0;
}
