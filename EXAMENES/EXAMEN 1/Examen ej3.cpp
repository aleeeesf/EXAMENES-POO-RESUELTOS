#include <iostream>

using namespace std;

class C1{
	
	public:
		C1(int x_, int y_): x(x_), y(y_){}
		
	private:
		int x;
		int y;
};

class C2{
	
	public:
		
	private:
};

class C3: public C1{

	public:
		C3(int x_, int y_, char x2_):C1(x_,y_),x(x2_){};
		
	private:
		char x;
		C2 c2;
};

class C4: public C1{
	
	public:
		C4(int x_, int y_, char x2_, int z_):C1(x_,y_),x(x2_),z(z_){};
		
	private:
		char x;
		int z;
};


