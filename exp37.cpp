#include<iostream>
using namespace std;
class A
{
	public:
		void fun1()
		{
			cout<<"class A\n";
		}
};
class B
{
	public:
		void fun2()
		{
			cout<<"class B\n";
		}
};
class C
{
	public:
		void fun3()
		{
			cout<<"class C\n";
		}
};
class D:public A,public B,public C
{
};
class E:public D{
};
class F:public D{
};
class G:public D{
};
int main()
{
	E obj1;
	F obj2;
	G obj3;
	obj1.fun1();
	obj1.fun2();
	obj1.fun3();
	obj2.fun1();
	obj2.fun2();
	obj2.fun3();
	
}