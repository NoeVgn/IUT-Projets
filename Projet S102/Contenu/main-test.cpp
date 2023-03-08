// Projet C++ S102 Comparaison d'approches algorithmiques
// Alexy HEMERY
// Noé VENGEON
// TP1I
#include "carte.h"
#include "joueur.h"
#include "jeu.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main_test() {
  Carte cdef; // Carte vide
  Carte c("Poele", 5, 5, 5);
  Carte c1("Cuillere", 2, 1, 2);
  Carte c2("Epee simple", 5, 1, 5);

  Joueur jdef; // Joueur test

  Jeu jeudef; // Jeu test

  cout << endl << "Carte vide" << endl;
  cdef.afficheCarte();
  cout << endl;
  cout << "Carte pleine" << endl;
  c.afficheCarte();

  cout << endl;
  jdef.ajouteCarte(c2);
  jdef.sonNom();
  cout << endl;
  jdef.sonPrestige();
  cout << endl;
  jdef.infoJoueur();
  // cout << cdef.degatPhysique(c) << endl;

  // Test degatPhysique  -  "Cuillere" (cible) attaque  --> "Epee Simple"
  // (adversaire) Resultat attendu : inflige -4 au joueur qui a la cuillere (à
  // soi-même)
  if (c1.degatPhysique(c2) == -4)
    cout << "Test fonction degatPhysique : CORRECT | attendu : -4 | resultat : "
         << c1.degatPhysique(c2) << endl;
  else
    cout << "Test fonction degatPhysique : INCORRECT | attendu : -4 | resultat "
            ": "
         << c1.degatPhysique(c2) << endl;

  // Test degatPhysique  -  "Epee Simple" (cible) attaque  --> "Cuillere"
  // (adversaire) Resultat attendu : inflige 4 au joueur qui a la cuillere (à
  // l'adversaire)
  if (c2.degatPhysique(c1) == 4)
    cout << "Test fonction degatPhysique : CORRECT | attendu : 4 | resultat : "
         << c2.degatPhysique(c1) << endl;
  else
    cout
        << "Test fonction degatPhysique : INCORRECT | attendu : 4 | resultat : "
        << c2.degatPhysique(c1) << endl;

  // Test degatMagique  -  "Cuillere" (cible) attaque  --> "Epee Simple"
  // (adversaire) Resultat attendu : inflige -5 au joueur qui a la cuillere (à
  // soi-même)
  if (c1.degatMagique(c2) == -5)
    cout << "Test fonction degatMagique : CORRECT | attendu : -5 | resultat : "
         << c1.degatMagique(c2) << endl;
  else
    cout
        << "Test fonction degatMagique : INCORRECT | attendu : -5 | resultat : "
        << c1.degatMagique(c2) << endl;

  // Test degatMagique  -  "Epee Simple" (cible) attaque  --> "Cuillere"
  // (adversaire) Resultat attendu : inflige 5 au joueur qui a la cuillere (à
  // l'adversaire)
  if (c2.degatMagique(c1) == 5)
    cout << "Test fonction degatMagique : CORRECT | attendu : 5 | resultat : "
         << c2.degatMagique(c1) << endl;
  else
    cout << "Test fonction degatMagique : INCORRECT | attendu : 5 | resultat : "
         << c2.degatMagique(c1) << endl;

  jeudef.initialiserReserve("jeudecarte.txt");
  jdef.initPile(jeudef.getReserve());

  //jeudef.afficheReserve();
  cout << "Pile avant le melange : " << endl;
  jdef.affichePile();
  cout << endl <<"Pile apres le melange : " << endl;
  jdef.melangePile(jdef.getPile());
  jdef.affichePile();
  /////////////////////////////
  cout<<endl;
  
  vector<int> temp;
  temp=jeudef.vecAtqCroissante(jdef.getPile());
  afficheVecRangAtqCroiss(temp);
  cout << endl << "Pile de carte du joueur jdef trie par points d'attaque croissant : " << endl << endl;
  jdef.afficheRangToCarte(temp);
  cout << endl << "Pile de carte du joueur jdef trie par points d'attaque decroissant : " << endl << endl;
  jdef.afficheRangToCarte(inverseVec(temp));
  
  
}