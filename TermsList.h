#pragma once
#include "TermsListNode.h"

class TermsBST;
class MemberQueueNode;
class NameBST;

class TermsLIST
{
private:
	TermsListNode* head;
	int sizeList;


public:
	TermsLIST();
	~TermsLIST();

	TermsListNode* getHead();
	
	// insert
	void insert(MemberQueueNode* TLNode, TermsBST* TermsBST_A, TermsBST* TermsBST_B, TermsBST* TermsBST_C, TermsBST* TermsBST_D);
	// delete
	void delete_Termslist(TermsListNode* delNode);
	void size_update(TermsListNode* curNode, TermsBST* TermsBST_A, TermsBST* TermsBST_B, TermsBST* TermsBST_C, TermsBST* TermsBST_D);
	
};
