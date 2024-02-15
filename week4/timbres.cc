#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
   protected :
string nom;
unsigned int annee;
string pays;
double valeur_faciale;

public :
 
 Timbre(string n , int a , string p ="Suisse", double v = 1.0):nom(n),annee(a),pays(p),valeur_faciale(v){}
 double vente(){ 
	 if(age()<=5){
		 return valeur_faciale;}
     else{
		 
		return valeur_faciale * (2.5*age()); 
	  }
	 
	 }
 int age(){
	 return ANNEE_COURANTE-annee;
	 }
 
 ostream& afficher(ostream& sortie ) const { 
	 sortie << "Timbre" <<" de nom "<<nom<<" datant de "<<annee<<" (provenance "<<pays<<") ayant pour valeur faciale "<<valeur_faciale<<" francs";
	 return sortie;
	   }

};

class Rare : public Timbre{

private:
 int num_exp;

public : 
 double PRIX_BASE_TRES_RARE = 600 ;
 double PRIX_BASE_RARE = 400 ;
 double PRIX_BASE_PEU_RARE = 50;

 Rare( string n , int a , string p ="Suisse", double v = 1.0 , int nex = 100) : Timbre (n,a,p,v), num_exp(nex){}
 int nb_exemplaires() {return num_exp;}
 string s = "Timbre rare (" + to_string(num_exp) + " ex.) ";
 //string m = to_string(nb_exemplaires());
 
 ostream& afficher1(ostream& sortie){ 
	 sortie << "Timbre rare (" << num_exp << " ex.) " <<"de nom "<<nom<<" datant de "<<annee<<" (provenance "<<pays<<") ayant pour valeur faciale "<<valeur_faciale<<" francs";
	   return sortie;
	   }
 double vente(){
	 if(num_exp < 100 ) { return PRIX_BASE_TRES_RARE * (age() / 10.0);  }
	 else if ( num_exp > 100 and num_exp < 1000) { return PRIX_BASE_RARE * (age() / 10.0); }
	 else {  return PRIX_BASE_PEU_RARE * (age() / 10.0); }
	 
	 }
	 
	 	
	
	};
	
class Commemoratif : public Timbre{
	
	
public : 

  Commemoratif(string n , int a , string p ="Suisse", double v = 1.0):Timbre(n,a,p,v){}
  double vente() {
	  double p = Timbre::vente();
	  return p*2;
	  
	  }
  ostream& afficher2(ostream& sortie  )const { 
	  
	sortie << "Timbre commémoratif "<<"de nom "<<nom<<" datant de "<<annee<<" (provenance "<<pays<<") ayant pour valeur faciale "<<valeur_faciale<<" francs";
	   return sortie;
	   	
	}
	};
	
	
ostream& operator<<(ostream& sortie, Timbre const& t){ 
	t.afficher(sortie);
	return sortie;
	
	}

ostream& operator<<(ostream& sortie, Rare  t){ 
	t.afficher1(sortie);
	return sortie;
	
	}

ostream& operator<<(ostream& sortie, Commemoratif  t){ 
	t.afficher2(sortie);
	return sortie;
	
	}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
