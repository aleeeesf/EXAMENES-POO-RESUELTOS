#include <iostream>
#include <set>
#include <map>

using namespace std;

/*********************************/
/*			APARTADO A			 */
/*********************************/

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


/*********************************/
/*			APARTADO B			 */
/*********************************/

C::C():d(nullptr){}

/*********************************/
/*			APARTADO C			 */
/*********************************/
class A{
	
	public:
		
		typedef map<C*, X> objetosC;		//Siendo un X un tipo de dato cualesquiera (int, string...)
		void rel1(C& c_, X x_);
		const objetosC& rel1() const noexcept;
		
	private:
		
		objetosC c;		//rel1	
};


