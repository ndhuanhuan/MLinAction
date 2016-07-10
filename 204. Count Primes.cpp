// Leetcode.cpp : Defines the entry point for the console application.
//https://www.hrwhisper.me/leetcode-count-primes/


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrime(n, true);
		for (int i = 2; i*i < n; i++) 
		{
			if (isPrime[i]) 
			{
				for (int j = i*i; j < n; j += i) 
				{
					isPrime[j] = false;
				}
			}
		}

		int count = 0;
		for (int i = 2; i<n; i++) {
			if (isPrime[i]) {
				count++;
			}
		}
		return count;
	}
};
int main()
{
	Solution sol;
	cout << sol.countPrimes(100);
	return 0;
	
			 

}
