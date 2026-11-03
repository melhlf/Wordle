#ifndef FONCTIONS
#define FONCTIONS


void copier(char src[], char dest[]);
int comparer(char arg1[],char arg2[]);
int existe(char mot[], char dico[][6], int nb);
void minuscule(char mot[]);
void bonnecouleur(char secret[],char proposition[],int couleurs[]);
void affichage(char tableau[][6],int couleurs[][5],int essaie);

#endif