#include "customSearch.h"
#include <stdio.h>
#include <string.h>
#include "openFile.h"

void research(char activité[50],char dpt[50]) {
  FILE * acces_fichier; // POINTEUR POUR LE CHEMIN DU FICHIER

	T_Etudiant etu; // JSPLUS
	int i;  // I

	acces_fichier = fopen(activité, "rt");

	if (acces_fichier != NULL) 
  { // SI LE FICHIER S'EST OUVERT
		i = 0;
		while (! feof(acces_fichier)) { // TANT QUON EST PAS A LA FIN DU FICHIER
			fscanf(acces_fichier, "%s %s", etu.nom, etu.dpt); // SCAN DE LA LIGNE FORMAT : NOM DPT
      if (strcmp(etu.dpt,dpt) == 0)
      {
			  printf("%s / %s\n", etu.nom, etu.dpt); // ECRIRE CHAQUE LIGNE 1 PAR 1
      }
			i++;
		}
	}
	fclose(acces_fichier);
}


int customSearch() {
  T_Ensemble sport;
  T_Ensemble musique;
  int reponse;
  int dep;
  int act;
  int i;

	printf("= Recherche avancée =\n\n");
  
	printf("Voulez vous faire une recherche par :\n-département(1) \n-activité(2) \n-les deux(3)\n");
  scanf("%d", &reponse);
  if(reponse == 1)
  {
    printf("Quelle département voulez-vous ?\n (1)GMP (2)STID (3)GEA (4)INFO (5)TC\n");
    scanf("%d", &dep);
    if (dep == 1)
    {
      research("data/IUT.txt", "GMP");
    }
    else if (dep == 2)
    {
      research("data/IUT.txt", "STID");
    }
    else if (dep == 3)
    {
      research("data/IUT.txt", "GEA");
    }
    else if (dep == 4)
    {
      research("data/IUT.txt", "INFO");
    }
    else if (dep == 5)
    {
      research("data/IUT.txt", "TC");
    }
  }
  else if(reponse == 2)
  {
    printf("Quelle activité voulez-vous ?\n (1)Sport (2)Musique\n");
    scanf("%d", &act);
    if (act == 1)
    {
      sport = openFile("data/SPORT.txt", "rt");
      for(i =0; i<sport.nombreTotalEtudiants; i++)
      {
        printf("%d %s %s\n",i+1 , sport.ensemble[i].nom, sport.ensemble[i].dpt );
      }
      
    } 
    else if (act == 2)
    {
      musique = openFile("data/MUSIQUE.txt", "rt");
      for(i =0; i<musique.nombreTotalEtudiants; i++)
      {
        printf("%d %s %s\n",i+1 , musique.ensemble[i].nom, musique.ensemble[i].dpt );
      }
    }
		else{
			printf("Saisie invalide.");
		}
	}
  else if(reponse == 3)
  {
    printf("Quelle activité voulez-vous ?\n (1)Sport (2)Musique\n");
    scanf("%d", &act);
    if (act == 1)
    {
      printf("Quelle département voulez-vous ?\n (1)GMP (2)STID (3)GEA (4)INFO (5)TC\n");
			scanf("%d", &dep);
			if (dep == 1)
			{
				research("data/SPORT.txt", "GMP");
			}
			else if (dep == 2)
			{
				research("data/SPORT.txt", "STID");
			}
			else if (dep == 3)
			{
				research("data/SPORT.txt", "GEA");
			}
			else if (dep == 4)
			{
				research("data/SPORT.txt", "INFO");
			}
			else if (dep == 5)
			{
				research("data/SPORT.txt", "TC");
			}  
    }
    else if (act == 2)
    {
      printf("Quelle département voulez-vous ?\n (1)GMP (2)STID (3)GEA (4)INFO (5)TC\n");
			scanf("%d", &dep);
			if (dep == 1)
			{
				research("data/MUSIQUE.txt", "GMP");
			}
			else if (dep == 2)
			{
				research("data/MUSIQUE.txt", "STID");
			}
			else if (dep == 3)
			{
				research("data/MUSIQUE.txt", "GEA");
			}
			else if (dep == 4)
			{
				research("data/MUSIQUE.txt", "INFO");
			}
			else if (dep == 5)
			{
				research("data/MUSIQUE.txt", "TC");
			}
    } 
  }
  else
  {
		printf("Saisie invalide, veuillez réessayer.");
  }

return 0;
}


