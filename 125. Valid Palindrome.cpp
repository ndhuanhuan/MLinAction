#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {

public:
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = prev(s.end());
        while (left < right) {
            if (!isalnum(*left)) {
                ++left;
            } else if (!isalnum(*right)) {
                --right;
            } else if (tolower(*left) != tolower(*right)) {
                return false;
            } else {
                ++left, --right;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s  ="bcdedcb";
    vector<int> v{4,5,6,7,0,1,2};

    cout << sol.isPalindrome(s) << endl;
//    cout << sol.findKthLargest(v, 2) << endl;
//    cout << sol.findKthLargest(v, 3) << endl;
//    cout << sol.findKthLargest(v, 4) << endl;
//    cout << sol.findKthLargest(v, 5) << endl;
//    cout << sol.findKthLargest(v, 6) << endl;

    return 0;
}
