#pragma once
using namespace std;
#include <string>
#include <iostream>

class NameBSTNode
{
private:
	NameBSTNode* parent;
	NameBSTNode*	left;
	NameBSTNode*	right;
	string name;
	int age;
	string date;
	string ex_date; //Personal information expiration date
	

public:
	NameBSTNode() {
		this->left = NULL;
		this->right = NULL;
		this->name = "";
		this->age = 0;
		this->date = "";
		this->ex_date = "";
		this->parent = NULL;
	}
	~NameBSTNode() {}

	NameBSTNode*	getLeft()			{ return this->left; }
	NameBSTNode*	getRight()			{ return this->right; }
	NameBSTNode* getParent() { return this->parent; }
	void setLeft(NameBSTNode* left)						{ this->left = left; }
	void setRight(NameBSTNode* right)					{ this->right = right; }
	void setinfo(string name, int age, string date, string ex_date) {
		this->name = name;
		this->age = age;
		this->date = date;
		this->ex_date = ex_date;
	}
	void setParent(NameBSTNode* parent) { this->parent = parent; };
	string getName() { return this->name; }
	int getAge() { return this->age; }
	string getDate() { return this->date; }
	string getExdate() { return this->ex_date; }



};