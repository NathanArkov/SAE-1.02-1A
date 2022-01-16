#include "stats.h"
#include <stdio.h>
#include "openFile.h"
#include <stdlib.h>
#include <string.h>


int compteur_ligne(char fichier_ouvert[]) {

	FILE * fichier = fopen(fichier_ouvert, "r") ;
	int c;
	int nLignes = 0;
	int c2 = '\0';
	while((c=fgetc(fichier)) != EOF)
	{
		if(c=='\n')
			nLignes++;
		c2 = c;
	}
	/* c2 est égal au caractère juste avant le EOF. */
	if(c2 != '\n')
		nLignes++; /* Dernière ligne non finie */
	
	fclose(fichier);
	return nLignes;
}

int compteur_dpt(char fichier[50],char dpt[50])
{
  FILE * acces_fichier; // POINTEUR POUR LE CHEMIN DU FICHIER

	T_Etudiant etu; // JSPLUS
	int i;
	int nbLigneDpt = 0;

	acces_fichier = fopen(fichier, "rt");

	if (acces_fichier != NULL) { // SI LE FICHIER S'EST OUVERT
		i = 0;
		while (! feof(acces_fichier)) { // TANT QUON EST PAS A LA FIN DU FICHIER
			fscanf(acces_fichier, "%s %s", etu.nom, etu.dpt); // SCAN DE LA LIGNE FORMAT : NOM DPT
      if (strcmp(etu.dpt,dpt) == 0)
      {
			  nbLigneDpt++;
      }
			i++;
		}
	}
	else {
		printf("Impossible d'ouvrir le fichier \n");
	}

	fclose(acces_fichier);
	return nbLigneDpt;
}

int stats() {
	
	int nbEtuIUT = compteur_ligne("data/IUT.txt");
	int nbEtuSport = compteur_ligne("data/SPORT.txt");
	int nbEtuMusique = compteur_ligne("data/MUSIQUE.txt");
	int nbEtuGMP = compteur_dpt("data/IUT.txt", "GMP");
	int nbEtuSTID = compteur_dpt("data/IUT.txt", "STID");
	int nbEtuINFO = compteur_dpt("data/IUT.txt", "INFO");
	int nbEtuGEA = compteur_dpt("data/IUT.txt", "GEA");
	int nbEtuTC = compteur_dpt("data/IUT.txt", "TC");
	int nbEtuGMPS = compteur_dpt("data/SPORT.txt", "GMP");
	int nbEtuSTIDS = compteur_dpt("data/SPORT.txt", "STID");
	int nbEtuINFOS = compteur_dpt("data/SPORT.txt", "INFO");
	int nbEtuGEAS = compteur_dpt("data/SPORT.txt", "GEA");
	int nbEtuTCS = compteur_dpt("data/SPORT.txt", "TC");
	int nbEtuGMPM = compteur_dpt("data/MUSIQUE.txt", "GMP");
	int nbEtuSTIDM = compteur_dpt("data/MUSIQUE.txt", "STID");
	int nbEtuINFOM = compteur_dpt("data/MUSIQUE.txt", "INFO");
	int nbEtuGEAM = compteur_dpt("data/MUSIQUE.txt", "GEA");
	int nbEtuTCM = compteur_dpt("data/MUSIQUE.txt", "TC");

	float pctGMP = (nbEtuGMP * 100 / nbEtuIUT);
	float pctSTID = (nbEtuSTID * 100 / nbEtuIUT);
	float pctINFO = (nbEtuINFO * 100 / nbEtuIUT);
	float pctGEA = (nbEtuGEA * 100 / nbEtuIUT);
	float pctTC = (nbEtuTC * 100 / nbEtuIUT);
	float pctGMPS = (nbEtuGMPS * 100 / nbEtuSport);
	float pctSTIDS = (nbEtuSTIDS * 100 / nbEtuSport);
	float pctINFOS = (nbEtuINFOS * 100 / nbEtuSport);
	float pctGEAS = (nbEtuGEAS * 100 / nbEtuSport);
	float pctTCS = (nbEtuTCS * 100 / nbEtuSport);
	float pctGMPM = (nbEtuGMPM * 100 / nbEtuMusique);
	float pctSTIDM = (nbEtuSTIDM * 100 / nbEtuMusique);
	float pctINFOM = (nbEtuINFOM * 100 / nbEtuMusique);
	float pctGEAM = (nbEtuGEAM * 100 / nbEtuMusique);
	float pctTCM = (nbEtuTCM * 100 / nbEtuMusique);

	
	printf("= Statistiques =\n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - -\n");
	printf("Nombre d'étudiants en GMP    :   %i (%.1f%c)\n", nbEtuGMP, pctGMP, '%');
	printf("Nombre d'étudiants en STID   :   %i (%.1f%c)\n", nbEtuSTID, pctSTID, '%');
	printf("Nombre d'étudiants en INFO   :   %i (%.1f%c)\n", nbEtuINFO, pctINFO, '%');
	printf("Nombre d'étudiants en GEA    :   %i (%.1f%c)\n", nbEtuGEA, pctGEA, '%');
	printf("Nombre d'étudiants en TC     :   %i (%.1f%c)\n", nbEtuTC, pctTC, '%');
	printf("TOTAL                        :   %i\n", nbEtuIUT);
	printf("- - - - - - - - - - - - - - - - - - - - - - \n");
	printf("Nombre d'étudiants sportifs  \n");
	printf("En GMP                       :   %i (%.1f%c)\n", nbEtuGMPS, pctGMPS, '%');
	printf("En STID                      :   %i (%.1f%c)\n", nbEtuSTIDS, pctSTIDS, '%');
	printf("En INFO                      :   %i (%.1f%c)\n", nbEtuINFOS, pctINFOS, '%');
	printf("En GEA                       :   %i (%.1f%c)\n", nbEtuGEAS, pctGEAS, '%');
	printf("En TC                        :   %i (%.1f%c)\n", nbEtuTCS, pctTCS, '%');
	printf("TOTAL                        :   %i\n", nbEtuSport);
	printf("- - - - - - - - - - - - - - - - - - - - - -\n");
	printf("Nombre d'étudiants musiciens \n");
	printf("En GMP                       :   %i (%.1f%c)\n", nbEtuGMPM, pctGMPM, '%');
	printf("En STID                      :   %i (%.1f%c)\n", nbEtuSTIDM, pctSTIDM, '%');
	printf("En INFO                      :   %i (%.1f%c)\n", nbEtuINFOM, pctINFOM, '%');
	printf("En GEA                       :   %i (%.1f%c)\n", nbEtuGEAM, pctGEAM, '%');
	printf("En TC                        :   %i (%.1f%c)\n", nbEtuTCM, pctTCM, '%');
	printf("TOTAL                        :   %i\n", nbEtuMusique);
	printf("- - - - - - - - - - - - - - - - - - - - - -\n\n\n");

	return 0;
}