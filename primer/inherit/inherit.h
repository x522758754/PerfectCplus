#pragma once
#include "unitApp.h"
#include <iostream>


//�����˽⹹�캯���������������������������麯��
class inherit : public unitApp
{
public:
	inherit();
	virtual ~inherit();
	virtual void run(int argc, char** argv);

	/* ���������ĵ���
	* ����һ������ռ�ò���ջ�ڴ�Ͷ��ڴ棨��������ˣ�
	* ���������أ�һ����ϵͳ���ã��������ô��ڷ���
	* ��ʾ���ã�ֻ�ǵ���ִ���������������Ƶ�����ͨ�������������ͷ�ջ�ڴ棬Ҳ����ݻ��������
	* ϵͳ���ã�������ͷ�ջ�ڴ棬���ڴ������û��ֹ��ͷ�
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

//��������������Ϊ�麯��
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

//����������
class BB :public AA
{
public:
	BB() { std::cout << "BB::BB()" << std::endl; }
	~BB() { std::cout << "BB::~BB()" << std::endl; }
	void foo() { std::cout << "BB::foo()" << std::endl; }
};