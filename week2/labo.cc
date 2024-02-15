#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/


private: 
double poids;
uint32_t age;
uint32_t esperance_vie;
string couleur;
bool clonee=false;

public:

Souris(double p, string c , uint32_t a=0 , uint32_t esp=36  ) 
:poids(p),age(a),esperance_vie(esp),couleur(c) {cout <<  "Une nouvelle souris !" << endl;}

Souris( Souris const& s){
cout <<  "Clonage d'une souris !" << endl;
poids=s.poids;
age=s.age;
couleur=s.couleur;
clonee=true;

esperance_vie=4*s.esperance_vie/5;


}

~Souris(){ cout << "Fin d'une souris..."<<endl;}

void afficher(){
 
 if(clonee){ 
   cout << "Une souris "<< couleur<< ", clonee, de "<<age << " mois et pesant "<< poids << " grammes"<<endl;
 }
 else
 {
      cout << "Une souris "<< couleur<< " de "<<age << " mois et pesant "<< poids << " grammes"<<endl;

 }
 
}

void vieillir(){
age++;
 if(clonee and (age > esperance_vie/2) ) { couleur = "verte";}

}



void evolue(){
for(int i(age);age< esperance_vie;i++ ){
 
 vieillir();

}

}

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
