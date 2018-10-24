#include "inherit.h"

inherit::inherit()
{

}

inherit::~inherit()
{

}

void inherit::run(int argc, char** argv)
{
	std::cout << "直接定义一个对象,对象的存在栈(stack)中" << std::endl;
	std::cout << "栈中的内存，系统自动回收" << std::endl;
	A aaa;

	std::cout << "new出来的对象，对象存在堆(heap)中" << std::endl;
	std::cout << "堆中的内存，用户自己管理" << std::endl;
	std::cout << "所以delete/new要成对出现" << std::endl;
	std::cout << "内存泄漏：内存不再使用之后，并未释放" << std::endl << std::endl;;


	std::cout << "A析构函数不为虚函数" << std::endl;
	A* a = new B();
	a->foo();
	delete a; //只是释放了内存，注意a仍指向那块空间，须将a置空
	a = nullptr;
	std::cout << "AA析构函数为虚函数" << std::endl;
	AA* aa = new BB();
	aa->foo();
	delete aa;
	aa = nullptr;
}

