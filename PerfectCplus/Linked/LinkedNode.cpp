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
	//�ж�����ָ���Ƿ�һ��
	if (pData == node.pData)
		return true;

	return false;
}
