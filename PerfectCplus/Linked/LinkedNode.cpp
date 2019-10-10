#include "LinkedNode.h"

template<class T>
LinkedNode<T>::LinkedNode()
{

}

template<class T>
LinkedNode<T>::~LinkedNode()
{

}

template<class T>
bool LinkedNode<T>::operator==(const LinkedNode & node) const
{
	//判断数据指针是否一样
	if (pData == node.pData)
		return true;

	return false;
}
