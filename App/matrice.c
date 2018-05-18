#include "matrice.h"

void echanger(Element *T, int a, int b) {
	Element temp = T[a];
	T[a] = T[b];
	T[b] = temp;
}

void quickSort(Element *T, int debut, int fin) {
    int gauche = debut - 1;
    int droite = fin + 1;
    const int pivot = T[debut].j;
    
    if(debut >= fin)
        return;

    while(1)
    {
        do droite--; while(T[droite].j > pivot);
        do gauche++; while(T[gauche].j < pivot);

        if(gauche < droite)
            echanger(T, gauche, droite);
        else break;
    }
    quickSort(T, debut, droite);
    quickSort(T, droite+1, fin);
}

void init_element(Element *e, int i, int j, double p) {
	e->i = i;
	e->j = j;
	e->p = p;
}

void init_matrice(Matrice *M, int m, int n) {
	M->m = m;
	M->T = malloc(m * sizeof(Element));
	M->n = n;
	M->debCol = malloc((n + 1) * sizeof(int));
	int i ;
	for(i = 0; i < n + 1; i++) {
		M->debCol[i] = 0;
	}
}

void free_matrice(Matrice *M) {
	free(M->T);
	free(M->debCol);
}

void affiche(Matrice *M) {
	printf("Tableau T\n");
	printf("Nb éléments : %d\n", M->m);
	int i  = 0;
	for( i = 0; i < M->m; i++)
		printf("%*d %*d %lf\n", 2, M->T[i].i + 1, 2, M->T[i].j + 1, M->T[i].p); 

	printf("\n");
	printf("Tableau debCol\n");
	printf("Nb éléments : %d\n", M->n);
	for( i = 0; i < M->n; i++)
		printf("%*d %*d\n", 2, i + 1, 2, M->debCol[i]);
}

void majDebutColonnes(Matrice *M) {
	int tmp, somme;
	somme = 0;
	int i;
	for( i = 0; i < M->n + 1; i++) {
		tmp = M->debCol[i];
		M->debCol[i] = somme;
		somme += tmp;
	}
}

void import_matrice(FILE *web, Matrice *M) {
	int n, m, d, count, ligne, colonne;
	double proba;
	
	Element tmp;
	
	fscanf(web, "%d\n%d\n", &n, &m);
	init_matrice(M, m, n);
		
	count = 0;
	int i ;
	int j ;
	for(i = 0; i < n; i++) {
		
		fscanf(web, "%d %d ", &ligne, &d);
		
		for(j = 0; j < d; j++) {
			
			fscanf(web, "%d %lf ", &colonne, &proba);
			init_element(&tmp, ligne - 1, colonne - 1, proba);
			
			M->T[count++] = tmp;
			++M->debCol[colonne - 1];
		}
	}
	majDebutColonnes(M);
	quickSort(M->T, 0, m - 1);
}

void init_distrib(int n, double *a, double *b , double *c) {
	
	int i;
	for(i = 0; i < n; i++) {
		a[i] = 1.0 / (double) n;
		b[i] = 0;
		c[i] = 0;
	}
}