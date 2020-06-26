#include <iostream>
using namespace std;

template<class T1, class T2> class par{
public:
    par(): prime(T1()), segun(T2()){}
    par(const T1& x, const T2& y): prime(x), segun(y){}
    T1 primero() const {return prime;}
    T1& primero(){return prime;}
    T2 segundo() const {return segun;}
    T2& segundo(){return segun;}
private:
    T1 prime;
    T2 segun;
};

template<class T1, class T2>
ostream& operator << (ostream& os, const par<T1,T2>& p)
{
	os<<"primero: "<<p.primero()<<"segundo: "<<p.segundo()<<endl;
	return os;	
}

class Racional{
	
	public:
		Racional(int a, int b):p(a,b){}
		Racional(const Racional& r):p(r.numerador(),r.denominador()){}
		const int& numerador() const noexcept{return p.primero();}
		const int& denominador() const noexcept{return p.segundo();}
			
	private:
		par<int,int> p;
};

int main(){
	
	
	return 0;
}
