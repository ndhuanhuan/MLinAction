// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int find_max(int freq[], bool excep[]) {
	int max_i = -1;
	int max = -1;
	for (char c = 'a'; c <= 'z'; c++) {
		if (!excep[c] && freq[c] > 0 && freq[c] > max) {
			max = freq[c];
			max_i = c;
		}
	}
	return max_i;
}

void create(char* str, int d, char ans[]) {
	int n = strlen(str);
	int freq[256] = { 0 };
	for (int i = 0; i < n; i++)
		freq[str[i]]++;

	int used[256] = { 0 };
	for (int i = 0; i < n; i++) {
		bool excep[256] = { false };
		bool done = false;
		while (!done) {
			int j = find_max(freq, excep);
			if (j == -1) {
				cout << "Error!\n";
				return;
			}
			excep[j] = true;
			if (used[j] <= 0) {
				ans[i] = j;
				freq[j]--;
				used[j] = d;    // used[j] which means the least distance between this position and the next position we can use this character ‘j’
				done = true;
			}
		}
		for (int i = 'a'; i < 'z'; i++)
			used[i]--;
	}
	ans[n] = '\0';
}

int main()
{
	char str[] = "aaaabbbccceedd";
	char ans[100];
	int distance = 2;
	create(str, 2, ans);

	for (int i = 0; i < strlen(str); i++)
		cout << ans[i] << ", ";
	cout << "\n";

	return 0;
}
