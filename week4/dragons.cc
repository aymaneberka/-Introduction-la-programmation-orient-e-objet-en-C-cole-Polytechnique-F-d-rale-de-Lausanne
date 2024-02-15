#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int distance(int x, int y)
{
  return abs(x - y);
}

class Creature
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

 protected : 

string nom_;
int niveau_;
int points_de_vie_;
int force_ ;
int position_;

 public :

int position(){return position_;} 
Creature( string n , int niv , int pt , int f , int p=0):nom_(n),niveau_(niv),points_de_vie_(pt),force_(f),position_(p){}
bool vivant(){ 
	
	if(points_de_vie_ > 0 ){
		return true;
		} 
		else {
			return false;
			}
	}
int points_attaque(){ if(this -> vivant() == true ){
	int res = niveau_ * force_ ;
	return 	res;	
	}
  else {
	  return 0;
	  }
 }

void deplacer(int n){ if(vivant()){position_ += n;} }
void adieux(){cout<<nom_<<" n'est plus !"<<endl;}
void faiblir(int f){
	
	if( this->vivant() == true ){
		
		points_de_vie_ = points_de_vie_ - f;
		
		if( this->vivant()==false ){
		points_de_vie_ = 0;
		adieux();
		
		}
	}
	
	
	}

void afficher(){
	cout<<nom_<<", niveau: "<<niveau_<<", points de vie: "<< points_de_vie_ <<", force: "<<force_<<", points d'attaque: "<<points_attaque()<<", position: "<<position_<<endl;
	
	}


};


class Dragon : public Creature{
	
	int portee_flamme_;
	
public :
  
  Dragon( string n , int niv , int pt , int f, int pf , int p=0 ):Creature(n,niv,pt,f,p), portee_flamme_(pf){}
  void voler(int pos){if(vivant()){position_ = pos;}}
  
  void souffle_sur(Creature& bete){
	  int dis = distance(position(),bete.position());
	  if((this->vivant() == true) and (bete.vivant() == true ) and ( dis <= portee_flamme_) ){//le dragon est vivant
		 
				  
				  bete.faiblir(this->points_attaque());
				 // points_de_vie_= points_de_vie_ - (distance(position(),bete.position()));
				 // int dow = points_de_vie_ - dis ; 
				  this->faiblir(dis);
				  if((this->vivant()==true) and (bete.vivant()==false) ){
					  
					  niveau_ ++;
		
			  }
		  
		  
		  }
	  
	  }	
	  
	  

	
	};
	

class Hydre : public Creature{
	
private : 
 int longueur_cou_;	
 int dose_poison_;
 
public :
  
   Hydre( string n , int niv , int pt , int f, int lg , int dp , int p=0 ):Creature(n,niv,pt,f,p), longueur_cou_(lg),dose_poison_(dp){}
   void empoisonne(Creature& bete){
	   if(this->vivant()==true){
		    
		   if((bete.vivant()==true) and (distance(position(),bete.position())<= longueur_cou_) ){
			   //int g = points_attaque()+ dose_poison_;
			   bete.faiblir(points_attaque());
			   bete.faiblir(dose_poison_);
			   if(bete.vivant()==false){ 
				   
					niveau_ ++;
				   
				   }
			   
			   }
		   
		   
		   }
	   
	   
	   }
	
	
	};
	
void combat(Dragon&  dragon , Hydre& hydre) {
	
	hydre.empoisonne(dragon);
	dragon.souffle_sur(hydre);
	
	}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Dragon dragon("Dragon rouge"   , 2, 10, 3, 20         );
  Hydre  hydre ("Hydre maléfique", 2, 10, 1, 10, 1,  42 );

  dragon.afficher();
  cout << "se prépare au combat avec :" << endl;
  hydre.afficher();

  cout << endl;
  cout << "1er combat :" << endl;
  cout << "    les créatures ne sont pas à portée, donc ne peuvent pas s'attaquer."
       << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon vole à proximité de l'hydre :" << endl;
  dragon.voler(hydre.position() - 1);
  dragon.afficher();

  cout << endl;
  cout << "L'hydre recule d'un pas :" << endl;
  hydre.deplacer(1);
  hydre.afficher();

  cout << endl;
  cout << "2e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 2 points de vie supplémentaires\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 41 = 2 ].\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon avance d'un pas :" << endl;
  dragon.deplacer(1);
  dragon.afficher();

  cout << endl;
  cout << "3e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 1 point de vie supplémentaire\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 42 = 1 ] ;\n\
  + l'hydre est vaincue et le dragon monte au niveau 3.\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "4e Combat :" << endl;
  cout << "    quand une créature est vaincue, rien ne se passe." << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  return 0;
}
