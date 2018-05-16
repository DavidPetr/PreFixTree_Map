#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
using string = std::string;

struct node {
	int* value_ = nullptr;
	string word_ = "";
	std::map<char, node*> map_;
	node() {};
	node(char key, string parentKey, int val, node *p = nullptr)
	{
		if (val != 0)value_ = new int(val);
		word_ = parentKey;
		if (key != '\0')word_ += key;
		if (p != nullptr)map_[key] = p;
	}
	node(const node* copy){
		if (copy->value_)value_ = new int(*copy->value_);
		else value_ = nullptr;
		word_ = copy->word_;
	}
};
class PreFixTree {
public:
	PreFixTree();
	PreFixTree(string keys[],int values[],int size);
	PreFixTree(const PreFixTree&);
	PreFixTree(PreFixTree&&);
	PreFixTree operator=(const PreFixTree& assignment);//half done
	PreFixTree operator=(PreFixTree&& move);
	~PreFixTree();//half done
	void print();
	std::pair<node*, bool>insert(string key, int value);
	node* find(string);
private:
	node* root_;
};