#include "MemberQueue.h"


MemberQueue::MemberQueue()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

MemberQueue::~MemberQueue()
{

}

bool MemberQueue::empty()
{
	if (this->size == 0)
		return true;
	else
		return false;
}

bool MemberQueue::full()
{
	if (this->size != 100) //#define MAXSIZE 100
		return false;
	else
		return true;
}

bool MemberQueue::push(string name, int age, string date, char type)//Import data to file I/O and insert information one by one after parsing
{
	if (empty() == true) { //If the MemberQueue is empty
		MemberQueueNode* newNode = new MemberQueueNode;
		newNode->setinfo(name, age, date, type);
		newNode->setprev(NULL);
		newNode->setnext(NULL);
		this->head = newNode;
		this->tail = newNode;
		this->size++;
		return true;
	}
	else if (!full()) { //When the queue is not full

		MemberQueueNode* newNode = new MemberQueueNode;
		newNode->setinfo(name, age, date, type);
		//삽입된 노드끼리 큐에 넣기
		this->tail->setnext(newNode);
		newNode->setprev(this->tail);
		this->tail = newNode;
		this->tail->setnext(NULL);
		this->size++; 
		return true;
	}

	else { //Queue is full
		return false;
	}
}


bool MemberQueue::pop() //pop하면 termsList와 name BST로 멤버큐노드가 입력됨. 리턴을 delNode로 하고 delNode를 delete해줘야함.
{
	if (empty() == false) { //멤버 큐가 비어있지 않다면
		MemberQueueNode* delNode = this->head; //this->head가 가리키는 주소를 똑같이 가리키는 delNode 선언
		if (this->size == 1) { //size가 1인 경우 큐 초기화
			this->size--; //사이즈 감소
			delete delNode;



		}
		else { //size가 1보다 큰 경우
			this->head = this->head->getnext();
			this->size--; //사이즈 감소
			delete delNode;
		}
		return true;
	}
	else {
		return false;
	}
}

MemberQueueNode* MemberQueue::front()
{
	return this->head;
}
