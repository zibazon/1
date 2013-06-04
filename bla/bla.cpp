// bla.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class A
{
public:
	virtual void doSomething() = 0
	{
		cout << "do something!" << endl;
	}
};

class B: public A
{
public:
	virtual void doSomething()
	{
		cout << "B do smtg!";
	}
};


typedef void (A:: *pFun)();


class Test
{
	void f(int n) const {cout << "f() " << n << endl;}
	void g(int n) const {cout << "g() " << n << endl;}
	
	enum {functionNumber = 2};
	void (Test::*pTestFun[functionNumber])(int) const;


public:
	static int s;
	int a;

	Test()
	{
		pTestFun[0] = &Test::f;
		pTestFun[1] = &Test::g;
	}

	void selectFunction(const int &orderNumber, const int &value) const
	{
		if ((orderNumber < 0) || (orderNumber >= functionNumber))
			return;

		(this->*pTestFun[orderNumber])(value);
	}
};

int Test::s = 10;

int _tmain(int argc, _TCHAR* argv[])
{
	Test t;
	t.selectFunction(0, 0);
	t.selectFunction(1, 1);
	int *p = &Test::s;
	*p = 22;
	cout << *p << endl;
	getchar();
	return 0;
}

