#include<iostream>
using namespace std;
struct Element{
	char Thari[2];
	char Tbulan[10];
	int uang;
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
void createElement(pointer& pBaru){
	pBaru=new Element;
	cout << "Tanggal		: "; cin>>pBaru->Thari;
	cout << "Bulan		: "; cin>> pBaru->Tbulan;
	cout << "Uang		: "; cin>> pBaru->uang;
	pBaru->next=NULL;
}
void insert(Queue& Q, pointer pBaru){
	if (Q.Head==NULL){
		Q.Head=pBaru;
		Q.Tail=pBaru;
	}
	else {
		Q.Tail->next=pBaru;
		Q.Tail=Q.Tail->next;
	}
}
void traversal(Queue Q){
	cout << "|Tanggal\t|Jml Uang\t|"<< endl;
	cout << "----------------------------------\n";
	int total=0;
	while (total<100000&&Q.Head!=NULL){
		cout << "|"<<Q.Head->Thari<<"\t|"<<Q.Head->uang<<"\t\t|\n";
		total+=Q.Head->uang;
		Q.Head=Q.Head->next;
	}
	if (Q.Head!=NULL&&total>100000){
		cout<< "Antrian tabungan setelah Uang Lebih dari kebutuhan\n";
		cout << "|Tanggal\t|Jml Uang\t|"<< endl;
	cout << "-----------------------------------\n";
	while(Q.Head!=NULL){
		cout << "|"<<Q.Head->Thari<<"\t\t|"<<Q.Head->uang<<"\t\t|\n";
		Q.Head=Q.Head->next;
	}
	}
}
int main(){
	pointer pBaru;
	int pil;
	char p;
	createList(Q);
	pilihan :
		system("cls");
	cout << "\t\tPilihan\n";
	cout << "1. Tabung\n";
	cout << "2. Traversal\n";
	cin>>pil;
	switch(pil){
		case 1 :
			createElement(pBaru);
			insert(Q, pBaru);
			break;
		case 2 :
			traversal(Q);
			cout << "Press y to continue\n";
			cin >> p;
			break;
	}goto pilihan;
}
