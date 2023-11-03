#include "TermsList.h"
#include "TermsBST.h"
#include "MemberQueue.h"

using namespace std;

TermsLIST::TermsLIST() : sizeList(0), head(nullptr)
{

}
TermsLIST::~TermsLIST()
{

}

TermsListNode* TermsLIST::getHead()
{
	return head;
}




// insert
void TermsLIST::insert(MemberQueueNode* TLNode, TermsBST* TermsBST_A, TermsBST* TermsBST_B, TermsBST* TermsBST_C, TermsBST* TermsBST_D) {
	//If there's nothing on the list
	if (this->sizeList == 0) {
		TermsListNode* newNode = new TermsListNode; 
		if (TLNode->gettype() == 'A') {
			newNode->settype(TLNode->gettype()); 
			newNode->setroot(TermsBST_A->getRoot());
		}
		else if (TLNode->gettype() == 'B') {
			newNode->settype(TLNode->gettype()); 
			newNode->setroot(TermsBST_B->getRoot());
		}
		else if (TLNode->gettype() == 'C') {
			newNode->settype(TLNode->gettype()); 
			newNode->setroot(TermsBST_C->getRoot());
		}
		else {//If the last type of list is D
			newNode->settype(TLNode->gettype());
			newNode->setroot(TermsBST_D->getRoot());
		}
		newNode->sizeup();
		this->head = newNode;
		this->sizeList++; 
	}

	//When a node enters the TermsList for the second time
	else if (this->sizeList == 1) {
		TermsListNode* curNode; 
		curNode = this->head; 

		//Type duplication check
		if (curNode->gettype() == TLNode->gettype()) {
			curNode->sizeup();
		}
		else {//Connect a link-drip when the type of the new node is a type that was not in the TermsList
			TermsListNode* newNode = new TermsListNode;
			if (TLNode->gettype() == 'A') {
				newNode->settype(TLNode->gettype());
				newNode->setroot(TermsBST_A->getRoot());
			}
			else if (TLNode->gettype() == 'B') {
				newNode->settype(TLNode->gettype()); 
				newNode->setroot(TermsBST_B->getRoot());
			}
			else if (TLNode->gettype() == 'C') {
				newNode->settype(TLNode->gettype()); 
				newNode->setroot(TermsBST_C->getRoot());
			}
			else { //If the last type of list is D
				newNode->settype(TLNode->gettype());
				newNode->setroot(TermsBST_D->getRoot());
			}
			curNode->setNext(newNode);
			newNode->setPrev(curNode);
			newNode->sizeup();
			this->sizeList++;
		}

	}

	//When a node enters the TermsList for the third time
	else if (this->sizeList == 2) {
		TermsListNode* curNode; 
		curNode = this->head; 

		//Type duplication check
		if (curNode->gettype() == TLNode->gettype()) {
			curNode->sizeup();
		}
		//Type duplication check
		else if ((curNode->getNext()->gettype()) == TLNode->gettype()) {
			curNode->getNext()->sizeup();
		}

		else {//Connect a link-drip when the type of the new node is a type that was not in the TermsList
			TermsListNode* newNode = new TermsListNode;
			if (TLNode->gettype() == 'A') {
				newNode->settype(TLNode->gettype()); 
				newNode->setroot(TermsBST_A->getRoot());
			}
			else if (TLNode->gettype() == 'B') {
				newNode->settype(TLNode->gettype());
				newNode->setroot(TermsBST_B->getRoot());
			}
			else if (TLNode->gettype() == 'C') {
				newNode->settype(TLNode->gettype());
				newNode->setroot(TermsBST_C->getRoot());
			}
			else { //If the last type of list is D
				newNode->settype(TLNode->gettype()); 
				newNode->setroot(TermsBST_D->getRoot());
			}
			curNode->getNext()->setNext(newNode);
			newNode->setPrev(curNode->getNext());
			newNode->sizeup();
			this->sizeList++; //increase list size
		}

	}


	//When a node enters the TermsList for the fourth time
	else {
		TermsListNode* curNode; 
		curNode = this->head;
		////Type duplication check
		if (curNode->gettype() == TLNode->gettype()) {
			curNode->sizeup();
		}
	//Type duplication check
		else if ((curNode->getNext()->gettype()) == TLNode->gettype()) {
			curNode->getNext()->sizeup();
		}
		//Type duplication check
		else if ((curNode->getNext()->getNext()->gettype()) == (TLNode->gettype())) {
			curNode->getNext()->getNext()->sizeup();
		}

		else { //If there is no overlap in any case and the fourth node is not on the list, determine it to be the last type
			TermsListNode* newNode = new TermsListNode;
			if (TLNode->gettype() == 'A') {
				newNode->settype(TLNode->gettype()); 
				newNode->setroot(TermsBST_A->getRoot());
			}
			else if (TLNode->gettype() == 'B') {
				newNode->settype(TLNode->gettype());
				newNode->setroot(TermsBST_B->getRoot());
			}
			else if (TLNode->gettype() == 'C') {
				newNode->settype(TLNode->gettype()); 
				newNode->setroot(TermsBST_C->getRoot());
			}
			else { //If the last type of list is D
				newNode->settype(TLNode->gettype()); 
				newNode->setroot(TermsBST_D->getRoot());
			}
			curNode->getNext()->getNext()->setNext(newNode);
			newNode->setNext(NULL);
			newNode->setPrev(curNode->getNext()->getNext());
			newNode->sizeup();
		}

	}
}

// delete
//Delete to match the location of the node you want to delete
void TermsLIST::delete_Termslist(TermsListNode* delNode) {
	//When first erasing a node
	if (delNode == this->head){
		delNode->getNext()->setPrev(NULL);
		this->head = delNode->getNext();
		delNode->setNext(NULL);
		delete delNode;
	}
	//When erasing the second or third node
	else if ((delNode->getNext() != NULL)) {
		delNode->getNext()->setPrev(delNode->getPrev());
		delNode->getPrev()->setNext(delNode->getNext());
		delNode->setNext(NULL);
		delNode->setPrev(NULL);
	}
	//When erasing the last node
	else {
		delNode->getPrev()->setNext(NULL);
		delNode->setPrev(NULL);
		delete delNode;
	}
}
//Delete LIST after updating size
void TermsLIST::size_update(TermsListNode* curNode, TermsBST* TermsBST_A, TermsBST* TermsBST_B, TermsBST* TermsBST_C, TermsBST* TermsBST_D) {

		if (curNode->gettype() == 'A') {
			curNode->setsize(TermsBST_A->getsize());
		}
		else if (curNode->gettype() == 'B') {
			curNode->setsize(TermsBST_B->getsize());
		}
		else if (curNode->gettype() == 'C') {
			curNode->setsize(TermsBST_C->getsize());
		}
		else if (curNode->gettype() == 'D') {
			curNode->setsize(TermsBST_D->getsize());
		}
		curNode = this->head;

		while (curNode != NULL) {
			if (curNode->getsize_List() == 0) {
				TermsListNode* delNode = curNode;
				delete_Termslist(delNode);
			}
				curNode = curNode->getNext();
	}



}





