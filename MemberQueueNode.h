#pragma once
#include <iostream>

using namespace std;

class MemberQueueNode
{
private:

	MemberQueueNode* nextnode;
	MemberQueueNode* prevnode;
	string name;
	int age;
	string date;
	char type;

public:
	MemberQueueNode() {
		this->type = NULL;
		this->age = 0;
		this->nextnode = NULL;
		this->prevnode = NULL;
	}
	~MemberQueueNode() {}
	void setinfo(string name, int age, string date, char type) { 
		this->name = name;
		this->age = age;
		this->date = date;
		this->type = type;
	}
	string getname() { return this->name; }
	int getage() { return this->age; }
	string getdate() { return this->date; }
	char gettype() { return this->type; }


	void setnext(MemberQueueNode* nextNode) { this->nextnode = nextNode; }
	MemberQueueNode* getnext() { return this->nextnode; }
	void setprev(MemberQueueNode* prevNode) { this->prevnode = prevNode; }
	MemberQueueNode* getprev() { return this->prevnode; }
};