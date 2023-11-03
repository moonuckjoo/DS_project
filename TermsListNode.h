#pragma once
#include <iostream>


using namespace std;

class TermsBSTNode;

class TermsListNode
{
private:
	TermsListNode*	next;
	TermsListNode* prev;
	char type;
	int size;
	TermsBSTNode* root;
	
public:
	TermsListNode() {
		this->next = NULL;
		this->type = NULL;
		this->root = NULL;
		this->size = 0;
		this->prev = NULL;
	}
	~TermsListNode() {}
	TermsListNode* getPrev() { return this->prev; }
	void setPrev(TermsListNode* prev) { this->prev = prev; }
	TermsListNode*	getNext()		 { return this->next; }
	char gettype() { return this->type; }
	TermsBSTNode* getroot() { return this->root; }
	void settype(char type) { this->type = type; }
	void setNext(TermsListNode* next) { this->next = next; }
	void setroot(TermsBSTNode* root) { this->root = root; }
	void sizeup() { this->size++; }
	int getsize_List() { return this->size; }
	void setsize(int size) { this->size = size; }
};