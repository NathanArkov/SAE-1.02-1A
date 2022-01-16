#include "openFile.h"
#include <stdio.h>
#include <string.h>
#define TAILLE_CH_MAX 500

T_Ensemble openFile(char chaine[TAILLE_CH_MAX], char ouverture[TAILLE_CH_MAX]) {

	FILE * acces_fichier; // POINTEUR POUR LE CHEMIN DU FICHIER

	T_Etudiant etu; // JSPLUS
	T_Ensemble Etudiants; // ENSEMBLE D'ETUDIANTS
	int i = 0;  // I

	acces_fichier = fopen(chaine, ouverture);

	if (acces_fichier != NULL) { // SI LE FICHIER S'EST OUVERT
		
		while (! feof(acces_fichier)) { // TANT QUON EST PAS A LA FIN DU FICHIER
			fscanf(acces_fichier, "%s %s", Etudiants.ensemble[i].nom, Etudiants.ensemble[i].dpt); // SCAN DE LA LIGNE FORMAT : NOM DPT
			i++;
		}
		fclose(acces_fichier);
	}
	else {
		printf("Impossible d'ouvrir le fichier \n");
	}
  
  Etudiants.nombreTotalEtudiants = i;

	return Etudiants; //ON RETOURNE L'ENSEMBLE D'ETUDIANTS
}