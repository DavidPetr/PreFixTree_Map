#include "PreFixTree.h"
int main() {
	string keys[8] = {"to","tea","ted","ten","A","i","in","inn"};
	int values[8] = { 7,3,4,12,15,11,5,9 };
	PreFixTree T(keys, values, 8),C(T),A;
	
	/*
	//Trie print test
	T.print();

	//insert(string,int value) test
	std::pair<node*, bool> p = T.insert("tea", 28);
	std::cout <<"Existed before="<< p.second <<" Value="<< *p.first->value_ <<"\n";
	
	//find(string) test
	if (T.find("too") != nullptr)std::clog << T.find("to")->word_ << " ";
	else std::clog << "Not Existed Word\n ";
	
	//assignment test
	A=C;	
	A.print();
	
	*/
	system("PAUSE");
	return 0;
}