#include "inherit.h"

inherit::inherit()
{

}

inherit::~inherit()
{

}

void inherit::run(int argc, char** argv)
{
	std::cout << "ֱ�Ӷ���һ������,����Ĵ���ջ(stack)��" << std::endl;
	std::cout << "ջ�е��ڴ棬ϵͳ�Զ�����" << std::endl;
	A aaa;

	std::cout << "new�����Ķ��󣬶�����ڶ�(heap)��" << std::endl;
	std::cout << "���е��ڴ棬�û��Լ�����" << std::endl;
	std::cout << "����delete/newҪ�ɶԳ���" << std::endl;
	std::cout << "�ڴ�й©���ڴ治��ʹ��֮�󣬲�δ�ͷ�" << std::endl << std::endl;;


	std::cout << "A����������Ϊ�麯��" << std::endl;
	A* a = new B();
	a->foo();
	delete a; //ֻ���ͷ����ڴ棬ע��a��ָ���ǿ�ռ䣬�뽫a�ÿ�
	a = nullptr;
	std::cout << "AA��������Ϊ�麯��" << std::endl;
	AA* aa = new BB();
	aa->foo();
	delete aa;
	aa = nullptr;
}

