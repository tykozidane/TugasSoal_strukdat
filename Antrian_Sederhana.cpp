#include<iostream>
using namespace std;
int urut=0;
struct Element{
	int No;
	char nama[30];
	Element* next;
};
typedef Element* pointer;
typedef pointer List;
struct Queue{
	List Head;
	List Tail;
};
Queue Q;
void createList(Queue& Q){
	Q.Head=NULL;
	Q.Tail=NULL;
}
void createElement (pointer& pBaru){
	pBaru=new Element;
	urut+=1;
	cout << "Nama	: "; cin >> pBaru->nama;
	pBaru->No=urut;
	pBaru->next=NULL;
}
void insert(pointer& pBaru, Queue& Q){
	if (Q.Head==NULL){
		Q.Head=pBaru;
		Q.Tail=pBaru;
	}
	else {
		Q.Tail->next=pBaru;
		Q.Tail=pBaru;
	}
}
void nextantrian(Queue& Q){
	if(Q.Head==NULL){
		cout << "Antrian Habis\n";
	}
	else if(Q.Head==Q.Tail){
		cout << "No		: " << Q.Head->No<<endl;
		cout << "Nama	: " << Q.Head->nama<<endl;
		createList(Q);
	}
	else {
		cout << "No		: " << Q.Head->No<<endl;;
		cout << "Nama	: " << Q.Head->nama<<endl;
		Q.Head=Q.Head->next;
	}
}
int main(){
	pointer pBaru;
	int pil;
	char n;
	createList(Q);
	pilihan	:
	system("cls");
	cout << "\t\tPilihan Menu\n";
	cout << "1. Antrian Selanjutnya\n";
	cout << "2. Tambah Antrian\n";
	cin >> pil;
	switch(pil){
		case 1 :
			nextantrian(Q);
			cout << "next(y)	: ";
			cin >> n;
			break;
		case 2 :
			createElement(pBaru);
			insert(pBaru, Q);
			break;
	}goto pilihan;
}
