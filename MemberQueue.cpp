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
		//���Ե� ��峢�� ť�� �ֱ�
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


bool MemberQueue::pop() //pop�ϸ� termsList�� name BST�� ���ť��尡 �Էµ�. ������ delNode�� �ϰ� delNode�� delete�������.
{
	if (empty() == false) { //��� ť�� ������� �ʴٸ�
		MemberQueueNode* delNode = this->head; //this->head�� ����Ű�� �ּҸ� �Ȱ��� ����Ű�� delNode ����
		if (this->size == 1) { //size�� 1�� ��� ť �ʱ�ȭ
			this->size--; //������ ����
			delete delNode;



		}
		else { //size�� 1���� ū ���
			this->head = this->head->getnext();
			this->size--; //������ ����
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
