#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

class Patient {
	
	
	private :
	  
	  double masse;
	  double hauteur;
	  
	  
	public:
	    
	  void init ( double m, double h) {
		  
		  if( m<= 0 or h <=0){
			  masse=0;
			  hauteur = 0;
			  }
			  else
			  {
				  masse = m;
				  hauteur=h;
				  
				  }
		  }
		  
		  
		  
	  double poids() {return masse;}
	  double taille() {return hauteur;}
	  
	  double imc() { 
		  if(hauteur ==0) {return 0;} 
		  else {
			  double res=masse/(hauteur*hauteur);
			  return res;
			  
			  }
	  
		  }
	
	  void afficher() {
		  
		  cout << "Patient : "<< masse<< "kg pour "<<hauteur<<" m" <<endl;
		  
		  }
	
	
	
	};



/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
