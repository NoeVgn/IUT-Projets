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

int main() {
  try{
  regle();
  bool recommencer;
  recommencer=true;
  bool verif;
  verif=true;
  while (recommencer) {
    Joueur j1; // joueur j1
    Joueur j2; // joueur j2
    Jeu jeudef(j1,j2); // class jeu
    jeudef.initialiserReserve("jeudecarte.txt");
    cout<<endl;
    int reponse;
    cout << "Quel mode de jeu voulez-vous jouer ?" << endl;
    cout << "[1] mode de jeu humain contre IA" << endl;
    cout << "[2] mode de jeu humain contre humain" << endl;
    cin>>reponse;
    /*while(reponse != 1 || reponse != 2){
      cout<<"Erreur veuillez resaisir votre choix (1 ou 2)"<<endl;
      cin >> reponse;
    }*/
    switch (reponse){
      case 1: // humain contre IA
        {
        cout<<"Quelle stratégie voulez-vous adopter pour votre pile de carte ? (quel ordre de rangement ?)"<<endl;
        cout << "[1] trie par ordre croissant de l'attaque" << endl;
        cout << "[2] trie par ordre decroissant de l'attaque" << endl;
        cout << "..." << endl; //autres ordre de tri possibles (mais pas traité : manque de temps)
        cout << "[3] trie aleatoirement" << endl;
        cout << "[4] trie manuellement" << endl;
        int strat;
        cin>>strat;
        /*while(strat!=1 || strat!=2 || strat!=3 || strat!=4){
          cout<<"Erreur veuillez resaisir votre choix (1,2,3 ou 4)"<<endl;
          cin>>strat;
        }*/
        switch (strat) {
          case 1: // ordre croissant
            {
            j1.initPile(jeudef.getReserve());
            vector<int> temp=jeudef.vecAtqCroissante(j1.getPile());
            j1.initPile(converse(j1.getPile(),temp));
              }
            break;
          case 2: // decroissant
            {
            vector<int> temp2;
            j1.initPile(jeudef.getReserve());
            temp2=jeudef.vecAtqCroissante(j1.getPile());
            temp2=inverseVec(temp2);
            j1.initPile(converse(j1.getPile(),temp2));
              }
            break;
          case 3: // trie aleatoire
            {
            j1.initPile(jeudef.getReserve());
            j1.melangePile(j1.getPile());
              }
            break;
          case 4: // trie manuel
            {
            jeudef.afficheReserve();
            j1.initPile(choisirCarte(jeudef.getReserve()));
            }
            break;
          }
        j2.initPile(jeudef.getReserve());
        j2.melangePile(j2.getPile());
        cout<<"la pile du joueur 1 contient : "<<endl;
        j1.affichePile();
        cout<<endl;
        cout<<"La pile du joueur 2 contient : "<<endl;
        j2.affichePile();
        cout<<endl;
        jeudef.initj(j1,j2);
          while(verif){
            jeudef.joueCarte();
            verif=!jeudef.verifFin();
          }
          break;
      }
      case 2: // humain contre humain
        {
        cout<<"------------Joueur1------------"<<endl;
        cout<<"Quelle stratégie voulez-vous adopter pour votre pile de carte ? (quel ordre de rangement ?)"<<endl;
        cout << "[1] trie par ordre croissant de l'attaque" << endl;
        cout << "[2] trie par ordre decroissant de l'attaque" << endl;
        cout << "..." << endl; //autres ordre de tri possibles (mais pas traité : manque de temps)
        cout << "[3] trie aleatoirement" << endl;
        cout << "[4] trie manuellement" << endl;
        int strat;
        cin>>strat;
        /*while(strat!=1 || strat!=2 || strat!=3 || strat!=4){
          cout<<"Erreur veuillez resaisir votre choix (1,2,3 ou 4)"<<endl;
          cin>>strat;
        }*/
        switch (strat) {
          case 1: // ordre croissant
            {
            vector<int> temp;
            temp=jeudef.vecAtqCroissante(j1.getPile());
            j1.initPile(converse(j1.getPile(),temp));
              }
            break;
          case 2: // ordre decroissant
            {
            vector<int> temp2;
            temp2=jeudef.vecAtqCroissante(j1.getPile());
            temp2=inverseVec(temp2);
            j1.initPile(converse(j1.getPile(),temp2));
              }
            break;
          case 3: // trie aleatoire
            {
            j1.initPile(jeudef.getReserve());
            j1.melangePile(j1.getPile());
              }
            break;
          case 4: // trie manuel
            {
            jeudef.afficheReserve();
            j1.initPile(choisirCarte(jeudef.getReserve()));
              }
            break;
          }
        cout<<"------------Joueur2------------"<<endl;
        cout<<"Quelle stratégie voulez-vous adopter pour votre pile de carte ? (quel ordre de rangement ?)"<<endl;
        cout << "[1] trie par ordre croissant de l'attaque" << endl;
        cout << "[2] trie par ordre decroissant de l'attaque" << endl;
        cout << "..." << endl; //autres ordre de tri possibles (mais pas traité : manque de temps)
        cout << "[3] trie aleatoirement" << endl;
        cout << "[4] trie manuellement" << endl;
        int strat2;
        cin>>strat2;
        /*while(strat2!=1 || strat2!=2 || strat2!=3 || strat2!=4){
          cout<<"Erreur veuillez resaisir votre choix (1,2,3 ou 4)"<<endl;
          cin>>strat2;
        }*/
        switch (strat2) {
          case 1: // ordre croissant
            {
            vector<int> temp;
            temp=jeudef.vecAtqCroissante(j2.getPile());
            j2.initPile(converse(j2.getPile(),temp));
              }
            break;
          case 2: // ordre decroissant
            {
            vector<int> temp2;
            temp2=jeudef.vecAtqCroissante(j2.getPile());
            temp2=inverseVec(temp2);
            j2.initPile(converse(j2.getPile(),temp2));
              }
            break;
          case 3: // trie aleatoire
            {
            j2.initPile(jeudef.getReserve());
            j2.melangePile(j2.getPile());
              }
            break;
          case 4: // trie manuel
            {
            jeudef.afficheReserve();
            j2.initPile(choisirCarte(jeudef.getReserve()));
              }
            break;
          }
        cout<<"la pile du joueur 1 contient : "<<endl;
        j1.affichePile();
        cout<<endl;
        cout<<"La pile du joueur 2 contient : "<<endl;
        j2.affichePile();
        cout<<endl;
        jeudef.initj(j1,j2);
          while(verif){
            jeudef.joueCarte();
            verif=!jeudef.verifFin();
          }
          break;
        }
    }
    cout<<endl;
    if(jeudef.vainqueur()==1) cout <<"Felicitations ! Le joueur 1 est le gagnant"<<endl;
    else if(jeudef.vainqueur()==0) cout<<"Match nul ! Le jeu se fini par une egalite"<<endl;
    else cout <<"Felicitations ! Le joueur 2 est le gagnant"<<endl;

    //Savoir si le joueur veut recommencer
    recommencer=rejouer();
  }
  cout<<"Merci d'avoir joué"<<endl;
}
  catch(invalid_argument &e){
    cerr<<"ERREUR : " << e.what() << endl;
  }
  catch(out_of_range &e){
    cerr<<"ERREUR : "<<e.what()<<endl;
  }
}