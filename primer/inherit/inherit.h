#pragma once
#include "unitApp.h"
#include <iostream>


//初步了解构造函数、析构函数、虚析构函数、虚函数
class inherit : public unitApp
{
public:
	inherit();
	virtual ~inherit();
	virtual void run(int argc, char** argv);

	/* 析构函数的调用
	* 对于一个对象，占用部分栈内存和堆内存（如果申请了）
	* 不允许重载，一般有系统调用，主动调用存在风险
	* 显示调用，只是单纯执行析构函数（类似调用普通函数），不会释放栈内存，也不会摧毁这个对象
	* 系统调用，会额外释放栈内存，堆内存则由用户手工释放
	*/
};

class A
{
public:
	A() {std::cout<<"A::A()"<<std::endl;};
	~A() { std::cout << "A::~A()" << std::endl; };
	void foo() { std::cout << "A::foo()" << std::endl; }
private:

};

//父类析构函数不为虚函数
class B :public A
{
public:
	B() { std::cout << "B::B()" << std::endl; }
	~B() { std::cout << "B::~B()" << std::endl; }
	void foo() { std::cout << "B::foo()" << std::endl; }
};

class AA
{
public:
	AA() { std::cout << "AA::AA()" << std::endl; };
	virtual~AA() { std::cout << "AA::~AA()" << std::endl; };
	virtual void foo() { std::cout << "AA::foo()" << std::endl; }
private:

};

//虚析构函数
class BB :public AA
{
public:
	BB() { std::cout << "BB::BB()" << std::endl; }
	~BB() { std::cout << "BB::~BB()" << std::endl; }
	void foo() { std::cout << "BB::foo()" << std::endl; }
};