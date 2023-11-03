#include "TermsBST.h"
#include "TermsList.h"
#include "MemberQueue.h"
#include "NameBST.h"
#include <string>
#include <iostream>
using namespace std;

TermsBST::TermsBST()
{


	this->BST_size = 0;
	this->root = NULL;

}

TermsBST::~TermsBST()
{

}


TermsBSTNode* TermsBST::getRoot()
{
	return this->root;
}


void TermsBST::insert(TermsBSTNode* curNode, TermsBSTNode* TBNode) {


	if (this->root == NULL) { //dont have root
		TermsBSTNode* newNode = new TermsBSTNode; 
		newNode->setinfo(TBNode->getname(), TBNode->getage(), TBNode->getdate(), TBNode->getex_date());
		this->root = newNode; //새로운 노드를 루트 노드로
		this->root->setLeft(NULL);
		this->root->setRight(NULL);
		this->root->setParent(NULL);
		curNode = this->root;
		this->BST_size++;
	}
	else if (curNode->getex_date() > TBNode->getex_date()) { //curNode has a longer retention period than the newNode
		if (curNode->getLeft() == NULL) { //If curNdoe don't have a left child
			TermsBSTNode* newNode = new TermsBSTNode; 
			newNode->setinfo(TBNode->getname(), TBNode->getage(), TBNode->getdate(), TBNode->getex_date());
			curNode->setLeft(newNode); 
			newNode->setParent(curNode);
			this->BST_size++;
		}
		else { //If you have a leftchild, rerun the insert function and put it down
			if (curNode->getLeft()->getex_date() == TBNode->getex_date())
				return;
			insert(curNode->getLeft(), TBNode);
		}
	}
	else if (curNode->getex_date() <= TBNode->getex_date()) { 
		if (curNode->getRight() == NULL) {
			TermsBSTNode* newNode = new TermsBSTNode; 
			newNode->setinfo(TBNode->getname(), TBNode->getage(), TBNode->getdate(), TBNode->getex_date());
			curNode->setRight(newNode);
			newNode->setParent(curNode);
			this->BST_size++;
		}
		else { //Re-run insert if you have a right foot child
			if (curNode->getRight()->getex_date() == TBNode->getex_date())
				return;
			insert(curNode->getRight(), TBNode);


		}
	}
}

//return TermsBST size
int TermsBST::getsize() { return this->BST_size; };

//dataparsing
TermsBSTNode* TermsBST::ex_data_parsing(MemberQueueNode* MQNode) {
	//case A
	if (MQNode->gettype() == 'A') {
		TermsBSTNode* newNode = new TermsBSTNode;
		
		string year, month, day;
		bool parsing_point = false;
		int cnt = 0;
		for (char c : MQNode->getdate()) {
			if (c == '-') {
				parsing_point = true;
				cnt++;
				continue;
			}
			if (cnt == 0) {
				year += c;
			}
			else if (cnt == 1) {
				month += c;
			}
			else {
				day += c;
			}
		}

		
		int ex_year = stoi(year);
		int ex_month = stoi(month) + 6;
		int ex_day = stoi(day);
		if (ex_month / 12 == 1) { 
			ex_year++;
			ex_month = ex_month % 12;

		}

		//int-type expiration date converted back to string
		string ex_date1;
		//Consider the data format
		if (to_string(ex_month).length() == 1) { 
			if (to_string(ex_day).length() == 1)
				ex_date1 = to_string(ex_year) + "-0" + to_string(ex_month) + "-0" + to_string(ex_day);
			else 
				ex_date1 = to_string(ex_year) + "-0" + to_string(ex_month) + "-" + to_string(ex_day);
		}
		else {
			if (to_string(ex_day).length() == 1)
				ex_date1 = to_string(ex_year) + "-" + to_string(ex_month) + "-0" + to_string(ex_day);
			else
				ex_date1 = to_string(ex_year) + "-" + to_string(ex_month) + "-0" + to_string(ex_day);

		}

		//Enter parsed data
		newNode->setinfo(MQNode->getname(), MQNode->getage(), MQNode->getdate(), ex_date1); 
		newNode->setint_ex_date(ex_year, ex_month, ex_day); 
		return newNode;
	}

	//case B
	else if (MQNode->gettype() == 'B') {
		TermsBSTNode* newNode = new TermsBSTNode; 
		
		string year, month, day;
		bool parsing_point = false;
		int cnt = 0;
		for (char c : MQNode->getdate()) {
			if (c == '-') {
				parsing_point = true;
				cnt++;
				continue;
			}
			if (cnt == 0) {
				year += c;
			}
			else if (cnt == 1) {
				month += c;
			}
			else {
				day += c;
			}
		}
		
		int ex_year = stoi(year) + 1;
		int ex_month = stoi(month);
		int ex_day = stoi(day);

		
		string ex_date1;
		if (to_string(ex_month).length() == 1) { 
			if (to_string(ex_day).length() == 1) 
				ex_date1 = to_string(ex_year) + "-0" + to_string(ex_month) + "-0" + to_string(ex_day);
			else 
				ex_date1 = to_string(ex_year) + "-0" + to_string(ex_month) + "-" + to_string(ex_day);
		}
		else { 
			if (to_string(ex_day).length() == 1)
				ex_date1 = to_string(ex_year) + "-" + to_string(ex_month) + "-0" + to_string(ex_day);
			else 
				ex_date1 = to_string(ex_year) + "-" + to_string(ex_month) + "-0" + to_string(ex_day);
		}
		
		newNode->setinfo(MQNode->getname(), MQNode->getage(), MQNode->getdate(), ex_date1); 
		newNode->setint_ex_date(ex_year, ex_month, ex_day); 

		return newNode;
	}

	//case C
	else if (MQNode->gettype() == 'C') {
		TermsBSTNode* newNode = new TermsBSTNode; 
		
		string year, month, day;
		bool parsing_point = false;
		int cnt = 0;
		for (char c : MQNode->getdate()) {
			if (c == '-') {
				parsing_point = true;
				cnt++;
				continue;
			}
			if (cnt == 0) {
				year += c;
			}
			else if (cnt == 1) {
				month += c;
			}
			else {
				day += c;
			}
		}
		
		int ex_year = stoi(year) + 2;
		int ex_month = stoi(month);
		int ex_day = stoi(day);

		
		string ex_date1;
		if (to_string(ex_month).length() == 1) {
			if (to_string(ex_day).length() == 1) 
				ex_date1 = to_string(ex_year) + "-0" + to_string(ex_month) + "-0" + to_string(ex_day);
			else 
				ex_date1 = to_string(ex_year) + "-0" + to_string(ex_month) + "-" + to_string(ex_day);
		}
		else {
			if (to_string(ex_day).length() == 1)
				ex_date1 = to_string(ex_year) + "-" + to_string(ex_month) + "-0" + to_string(ex_day);
			else 
				ex_date1 = to_string(ex_year) + "-" + to_string(ex_month) + "-0" + to_string(ex_day);
		}
		
		newNode->setinfo(MQNode->getname(), MQNode->getage(), MQNode->getdate(), ex_date1); 
		newNode->setint_ex_date(ex_year, ex_month, ex_day); 
		return newNode;
	}

	//case D
	else {
		TermsBSTNode* newNode = new TermsBSTNode; 
		
		string year, month, day;
		bool parsing_point = false;
		int cnt = 0;
		for (char c : MQNode->getdate()) {
			if (c == '-') {
				parsing_point = true;
				cnt++;
				continue;
			}
			if (cnt == 0) {
				year += c;
			}
			else if (cnt == 1) {
				month += c;
			}
			else {
				day += c;
			}
		}
		
		int ex_year = stoi(year) + 3;
		int ex_month = stoi(month);
		int ex_day = stoi(day);

		
		string ex_date1;
		if (to_string(ex_month).length() == 1) { 
			if (to_string(ex_day).length() == 1) 
				ex_date1 = to_string(ex_year) + "-0" + to_string(ex_month) + "-0" + to_string(ex_day);
			else 
				ex_date1 = to_string(ex_year) + "-0" + to_string(ex_month) + "-" + to_string(ex_day);
		}
		else {
			if (to_string(ex_day).length() == 1)
				ex_date1 = to_string(ex_year) + "-" + to_string(ex_month) + "-0" + to_string(ex_day);
			else 
				ex_date1 = to_string(ex_year) + "-" + to_string(ex_month) + "-0" + to_string(ex_day);
		}
	
		newNode->setinfo(MQNode->getname(), MQNode->getage(), MQNode->getdate(), ex_date1); 
		newNode->setint_ex_date(ex_year, ex_month, ex_day); 
		return newNode;
	}
}


// RECUSIVE_SEARCH_DATE
TermsBSTNode* TermsBST::recursive_search_Terms_Date(TermsBSTNode* current, string searchdate) {
	if (current == nullptr) {

		return nullptr;
	}

	if (searchdate == current->getex_date()) {

		return current;
	}
	else if (searchdate < current->getex_date()) {

		return recursive_search_Terms_Date(current->getLeft(), searchdate);
	}
	else {
		return recursive_search_Terms_Date(current->getRight(), searchdate);
	}
}
//SEARCH_DATE
TermsBSTNode* TermsBST::search_Date(string searchdate) {
	TermsBSTNode* result = recursive_search_Terms_Date(root, searchdate);

	if (result == nullptr)  
		return	nullptr;

	else { 
		return result;

	}
}
//RECUSIVE_SEARCH_NAME
TermsBSTNode* TermsBST::recursive_search_Terms_Name(TermsBSTNode* current, string searchName) {
	//Termination conditions
	if (current == nullptr) {
		return nullptr;
	}

	if (searchName == current->getname()) {
		return current;
	}
	else if (searchName < current->getname()) {

		return recursive_search_Terms_Name(current->getLeft(), searchName);
	}
	else {
		return recursive_search_Terms_Name(current->getRight(), searchName);
	}
}
//SEARCH_NAME
TermsBSTNode* TermsBST::search_Name(string searchName) {
	TermsBSTNode* result = recursive_search_Terms_Name(root, searchName);

	if (result == nullptr)  //이름이 없는 경우
		return	nullptr;

	else { //이름을 찾은 경우
		return result;

	}
}

//DELETE
bool TermsBST::Terms_delete(TermsBSTNode* curNode) {
	if (curNode == NULL) { //No nodes to delete
		return false;
	}
	else { 
		//If nodes with 0 child are deleted (leafNode)
		if ((curNode->getLeft() == NULL) && (curNode->getRight()) == NULL) {
			if (curNode == this->root) { //curNode == root
				delete curNode;
				root = NULL;
				this->BST_size--;
				return true;
			}
			else { //Just delete nodes with 0 child if they are not root
				if (curNode->getParent()->getLeft() == curNode)
				{
					curNode->getParent()->setLeft(NULL);
					curNode->setParent(NULL);
				}
				else {
					curNode->getParent()->setRight(NULL);
					curNode->setParent(NULL);
				}
				delete curNode;
				this->BST_size--;
				return true;
			}
		}
		//If you remove a node with one child
		else if ((curNode->getLeft() == NULL) || (curNode->getRight() == NULL)) {
			if (curNode == root) {//curNode==root
				if (curNode->getLeft() != NULL) { //If only leftchild exists, delete the curNode after moving the root.
					curNode->getLeft()->setParent(NULL);
					this->root = curNode->getLeft();
					delete curNode;
					this->BST_size--;
					return true;
				}
				else if (curNode->getRight() != NULL) { //if only rightchild exists
					curNode->getRight()->setParent(NULL);
					this->root = curNode->getRight();
					delete curNode;
					this->BST_size--;
					return true;
				}
			}
			else { //If the node to delete is not the root node
				//For left subtrees
				if ((curNode->getex_date()) < (this->root->getex_date())) {
					//If leftchild exists, connect the parent and child nodes of the curNode and delete them
					if (curNode->getLeft() != NULL) {
						if (curNode->getParent()->getRight() == curNode)
						{
							curNode->getParent()->setRight(curNode->getLeft());
							curNode->getLeft()->setParent(curNode->getParent());
							curNode->setLeft(NULL);
							curNode->setParent(NULL);
							delete curNode;
							this->BST_size--;
							return true;
						}
						else {
							curNode->getParent()->setLeft(curNode->getLeft());
							curNode->getLeft()->setParent(curNode->getParent());
							curNode->setLeft(NULL);
							curNode->setParent(NULL);
							delete curNode;
							this->BST_size--;
							return true;
						}
					}
					else { //If rightchild exists, connect the parent and child nodes of the curNode and delete them
						curNode->getParent()->setLeft(curNode->getRight());
						curNode->getRight()->setParent(curNode->getParent());
						delete curNode;
						this->BST_size--;
						return true;
					}
				}
				//For the right subtree
				else { //If it is greater than or equal to the right node of the root
					if (curNode->getLeft() != NULL) { //If leftchild exists, connect the parent and child nodes of the curNode and delete them
						if (curNode->getParent()->getLeft() == curNode) {
							curNode->getLeft()->setParent(curNode->getParent());
							curNode->setLeft(NULL);
							curNode->getParent()->setLeft(curNode->getLeft());
							curNode->setParent(NULL);
							delete curNode;
							this->BST_size--;
							return true;
						}
						else {
							curNode->getLeft()->setParent(curNode->getParent());
							curNode->setLeft(NULL);
							curNode->getParent()->setRight(curNode->getLeft());
							curNode->setParent(NULL);
							delete curNode;
							this->BST_size--;
							return true;
						}

					}
					else { //If rightchild exists, connect the parent and child nodes of the curNode and delete them
						if (curNode->getParent()->getLeft() == curNode) {
							curNode->getRight()->setParent(curNode->getParent());
							curNode->setRight(NULL);
							curNode->getParent()->setLeft(curNode->getRight());
							curNode->setParent(NULL);
							delete curNode;
							this->BST_size--;
							return true;
						}
						else {
							curNode->getRight()->setParent(curNode->getParent());
							curNode->setRight(NULL);
							curNode->getParent()->setRight(curNode->getRight());
							curNode->setParent(NULL);
							delete curNode;
							this->BST_size--;
							return true;
						}

					}
				}

			}
		}
		//If you remove a node with two children
		else {
			TermsBSTNode* rightsmall = curNode->getRight();
			if (rightsmall->getLeft() == NULL) {
				curNode->setinfo(rightsmall->getname(), rightsmall->getage(), rightsmall->getdate(), rightsmall->getex_date());
				if (rightsmall->getRight() == NULL) {
					curNode->setRight(NULL);
					rightsmall->setParent(NULL);
					delete rightsmall;
					this->BST_size--;
					return true;
				}
				//rightchild of rightsmall if present
				else {
					rightsmall->getRight()->setParent(curNode);
					rightsmall->getParent()->setRight(curNode->getRight());
					rightsmall->setParent(NULL);
					rightsmall->setRight(NULL);
					delete rightsmall;
					this->BST_size--;
					return true;
				}
			}
			//If you have getleft of rightsmall
			else if (rightsmall->getRight() == NULL) {
				//Find the smallest subtree value larger than the curNode and change the key value
				while (rightsmall->getLeft() != NULL) {
					rightsmall = rightsmall->getLeft();
				}
				curNode->setinfo(rightsmall->getname(), rightsmall->getage(), rightsmall->getdate(), rightsmall->getex_date());
				if (rightsmall->getRight() == NULL) {
					rightsmall->getParent()->setLeft(NULL);
					rightsmall->setParent(NULL);
					delete rightsmall;
					this->BST_size--;
					return true;
				}
				else { //rightchild of rightsmall if present
					rightsmall->getRight()->setParent(rightsmall->getParent());
					rightsmall->getParent()->setLeft(rightsmall->getRight());
					rightsmall->setParent(NULL);
					rightsmall->setRight(NULL);
					delete rightsmall;
					this->BST_size--;
					return true;
				}
			}

		}

	}

	if (this->BST_size == 0)
		this->root = NULL;

}

