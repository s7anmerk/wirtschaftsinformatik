#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Name {
	class el { // Listenelement
		public:
			   string p;	//Zeichenkette 
			   el *pe;  //Zeiger auf naechstes Element

			   el(string p=""):p(p),pe(0){
				   cout<<"Konstruktor el: "<<this->p<<'\n'; 
			   }

			   ~el(){	cout<<"Destruktor el: "<<this->p<<'\n';
						p=""; pe=0; 
			   }
	};

	el *pel;			//Startzeiger der el-Liste

public:
	Name():pel(0){ cout<<"Konstruktor Name()"<<endl; };

	/*
	~Name(){	//Loeschen der Liste vom Ende aus (unguenstig)
			el *pp=pel, *pold=pel;
			while(pel){ 
				while(pp->pe){ pold = pp; pp=pp->pe; }
				delete pp; 
				if(pp == pel){ pel=0; pp=0; }
				else {
						pold->pe=0;			//kein Nachfolger
						pp=pel; pold=pel;	//wieder von vorn
				}
			}
			cout<<"Destruktor ~Name() beendet\n";
	}
	*/

	~Name(){	//Loeschen der Liste von vorn (guenstig)
			el *pnext = pel;
			while(pel){
						pnext = pel->pe;	//Zeiger auf Nachfolger
						delete pel;			//Loeschen Kopfelement
						pel = pnext;		//pel zeigt auf Nachfolger
			}
			cout<<"Destruktor ~Name() beendet\n";
	}

	void addfirst(string z){	// neuer Namen an den Listenanfang anfuegen (guenstig)
		el *pold = pel;
		pel = new el(z); 
		pel->pe = pold;
	}

	void addlast(string z){ // neuer Namen an das Listenende anfuegen (unguenstig)
		el *pp=pel;
		if(!pel) pel=new el(z);
		else {
				while(pp->pe) pp=pp->pe;
				pp->pe=new el(z);
		}
	}
	
	//Loeschen des Namens mit Index k (0<=k<Anzahl Namen)
	bool loesch(unsigned long k){
			unsigned long i=0;
			el *pnext = pel, *pold = 0;
			while(pnext && (i<k)){ i++; pold = pnext; pnext = pnext->pe; }
			if((i<k)|| !pnext){ cout<<"Element mit Index = "<<k<<" nicht vorhanden\n";
			                 // if(i<k)cout<<"i = "<<i<<" < k = "<<k<<endl;
							 //	if(!pnext)cout<<"pnext == 0, i = "<<i<<"  k = "<<k<<endl;
					 return false;
			}
			if(i==0){ pel=pel->pe; delete pnext; }
			else {
					pold->pe = pnext->pe; 
					delete pnext;
			}
			cout<<"Element mit Index = "<<k<<" geloescht\n";
			return true;
	}
	
	//Anzeigen des Namens mit Index k (0<=k<Anzahl Namen)
	void show(unsigned long k){
			unsigned long i=0;
			el *pnext = pel;
			while(pnext && (i<k)){ i++; pnext = pnext->pe; }
			if((i<k)||!pnext) cout<<"Element mit Index = "<<k<<" nicht vorhanden\n";
			else cout<<"Name mit Index "<<k<<" : "<<pnext->p<<'\n';
	}

	//Anzeigen aller Namen
	void show(){
		el *pnext = pel;
		while(pnext){ 
					cout<<pnext->p<<'\n';
					pnext=pnext->pe;
		}
	}

	//Anzahl Namen in Liste
	unsigned long anz(){
		el *pnext = pel;
		unsigned long i=0UL;
		while(pnext){ 
					i++;
					pnext=pnext->pe;
		}
		return i;
	}
};

void main(){
	Name *p1 = new Name();
//	p1->addfirst("HTW");
//	p1->addfirst("TU");
	p1->show(0UL);
	p1->addlast("HTW");
	p1->addlast("TU");
	p1->show();
	cout<<"Anzahl Namen = "<<p1->anz()<<endl;
	p1->show(0UL);
	p1->show(1UL);
	p1->show(2UL);
	p1->loesch(3UL);
	p1->loesch(0UL);
	p1->loesch(0UL);
	p1->loesch(0UL);
	cout<<"Anzahl Namen = "<<p1->anz()<<endl;
	delete p1;
	p1=0;
	cin.get();
}

/*
Konstruktor Name()
Element mit Index = 0 nicht vorhanden
Konstruktor el: HTW
Konstruktor el: TU
HTW
TU
Anzahl Namen = 2
Name mit Index 0 : HTW
Name mit Index 1 : TU
Element mit Index = 2 nicht vorhanden
Element mit Index = 3 nicht vorhanden
Destruktor el: HTW
Element mit Index = 0 geloescht
Destruktor el: TU
Element mit Index = 0 geloescht
Element mit Index = 0 nicht vorhanden
Anzahl Namen = 0
Destruktor ~Name() beendet
*/