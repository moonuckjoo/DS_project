#pragma once
#include "MemberQueueNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class MemberQueue
{
private:
	MemberQueueNode* head;
	int size;
	MemberQueueNode* tail;
public:
	MemberQueue();
	~MemberQueue();
	bool empty();
	bool full();
	bool push(string name, int age, string date, char type);
	bool pop();
	MemberQueueNode* front();
	

};

