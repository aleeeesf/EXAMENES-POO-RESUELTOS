#include <iostream>
#include <set>
#include <map>

using namespace std;

class A{
	
	class C;	//Declaración adelantada

	public:
		
		typedef set<C*> objetosC;
		void rel1(C& c_);
		const objetosC rel1() const noexcept;
		
	private:
		
		objetosC c;		//rel1	
};

class C{
	
	class D;	//Declaración adenlantada
	
	public:
		C();
		void rel4(D& d_);
		const D& rel4() const noexcept;
		
	private:
		D* d;		//rel4	
};

class D{
	
	class B;	//Declaración adelantada
	
	public:
		typedef set<C*> objetosC;
		typedef set<B*> objetosB;
		
		void rel4(C& c_);
		void rel3(B& b_);
		
		const objetosC& rel4() const noexcept;
		const objetosB& rel3() const noexcept;
		const A& rel2() const noexcept;
		int cualificador() const noexcept; 		//Devuelve d1
				
	private:
		objetosC c;		//rel4
		objetosB b;		//rel3
		A* a;			//rel2
		int d1;			//cualificador de d
};

class B{
	
	public:
		typedef map<int,D*> objetosD;
		void rel3(D& d_);
		const objetosD& rel3() const noexcept;
	
	private:
		objetosD d; 	//rel3
};

class C_asocia_D{
	
	public:
		typedef map<C*, D*> CD;
		typedef map<D*, set<C*>> DC;
		
		void asocia(C& c_, D& d_);
		void asocia(D& d_, C& c_);
		
		const D& asociado_con_C(C& c_) noexcept;
		const set<C*>& asociados_con_D(D& d_) noexcept; 
	
	private:	
		CD cd;
		DC dc;
	
};

void C_asocia_D::asocia(C& c_, D& d_)
{	
	cd[&c_] = &d_;
	
	//Buscamos si el objeto c_ está asociodo con otro objeto d_
	for(DC::iterator i = dc.begin(); i != dc.end(); ++i){		
		
		auto x = i->second.find(&c_);
		
		if(x != i->second.end()){	//No ha llegado a su fin -> existe un objeto c = &c_
		
			 throw "Violación de multiplicidad";		//Si lo encuetra, lanzamos excepción
			 i->second.erase(&c_);					//Lo desasociamos del antiguo d_;
		}
	}
	/* Una vez buscada la asociación de c_ con otro objeto con d_,
	 * lo asociamos con el nuevo	*/
	dc[&d_].insert(&c_);
}

void C_asocia_D::asocia(D& d_, C& c_)
{
	
	asocia(c_,d_);
}

const D& C_asocia_D::asociado_con_C(C& c_) noexcept
{
	CD::iterator i = cd.find(&c_);
	return *i->second;
}

const set<C*>& C_asocia_D::asociados_con_D(D& d_) noexcept
{
	DC::iterator i = dc.find(&d_);
	return i->second;
}

