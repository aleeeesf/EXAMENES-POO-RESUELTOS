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

};

class D: public B, public C {
		X x;
	public:
		D(): x("D") {
			cout << "Constructor de D" << endl;
		}
		

};

int main(){
	
  A *pa; 
  B *pb; 
  D d, *pd; 
  
  pd = &d; 
  pa = &d; //si quitamos VIRTUAL no funciona
  pa->f(); 
  pb = &d; 
  pb->f(); 
  d = (D*)pa; 
  pd = (D *)pb; 
  pd->B::f(); 
  d.C::f(); 
	
	return 0; 
}
