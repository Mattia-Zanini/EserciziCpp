#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){

    string pippo = "variabile stringa";
    int eta;

    cout<<"Welcome"<<endl;

    cout<<"Inserisci la tua età: ";
    cin>>eta;
    cout<<"La tua età: "<<eta<<endl;

    cout<<pippo<<endl;
    cout<<"La stringa ha una lunghezza di: "<<pippo.size()<<endl;
    cout<<"Questa è la prima lettera: "<<pippo[0]<<endl;
    pippo[8] = '3';
    cout<<"Stringa modificata: "<<pippo<<endl;

    int x = 5;
    int y = 3;
    cout<<"Condizione: ";
    cout<<(x>y)<<endl;

    string nome;
    cout<<"Inserisci il tuo nome: "<<endl;
    cin>>nome; //lo spazio è un carattere che termina l'input
    cout<<nome;

    return 0;
}