#include "PreFixTree.h"

//Task 1 (insert,find)
std::pair <node*, bool>PreFixTree::insert(string s, int val) {
	int length = s.length(), i = 0;
	node *ptr = root_, *temp;
	bool t;
	std::map<char, node*>::iterator it;
	while (length--) {
		t = true;
		it = ptr->map_.find(s[i]);
		if (it != ptr->map_.end())
			ptr = it->second;
		else {
			if (length==0)
				temp = new node(s[i], ptr->word_, val);
			else
				temp = new node(s[i], ptr->word_, 0);
			ptr->map_.insert(std::pair<char, node*>(s[i], temp));
			ptr = temp;
			t = false;	// false => didn't exist before
		}
		++i;	
	}
	return std::make_pair(ptr, t);
}
node* PreFixTree::find(string s) {
	int length = s.length(), i = 0;
	node *ptr = root_;
	std::map<char, node*>::iterator it;
	while (length--) {
		it = ptr->map_.find(s[i]);
		if (it != ptr->map_.end())
			ptr = it->second;
		else return nullptr;
		++i;
	}
	if (ptr->value_ == nullptr)return nullptr;
		return ptr;
}

//Task 2 (constructor, destructor,print)
PreFixTree::PreFixTree() :root_(nullptr) {}
PreFixTree::PreFixTree(string s[], int a[], int size) {
	root_ = new node('\0', "", 0);
	node* ptr, *temp;
	int i, j;
	std::map<char, node*>::iterator it;
	for (i = 0; i < size; ++i) {
		ptr = root_;
		for (j = 0; j < (int)s[i].length(); ++j) {
			it = ptr->map_.find(s[i][j]);
			if (it != ptr->map_.end()) {
				ptr = it->second;
			}
			else {
				if (j == s[i].length() - 1)
					temp = new node(s[i][j], ptr->word_, a[i]);
				else
					temp = new node(s[i][j], ptr->word_, 0);
				ptr->map_.insert(std::pair<char, node*>(s[i][j], temp));
				ptr = temp;
			}
		}
	}
}
PreFixTree::~PreFixTree() {
	delete root_;
	//to be continued;
}
void PreFixTree::print() {
	std::stack<node*> S;
	node* ptr = root_;
	std::map<char, node*>::iterator it;
	S.push(root_);
	while (S.empty() == false && ptr!=nullptr) {
		ptr = S.top();
		std::cout << ptr->word_ << "\n";
		S.pop();
		for (it = ptr->map_.begin(); it != ptr->map_.end(); ++it)
			S.push(it->second);
	}
}


//Task 3 (copy,assignment,move)
PreFixTree PreFixTree::operator=(PreFixTree && move)
{
	root_ = move.root_;
	move.root_ = nullptr;
	std::clog << "Move \n";
	return *this;
}
PreFixTree::PreFixTree(PreFixTree&& move) :root_(move.root_) {
	move.root_ = NULL;
}
PreFixTree::PreFixTree(const PreFixTree& copy) {
	if (copy.root_) {
		std::stack<node*> S_copy, Parent_this;
		std::map<char, node*>::iterator it;
		std::stack<char> I;
		node* ptr_copy = copy.root_, *parentT, *temp;
		char c;
		root_ = new node(copy.root_);
		parentT = root_;	

		for (it = ptr_copy->map_.begin(); it != ptr_copy->map_.end(); ++it) {
			Parent_this.push(root_);
			S_copy.push(it->second);
			I.push(it->first);
		}
		while (S_copy.empty() == false) {

			c = I.top();
			ptr_copy = S_copy.top();
			parentT = Parent_this.top();

			it = parentT->map_.find(c);
			if (it == parentT->map_.end()) {
				node* ptr_temp = new node(ptr_copy);
				parentT->map_.insert(std::pair<char, node*>(ptr_copy->word_.back(), ptr_temp));
				temp = ptr_temp;
			}
			S_copy.pop();
			Parent_this.pop();
			I.pop();

			for (it = ptr_copy->map_.begin(); it != ptr_copy->map_.end(); ++it) {
				Parent_this.push(temp);
				S_copy.push(it->second);
				I.push(it->first);
			}
		}
	}
	else root_ = nullptr;
}
PreFixTree PreFixTree::operator=(const PreFixTree& assignment)
{
	if (this==&assignment)return *this;
	//this->~PreFixTree();
	else {
		root_ = new node(assignment.root_);
		return *this;
	}
}

