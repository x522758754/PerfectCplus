#include "virtualDetail.h"
#include <vector>

virtualDetail::virtualDetail()
{

}

virtualDetail::~virtualDetail()
{

}

void virtualDetail::run(int argc, char** argv)
{
	explain_vitual();
}

void virtualDetail::explain_vitual()
{
	std::cout << "\nBase* pBase = new Derive();" << std::endl;
	std::cout << "pBase->foo();" << std::endl;
	std::cout << "Result:" << std::endl;
	Base* pBase = new Derive();
	pBase->foo();
	delete pBase;
	pBase = nullptr;

	std::cout << "\nBase* pBase = new Base();" << std::endl;
	std::cout << "pBase->foo();" << std::endl;
	std::cout << "Result:" << std::endl;
	pBase = new Base();
	pBase->foo();
	delete pBase;
	pBase = nullptr;

	//对象无法达到多态的效果
	std::cout << "\n对象无法达到多态的效果\nBase b;" << std::endl;
	std::cout << "b.foo();" << std::endl;
	std::cout << "Result:" << std::endl;
	Base b;
	b.foo();
}

void virtualDetail::explain_Polymorphism(Base* pBase)
{
	pBase->foo();
}

