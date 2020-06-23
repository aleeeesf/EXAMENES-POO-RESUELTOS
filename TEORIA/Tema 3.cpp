#include <iostream>

using namespace std;
/*	Pruebas con Estudiante <- Doctorando, diapositivas del tema 3.2	*/
/*
class Estudiante{
	
	public:
		Estudiante(string nombre, int dni):nombre_(nombre),dni_(dni){}
		void mostrar() {
			cout<<"Nombre: "<<nombre_<<endl;
			cout<<"DNI: "<<dni_<<endl;
			cout<<"=========================="<<endl;
		}
		
	private:
		string nombre_;
		int dni_;	
};

class Doctorando:public Estudiante{
	
	public:
		Doctorando(string nombre, int dni, string tutor):Estudiante(nombre,dni),tutor_(tutor){}
		void mostrar() {
			
			Estudiante::mostrar();
			cout<<"Su profesor es:"<<tutor_<<endl;
			cout<<"=========================="<<endl;
		}
		
	private:
		string tutor_;
};

int main(){

	Estudiante e("Alejandro",20501318);
	Doctorando d("Lorena", 20501319, "Er Palomo"), *pd;
	//e.mostrar();
	
	Estudiante *pe = &e;
	//pe->mostrar();
	//pe = &d;
	//pe->mostrar();
	//d.mostrar();
	
	//pe = &d;
	//pe->mostrar();
	//pd = pe;
	//d = static_cast<Doctorando>(pe);
	//pd->mostrar();
	return 0;
}

*/



