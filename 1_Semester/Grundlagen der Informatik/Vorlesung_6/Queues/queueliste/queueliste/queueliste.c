#include <stdio.h>
#include <stdlib.h>

struct elem {			/* Listenelement */
	int zahl;           /* Wert */
	struct elem *next;  /* Nachfolger */
};

struct elem *first = 0, *last = 0; /* Anfangszeiger, Endzeiger */

void enqueue(int x){               /* x in Queue zuletzt */
	struct elem *pt = (struct elem *)malloc(sizeof(struct elem));
	pt->zahl = x;
	pt->next = 0;
    if(!first && !last) first = last = pt;
	else { 
		last->next = pt; /* bisher letztes zeigt auf Nachfolger */
		last = pt;       /* letztes Element ist pt */
	}
}

unsigned long anzahl(){      /* Anzahl der Listenelemente */
	struct elem *pt = first; /* Initialisierung pt mit first */
	unsigned long anz = 0UL;
	while(pt){               /* existiert weiteres Element ? */
		anz++;
		pt = pt->next;       /* next Element auswaehlen */
	}
	return anz;              
}

int empty(){				/* Queue leer ? */
	if(!first && !last) return 1; /* !first oder !last reicht */
	return 0;
}

int dequeue(){              /* first aus Queue entfernen */
    int x = 0;
	struct elem *pt = first;
	if(empty()) printf("Warning: empty queue dequeue\n");
	else {
			x = first->zahl;
			first = first->next; /* first := Nachfolger first */
			if(!first) last = 0; /* wenn first==0, dann last:=0 */
			free(pt);      /* Freigabe bisher erstes Element */
	}
	return x;
}

void print_queue(){        /* Ausgabe der Queue */
	struct elem *pt = first;
	while(pt){ 
		printf("%d ", pt->zahl);
		pt=pt->next;
	}
}

int main(){
	int z = 0;
	while(1){
		printf("int-Zahl fuer Queue (F6=EOF): ");
		scanf("%d", &z);
		while(getchar() != '\n');
		if(feof(stdin)) break;
		enqueue(z);
		z=0;
	}
	
	printf("entnommenes Element = %d\n",dequeue());
	printf("entnommenes Element = %d\n",dequeue());

	while(1){
		printf("int-Zahl fuer Queue (F6=EOF): ");
		scanf("%d", &z);
		while(getchar() != '\n');
		if(feof(stdin)) break;
		enqueue(z);
		z=0;
	}
	printf("Inhalt Queue mit Anzahl %d: \n", anzahl());
	print_queue();
	getchar();
}

/*
int-Zahl fuer Queue (F6=EOF): 0
int-Zahl fuer Queue (F6=EOF): 1
int-Zahl fuer Queue (F6=EOF): 2
int-Zahl fuer Queue (F6=EOF): 3
int-Zahl fuer Queue (F6=EOF): 4
int-Zahl fuer Queue (F6=EOF): 5
int-Zahl fuer Queue (F6=EOF): 6
int-Zahl fuer Queue (F6=EOF): ^Z

entnommenes Element = 0
entnommenes Element = 1
int-Zahl fuer Queue (F6=EOF): 7
int-Zahl fuer Queue (F6=EOF): ^Z

Inhalt Queue mit Anzahl 6:
2 3 4 5 6 7
*/