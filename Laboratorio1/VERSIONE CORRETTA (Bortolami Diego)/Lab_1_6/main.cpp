//Lab_1: Esercizio 6 - Revisione finale
#include <iostream>

int counter = 0; // E' stato necessario utilizzare una variabile globale accessibile dallo scope globale!

void call_counter(void)
	
{	
	counter = counter + 1;
}	

int main() 

{	
	
	call_counter(); //
	call_counter(); //	
	call_counter(); //
	call_counter(); //
	call_counter(); // Funzione call_counter chiamata per 8 volte
	call_counter(); //
	call_counter(); //
	call_counter(); //
	
	std::cout << "La funzione è stata chiamata " << counter << " volte!\n";
	
return 0;

}
	
// Risposte alle domande dell'esercizio 6:
// E' necessario utilizzare una variabile globale, con durata di memorizzazione pari alla durata del programma e il suo scope coincide con l'intero programma.