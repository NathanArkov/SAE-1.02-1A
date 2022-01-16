#include "manageInfos.h"
#include <stdio.h>
#include <stdlib.h>
#include "openFile.h"
#include <string.h>


void delEtu(char nom[], char dpt[], char fichier[]) {
	
	T_Etudiant etuDel;
	int i=0;
	char nom_del[100], dpt_del[100];
	int taille = 0;

	FILE* acces_fichier = NULL;
	FILE* acces_temp = NULL;

	acces_fichier = fopen(fichier, "rt");
	acces_temp = fopen("data/temp.txt", "w+");

	
	if (acces_fichier != NULL && acces_temp != NULL)
	{
		printf("Suppression de %s en %s\n", nom, dpt);
		
		
		do{
			taille = fscanf(acces_fichier, "%s %s", etuDel.nom, etuDel.dpt);
			if(taille != -1) {
				if((strcmp(etuDel.nom , nom))==0){
					printf("Suppression de %s en %s...", nom, dpt);
				}
				else {
					fputs(etuDel.nom, acces_temp);
					fputc(' ', acces_temp);
					fputs(etuDel.dpt, acces_temp);
					fputc('\n', acces_temp);
				}
			}
	
		} while(! feof(acces_fichier));

	}
	else
	{
		printf("Impossible d'ouvrir le fichier\n");
	}
	fclose(acces_fichier);
	fclose(acces_temp);
	remove(fichier);
	rename("data/temp.txt", fichier);
}

void addEtu(char nom[], char dpt[], char fichier[]) {

	FILE* acces_fichier = NULL;

	acces_fichier = fopen(fichier, "a+");

	
	if (acces_fichier != NULL)
	{
		printf("Ajout de %s en %s\n", nom, dpt);
		fputc('\n', acces_fichier);
		fputs(nom, acces_fichier);
		fputc(' ', acces_fichier);
		fputs(dpt, acces_fichier);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier\n");
	}
	fclose(acces_fichier);
}

int manageInfos() {
	int choix;
	char nom[100];
	char dpt[100];
	char groupe[100];
  char *positionEntree = NULL;
  char* chaine;
  int longueur;

	do {
		printf("= Gérer les informations relatives aux étudiants =\n\n");
		printf("1 | Ajouter un étudiant\n");
		printf("2 | Retirer un étudiant\n");
		printf("3 | Ajouter un étudiant à un groupe\n");
		printf("4 | Retirer un étudiant d'un groupe\n");
		printf("Que voulez vous faire ? (1 / 2 / 3 / 4)\n");
		scanf("%d", &choix);

		switch (choix) {
			case 1 :
				printf("\n\nSaisir le nom de l'étudiant : ");
				scanf("%s", nom);
				printf("\nSaisir son département : ");
				scanf("%s", dpt);
				addEtu(nom, dpt, "data/IUT.txt");
        printf("\nEtudiant ajouté à la liste !");
				break;
			case 2 :
				printf("\n\nSaisir le nom de l'étudiant : ");
				scanf("%s", nom);
				printf("\nSaisir son département : ");
				scanf("%s", dpt);
				delEtu(nom, dpt, "data/IUT.txt");
        printf("\nUn étudiant a été supprimé de la liste !");
				break;
			case 3 :
				printf("\n\nSaisir le nom de l'étudiant : ");
				scanf("%s", nom);
				printf("\nSaisir son département : ");
				scanf("%s", dpt);
				printf("Saisir son groupe (exemple: data/IUT.txt) :\n");
				scanf("%s", groupe);
				addEtu(nom, dpt, groupe);
        printf("\nEtudiant ajouté à la liste !");
				break;
			case 4 :
				break;
			default :
				printf("Saisie invalide, veuillez réessayer.\n\n");
				break;
		}
	}
	while(choix <1 || choix > 4);


	return 0;
}