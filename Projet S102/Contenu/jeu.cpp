// Projet C++ S102 Comparaison d'approches algorithmiques
// Alexy HEMERY
// Noé VENGEON
// TP1I

#include "jeu.h"
#include "carte.h"
#include "joueur.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//Constructeur vide
Jeu::Jeu() {
  vector<Carte> _reserve; // on définit le vecteur en vide
  Joueur _joueur1; // Aucun joueur
  Joueur _joueur2; // Aucun joueur
  }

//Constructeur
Jeu::Jeu(vector<Carte> &reserve, Joueur joueur1, Joueur joueur2) {
  _reserve = reserve;
  _joueur1 = joueur1;
  _joueur2 = joueur2;
  }

//Constructeur
Jeu::Jeu(Joueur joueur1, Joueur joueur2){
  vector<Carte> _reserve;
  _joueur1=joueur1;
  _joueur2=joueur2;
}

void Jeu::initj(Joueur j1, Joueur j2){
  _joueur1=j1;
  _joueur2=j2;
  _joueur1.resetPrestige();
  _joueur2.resetPrestige();
}

//Question 1 - Deroulement d'une partie
void Jeu::joueCarte() {
  _joueur1.jouentUneCarte(_joueur2);
  cout << "joueur 1 : "<<endl;
  _joueur1.sonPrestige();
  cout << "joueur 2 : "<<endl;
  _joueur2.sonPrestige();
}

void Jeu::afficheReserve() {
  for (int i=0; i<_reserve.size(); i++) {
    _reserve[i].afficheCarteSimple();
  }
}

//Savoir quel joueur est le vainqueur
bool Jeu::verifFin() {
  return (_reserve.empty() || _joueur1.getPrestige()<=0 || _joueur2.getPrestige()<=0);
}

int Jeu::vainqueur(){
  int result;
  //Si le joueur 1 gagne
  if(_joueur1.getPrestige() > _joueur2.getPrestige()) result=1;
  //Si il y a match nul
  else if (_joueur1.getPrestige() == _joueur2.getPrestige()) result=0;
  //Si le joueur 2 gagne
  else result=-1;
  return result;
}

vector<Carte> & Jeu::getReserve() {
  return(_reserve);
}

void Jeu::initialiserReserve(const string& fichier) {
  
  ifstream fichiertxt(fichier, ios::in);  // on ouvre en lecture
 
  if(fichiertxt.is_open())  // si l'ouverture a fonctionné
    {
      string ligne;  // déclaration d'une chaîne qui contiendra la ligne lue
      while(getline(fichiertxt, ligne)) {
        //getline(fichiertxt, ligne);
        Carte nouvelle_carte;
        nouvelle_carte.remplir(ligne);
        _reserve.push_back(nouvelle_carte);
      }
 
      fichiertxt.close();
    }
  else
    cerr << "Impossible d'ouvrir le fichier !" << endl;
}

vector<int> Jeu::vecAtqCroissante(const vector<Carte> & pile) {
    vector<int> rangAtqCroiss;
    vector<Carte> vecCarteTemp = pile;
    for(int i=0; i<pile.size(); i++){
        rangAtqCroiss.push_back(i);
    }
    bool echange;
    echange = false;
    while(!echange) {
        echange = true;
        for(int i=0; i<vecCarteTemp.size()-1; i++) { // algorithme de tri à bulle par rapport a l'attaque trier dans l'ordre croissant
            if(vecCarteTemp[i].getAttaque() > vecCarteTemp[i+1].getAttaque()) {
                echanger(i, i+1, vecCarteTemp, rangAtqCroiss);
                echange = false;
            }
        }
    }
    return rangAtqCroiss;
}

void echanger(int ind1, int ind2, vector<Carte> &vecCarteTemp, vector<int> &rangAtqCroiss)
{ // echange 2 valeurs de 2 vecteurs
    Carte tpm = vecCarteTemp[ind1];
    int rang = rangAtqCroiss[ind1];
    vecCarteTemp[ind1] = vecCarteTemp[ind2];
    rangAtqCroiss[ind1] = rangAtqCroiss[ind2];
    vecCarteTemp[ind2] = tpm;
    rangAtqCroiss[ind2] = rang;
}

void afficheVecRangAtqCroiss(vector<int> & rangAtqCroiss) {
  for (int i=0; i<rangAtqCroiss.size(); i++) {
    cout << rangAtqCroiss[i] << endl;
  }
}

// inverse un vecteur exemple: vecteur de int dans ordre croissant devient un vecteur dans ordre décroissant
vector<int> inverseVec(vector<int> vecteurCroissant)
{
    int n = vecteurCroissant.size();
    for(int i=0; i<n/2; i++)
    {
        int temp = vecteurCroissant[i];
        vecteurCroissant[i] = vecteurCroissant[n-i-1];
        vecteurCroissant[n-i-1] = temp;
    }
    return vecteurCroissant;
}

void regle(){
  cout<< "-------------------REGLE----------------------" <<endl;
  cout<<"Le jeu consiste en l’affrontement de deux joueurs très prestigieux (ils ont 25 points de prestige) chacun muni d’une pile de 20 cartes sélectionnées à partir d’une réserve identique. Chaque carte a trois statistiques : une valeur d’attaque physique, une valeur de puissance magique et une valeur de défense physique. L’objectif est de réduire les points de prestige de son adversaire et de défendre les siens. Le vainqueur est le premier à envoyer son adversaire dans la boue (prestige à zéro) ou d’avoir plus de prestige que son adversaire à la fin de l’affrontement (lorsqu’il n’y a plus de carte ou lorsque les deux joueurs sont dans le négatif). Dans un premier temps chaque joueur classe ses cartes dans l’ordre de son choix. Ensuite, on fait défiler les cartes, une carte de chaque joueur à la fois simultanément, comme à la bataille. Les cartes de chaque joueur sont comparées et des dégâts sont infligés au prestige de chacun. Les attaques se confrontent aux défenses et les magies se confrontent entre elles. Le calcul des dégâts suit les règles : "<<endl;
  cout<<endl;
  cout << "Le joueur qui a le plus d’attaque physique diminue le prestige de son adversaire de la différence entre sa valeur d’attaque et la valeur de défense de l’autre joueur. Si les deux joueurs ont la même valeur d’attaque physique, aucun dégât physique n’est infligé au prestige des joueurs. Si le défenseur a plus de défense que la valeur d’attaque, le défenseur ne regagne pas de point de prestige." <<endl;
  cout << endl;
  cout<< "Le joueur qui a le plus de puissance magique diminue le prestige de son adversaire de la différence entre les valeurs de puissance magique des deux joueurs." <<endl;
  cout<< "----------------------------------------------" <<endl;
}

bool rejouer() {
  char reponse;
  bool recommencer = false;
  cout << "Voulez-vous rejouer [O=oui/N=non]" << endl;
  cin >> reponse;
  while(reponse != 'O' && reponse != 'N') {
    cout << "Veuillez entrer 'O' pour rejouer ou 'N' pour arreter de jouer" << endl;
    cin >> reponse;
  }
  if (reponse == 'O') {
    recommencer = true;
  }
  return recommencer;
}

int modeJeu(){
  int reponse;
  cout << "Quel mode de jeu voulez-vous jouer ?" << endl;
  cout << "[1] mode de jeu humain contre IA" << endl;
  cout << "[2] mode de jeu humain contre humain" << endl;
  cin>>reponse;
  while(reponse!=1 || reponse!=2){
    cout<<"Erreur veuillez resaisir votre choix (1 ou 2)"<<endl;
    cin>>reponse;
  }
  return (reponse);
}
