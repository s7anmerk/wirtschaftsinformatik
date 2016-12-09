#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 19

/* Rekursive Tiefensuche, iterative Tiefensuche mit Stack, iterative Breitensuche mit Queue fuer gerichtete Graphen */

/* Globale Variablen */
double am[N][N];            /* Adjazenzmatrix */
int dfs_num[N];             /* dfs_num[i] Reihenfolge Besuch Knoten i */
int d[N], f[N];             /* d[i] Zeit erstmaliges Erreichen Knoten i, f[i] Zeit Knoten vollstaendig abgearbeitet */


/*============================ Queue ===============================================*/

typedef struct {            /* Definition type queue */

           int *pq; 		/* body of queue - array*/
           int first;      	/* position of first element */
           int last;       	/* position of last element */
           int count;      	/* number of queue elements */
		   int queuesize;  	/* size of queue - array */
} queue;

#define TRUE    1
#define FALSE   0

typedef int boolean;


/* Initialisierung queue q  mit Laenge n, n>0 */
void init_queue(queue *q, int n)           
{
	if(n <= 0)             /* Laenge n unzulaessig ? */
		n = 1;             /* Laenge n auf n=1 korrigieren */
    q->first = 0;          /* Anfangsindex = 0 */
	q->last = n-1;         /* letztes Element */
	q->queuesize = n;      /* maximale Anzahl der Elemente */
    q->count = 0;          /* Anzahl Elemente in queue */
	q->pq = 0;			   /* Array ohne Speicherplatz */
	q->pq = (int *)malloc(n*sizeof(int)); /* Array initialisieren */
}

/* Freigabe queue q */
void free_queue(queue *q){
    q->first = 0;          /* Anfangsindex = 0 */
	q->last = 0;           /* letztes Element */
	q->queuesize = 0;      /* maximale Anzahl der Elemente */
    q->count = 0;          /* Anzahl Elemente in queue */
	free(q->pq);           /* Speicherplatz pq freigeben */
	q->pq = 0;			   /* Array ohne Speicherplatz */
}

/* Eintragen x in queue q an Ende */
void enqueue(queue *q, int x)       
{
        if (q->count >= q->queuesize){        /* queue voll ? */
		        printf("Warning: queue overflow enqueue x=%d\n",x);
		        return;
		}
        q->last = (q->last+1) % q->queuesize; /* Modulo-Division */
        q->pq[ q->last ] = x;                 /* Eintragen x     */
        q->count = q->count + 1;              /* count erhoehen  */   
}

/* Erstes Element x aus queue q entfernen */
int dequeue(queue *q)
{
        int x = 0;
        if (q->count <= 0){ printf("Warning: empty queue dequeue.\n");
		                    return 0;
		}
        
        x = q->pq[ q->first ];
        q->first = (q->first+1) % q->queuesize;
        q->count = q->count - 1;
        return x;
}

/* Queue q leer ? */
int empty(queue *q)
{
        if (q->count <= 0) return (TRUE);
        return (FALSE);
}

/* Queue q ausgeben */
void print_queue(queue *q)
{
        int i=0;
		if(!(q->count)) return; 
        i=q->first;       
        while (i != q->last) {
                printf("%d ",q->pq[i]);
                i = (i+1) % q->queuesize;}  
		printf("%d\n",q->pq[i]);
}


/*============================ Queue Ende ==========================================*/

/* iterative Breitensuche BFS */
void bfs_iter(double am[][N], int v, int bfs_num[], int *number) 
{
	size_t i = 0;
    queue s;                            /* neue Queue s deklarieren */
	init_queue(&s, N);                  /* queue s mit maximaler Laenge N initialisieren */

    enqueue(&s,v);                      /* v als Element nach s */
    while (s.count > 0)                 /* Solange s nicht leer */
    {
        v = dequeue(&s);                /* v als erstes Element von s entnehmen */
        if (bfs_num[v] != 0) continue;
               
        bfs_num[v] = ++(*number);       /* Knoten v besucht, Reihenfolgenummer incr. */
        for (i = 0; i < N; i++)         /* Alle Knoten i durchlaufen, */
            if (am[v][i] >= 0)          /* die Nachfolger i von v (Kante v->i) */
                enqueue(&s, i);         /* i in Queue s einfuegen */
    }
	free_queue(&s);                     /* Freigabe queue s */             
}

/* Start Breitensuche BFS iterativ */
void call_bfs_iter(double am[][N], int bfs_num[]) 
{
	int i = 0;
	int number = 0;                     /* Zaehler n initialisieren */

    for (i = 0; i < N; i++)
        bfs_num[i] = 0;                    /* Vektor besuchter Knoten initialisieren */
                        
    for (i = 0; i < N; i++)                /* Alle Knoten i (Kreuzungen) durchlaufen */
    {
        if (bfs_num[i] == 0)               /* Knoten i noch nicht besucht ? */
            bfs_iter(am, i, bfs_num, &number);      /* iterative Tiefensuche ab Knoten i */
    }

    printf("\n\nBreitensuche iterativ\n");
    printf("Knoten  Reihenfolge\n");
    for (i = 0; i < N; i++)
        printf("%6d       %6d\n", i, bfs_num[i]);
	printf("\n");
}


/*============================ Stack ===============================================*/

/* Beispiel fuer Stack, der int-Werte in einen Vektor s speichern kann   */
struct stack {
       int  *s,     /* Stack als int-Vektor */
			sp,	    /* Stack Pointer (akt. Index), zeigt auf freies Element  */
			unten,  /* Index untere Grenze  */
			oben;   /* Index obere Grenze   */
} sta;              /* Name des Stacks */

/* Initialisierung Stack mit n>0 Elementen */
void stackinit(struct stack *st, int n) { 
	st->s = NULL; st->sp = 0; st->unten = 0; st->oben = 0;
	if(n>0){
	   st->s = (int*)malloc(n*sizeof(int));
	   st->sp    = 0;
	   st->unten = 0;
	   st->oben  = n-1;
	}
}

/* Freigabe Speicherplatz s im Stack st */
void stackfree(struct stack *st){  
	if(st->oben + 1 > 0)
		free(st->s);
	st->s = 0;
	st->sp = 0; 
	st->unten = 0; 
	st->oben = 0;
}

/* Stack st leer ? */
int isEmpty(struct stack *st) { return st->sp <= st->unten; } 

/* Stack st voll ? */
int isFull(struct stack *st)  { return st->sp  > st->oben;  } 

/* wert im Stack st speichern */
void push(struct stack *st, int wert) {      
   if (st->s == NULL) {                      /* Vektor s im Stack st 0 ? */
      printf("Stack fehlt\n");
      return;
   }
   if (isFull(st)) {                         /* Stack st ist voll ? */
      printf("Stack voll\n");
      return;
   }
   st->s[(st->sp)] = wert; (st->sp)++;       /* stack[sp]=wert, sp=sp+1 */
}

/* Entferne oberstes Element aus Stack */
void pop(struct stack *st) {  
   if (st->s == NULL) {
      printf("Stack fehlt\n");
      return;
   }
   if (isEmpty(st)) {
      printf("Stack leer\n");
      return;
   }
   (st->sp)--;              /* Stackpointer um 1 reduzieren */
}

/* Rueckgabe, Lesen oberstes Element, ohne zu loeschen */
int top(struct stack *st) {  
   if (st->s == NULL) {
      printf("Stack fehlt\n");
      return -1;
   }
   if (isEmpty(st)) {
      printf("Stack leer\n");
      return -1;
   }
   return st->s[st->sp-1];
}

/* oberstes Element lesen und entfernen */
int popTop(struct stack *st) { 
   int wert = top(st);
   pop(st);
   return wert;
}
/*================================= Stack Ende ====================================*/


/* Initialisierung Adjazenzmatrix am[][] und Erreichbarkeitsvektor dfs_num[N] */
void init(double am[][N]){   
	 size_t i=0, j=0;
	 for (i = 0; i < N; i++)
            {
				dfs_num[i] = 0;
                for (j = 0; j < N; j++)
                    am[i][j] = -1;  /* -1 <==> keine Verbindung zwischen Knonten i und j */
            }
}

/* Initialisierung fuer Vektoren d[N] unf f[N] */
void init_df(int df[]){
	 size_t i = 0;
	 for(i = 0; i < N; i++)
        df[i] = 0;
}

/* rekursive Tiefensuche */
void dfs(double am[][N], int v, int dfs_num[], int *number, int *zeit) 
{    
	size_t i=0;
    dfs_num[v] = ++(*number);                   /* Knoten v besucht, Reihenfolgenummer incr. */
	d[v] = (*zeit)++;                           /* Knoten v erstmalig erreicht */
    for(i=0; i<N; i++)                          /* Alle Knoten i durchlaufen, */
        if(am[v][i]>=0 && dfs_num[i]==0)        /* die Nachfolger von v (Kante v->i) und nicht besucht */
            dfs(am, i, dfs_num, number, zeit);  /* Tiefensuche dfs ab neu erreichten Knoten i rekursiv */
	f[v] = *zeit;                               /* Knoten v vollstaendig abgearbeitet */
}

/* Aufruf der rekursiven Tiefensuche */
void call_dfs(double am[][N], int dfs_num[])
{ 
	size_t i = 0;
	int number = 0, zeit = 0;
	for (i = 0; i < N; i++)                         /* Alle Knoten i (Kreuzungen) durchlaufen */
    {
        if (dfs_num[i] == 0)                        /* Knoten i noch nicht besucht ? */
            dfs(am, i, dfs_num, &number, &zeit);    /* Tiefensuche ab Knoten i */
    }

    printf("Tiefensuche rekursiv\n\n");
    printf("Knoten  Reihenfolge\n");
    for (i = 0; i < N; i++)
    {
        printf("%6d       %6d\n", i, dfs_num[i]);
    }
	printf("\n");
}

/* iterative Tiefensuche */
void dfs_iter(double am[][N], int v, int dfs_num[], int *number) 
{
	size_t i = 0;

	stackinit(&sta, N);                         /* stack initialisieren */	
    push(&sta, v);                              /* v als Element nach s */
    while(sta.sp > 0)                           /* Solange s nicht leer */
    {
		v = popTop(&sta);                       /* v als oberstes Element von s entnehmen */
				
        if(dfs_num[v] == 0)                     /* wenn v nicht besucht */
        {	
            dfs_num[v] = ++(*number);              /* Knoten v besucht, Reihenfolgenummer incr. */
            for (i = 0; i < N; i++)             /* Alle Knoten i durchlaufen,  */
                if (am[v][i] >= 0)              /* die Nachfolger i von v (Kante v->i) */
                    push(&sta, i);              /* i als Element nach s */
        } 
    }
	stackfree(&sta);                            /* Stack freigeben */
}

/* Aufruf der iterativen Tiefensuche */
void call_dfs_iter(double am[][N], int dfs_num[])
{ 
	size_t i = 0;
	int number = 0;

	for (i = 0; i < N; i++)
        dfs_num[i] = 0;                           /* Vektor besuchter Knoten mit 0 initialisieren */

	for (i = 0; i < N; i++)                       /* Alle Knoten i (Kreuzungen) durchlaufen */
        if (dfs_num[i] == 0)                      /* Knoten i noch nicht besucht ? */
            dfs_iter(am, i, dfs_num, &number);    /* iterative Tiefensuche ab Knoten i */

    printf("\n\nTiefensuche iterativ\n\n");
    printf("Knoten  Reihenfolge\n");
    for (i = 0; i < N; i++)
        printf("%6d       %6d\n", i, dfs_num[i]);
	printf("\n");
}

/* Anzeige Adjazenzmatrix mit Zeilen- und Spaltennummern */
void show_am(double am[][N]){
	size_t i=0, j=0;
	printf("\nAdjazenzmatrix\n\n");
	printf("    ");
	for(i=0; i<N; i++)
		printf("%4d", i);
	printf("\n");
	for(i=0; i<=N; i++)
		printf("----");
	printf("\n");

	for(i=0; i<N; i++){
		printf("%2d |", i);
		for(j=0; j<N; j++)
			printf("%4.0lf", am[i][j]);
		printf("\n");
	}
	printf("\n");
}

/* Anzeige fuer Vektoren d bzw. f (Erreicht bzw. Verlassen) */
void show_df(char *s, int df[]){
	size_t i = 0;
	if(s)
		printf("\n\n%s\n", s);
	printf("Knoten: ");
	for(i=0; i<N; i++)
		printf("%4d", i);
	printf("\n----");
	for(i=0; i<=N; i++)
		printf("----");
	printf("\nZeit  : ");
	for(i=0; i<N; i++)
		printf("%4d", df[i]);
	printf("\n");
}

/* Hauptprogramm */
void main(){
	init(am);      /* Adjazenzmatrix initialisieren */
	init_df(d);    /* Vektor Zeit erstmaliges Erreichen initialisieren */
	init_df(f);    /* Vektor Zeit vollstaendige Abarbeitung initialisieren */

    /* Adjazenzmatrix mit Kanten versehen */
	am[0][ 1] = 1;
    am[0][ 2] = 1;
    am[1][ 3] = 1;
    am[1][ 4] = 1;
    am[3][ 5] = 1;
    am[5][ 6] = 1;
    am[5][ 7] = 1;
    am[5][ 8] = 1;
    am[8][ 9] = 1;
    am[8][ 10] = 1;
    am[10][ 11] = 1;
    am[10][ 12] = 1;
    am[13][ 14] = 1;
    am[13][ 15] = 1;
    am[14][ 16] = 1;
    am[14][ 17] = 1;
    am[16][ 18] = 1;
    am[18][ 8] = 1;
	am[11][18] = 1; /* Zyklus eingebaut */

	show_am(am);    /* Adjazenzmatrix anzeigen */

	call_dfs(am, dfs_num);        /* Aufruf rekursive Tiefensuche */
	show_df("Zeitpunkt Erreichen\n", d);  /* Anzeige Zeit erstmaliges Erreichen der Knoten */
	show_df("Zeitpunkt Verlassen\n", f);  /* Anzeige Zeit vollstaendige Abarbeitung der Knoten */

	call_dfs_iter(am, dfs_num);  /* Aufruf iterative Tiefensuce */

	call_bfs_iter(am, dfs_num);  /* Aufruf iterative Breitensuche */
	
	getchar();
}

/*

Adjazenzmatrix

       0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
--------------------------------------------------------------------------------
 0 |  -1   1   1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
 1 |  -1  -1  -1   1   1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
 2 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
 3 |  -1  -1  -1  -1  -1   1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
 4 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
 5 |  -1  -1  -1  -1  -1  -1   1   1   1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
 6 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
 7 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
 8 |  -1  -1  -1  -1  -1  -1  -1  -1  -1   1   1  -1  -1  -1  -1  -1  -1  -1  -1
 9 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
10 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1   1   1  -1  -1  -1  -1  -1  -1
11 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1   1
12 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
13 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1   1   1  -1  -1  -1
14 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1   1   1  -1
15 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
16 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1   1
17 |  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
18 |  -1  -1  -1  -1  -1  -1  -1  -1   1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1

Tiefensuche rekursiv

Knoten  Reihenfolge
     0            1
     1            2
     2           14
     3            3
     4           13
     5            4
     6            5
     7            6
     8            7
     9            8
    10            9
    11           10
    12           12
    13           15
    14           16
    15           19
    16           17
    17           18
    18           11



Zeitpunkt Erreichen

Knoten:    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
------------------------------------------------------------------------------------
Zeit  :    0   1  13   2  12   3   4   5   6   7   8   9  11  14  15  18  16  17  10


Zeitpunkt Verlassen

Knoten:    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
------------------------------------------------------------------------------------
Zeit  :   14  13  14  12  13  12   5   6  12   8  12  11  12  19  18  19  17  18  11


Tiefensuche iterativ

Knoten  Reihenfolge
     0            1
     1            3
     2            2
     3            5
     4            4
     5            6
     6           14
     7           13
     8            7
     9           12
    10            8
    11           10
    12            9
    13           15
    14           17
    15           16
    16           19
    17           18
    18           11



Breitensuche iterativ
Knoten  Reihenfolge
     0            1
     1            2
     2            3
     3            4
     4            5
     5            6
     6            7
     7            8
     8            9
     9           10
    10           11
    11           12
    12           13
    13           15
    14           16
    15           17
    16           18
    17           19
    18           14

*/