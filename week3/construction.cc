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
 if(couleur!=""){

	 sortie <<"("<<forme<<", "<<couleur<<") ";
	 return sortie;
	 }
	else
	sortie <<forme;

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
  Construction (Brique const& b):contenu(1,vector<vector<Brique>>(1,vector<Brique>(1,b))){
	  //vector<vector<vector <Brique>>> t ({{{b}}});

	  }

  ostream& afficher(ostream& sortie) const {

	  if(!contenu.empty()){
		  //cout << "size = "<< contenu.size() <<endl;
		  for(size_t i = contenu.size() ; i > 0 ; i-- ){
              
			  cout <<"Couche "<<i-1<<" :"<< endl;
			  for(size_t j = 0 ;j < contenu[i-1].size(); j++){
				  
				  for(size_t k = 0; k < contenu[i-1][j].size();  k++){
					  sortie << contenu[i-1][j][k];
					  
					  }
				  cout << endl;
				  }

			  }
		  }
	  return sortie;
	  }



  void operator^=(Construction const& c){
	  
	  for(size_t i =0 ; i< c.contenu.size();i++){
	  contenu.push_back(c.contenu[i]);
    }
	 //vector<vector<vector <Brique> > > I;
	 //vector<vector <Brique> > J ;
	 //vector <Brique> K ;
	 
	 
	   //// int ta = contenu.size()-1;
        //for(int i =0 ; i< c.contenu.size();i++){
			//for(int j = 0 ;j < c.contenu[i].size(); j++){
				  //for(int k=0; k < c.contenu[i][j].size();  k++){
					
					   //K.push_back(c.contenu[i][j][k]);
					  
					  //}
					  //J.push_back(K);
				  //}
				  
			
			//contenu.push_back(J);
			//K.clear();
			//J.clear();
			//}

	  }

 void operator-=(Construction const& c){
   vector<Brique> J;
	 if(c.contenu.size() >= contenu.size()){

		 for(size_t i = 0 ; i < contenu.size() ; i++){
          //hauteur
			 for(size_t j = 0 ; j < c.contenu[i].size(); j++){
             //profondeur
				 for(size_t k = 0 ; k < c.contenu[i][j].size() ; k++){
                 //largeur
                        J.push_back(c.contenu[i][j][k]);
					 }
					 contenu[i].push_back(J);
					 J.clear();

				 }

			 }

		 }

	 }




  void operator+=(Construction const& c){

    //vector<vector <Brique> > J ;
	 //vector <Brique> K ;

  
	   if(c.contenu.size() >= contenu.size()){
		   bool flag=false;

		    for(size_t i = 0 ; i < c.contenu.size() ; i++){
				//for(int j = 0 ; j < c.contenu[i].size(); j++){
					//for(int l = 0 ; l < contenu[i].size(); l++) {

					if(c.contenu[i].size() < contenu[i].size()) {flag = true;}
					 
					// }
					//}

				} // if true ça signifie que la profondeur du "c" est plus petite que notre objet

		     if(flag == false){

		   for(size_t i = 0 ; i < contenu.size() ; i++){
				for(size_t j = 0 ; j < contenu[i].size(); j++){
				    for(size_t k = 0 ; k < c.contenu[i][j].size();k++){
					
					 //K.push_back(c.contenu[i][j][k]);
				   ////contenu[i][j].push_back(c.contenu[i][j][k]);
			           //}
                    //contenu[i].push_back(K);
                    //K.clear();
                    
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

	for(size_t i =0 ; i<n-1 ; i++){

		b = a + b;
		//cout<<"houni *";
		}
		return b;
}

const Construction operator/(unsigned int n, Construction const& a)
{   //cout<<"houni / ";
	Construction b(a);
	for(size_t i =0 ; i<n-1 ; i++){

		b= b ^ a;

		}
		return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{   //cout<<"houni %";
	Construction b(a);
	for(size_t i =0 ; i<n-1; i++){

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
