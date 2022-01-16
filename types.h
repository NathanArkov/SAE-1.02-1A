#define TAILLE_CH_MAX 500
#define TAILLE_NB_MAX_ETU 200

struct S_Etudiant {
	char nom[TAILLE_CH_MAX];
	char dpt[TAILLE_CH_MAX];
};

typedef struct S_Etudiant T_Etudiant;

struct S_Ensemble {
	int nombreTotalEtudiants;
	T_Etudiant ensemble[TAILLE_NB_MAX_ETU];
};

typedef struct S_Ensemble T_Ensemble;