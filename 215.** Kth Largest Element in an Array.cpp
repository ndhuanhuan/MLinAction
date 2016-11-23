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



class Solution {
public:   
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--)
            max_heapify(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[0], nums[heap_size - 1]);
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[heap_size];
    }
private:
    int heap_size;
};








