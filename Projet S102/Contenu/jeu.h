// Projet C++ S102 Comparaison d'approches algorithmiques
// Alexy HEMERY
// Noé VENGEON
// TP1I
// Classe Jeu pour gérer la partie

#ifndef _JEU_H_
#define _JEU_H_

#include "joueur.h"
#include "carte.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Jeu {
  vector<Carte> _reserve;
  Joueur _joueur1;
  Joueur _joueur2;

public:
  Jeu();
  Jeu(Joueur,Joueur);
  Jeu(vector<Carte> &, Joueur, Joueur);
  void initj(Joueur,Joueur);
  void joueCarte();
  void afficheReserve();
  bool verifFin();
  int vainqueur();
  vector<Carte> & getReserve();
  void initialiserReserve(const string& fichier);
  vector<int> vecAtqCroissante(const vector<Carte> &);
};
bool rejouer();
void echanger(int ind1, int ind2, vector<Carte> &, vector<int> &);
void afficheVecRangAtqCroiss(vector<int> &);
vector<int> inverseVec(vector<int> vecteurCroissant);
void regle();
int modeJeu();

#endif