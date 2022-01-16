#include "noActivity.h"
#include <stdio.h>
#include <stdlib.h>
#include "openFile.h"
#include <string.h>

int noActivity()
{
  
  T_Ensemble SPORT;
  SPORT = openFile("data/SPORT.txt", "rt");
  T_Ensemble MUSIQUE;
  MUSIQUE = openFile("data/MUSIQUE.txt", "rt");
  
  FILE * acces_fichier; // POINTEUR POUR LE CHEMIN DU FICHIER

	T_Etudiant etu;
	int i, j, present = 0;  // VARIABLES POUR LES BOUCLES for

	acces_fichier = fopen("data/IUT.txt", "rt");

	printf("= Aucune Activité =\n\n");
	printf("Liste des étudiants ne pratiquant aucune activité :\n\n");

	if (acces_fichier != NULL) { // SI LE FICHIER EST OUVERT
		while (! feof(acces_fichier)) { // TANT QUON EST PAS A LA FIN DU FICHIER
			fscanf(acces_fichier, "%s %s", etu.nom, etu.dpt); // SCAN DE LA LIGNE FORMAT : NOM DPT
      present = 0;
      for( i=0; i<SPORT.nombreTotalEtudiants; i++)
      {
        if(strcmp(etu.nom, SPORT.ensemble[i].nom) == 0)
          present = 1;
      }
      for( j=0; j<MUSIQUE.nombreTotalEtudiants; j++)
      {
        if(strcmp(etu.nom, MUSIQUE.ensemble[j].nom) == 0)
          present = 1;
      }
      if(present == 0)
      {
        printf("%s (Département : %s)\n",etu.nom ,etu.dpt);
      }
			i++;
		}
	}
	else{
		printf("Impossible d'ouvrir le fichier \n");
	}
	fclose(acces_fichier);
	printf("\n\n\n");
  return 0;
}
