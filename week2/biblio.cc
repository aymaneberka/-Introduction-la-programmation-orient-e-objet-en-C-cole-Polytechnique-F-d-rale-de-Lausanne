#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
 
 
 class Auteur{
	 
	 string nom;
	 bool perime;
	 
	 public:
	 
	 Auteur( string n , bool p=false):nom(n),perime(p){}
	 string getNom() const {return nom;}
	 bool getPrix() const{return perime;}
		 
     Auteur( Auteur const& ) = delete;
	 
	 
	 };
	 
class Oeuvre{
	
	string titre;
	string langue;
	Auteur const& auteur;
	
	public:
	Oeuvre(string t , Auteur const& A , string l):titre(t),auteur(A),langue(l){}
	//{titre=t; auteur=A; langue=l;}
	string getTitre() const{return titre;}
	Auteur const&  getAuteur() const{return auteur;}
	string getLangue() const{return langue;}
	
	void affiche(){
		
		cout << titre<<", "<< auteur.getNom() <<", en "<<langue << endl;
		}
	
 
 ~Oeuvre(){ 
	 char c = 0x22;
	 cout << "L'oeuvre " <<c<<titre<<", "<<auteur.getNom()<<", en "<<langue<<c<<" n'est plus disponible."<<endl;}
 
};

class Exemplaire {
	
	Oeuvre& oeuvre ;  
	
	public:
	
	Exemplaire(Oeuvre& o):oeuvre(o){cout <<"Nouvel exemplaire de : "; oeuvre.affiche() ;}
	//Exemplaire( Exemplaire const&  Ou):oeuvre(Ou.getOeuvre().getTitre(),Ou.getOeuvre().getLangue() , Ou.getOeuvre().getAuteur() ) { cout <<"Copie d'un exemplaire de : "<< Ou.getOeuvre().getTitre()<<", "<<Ou.getOeuvre().getAuteur().getNom()<<", en "<<Ou.getOeuvre().getLangue() << endl; }
	~Exemplaire(){
		char c = 0x22;
		cout <<"Un exemplaire de "<<c<< oeuvre.getTitre()<<", "<<oeuvre.getAuteur().getNom() <<", en "<<oeuvre.getLangue()<<c <<" a été jeté !"<< endl; }
	const Oeuvre&  getOeuvre() const{ return oeuvre;}
	void affiche() const { 	cout <<"Exemplaire de : "<< oeuvre.getTitre()<<", "<<oeuvre.getAuteur().getNom() <<", en "<<oeuvre.getLangue() << endl;  }
	
	
	};
	
class Bibliotheque{
	
	string nom;
	vector<Exemplaire*> ens;
	
	public:
	Bibliotheque(string n):nom(n){cout << "La bibliothèque "<<nom<<" est ouverte !"<<endl;}
	string getNom() const{return nom;}
	
	void stocker(Oeuvre& o,int n=1){
		int i =0;
		do{
			//Exemplaire exp(o);
			ens.push_back(new Exemplaire(o));
			i++;
			
			
			}while(i<n);
		}
		
		
	void lister_exemplaires(){
		
		for(size_t i =0 ; i<ens.size();i++){
			ens[i]->affiche();
			}
		
		}
		
	void lister_exemplaires(string l){
		
		for(size_t i =0 ; i<ens.size();i++){
			if(ens[i]->getOeuvre().getLangue()==l){
				
				ens[i]->affiche();
				}
			}
		
		}
		
	
	int compter_exemplaires( Oeuvre const& o){
		
		int c=0;
		for(size_t i=0;i<ens.size();i++){
			
			if(ens[i]->getOeuvre().getTitre()==o.getTitre()){
				c++;
				}
			
			}
		return c;
		}
		
		
	void afficher_auteurs(bool flag =false){
		
		if (flag == true){
			
			for(size_t i=0 ; i < ens.size();i++){
				if(ens[i]->getOeuvre().getAuteur().getPrix() == true){
					cout << ens[i]->getOeuvre().getAuteur().getNom() << endl;
					}
				}
			  
			}
		
		}
		
		
		
	~Bibliotheque(){
		
		cout << "La bibliothèque "<<nom<<" ferme ses portes,"<<endl;
        cout <<"et détruit ses exemplaires :"<< endl;
        
        for(size_t i=0 ; i < ens.size();i++){
			delete ens[i];
			}
		}
	
	};
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
