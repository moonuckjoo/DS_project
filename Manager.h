#pragma once
#include "MemberQueue.h"
#include "TermsList.h"
#include "TermsBST.h"
#include "NameBST.h"
#include <fstream>
using namespace std;

class Manager
{
private:
	ifstream	fcmd;
	ofstream	flog;
	TermsLIST* Termslist = new TermsLIST;
	MemberQueue* memberQueue = new MemberQueue; 
	TermsBST* TermsBST_A = new TermsBST;
	TermsBST* TermsBST_B = new TermsBST;
	TermsBST* TermsBST_C = new TermsBST;
	TermsBST* TermsBST_D = new TermsBST;
	NameBST* namebst = new NameBST;

public:
	Manager();
	~Manager();
	void run(const char* command);
	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);
	void Printlist_A(TermsBSTNode* rootNode);
	void Printlist_B(TermsBSTNode* rootNode);
	void Printlist_C(TermsBSTNode* rootNode);
	void Printlist_D(TermsBSTNode* rootNode);
	void inorder_print(TermsBSTNode* root);
	void Printlist_name(NameBSTNode* rootNode);
	void inorder_print_name(NameBSTNode* root);
	void TermsBST_postorder_delete(TermsBST* BSTtype, TermsBSTNode* root, string searchdate);
	void NameBST_postorder_delete(NameBST* namebst, NameBSTNode* root, string searchdate);

};
