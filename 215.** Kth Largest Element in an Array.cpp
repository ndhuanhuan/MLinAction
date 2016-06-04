//quick sort
//http://www.cnblogs.com/easonliu/p/4523941.html
//http://www.algolist.net/Algorithms/Sorting/Quicksort


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

private:
    void quickSort(vector<int>& nums, int left, int right)
    {
        int i=left, j = right;
        int pivot = nums[(i+j)/2];
        int tmp;

        while(i<=j){
            while (nums[i]<pivot)
            {
                i++;
            }
            while(nums[j]>pivot)
            {
                j--;
            }
            if(i<=j)
            {
                tmp = nums[i];
                nums[i]=nums[j];
                nums[j] = tmp;
                i++;
                j--;
            }
        }

        if (left<j)
            quickSort(nums,left,j);
        if (i<right)
            quickSort(nums,i,right);

    }


public:
    int findKthLargest(vector<int>& nums, int k) {
       quickSort(nums,0,nums.size()-1);
//       for(auto i:nums)
//        {
//            cout<< i <<endl;
//        }
       return nums[nums.size()-k];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{3,2,1,5,6,4,4,7};
    cout << sol.findKthLargest(v, 1) << endl;
    cout << sol.findKthLargest(v, 2) << endl;
    cout << sol.findKthLargest(v, 3) << endl;
    cout << sol.findKthLargest(v, 4) << endl;
    cout << sol.findKthLargest(v, 5) << endl;
    cout << sol.findKthLargest(v, 6) << endl;

    return 0;
}
