#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
class Asignatura;
class Grupo;



/* EJERCICIO 2*/
class Alumno{
	
	public:
		Alumno(string nombre_):nombre(nombre_){}
		typedef map<Asignatura*, Grupo*> asig_gr;
		void matriculado_en(Asignatura& asignatura, Grupo& grupo);
		const asig_gr& matriculadas() const;
				
	private:
		string nombre;
		asig_gr AG;
	
};

class Profesor{
	
	public:
		Profesor(string nombre_):nombre(nombre_){}
		void mostrar(){cout<<nombre<<endl;}
		typedef set<Grupo*> Grupos;
		void imparte(Grupo& grupo);
		const Grupos& impartidos() const;		
		
	private:
		Grupos G;
		string nombre;
	
};

class Grupo{
	
	public:
		Grupo(int cod):codigo(cod){}
		void mostrar(){cout<<codigo<<endl;}
		void pertenece(Asignatura& asignatura);
		const Asignatura& pertenecen() const;
		const Profesor& imparten() const;
		void imparte(Profesor& profesor);
		
	private:
		int codigo;
		Profesor* p;
		Asignatura* a;
	
};

class Asignatura{
	class Alumno;
	public:
		Asignatura(string nombr_):nombre(nombr_){}
		typedef set<Grupo*> Grupos;
		typedef set<Alumno*, Grupo*> Alumno_Gr;
		void matricula(Alumno& alumno, Grupo* grupo);
		const Alumno_Gr matriculados() const;
		void pertenece(Grupo& grupo);
		const Grupos& pertenecen() const;
		
		
	private:
		string nombre;
		Grupos g;
		Alumno_Gr GR;
	
};

/* EJERCICIO 4 - 8*/
class Alumno_Asignatura{
	
	public:
		typedef map<Asignatura*,Grupo*> Asignatura_grupo;
		typedef map<Alumno*,Grupo*> Alumno_grupo;

		typedef map<Alumno*,Asignatura_grupo> Al_As;
		typedef map<Asignatura*,Alumno_grupo> Al_As2;
		
		void matriculado_en(Alumno& alumno, Asignatura& asignatura, Grupo& grupo);
		void matriculado_en(Asignatura& asignatura,Alumno& alumno,Grupo& grupo);
		
		const Alumno_grupo& matriculados(Asignatura& asignatura) const;
		const Asignatura_grupo& matriculados(Alumno& alumno) const;
		
	private:
		Al_As AD;
		Al_As2 AI;
	
};

class Profesor_Asignatura{
	
	public:
		typedef map<Profesor*, set<Grupo*>> Profesores;
		typedef map<Grupo*, Profesor*> Grupos;
		void imparte(Profesor& profesor, Grupo& grupo);
		void imparte(Grupo& grupo, Profesor& profesor);
		const set<Grupo*>& impartidos(Profesor& profesor) ;
		const Profesor* impartidos(Grupo& grupo) ;
		
	private:
		Grupos g;
		Profesores p;
	
};




const Alumno_Asignatura::Alumno_grupo& Alumno_Asignatura::matriculados(Asignatura& asignatura) const
{
	Alumno_Asignatura::Al_As2::const_iterator i = AI.find(&asignatura);
	if(i != AI.end()) return i->second;
	
}

const Alumno_Asignatura::Asignatura_grupo& Alumno_Asignatura::matriculados(Alumno& alumno) const
{
	auto i = AD.find(&alumno);
	if(i != AD.end()) return i->second;
}

void Alumno_Asignatura::matriculado_en(Alumno& alumno,Asignatura& asignatura,Grupo& grupo)
{
	AD[&alumno][&asignatura] = &grupo;	
	AI[&asignatura][&alumno] = &grupo;
}

void Alumno_Asignatura::matriculado_en(Asignatura& asignatura,Alumno& alumno,Grupo& grupo)
{
	matriculado_en(asignatura,alumno,grupo);	
}





void Profesor_Asignatura::imparte(Profesor& profesor, Grupo& grupo)
{
	//Si no existe el grupo se crea uno nuevo
	//Si existe, se sustituye el profesor
	g[&grupo] = &profesor;

	//map<Profesor*, set<Grupo*>> Profesores;
	for(Profesores::iterator x = p.begin(); x != p.end(); ++x)	//Recorremos Profesor
	{				
		auto y = x->second.find(&grupo);
		
		if(y != x->second.end()){x->second.erase(&grupo);} 	//Recorremos los grupos de los profesores

	}
	
	p[&profesor].insert(&grupo);	

}

void Profesor_Asignatura::imparte(Grupo& grupo, Profesor& profesor)
{
	imparte(profesor,grupo);
}

const set<Grupo*>& Profesor_Asignatura::impartidos(Profesor& profesor) 
{

	Profesores::iterator i = p.find(&profesor);
	if(i != p.end()) return i->second;
	else return {};
}

const Profesor* Profesor_Asignatura::impartidos(Grupo& grupo) 
{
	Grupos::iterator i = g.find(&grupo);
	
	if(i != g.end()) return i->second;
	else return nullptr;
}





int main(){
	
	Alumno juan("Juan");
	Alumno lorena("Lorena");
	
	Asignatura MP("Metodologia de la programación");
	Asignatura POO("Programación Orientada A Objetos");
	
	Profesor Juan("Juan");
	Profesor Antonio("Antonio");
	Profesor Alejandro("Alejandro");
	Profesor Pepe("Pepe");
	
	Grupo a(1);
	Grupo b(2);
	Grupo c(3);
	Grupo d(4);
	Grupo e(5);
	
	Alumno_Asignatura AA;
	AA.matriculado_en(juan,MP,a);
	
	Profesor_Asignatura PA;
		
	PA.imparte(Juan, a);
	PA.imparte(Juan, b);
	PA.imparte(Antonio, a);
	PA.imparte(Alejandro, d);

	PA.imparte(Alejandro, e);
	PA.imparte(Pepe,d);
	
	//auto aux = PA.impartidos(Alejandro);
	//for(auto i:aux) i->mostrar();
	
	map<int,map<int,string>> prueba;
	string aa("hola");
	string bb("adios");
	string cc("pero quee");
	string dd("hola");
	
	prueba[1].insert(make_pair(1,aa));
	prueba[1].insert(make_pair(2,aa));
	prueba[1].insert(make_pair(3,cc));
	prueba[1][1] = cc;
	
	for(auto i: prueba){
		
		for(auto x: i.second){
		 cout<<x.first<<endl;			
		 cout<<x.second<<endl;}
		
	}


	
	
	
}
