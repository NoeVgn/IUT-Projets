// Projet C++ S102 Comparaison d'approches algorithmiques
// Alexy HEMERY
// Noé VENGEON
// TP1I
#include "joueur.h"
#include "carte.h"
#include "jeu.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// Constructeur vide
Joueur::Joueur() {
  _nom = "Yugi";
  _ptsprestige = 25;
  _piledecarte.push_back(Carte("MainDroite", 1, 0, 0));
  _piledecarte.push_back(Carte("MainGauche", 0, 1, 0));
  _piledecarte.push_back(Carte("Tête", 1, -2, 0));
  _piledecarte.push_back(Carte("Bouche", 1, -1, 2));
  _piledecarte.push_back(Carte("Genou", 2, 0, 0));
}

Joueur::Joueur(const string & nom, int ptsprestige, Carte & carte) {
  _nom = nom;
  _ptsprestige = ptsprestige;
  _piledecarte.push_back(carte);
}

Joueur::Joueur(const string & nom, int ptsprestige){
  _nom=nom;
  _ptsprestige=ptsprestige;
  vector<Carte> _piledecarte;
}

void Joueur::ajouteCarte(Carte &carte) { 
  _piledecarte.push_back(carte); 
}

void Joueur::sonNom() const { cout << "Le Nom du joueur est " << _nom << endl; }

void Joueur::sonPrestige() const {
  cout << "Le Prestige du joueur est de " << _ptsprestige << endl;
}

string Joueur::getNom() const{
  return _nom;
}

int Joueur::getPrestige() const {
  return(_ptsprestige);
}

void Joueur::infoJoueur() const {
  cout << "Le joueur " << _nom << " a " << _ptsprestige
       << " points de prestige, il reste " << _piledecarte.size()
       << " cartes dans sa pile." << endl;
}

void Joueur::initPile( vector<Carte> & reserve) {
  if (!_piledecarte.empty()) {//Si la pile n'est pas vide(par exemple contient les cartes par défaut : Main Droite, Bouche ...)
    while (!_piledecarte.empty()) {
      _piledecarte.pop_back(); // Alors on les retire
    }
    for (int i = 0; i < 20; i++) {
      _piledecarte.push_back(reserve[i]); // Puis on peut ajouter dans la pile les carte à partir de la réserve
    }
  }
  else {
    for (int i = 0; i < 20; i++) {
      _piledecarte.push_back(reserve[i]);
    }
  }
}

vector<Carte> & Joueur::getPile() {
  return(_piledecarte);
}

void Joueur::affichePile() {
  for (int i=0; i<_piledecarte.size(); i++) {
    _piledecarte[i].afficheCarteSimple();
  }
}

void Joueur::afficheRangToCarte(vector<int> rangAtqCroiss) {
  for (int i=0; i<_piledecarte.size(); i++) {
    _piledecarte[rangAtqCroiss[i]].afficheCarteSimple();
  }
}

bool Joueur::verifCarte() {
  return (_piledecarte.empty());
}

bool Joueur::verifEnJeu() {
  return (_ptsprestige>0);
}

void Joueur::carteSuiv(Carte & carte) {
  if (verifCarte())
    throw (string("Il n'y a pas plus de carte dans la pile"));
  else {
    int indice;
    indice = _piledecarte.size()-1;
    carte = _piledecarte[indice];
    _piledecarte.pop_back();
  }
}

void Joueur::jouentUneCarte(Joueur & j2) {
  Carte s1;
  Carte s2;
  carteSuiv(s1);
  j2.carteSuiv(s2);
  int dp, dm;
  cout<<"Le joueur 1 joue : "<<endl;
  s1.afficheCarte();
  cout<<"Le joueur 2 joue : "<<endl;
  s2.afficheCarte();
  ////////////////////////////////////
  if(s1.degatPhysique(s2)<0) {
    dp=s1.degatPhysique(s2)*-1;
    _ptsprestige = _ptsprestige- dp;
    }
  else {
    dp=s1.degatPhysique(s2);
    j2._ptsprestige = j2._ptsprestige-dp;
  }
  ////////////////////////////////////
  if(s1.degatMagique(s2)<0) {
    dm=s1.degatMagique(s2)*-1;
    _ptsprestige = _ptsprestige-dm;
  }
  else{
    dm=s1.degatMagique(s2);
    j2._ptsprestige = j2._ptsprestige-dm;
  }
}

void Joueur::melangePile(vector<Carte> &piledecarte) { //Pas de const vector<Carte> car on mélange et donc modifie le vecteur
  srand(time(NULL));

  for (int i =0; i < piledecarte.size(); i++) {
    int alea=rand() % piledecarte.size();
    Carte temp = piledecarte[i];
    piledecarte[i] = piledecarte[alea];
    piledecarte[alea] = temp;
  }
}

void Joueur::resetPrestige(){
  _ptsprestige=25;
}

vector<Carte> & choisirCarte(vector<Carte>& pileCarte){
  vector<Carte> vec;
  string rep;
  bool trouve=false;
  int i,ind,j;
  for(i=0;i<20;i++){
    cout<<"Entrer le nom de la carte que vous voulez : (" << i << "/" << "20" <<")"<<endl;
    cin>>rep;
    ind = 0;
    for(j = 0; j<pileCarte.size(); j++){
      if(rep == pileCarte[j].getnom()){
        trouve=true;
        ind=j;
      }
    }
    if (trouve){
      vec.push_back(pileCarte[ind]);
      vec[i].afficheCarte();
    }
    else{
      cout << "Cette carte n'est pas disponible" << endl;
      i--;
    }
  }
  return vec;
}

vector<Carte> Joueur::rechercheCarte(const vector<Carte>& tab){ 
  vector<Carte> v; 
  string rep;
  bool trouve=false;
  int j=0, ind;
  for(int i=0;i<20;i++){
    cout<<"Entrer le nom de la carte que vous voulez : ( "<<i<<"/"<<"20"<<")"<<endl;
    cin>>rep;
    while(!trouve && j<tab.size()){
      trouve=(rep==tab[j].getnom());
      ind=j;
      j++;
    }
    if (trouve){
      v.push_back(tab[ind]);
      v[j].afficheCarte();
    }
  }
  return v;
}

/*vector<Carte> Joueur::choisirCarte(const vector<Carte>& pileCarte){
  vector<Carte> v;
  string rep;
  bool trouve=false;
  int j=0, ind;
  for(int i=0;i<20;i++){
    cout<<"Entrer le nom de la carte que vous voulez : (" << i << "/" << "20" <<")"<<endl;
    cin>>rep;
    while(!trouve && j<pileCarte.size()){
      trouve=(rep==pileCarte[j].getnom());
      ind=j;
      j++;
    }
    if (trouve){
      v.push_back(pileCarte[ind]);
      v[j].afficheCarteSimple();
    }
  }
  return v;
}*/



vector<Carte> Joueur::choisirCarteAlphabetique(vector<Carte>& carte) {
  vector<Carte> v;
  string rep;
  for(int i=0; i<20; i++){
    cout<<"Entrer le nom de la carte que vous voulez : "<<endl;
    cin>>rep;
    int left = 0;
    int right = carte.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (carte[mid].getnom() == rep) v.push_back(carte[mid]);
      else if (carte[mid].getnom() < rep) left = mid + 1;
      else right = mid - 1;
    }
  }
  return v;
}

int Joueur::strategie() { 
  int reponse;
  cout << "Quelle stratégie voulez-vous adopter pour votre pile de carte " << getNom() << " ? (quel ordre de rangement)" << endl;
  cout << "[1] trie par ordre croissant de l'attaque" << endl;
  cout << "[2] trie par ordre decroissant de l'attaque" << endl;
  cout << "..." << endl; //autres ordre de tri possibles (mais pas traité : manque de temps)
  cout << "[3] trie aleatoirement" << endl;
  cout << "[4] trie manuellement" << endl;
  cin>>reponse;
  while(reponse!=1 || reponse!=2 || reponse!=3 || reponse!=4){
    cout<<"Erreur veuillez resaisir votre choix (1,2,3 ou 4)"<<endl;
    cin>>reponse;
  }
  return (reponse);
}

vector<Carte> & converse(vector<Carte> & carte,vector<int> & rang){
  vector<Carte> v;
  for(int i=0;i<20;i++){
    int rank=rang[i]; //prend la valeur du vecteur rang
    v.push_back(carte[rank]);
  }
  return v;
}