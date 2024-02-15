#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/

Flacon() = delete;
Flacon(string n  , double v , double p):nom(n),volume(v),pH(p){};
ostream& etiquette(ostream& sortie) const ;

string get_nom() const {return nom;}
double get_volume() const {return volume;}
double get_pH() const {return pH;}
Flacon& operator+=(Flacon const& f2 ) {
	
	nom = nom+" + "+f2.get_nom();
	volume = volume+f2.get_volume();
	double ph1 = pH; double ph2 = f2.get_pH();
	pH = -log10( ((volume * pow(10.0, -ph1)) + (f2.get_volume() * pow(10.0, -ph2)) ) / volume  );
	
	
	return *this;
	
	}
};
#define BONUS
ostream& Flacon :: etiquette (ostream& sortie) const {
	
	sortie << nom << " : " << volume << " ml, pH "<<pH;
	return sortie;
	
	}
	
ostream& operator<<(ostream& sortie, Flacon F){
	
	return F.etiquette(sortie);
	}

Flacon operator+(Flacon f1 , Flacon const& f2){
	
	string sF = f1.get_nom()+" + "+f2.get_nom();
	double v = f1.get_volume()+f2.get_volume();
	double ph1 = f1.get_pH(); double ph2 = f2.get_pH();
	double ph = -log10( ((f1.get_volume() * pow(10.0, -ph1)) + (f2.get_volume() * pow(10.0, -ph2)) ) / v  );
	
	
	return Flacon(sF , v , ph);
	}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
