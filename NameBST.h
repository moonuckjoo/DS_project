#pragma once
#include "NameBSTNode.h"

class MemberQueueNode;
class TermsBSTNode;

class NameBST
{
private:
	NameBSTNode* root;
	int NameBST_size;


public:
	NameBST();
	~NameBST();

	NameBSTNode* getRoot();
	NameBSTNode* change_temrstoName(TermsBSTNode* infoNode);
	// insert
	void insert(NameBSTNode* curNode, NameBSTNode* TLNode);
	
	// search
	NameBSTNode* search_name(string searchName);
	NameBSTNode* recursive_search_name(NameBSTNode* root, string searchName);
	NameBSTNode* recursive_search_Terms_date(NameBSTNode* current, string searchdate);
	NameBSTNode* search_date(string searchdate);
	// delete
	bool deleteBST(NameBSTNode* curNode);
};