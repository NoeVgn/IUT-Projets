// Projet C++ S102 Comparaison d'approches algorithmiques
// Alexy HEMERY
// Noé VENGEON
// TP1I
// Class Joueur pour gerer les joueurs
#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include "carte.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Joueur {
  string _nom;                // Nom du joueur
  int _ptsprestige;           // Nombre de points de prestige du joueur
  vector<Carte> _piledecarte; // Pile de carte

public:
  // constructeur vide
  Joueur();
  // Constructeur
  Joueur(const string &, int, Carte &);
  // Constructeur
  Joueur(const string &, int);

  void ajouteCarte(Carte &);

  void sonNom() const;

  string getNom() const;

  void sonPrestige() const;

  int getPrestige() const;

  void infoJoueur() const;

  void initPile(vector<Carte> &);

  vector<Carte> & getPile();

  void affichePile();

  void afficheRangToCarte(vector<int> rangAtqCroiss);

  bool verifCarte();

  bool verifEnJeu();

  void carteSuiv(Carte &);

  void jouentUneCarte(Joueur &);

  void melangePile(vector<Carte> &reserve);


  vector<Carte> choisirCarteAlphabetique(vector<Carte>&);

  void resetPrestige();

  int strategie();

  vector<Carte> rechercheCarte(const vector<Carte>&);

};

  vector<Carte> & choisirCarte(vector<Carte>&);

  vector<Carte> & converse(vector<Carte> &,vector<int> &);

#endif