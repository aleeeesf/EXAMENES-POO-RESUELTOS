#include <iostream>
#include <typeinfo>

using namespace std;
/*
class B{
	public:
		virtual void f() = 0;
		virtual ~B(){};
};

class D: public B{
	public:
		void f(){};

};

int main(){

	B *bp;
	D d;
	bp = &d;
	bp->f();


	return 0;
}
*/


struct V {
	virtual void fv() = 0;
	virtual ~V() {}
};

struct X : V {
	void fv() {}
};

struct Y : V {
	void fv() {}
};

struct Z : V {
	void fv() {}
};
/*
void f(V& v)
{
  if (typeid(v) == typeid(X)) {
 		std::cout << "Processing object X...\n";
  		// specific code for X
	}
  if (typeid(v) == typeid(Y)) {
  		std::cout << "Processing object Y...\n";
  		// specific code for Y
  	}
  if (typeid(v) == typeid(Z)) {
  		std::cout << "Processing object Y...\n";
  		// specific code for Z
	}
}
*/

/*
void f(X& x){
	std::cout << "Processing object X...\n";
}

void f(Y& y){
	std::cout << "Processing object Y...\n";
}

void f(V& v){
	std::cout << "Processing object Y...\n";
}
int main(){

	X x;
	V* pv = new Y;
	f(x);
	f(*pv);

	return 0;
}

*/
template<int id> 
class B {
		int* p;
	
	public:
		B(): p {new int} {
			cout << typeid(*this).name() << "::"
			<< typeid(*this).name() << "()" << endl;
		}
		B(const B& b): p {new int{*(b.p)}} {
			cout << typeid(*this).name() << "::" << typeid(*this).name()
			<< "(const" << typeid(*this).name() << "&)klk" << endl;
		}
		virtual ~B() {
			delete p;
			cout << typeid(*this).name() << "::~"
			     << typeid(*this).name() << "()" << endl;
		}
};

class D: public B<0> {
	public:
		D() {
			cout << "D::D()" << endl;
		}
		D(const D& d): B<0> {static_cast<const B&>(d)}, b1 {d.b1}, b2 {d.b2}
		{ cout << "D::D(const D&)" << endl; }
		~D() {
			cout << "D::~D()" << endl;
		}
	private:
		B<1> b1;
		B<2> b2;
};
int main() {
	B<0>& b {*new D};
	cout << "-----------------------" << endl;
	D d {dynamic_cast<D&>(b)};
	cout << "-----------------------" << endl;
	delete &b;
	cout << "-----------------------" << endl;
}


