#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
Brique() = delete;
Brique(Forme f , Couleur c):forme(f),couleur(c){};

ostream& afficher(ostream& sortie) const {
 if(!couleur.empty()){

	 sortie <<"("<<forme<<", "<<couleur<<")";
	 return sortie;
	 }
	else
	cout <<"("<<forme<<")";

return sortie;
    }
};

ostream& operator<<(ostream& sortie, Brique b){

	b.afficher(sortie);
	return sortie;

	}

class Construction
{
  friend class Grader;

  private:
  vector<vector<vector <Brique> > > contenu;

  public:
  vector<vector<vector <Brique> > > get_contenu(){return contenu;}
  Construction (Brique const& b):contenu({{{b}}}){
	  //vector<vector<vector <Brique>>> t ({{{b}}});

	  }

  ostream& afficher(ostream& sortie) const {

	  if(!contenu.empty()){
		  //cout << "size = "<< contenu.size() <<endl;
		  for(size_t i = contenu.size()-1 ; i > 0 ; i-- ){

			  cout <<"Couche "<<i+1<<" :"<< endl;
			  for(size_t j = 0 ;j < contenu[i].size(); j++){
				  for(size_t k=0; k < contenu[i][j].size();  k++){
					  cout << contenu[i][j][k];
					  }
				  cout << endl;
				  }

			  }
		  }
	  return sortie;
	  }



  void operator^=(Construction const& c){
	  //vector<vector<Brique>> b;
	  for(size_t i = 0 ; i < c.contenu.size()-1;i++){
	  cout<<"ajout done et size = "<<contenu.size()<<endl;
	  contenu.push_back(c.contenu[i]);

         }

	  }

 void operator-=(Construction const& c){


	 if(c.contenu[0].size() <= contenu[0].size()){

		 for(size_t i = 0 ; i < contenu.size() ; i++){

			 for(size_t j = 0 ; j < c.contenu[i].size(); j++){

				 for(size_t k = 0 ; k < c.contenu[i][j].size() ; k++){

					 contenu[i][j].push_back(c.contenu[i][j][k]);

					 }

				 }

			 }

		 }

	 }




  void operator+=(Construction const& c){

	   if(c.contenu[0].size() <= contenu[0].size()){
		   bool flag=false;

		    for(size_t i = 0 ; i < contenu.size() ; i++){
				for(size_t j = 0 ; j < c.contenu[i].size(); j++){

					if(c.contenu[i][j].size() > contenu[i][j].size()) {flag = true;}

					}

				} // if true ça signifie que la profondeur du "c" est plus grande que notre objet

		     if(!flag){

		   for(size_t i = 0 ; i < contenu.size() ; i++){
				for(size_t j = 0 ; j < c.contenu[i].size(); j++){
				    for(size_t k = 0 ; k< contenu[i][j].size()-1;k++){
						//cout<<"houni +=";
				   contenu[i][j].push_back(c.contenu[i][j][k]);
			           }

					}

				}

		   }

		  }

	  }
	} ;



ostream& operator<<(ostream& sortie , Construction const& c)  {

	c.afficher(sortie);

	return sortie;

	}
const Construction operator^(Construction a, Construction const& b)
{
	a^=b;
	return a;
}

const Construction operator-(Construction a , Construction const& b)
{
	a-=b;
	return a;
}
const Construction operator+(Construction a , Construction const& b)
{
	a+=b;
	return a;
}
const Construction operator*(unsigned int n, Construction const& a)
{
	Construction b(a);

	for(size_t i =0 ; i<n ; i++){

		b = a + b;
		//cout<<"houni *";
		}
		return b;
}

const Construction operator/(unsigned int n, Construction const& a)
{   //cout<<"houni / ";
	Construction b(a);
	for(size_t i =0 ; i<n ; i++){

		b= b ^ a;

		}
		return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{   //cout<<"houni %";
	Construction b(a);
	for(size_t i =0 ; i<n ; i++){

		b= b - a;

		}
		return b;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
