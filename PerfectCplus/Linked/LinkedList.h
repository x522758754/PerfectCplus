/*
����
*/
#pragma once
#include "LinkedNode.h"

template<class T>
class LinkedList
{
public:
	

public:
	LinkedList()
	{
		head = new LinkedNode();
		head->next = nullptr;
	};
	~LinkedList()
	{
		//ɾ�����нڵ�
		delete head;
		head = nullptr;
	};

	void print()
	{
		_NodePtr p = head;
		while (p->next)
		{

		}
	}

	//����ĳ���
	int length()
	{
		int n = 0;
		LinkedNode<T>* p = head;
		while (p)
		{
			p = p->next;
			n++;
		}

		return n;
	}

	//�Ƿ��л�
	bool loop()
	{
		return false;
	}

	//����
	void insert(T& t, int pos)
	{
		if (pos < 0)
		{
			pos = 0;
		}

		_NodePtr p = head;
		int n = 0;
		while (p)
		{
			if (pos <= n)
			{
				break;
			}
			n++;
			p = p->next;
		}

		_NodePtr pNewNode = new LinkedNode();
		pNewNode->pData = &t;
		pNewNode->next = p->next;
		p->next = pNewNode;
	}

	//�Ƴ�
	void remove(_NodePtr pNode)
	{
		auto p = pNode->next;
		pNode->pData = p->pData;
		pNode->next = p->next;
	}

public:
	_NodePtr* head;

private:

};

template<class T>
using _NodePtr = typename LinkedNode<T>*;

