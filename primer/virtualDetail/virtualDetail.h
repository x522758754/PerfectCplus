#pragma once
#include "unitApp.h"
#include <iostream>

//虚函数了解参考 https://blog.csdn.net/bao_jinyu/article/details/7843275?utm_source=blogxgwz0

class Base;
class Derive;

class virtualDetail : public unitApp
{
public:
	virtualDetail();
	virtual ~virtualDetail();

	virtual void run(int argc, char** argv);

	/* 1. virtual function,虚函数的标志virtual
	* 指向Base的指针，被调用的函数是foo可以是Derive的
	* virtual，即推迟联编或动态联编：函数的调用不是在编译函数时运行，而是在运行时刻确定
	* virtual function只能借助指针或者引用达到多态效果
	*/
	void explain_vitual();

	/* 2.多态：同一代码可以产生不同效果的特点，被称为“多态”
	* 只根据当前函数代码，无法确认确认调用的Base::foo()还是Derive::foo()
	* 可以肯定的是：
	* 指针pBase指向的是Base实例，则Base::foo()被调用
	* 指针pBase指向的是Derive实例，则Derive::foo()被调用
	*/
	void explain_Polymorphism(Base* pBase);

	/* 3.多态作用
	* 在面向对象的编程中，首先会针对数据进行抽象（确定基类）和继承（确定派生类），构成类层次。
	* 这个类层次的使用者在使用它们的时候，如果仍然在需要基类的时候写针对基类的代码，在需要派生类的时候写针对派生类的代码，就等于类层次完全暴露在使用者面前。
	* 如果这个类层次有任何的改变（增加了新类），都需要使用者“知道”（针对新类写代码）。这样就增加了类层次与其使用者之间的耦合，有人把这种情况列为程序中的“bad smell”之一。
	* 多态可以使程序员脱离这种窘境。再回头看看explain_Polymorphism()作为Base-Derive这个类层次的使用者，
	* 它并不知道这个类层次中有多少个类，每个类都叫什么，但是一样可以很好的工作，当有一个C类从A类派生出来后，explain_Polymorphism()也不需要“知道”（修改）。
	* 这完全归功于多态--编译器针对虚函数产生了可以在运行时刻确定被调用函数的代码。
	*/

	/* 4.动态联编：编译器针对虚函数产生可以在运行时刻确定被调用的函数代码
	* VTABLE机制:
	* 编译器发现class中有被声明为virtual的函数，就会为其搞一个虚函数表即VTABLE；VTABLE是一个函数指针数组，每个virtual占用这个数组的一个slot
	* 一个class只有一个VTABLE，不管它有多少实例，派生类有自己的VTABLE，但是派生类的VTABLE与VTABLE有相同的函数排列顺序，同名的虚函数被放在两个数组相同的位置。
	* 创建实例的时候，编译器会在每个实例的内存布局中增加一个vptr字段，指向本类的VTABLE。
	* 编译器看到虚函数调用，则会改写这个调用如
	* void explain_Polymorphism(Base* pBase) {pBase->foo();} =》
	* void explain_Polymorphism(Base* pBase) {pBase->vptr[1];}
	* 因为派生类和基类的foo函数具有相同的VTABLE索引，而他们的vptr指向不同的VTABLE,通过此种方式在运行时刻决定调用那个foo函数。
	*/

	/* 5.overload和override
	* virtual函数总是在派生类中被改写，这种改写被称为“override”
	* 编写一个与已有函数同名，但是参数列表不同
	*/

	/* 6.纯虚函数
	* virtual void pure() = 0;
	* 纯虚函数用来规范派生类的行为，实际上所谓的“接口”——告诉使用者，派生的类需要实现这个函数
	* 声明一个纯虚函数的类，即抽象类；
	* 抽象类，不能实例化
	*/

	/* 7.虚析构函数 
	* 析构函数也可以是虚的，甚至是纯虚的。
	* 纯虚的析构函数并没有什么作用，是虚的就够了。通常只有在希望将一个类变成抽象类（不能实例化的类），而这个类又没有合适的函数可以被纯虚化的时候，可以使用纯虚的析构函数来达到目的。
	* 当一个类打算被用作其它类的基类时，它的析构函数必须是虚的;
	* 当~Base()不是虚函数时
	* Base* pBase = new Derive()
	* delete pBase
	* 实际上只有Base::~Base()被调用，Derive::~Derived()不会被调用
	*/

	/* 8.构造函数不能是虚的
	* 指向VTABLE的vptr在构造函数调用前还未被初始化;而构造函数的作用是提供初始化，包括vtpr的初始化
	*/

	/* 9.私有虚函数
	* 这种写法的意思，Base类告诉Derive类，最好override f函数，但是你不要管它如何使用，也不要自己调用这个函数。
	*/

	/* 10.构造函数和析构函数中调用虚函数
	*  一个类的虚函数在它自己的构造函数和析构函数中被调用的时候，它们就变成普通函数了，不“虚”了。也就是说不能在构造函数和析构函数中让自己“多态”.
	*/
};

class Base
{
public:
	virtual void foo() { std::cout << "Call Base foo"<<std::endl; }

	
private:
	/* 私有虚函数
	* 这种写法的意思，Base类告诉Derive类，最好override f函数，但是你不要管它如何使用，也不要自己调用这个函数。
	*/
	virtual void f(){}
};

class Derive:public Base
{
public:
	virtual void foo() { std::cout << "Call Derive foo" << std::endl; }

private:
	virtual void f() {}
};