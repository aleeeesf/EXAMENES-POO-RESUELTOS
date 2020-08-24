#include <iostream>
#include <string>
#include <list>
using namespace std;
class Instrumento {
	public:
		
		enum tclase {instrumento, percusion, cuerda, viento};
		Instrumento(string n): nom(n), clase_(instrumento) {}
		void tocar() const {
			cout << "Soy un " << nombre() << " y pertenezco a "
			     << clase() << endl;
		}
		string nombre() const {
			return nom;
		}
		string clase() const {
			switch (clase_) {
				case percusion:
					return "percusión";
				case cuerda:
					return "cuerda";
				case viento:
					return "viento";
				default:
					return "instrumento";
			}
		}
	protected:
		string nom;
		tclase clase_;
};
class Percusion: public Instrumento {
	public:
		Percusion(string n): Instrumento(n) {
			clase_ = percusion;
		}
};
class Cuerda: public Instrumento {
	public:
		Cuerda(string n): Instrumento(n) {
			clase_ = cuerda;
		}
};
class Viento: public Instrumento {
	public:
		Viento(string n): Instrumento(n) {
			clase_ = viento;
		}
};
int main() {
	
	list<Instrumento*> l {new Percusion("tambor"), new Percusion("triángulo"),
		     new Instrumento("sintetizador"), new Cuerda("piano")
	};
	
	for (Instrumento* p : l) {
		p->tocar();
		delete p;
	}
}

