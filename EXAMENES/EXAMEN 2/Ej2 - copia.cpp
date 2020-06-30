#include <iostream>
#include <string>

using namespace std;

class X {
	public:
		X(string s = "por omision") {
			cout << "Constructor de X: " << s << endl;
		}
};

class A {
		X x;
	public:
		A(): x("A") {
			cout << "Constructor de A" << endl;
		} 
		
		void f() {
			cout << "Metodo f() de A" << endl;
		}
		virtual ~A(){}
};

class B: virtual public A {
		X x;
	public:
		B() {
			cout << "Constructor de B" << endl;
		} 
		
		void f() {
			cout << "Metodo f() de B" << endl;
		}
		virtual ~B(){}
};

class C: virtual public A {
		X x;
	public:
		C() {
			cout << "Constructor de C" << endl;
		} 
		
		void f() {
			cout << "Metodo f() de C" << endl;
		}
		virtual ~C(){}
};

class D: public B, public C {
		X x;
	public:
		D(): x("D") {
			cout << "Constructor de D" << endl;
		}
};

void probando(A* a){
	
	//if (A *a = dynamic_cast<A*>(a)) cout<<"Es A";
	//else if (B *b = dynamic_cast<B*>(a)) cout<<"Es B";
	//else if (C *c = dynamic_cast<C*>(a)) cout<<"Es C";
	if (D *d = dynamic_cast<D*>(a)) cout<<"Es D";
	
}

int main(){

	A *pa = new D;
	pa->B::f();
	//probando(pb);
	return 0; 
	

}
