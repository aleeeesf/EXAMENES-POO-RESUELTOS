#include <iostream>

using namespace std;

/*
class A{
	
};

class B:public A{

};

int main(){
	
	 A objA, *pA;
	 B objB, *pB;
	 pA = &objA;
	 pB = &objB;
	 objA = objB;
	 objA = (A)objB;
	 //objB = objA;
	 //objB = (B)objA;
	 pA = pB;
	 //pB = pA;
	 pB = (B*)pA;
	 pB = static_cast<B*> (pA);
	return 0;
}
*/




class B{
	public:
		void f(){
			cout<<"soy B"<<endl;
		}
};

class D:public B{
	public:
		void f(){
			cout<<"soy D"<<endl;		
		}
};



int main(){
	
	B b, *bp;
 	D d, *dp;
 	b.f();
 	bp = &d;
 	bp->f();
 	dp = &d;
 	dp->f();
	
	
	return 0;
}
