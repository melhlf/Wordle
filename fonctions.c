#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

#define NBMOTS 638


/////////////*FONCTIONS*///////////
    void copier(char src[], char dest[]){
       int i;
       for(i=0;i<6;i++){
        dest[i]=src[i];
       }
    }

    int comparer(char arg1[],char arg2[]){
        int i=0;
        for(i=0;i<5;i++){
            if(arg1[i]!=arg2[i])
            {
                return 0;
            }
        }
        return 1;
    }
    int existe(char mot[], char dico[][6], int nb){
    int i;
    for (i = 0; i < nb; i++){ 
        if (comparer(mot, dico[i])){
            return 1;           
        }
    }
    return 0;                  
    }

    void minuscule(char mot[]){
    int i;
    for(i=0; mot[i]!='\0'; i++){
        if(mot[i]>='A' && mot[i]<='Z'){
            mot[i] = mot[i] + 32;
        }
    }
    }

    void bonnecouleur(char secret[],char proposition[],int couleurs[]){
        int i,j,dejavu[5]={0,0,0,0,0};
        for(i=0;i<5;i++){
            if (secret[i]==proposition[i])
            {
                couleurs[i]=2;
                dejavu[i]=1;
            }else{
                couleurs[i]=0;
            }
            }
          
                for(i=0;i<5;i++){
                if (couleurs[i]==0){
                for ( j = 0; j < 5; j++)
                {
                    if (proposition[i]==secret[j] && dejavu[j]==0)
                    {
                        couleurs[i]=1;
                        dejavu[j]=1;
                        break;
                    }
                }
                }
        }
    }
    
    void affichage(char tableau[][6],int couleurs[][5],int essaie){
        int i,j;
        for ( i = 0; i < 6; i++)
        {
            for ( j = 0; j< 5; j++)
            {
                if (i<essaie)
                {
                    switch (couleurs[i][j])
                    {
                    case 2:
                        printf("\33[30;42m %c \33[00m ",tableau[i][j]);
                        break;
                    case 1:
                        printf("\33[30;43m %c \33[00m ",tableau[i][j]);
                        break;
                    default:
                        printf("\33[90;100m %c \33[00m ",tableau[i][j]);
                        break;
                    }
                }else{
                printf(" .  ");
                }
                printf(" ");
            }
            printf("\n\n");
        }
        
    }
