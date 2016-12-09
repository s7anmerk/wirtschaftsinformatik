#include  <stdio.h>
#include  <stdlib.h>

struct node {
   int          zahl;  
   struct node  *links;
   struct node  *rechts;
};
struct node  *wurzel = NULL;

struct node *neuerKnoten(int zahl) {
   struct node *knot = (struct node *)malloc(sizeof(struct node));
   knot->zahl  = zahl;
   knot->links = knot->rechts = NULL;
   return knot;
}

void insert(int zahl, struct node *k) {
   if (zahl < k->zahl) {
      if (k->links == NULL)
         k->links = neuerKnoten(zahl);
      else
         insert(zahl, k->links);
   } else {
      if (k->rechts == NULL)
         k->rechts = neuerKnoten(zahl);
      else
         insert(zahl, k->rechts);
   }
}

void einordnen(int zahl) {
   if (wurzel == NULL)
      wurzel = neuerKnoten(zahl);
   else
      insert(zahl, wurzel);
}

void  drucke_baum_inorder(struct node *k) { // inorder
   if (k != NULL) {
      drucke_baum_inorder(k->links);
      printf("%d, ", k->zahl);
      drucke_baum_inorder(k->rechts);
   }
}

void  drucke_baum_preorder(struct node *k) { // preorder
   if (k != NULL) {
      printf("%d, ", k->zahl);
	  drucke_baum_preorder(k->links);
      drucke_baum_preorder(k->rechts);
   }
}

void  drucke_baum_postorder(struct node *k) { // postorder
   if (k != NULL) {
	  drucke_baum_postorder(k->links);
      drucke_baum_postorder(k->rechts);
	  printf("%d, ", k->zahl);
   }
}

int hoehe(struct node *k){
	if(k==NULL)
		return 0;
	else {
		int hl = hoehe(k->links),
			hr = hoehe(k->rechts);
		return (hl > hr) ? hl+1 : hr+1;
	}
}

int anzahl(struct node *k){
	return (k==NULL) ? 0 : anzahl(k->links) + anzahl(k->rechts) + 1;
}

int blattzahl(struct node *k){
	if(k==NULL)
		return 0;
	if(k->links == NULL && k->rechts == NULL)
		return 1;
	return blattzahl(k->links) + blattzahl(k->rechts);
}

int  main() {
   int  zahl=0;
   while (1) {
      printf("Zahl (Windows-EOF=F6 oder Strg+Z, LINUX-EOF: Strg+D): ");
      scanf("%d", &zahl); while(getchar() != '\n');
      if (feof(stdin)) break;
      einordnen(zahl); zahl=0;
   }
   printf("\nHoehe     = %d\n", hoehe(wurzel));
   printf("\nAnzahl    = %d\n", anzahl(wurzel));
   printf("\nBlattzahl = %d\n", blattzahl(wurzel));
   printf("\n\ninorder:\n");
   drucke_baum_inorder(wurzel);
   printf("\n\npreorder:\n");
   drucke_baum_preorder(wurzel);
   printf("\n\npostorder:\n");
   drucke_baum_postorder(wurzel);
   printf("\n"); getchar(); return 0;
}
/*
Zahl (EOF=F6): 50
Zahl (EOF=F6): 30
Zahl (EOF=F6): 40
Zahl (EOF=F6): 10
Zahl (EOF=F6): 70
Zahl (EOF=F6): 90
Zahl (EOF=F6): 20
Zahl (EOF=F6): ^Z0
10, 20, 30, 40, 50, 70, 90,  inorder
50, 30, 10, 20, 40, 70, 90,  preorder
20, 10, 40, 30, 90, 70, 50,  postorder
*/

/*
Zahl (EOF=F6): 24
Zahl (EOF=F6): 22
Zahl (EOF=F6): 20
Zahl (EOF=F6): 18
Zahl (EOF=F6): 21
Zahl (EOF=F6): 19
Zahl (EOF=F6): 17
Zahl (EOF=F6): 25
Zahl (EOF=F6): 44
Zahl (EOF=F6): 40
Zahl (EOF=F6): 36
Zahl (EOF=F6): 32
Zahl (EOF=F6): 28
Zahl (EOF=F6): 30
Zahl (EOF=F6): 34
Zahl (EOF=F6): 38
Zahl (EOF=F6): 42
Zahl (EOF=F6): 46
Zahl (EOF=F6): 48
Zahl (EOF=F6): 33
Zahl (EOF=F6): 35
Zahl (EOF=F6): 37
Zahl (EOF=F6): 39
Zahl (EOF=F6): 41
Zahl (EOF=F6): 0
Zahl (EOF=F6): ^Z

Hoehe     = 8

Anzahl    = 25

Blattzahl = 10

inorder:
0, 17, 18, 19, 20, 21, 22, 24, 25, 28, 30, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 44, 46, 48,

preorder:
24, 22, 20, 18, 17, 0, 19, 21, 25, 44, 40, 36, 32, 28, 30, 34, 33, 35, 38, 37, 39, 42, 41, 46, 48,

postorder:
0, 17, 19, 18, 21, 20, 22, 30, 28, 33, 35, 34, 32, 37, 39, 38, 36, 41, 42, 40, 48, 46, 44, 25, 24,

*/