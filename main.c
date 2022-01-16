#include <stdio.h>
#include <stdlib.h>
#include "customSearch.h"   /* On appelle les autres fichiers du projet */
#include "manageInfos.h"
#include "noActivity.h"
#include "sportAndMusic.h"
#include "stats.h"
#include "openFile.h"

int main(void) {

	int choix = 0;
  do
  {
    printf("\nBienvenue dans l'outil de gestion de l'IUT de Metz\n\n");
  	printf("Que souhaitez vous faire ?\n");
  	printf("1 | Afficher les étudiants sportifs ET musiciens\n");
  	printf("2 | Afficher les étudiants ne pratiquant aucune activité\n");
  	printf("3 | Recherche par département et par activité\n");
  	printf("4 | Afficher les statistiques concernant les départements et les loisirs\n");
  	printf("5 | Mettre à jour la situation d'un étudiant\n");
  	do {
  		printf("Choix (1/2/3/4/5): ");
  		scanf("%d", &choix);

  		if (choix < 1 || choix > 5)
  			printf("\nSaisie invalide, veuillez réessayer.\n\n");
  	}
  	while (choix < 1 || choix > 5);

  	system("clear");

  	switch (choix) {
  		case 1 : 
  			sportAndMusic();
  			break;
  		case 2 :
  			noActivity();
  			break;
  		case 3 :
  			customSearch();
  			break;
  		case 4 :
  			stats();
  			break;
  		case 5 :
  			manageInfos();
  			break;
  	}
  }while (choix!=6);
  return 0;
}