#pragma once
using namespace std;
#include <string>

class TermsBSTNode
{
private:

	TermsBSTNode*	left;
	TermsBSTNode*	right;
	TermsBSTNode* parent;
	string name;
	int age;
	string date;
	string ex_date; //개인정보 만료일자
	
	//int형 개인정보 만료일자
	int ex_year, ex_month, ex_day;



public:
	TermsBSTNode() {
		this->left = NULL;
		this->right = NULL;
		this->name = "";
		this->age = 0;
		this->date = "";
		this->ex_date = "";
		
		this->ex_year = 0;
		this->ex_month = 0;
		this->ex_day = 0;

	}
	~TermsBSTNode() {}

	TermsBSTNode*	getLeft()			{ return this->left; }
	TermsBSTNode*	getRight()			{ return this->right; }
	TermsBSTNode* getParent() { return this->parent; }
	void setLeft (TermsBSTNode* left)	{ this->left = left; }
	void setRight(TermsBSTNode* right)	{ this->right = right; }
	void setinfo(string name, int age, string date, string ex_date) {
		this->name = name;
		this->age = age;
		this->date = date;
		this->ex_date = ex_date;
	}
	void setint_ex_date(int ex_year, int ex_month, int ex_day) {
		this->ex_year = ex_year;
		this->ex_month = ex_month;
		this->ex_day = ex_day;
	}
	void setParent(TermsBSTNode* parent) { this->parent = parent; }

	int getint_ex_year() { return this->ex_year; }
	int getint_ex_month() { return this->ex_month; }
	int getint_ex_day() { return this->ex_day; }

	string getname() { return this->name; }
	int getage() { return this->age; }
	string getdate() { return this->date; }
	string getex_date() { return this->ex_date; }

};