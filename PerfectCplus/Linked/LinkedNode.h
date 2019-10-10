/*
	Á´±í½Úµã
*/
#pragma once

template<class T>
class LinkedNode
{
public:
	LinkedNode();
	~LinkedNode();

	bool operator== (const LinkedNode& node) const;
public:

	T* pData;
	LinkedNode* next;
};