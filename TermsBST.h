#pragma once
#include "TermsBSTNode.h"
class MemberQueueNode;
class NameBST;
class TermsBST
{
private:
	TermsBSTNode* root;
	int BST_size;
public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();
	int getsize();
	TermsBSTNode* ex_data_parsing(MemberQueueNode* MQNode);
	// insert
	void insert(TermsBSTNode* curNode,TermsBSTNode* TBNode);

	// print

	// delete
	bool Terms_delete(TermsBSTNode* curNode);
	
	TermsBSTNode* search_Date(string searchdate);
	TermsBSTNode* recursive_search_Terms_Date(TermsBSTNode* current, string searchdate);
	TermsBSTNode* search_Name(string searchName);
	TermsBSTNode* recursive_search_Terms_Name(TermsBSTNode* root, string searchName);
	void TermsBST_postorder_delete(TermsBSTNode* root, string searchdate);
};