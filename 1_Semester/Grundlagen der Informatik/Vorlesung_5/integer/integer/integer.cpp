#include <iostream>
using namespace std;

class integer { // int - Variable in class verpacken
	private: 
		int i;
	public: 
		integer(int i=0):i(i){
			cout<<"integer-Objekt i = "<<this->i<<endl;
		}

		int get(){ return i; }

		void set(int i=0){ this->i = i; }

		static integer add(integer i1, integer i2){
				return i1.i + i2.i;
		//		return i1.get()+i2.get();
		}
};

int main(){
	integer i0(5), i1=4;
	cout<<"i0.i = "<<i0.get()<<endl;
	cout<<"i0.i + i0.i = "<<integer::add(i0, i0).get()<<endl;
	integer i3 = integer::add(i0, i0);
	cout<<"i3.i = "<<i3.get()<<endl;
	i0.set(22);
	cout<<"i0.i = "<<i0.get()<<endl;
	cin.get();
}

/*
integer-Objekt i = 5
i0.i = 5
integer-Objekt i = 10
i0.i + i0.i = 10
integer-Objekt i = 10
i3.i = 10
i0.i = 22
*/
