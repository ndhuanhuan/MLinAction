// Not very familiar with this.
// Good reference: http://yucoding.blogspot.com/2015/06/leetcode-question-implement-trie-prefix.html
//http://blog.csdn.net/lisonglisonglisong/article/details/45584721

// Leetcode.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;


class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		isWord = false;
	}
	bool isWord;
	unordered_map<char, TrieNode*> children;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		if (word.size() == 0) return;
		TrieNode* node = root;
		for (int i = 0; i < word.size(); i++) 
		{
			if (node->children.find(word[i]) == node->children.end()) 
			{
				node->children[word[i]] = new TrieNode();

			}
			node = node->children[word[i]];
		}
		node->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		if (word.size() == 0) return false;
		TrieNode* node = root;
		for (int i = 0; i < word.size(); i++) 
		{
			if (node->children.find(word[i]) == node->children.end()) 
			{
				return false;
			}
			node = node->children[word[i]];
		}
		return node->isWord;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		if (prefix.size() == 0) return false;
		TrieNode* node = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (node->children.find(prefix[i]) == node->children.end())
			{
				return false;
			}
			node = node->children[prefix[i]];
		}
		return true;
	}

private:
	TrieNode* root;
};
int main()
{
	Trie trie;
	//trie.insert("abc");
	//trie.search("abc");
	return 0;
	
			 

}
