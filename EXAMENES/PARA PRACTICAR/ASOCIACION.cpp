#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Salario;
class E;
class D;

class A{};

class B1: public A{
	
	public:
		typedef set<D*> objetosD;
		const string& identif() const noexcept {return identificador;}
		void asocia(D&);
		const objetosD& asociados() const noexcept;
	private:
		string identificador;
		objetosD d;
};

class B2: public A{
	
	public:
		typedef pair<E*, Salario*> E_S;
		void asocia(E&, Salario&);
		const E_S& asociados() const noexcept;
	private:
		E_S e_s;
	
	
};

class C final: public B1, public B2{
	
	public:
		const vector<Salario>& salarios() const noexcept;
		
	private:
		vector<Salario> S;
};

class D{
	
	public:
		typedef map<string,B1*> objetosB1;
		void asocia(B1&);
		const objetosB1& asociados() const noexcept;
		
	private:
		objetosB1 b1;
};

class E{
	public:
		typedef map<B2*, Salario*> B2_S;
		void asocia(B2&, Salario&);
		const B2_S& asociados()const noexcept;
	private:
		B2_S b2_s;
};

class Salario{
	public:
		
	private:
		int horas;
		C* c;
};

class B2_E{		//Clase de asociacion
	
	public:
		typedef map<B2*,pair<E*,Salario*>> objetosB2_E;
		typedef map<E*,map<B2*,Salario*>> objetosE_B2;
		
		const pair<E*,Salario>& asociados(B2 &) const noexcept;
		const map<B2*,Salario>& asociados(E &)  const noexcept;
		
		void asocia(B2&, E&, Salario&);
		void asocia(E&, B2&, Salario&);
	
	private:
		
		objetosB2_E b2_e;
		objetosE_B2 e_b2;
		
	
};
