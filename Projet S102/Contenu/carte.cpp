// Projet C++ S102 Comparaison d'approches algorithmiques
// Alexy HEMERY
// Noé VENGEON
// TP1I

#include "carte.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

// Constructeur vide
Carte::Carte() {
  _nom = "Mains nues";
  _attaque = 1;
  _defense = 1;
  _magie = 0;
}

// Constructeur
Carte::Carte(const string &nom, int attaque, int defense, int magie) {
  _nom = nom;
  _attaque = attaque;
  _defense = defense;
  _magie = magie;
}

// Affichage d'une carte
void Carte::afficheCarte() const {
  cout << "**********************" << endl;
  cout << "Nom : " << _nom << endl;
  cout << "Attaque : " << _attaque << endl;
  cout << "Defense : " << _defense << endl;
  cout << "Magie : " << _magie << endl;
  cout << "**********************" << endl;
}

void Carte::afficheCarteSimple() const {
  cout << _nom << "(" << _attaque << "," << _defense << "," << _magie << ")" << endl;
}

/*
  Carte c1("Cuillere", 2, 1, 2);
  Carte c2("Epee simple", 5, 1, 5);
*/

int Carte::degatPhysique(const Carte &carte) const {

  int result;

  if (_attaque > carte._attaque) { // La carte cible a plus d'attaque que la carte paramètre
    if (carte._defense > _attaque)
      result = 0;
    else
      result = _attaque - carte._defense;
  }


  else if(_attaque < carte._attaque) {
    if(_defense > carte._attaque) // Mais si la carte cible a plus de defense // La carte cible a moins d'attaque que la carte paramètre
      result = 0;
    else
      result = 0 - (carte._attaque - _defense); // Sinon les dégats sont bien pris par la carte cible
  }
    
  else
    result = 0;

  return (result);
}

int Carte::degatMagique(const Carte &carte) const {
  
  int result;
  
  if(_magie > carte._magie)
    result = _magie;
  else if (_magie < carte._magie)
    result = 0 - carte._magie;
  else
    result = 0;
  
  return (result);
}

void Carte::remplir(const string &ligne){
  parser(ligne, _nom, _attaque, _defense, _magie);
}

int Carte::getAttaque() const {
  return(_attaque);
}

void parser(const string &ligne, string & nom, int & a, int & d, int & m){
  //N.B. avec le #include <sstream> on peut accéder à une class stringstream
  
  stringstream ss(ligne); //créé un objet stringstream nommé "ss" en utilisant la chaîne "ligne" en tant que entrée permettant de traiter la chaîne ligne comme un flux de données pour extraire les différentes parties de la chaîne
  getline(ss, nom, ',');//extrait la première partie de la chaîne "ligne" jusqu'il y ait une virgule puis l'affecte à "nom"
  ss >> a; // On assigne donc à "a" (attaque) la deuxième partie de "ss"
  if(ss.peek() == ',') ss.ignore(); //vérifie si les valeurs "a", "d" et "m" ne sont pas délimitées par une virgule dans la chaîne "ligne"
    ss >> d; // On assigne donc à "d" (defense) la troisième partie de "ss"
  if(ss.peek() == ',') ss.ignore();
    ss >> m; // On assigne donc à "m" (magie) la quatrième partie de "ss"
}

string Carte::getnom() const { 
  return _nom; 
}