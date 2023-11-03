#include "NameBST.h"
#include "MemberQueueNode.h"
#include "TermsBST.h"

NameBST::NameBST() : root(nullptr)
{
	this->NameBST_size = 0;
}
NameBST::~NameBST()
{

}

NameBSTNode* NameBST::getRoot()
{
	return this->root;
}

NameBSTNode* NameBST::change_temrstoName(TermsBSTNode* infoNode) {
	NameBSTNode* changeNode = new NameBSTNode;
	changeNode->setinfo(infoNode->getname(), infoNode->getage(), infoNode->getdate(), infoNode->getex_date());
	return changeNode;
}

// insert



void NameBST::insert(NameBSTNode* curNode, NameBSTNode* TLNode) {



	if (this->root == NULL) { //if NameBST is not present
		NameBSTNode* newNode = new NameBSTNode; 
		newNode->setinfo(TLNode->getName(), TLNode->getAge(), TLNode->getDate(), TLNode->getExdate());
		this->root = newNode; 
		this->root->setLeft(NULL);
		this->root->setRight(NULL);
		this->root->setParent(NULL);
		curNode = this->root;
		this->NameBST_size++;
	}
	else if (curNode->getName() > TLNode->getName()) { //curNode is proactively behind the newNode
		if (curNode->getLeft() == NULL) { //If curNode dont have left child
			NameBSTNode* newNode = new NameBSTNode; 
			newNode->setinfo(TLNode->getName(), TLNode->getAge(), TLNode->getDate(), TLNode->getExdate());
			curNode->setLeft(newNode);
			newNode->setParent(curNode);
			this->NameBST_size++;
		}
		else { //If curNdoe have a left child, rerun the insert function and put it down
			if (curNode->getLeft()->getName() ==TLNode->getName())
				return;
			insert(curNode->getLeft(), TLNode);
		}
	}
	else if (curNode->getName() < TLNode->getName()) { //curNode is proactively ahead of the newNode
		if (curNode->getRight() == NULL) {
			NameBSTNode* newNode = new NameBSTNode; 
			newNode->setinfo(TLNode->getName(), TLNode->getAge(), TLNode->getDate(), TLNode->getExdate());
			curNode->setRight(newNode);
			newNode->setParent(curNode);
			this->NameBST_size++;
		}
		else { //Rerun insert if curNode have a right foot child
			if (curNode->getRight()->getName() == TLNode->getName())
				return;
			insert(curNode->getRight(), TLNode);


		}
	}
}
NameBSTNode* NameBST::recursive_search_name(NameBSTNode* current, string searchName) {
	//Setting Termination Conditions
	if (current == nullptr) {
		return nullptr;
	}
	// The name you are looking for matches the name of the current node
	if (searchName == current->getName()) {
		
		return current;
	}
// If the name you are looking for is smaller than the name of the current node,
// You must search in the left subtree.
	else if (searchName < current->getName()) {
		return recursive_search_name(current->getLeft(), searchName);
	}
// If the name you are looking for is larger than the name of the current node,
// You must search in the subtree on the right subtree.
	else {

		return recursive_search_name(current->getRight(), searchName);
	}
}


NameBSTNode* NameBST::search_name(string searchName) {
	NameBSTNode* result = recursive_search_name(root, searchName);

	if (result == nullptr)  //NO NAME
		return	nullptr;

	else { //YES NAME
		return result;

	}
}
//Date Version of the search
NameBSTNode* NameBST::recursive_search_Terms_date(NameBSTNode* current, string searchdate) {
	if (current == nullptr) {
		return nullptr;
	}

	if (searchdate == current->getExdate()) {
		return current;
	}
	else if (searchdate < current->getExdate()) {
		return recursive_search_Terms_date(current->getLeft(), searchdate);
	}
	else {
		return recursive_search_Terms_date(current->getRight(), searchdate);
	}
}

NameBSTNode* NameBST::search_date(string searchdate) {
	NameBSTNode* result = recursive_search_Terms_date(root, searchdate);

	if (result == nullptr)  //NO DATE
		return	nullptr;

	else { //YES DATE
		return result;

	}
}

// delete
bool  NameBST::deleteBST(NameBSTNode* curNode) {
	if (curNode == NULL)  //Return false if there is no node to delete
		return false;
	
	else { 
	//If a node with zero child is deleted (leafNode)
		if ((curNode->getLeft() == NULL) && (curNode->getRight()) == NULL) {
			//curNode == root
			if (curNode == this->root) { 
				delete curNode;
				root = NULL;
				this->NameBST_size--;
				return true;
			}
			else {  //Just delete nodes with 0 child if they are not root
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
				this->NameBST_size--;
				return true;
			}
		}
		//Remove a node with one child
		else if ((curNode->getLeft() == NULL) || (curNode->getRight() == NULL)) {
			if (curNode == root) { //case root
				if (curNode->getLeft() != NULL) { 
					curNode->getLeft()->setParent(NULL);
					this->root = curNode->getLeft();
					delete curNode;
					this->NameBST_size--;
					return true;
				}
				else if (curNode->getRight() != NULL) { 
					curNode->getRight()->setParent(NULL);
					this->root = curNode->getRight();
					delete curNode;
					this->NameBST_size--;
					return true;
				}
			}
			else { //case not root
				//case left sub tree
				if ((curNode->getName()) < (this->root->getName())) {
					//If leftchild exists, delete after connecting the parent and child nodes of the curNode
					if (curNode->getLeft() != NULL) {
						if (curNode->getParent()->getRight() == curNode)
						{
							curNode->getParent()->setRight(curNode->getLeft());
							curNode->getLeft()->setParent(curNode->getParent());
							curNode->setLeft(NULL);
							curNode->setParent(NULL);
							delete curNode;
							this->NameBST_size--;
							return true;
						}
						else {
							curNode->getParent()->setLeft(curNode->getLeft());
							curNode->getLeft()->setParent(curNode->getParent());
							curNode->setLeft(NULL);
							curNode->setParent(NULL);
							delete curNode;
							this->NameBST_size--;
							return true;
						}
					}
					else { //If rightchild exists, delete after connecting the parent and child nodes of the curNode
						curNode->getParent()->setLeft(curNode->getRight());
						curNode->getRight()->setParent(curNode->getParent());
						delete curNode;
						this->NameBST_size--;
						return true;
					}
				}
				//case right sub tree
				else { 
					if (curNode->getLeft() != NULL) { 
						if (curNode->getParent()->getLeft() == curNode) {
							curNode->getLeft()->setParent(curNode->getParent());
							curNode->setLeft(NULL);
							curNode->getParent()->setLeft(curNode->getLeft());
							curNode->setParent(NULL);
							delete curNode;
							this->NameBST_size--;
							return true;
						}
						else {
							curNode->getLeft()->setParent(curNode->getParent());
							curNode->setLeft(NULL);
							curNode->getParent()->setRight(curNode->getLeft());
							curNode->setParent(NULL);
							delete curNode;
							this->NameBST_size--;
							return true;
						}

					}
					else { 
						if (curNode->getParent()->getLeft() == curNode) {
							curNode->getRight()->setParent(curNode->getParent());
							curNode->setRight(NULL);
							curNode->getParent()->setLeft(curNode->getRight());
							curNode->setParent(NULL);
							delete curNode;
							this->NameBST_size--;
							return true;
						}
						else {
							curNode->getRight()->setParent(curNode->getParent());
							curNode->setRight(NULL);
							curNode->getParent()->setRight(curNode->getRight());
							curNode->setParent(NULL);
							delete curNode;
							this->NameBST_size--;
							return true;
						}

					}
				}

			}
		}
		//Remove a node with two children
		else { 
			NameBSTNode* rightsmall = curNode->getRight();
				if (rightsmall->getLeft() == NULL) {
					curNode->setinfo(rightsmall->getName(), rightsmall->getAge(), rightsmall->getDate(), rightsmall->getExdate());
					if (rightsmall->getRight() == NULL) {
					curNode->setRight(NULL);
					delete rightsmall;
					this->NameBST_size--;
					return true;
					}
					else { //rightchild of rightsmall if present
						rightsmall->getRight()->setParent(curNode);
						curNode->setRight(rightsmall->getRight());
						delete rightsmall;
						this->NameBST_size--;
						return true;
					}
				}
				else { //leftchild of rightsmall if present
					while (rightsmall->getLeft() != NULL) {
						rightsmall = rightsmall->getLeft();
					}
					curNode->setinfo(rightsmall->getName(), rightsmall->getAge(), rightsmall->getDate(), rightsmall->getExdate());
					if (rightsmall->getRight() == NULL) {
						rightsmall->getParent()->setLeft(NULL);
						rightsmall->setParent(NULL);
						delete rightsmall;
						this->NameBST_size--;
						return true;
					}
					else { //rightchild of leftsmall if present
						rightsmall->getRight()->setParent(rightsmall->getParent());
						rightsmall->getParent()->setLeft(rightsmall->getRight());
						rightsmall->setParent(NULL);
						rightsmall->setRight(NULL);
						delete rightsmall;
						this->NameBST_size--;
						return true;
					}
				}

		}

	}
		if (this->NameBST_size == 0)
		this->root = NULL;
	

}