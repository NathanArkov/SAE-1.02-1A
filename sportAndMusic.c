#include "sportAndMusic.h"
#include <stdio.h>
#include <stdlib.h>
#include "openFile.h"
#include <string.h>
#define TAILLE_TABLE 100

int sportAndMusic() {
  
  T_Ensemble SPORT;
  SPORT = openFile("data/SPORT.txt", "rt");
  T_Ensemble MUSIQUE;
  MUSIQUE = openFile("data/MUSIQUE.txt", "rt");
	T_Etudiant etu;
	int i, j;  // VARIABLES POUR LES BOUCLES for
  printf("= Sportifs ET Muisiciens =\n\n");
	printf("Liste des étudiants sportifs et musiciens :\n\n");

  for( i=0; i<SPORT.nombreTotalEtudiants; i++)
  {
  //printf("Sportif numero %d = %s.\n", i, SPORT.ensemble[i].nom);
  for( j=0; j<MUSIQUE.nombreTotalEtudiants; j++)
  {
   
   if(strcmp(SPORT.ensemble[i].nom, MUSIQUE.ensemble[j].nom) == 0)
   {
     printf("%s (Département : %s)\n", MUSIQUE.ensemble[j].nom, MUSIQUE.ensemble[j].dpt);
   }
  }

 
  }
	printf("\n\n\n");
	return 0;
}