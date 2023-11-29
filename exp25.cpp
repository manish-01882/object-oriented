#include<iostream>//25
using namespace std;
class A{
	int x;
	public:
		A(){
		}
		A(int a)
		{
			x = a;
		}
		A operator++()
		{
			A w1;
			w1.x = ++x;
			return w1;
		}
		A operator++(int)
		{
			x++;
			return x;
		}
		void display()
		{
			cout<<"x = "<<x<<"\n";
		}
};
int main()
{
	A obj1,obj2,obj3;
	obj1 = (5);
    obj2 = ++obj1;
	obj2.display();
	obj3 = obj2++;
	obj3.display();
	
}