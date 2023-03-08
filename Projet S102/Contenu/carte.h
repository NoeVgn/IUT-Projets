// Projet C++ S102 Comparaison d'approches algorithmiques
// Alexy HEMERY
// Noé VENGEON
// TP1I
// Classe Carte pour gerer les cartes à jouer
#ifndef _CARTE_H_
#define _CARTE_H_

#include <string>
#include <iostream>

using namespace std;

class Carte {
  string _nom;  // Nom de la carte
  int _attaque; // Statistique d'attaque de la carte
  int _defense; // Statistique de défense de la carte
  int _magie;   // Statistique de magie de la carte

public:
  /*------------------Carte();
  constructeur vide
  construit une carte vide si il n'y a pas de données précises
  */
  Carte();

  /*------------------Carte();
  construit une carte
  à l'aide de données précisés : nom, ataque, defense, magie
  */
  Carte(const string &, int , int , int );

  /*------------------void afficheCarte() const;
  affiche une carte avec son nom, attaque, defense et sa magie de manère esthétique
  */

  void afficheCarte() const;

  /*------------------void afficheCarteSimple() const;
  affiche une carte avec son nom, attaque, defense et sa magie de manère moins esthétique
  mais plus lisible et ainsi plus pratique pour les test
  */

  void afficheCarteSimple() const;

  /*------------------int degatPhysique(const Carte &)const;
  inflige des degats physique, soit a la carte cible,
  soit a la carte en parametre selon les statistiques
  */
  int degatPhysique(const Carte &)const;

  /*------------------int degatMagique(const Carte &)const;
  inflige des degats magique, soit a la carte cible,
  soit a la carte en parametre selon les statistiques
  */
  int degatMagique(const Carte &) const;

  void remplir(const string & ligne);

  int getAttaque() const;

  string getnom() const;

};

void parser(const string &, string &,int &,int &,int &);

#endif