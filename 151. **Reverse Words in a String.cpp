//Not familiar with string APIs , recite this
//http://www.cplusplus.com/reference/string/string/find_first_not_of/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


//4 5 6 7 0 1 2
class Solution {
public:
	void reverseWords(string &s) {
		reverse(s.begin(), s.end());

		size_t begin = 0, end = 0, len = 0;
		while ((begin = s.find_first_not_of(" ", end)) != string::npos) {
			if ((end = s.find(" ", begin)) == string::npos) {
				end = s.length();
			}
			// Reverse each word in the string.
			cout << end << endl;
			reverse(s.begin() + begin, s.begin() + end);

			// Shift the word to avoid extra space.
			//Moves the elements in the range [first,last) into the range beginning at result
			move(s.begin() + begin, s.begin() + end, s.begin() + len);
			len += end - begin;
			//cout<<len<<endl;
			s[len++] = ' ';
		}

		//remove last space
		s.resize(len ? len - 1 : 0);
		return;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	string s = "a";
	 
	sol.reverseWords(s);
	std::cout << s+"haah" << endl;
	//    cout << sol.findKthLargest(v, 2) << endl;
	//    cout << sol.findKthLargest(v, 3) << endl;
	//    cout << sol.findKthLargest(v, 4) << endl;
	//    cout << sol.findKthLargest(v, 5) << endl;
	//    cout << sol.findKthLargest(v, 6) << endl;

	return 0;
}



class Solution {
public:
void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length();)
    {
        while(s[i] == ' ')
           s.erase(i, 1);
        int j = i+1;
        while(j < s.length() && s[j] != ' ')
            ++j;
        reverse(s.begin()+i, s.begin()+j);
        i = j+1;
    }
    
    while(s.length() > 0 && s[s.length()-1] == ' ')
        s.erase(s.length()-1, 1);
        
    return;
}
};
