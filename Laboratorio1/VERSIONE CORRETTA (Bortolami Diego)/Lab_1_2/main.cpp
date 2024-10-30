// Lab_1: Esercizio 2 - Revisione finale
#include <iostream>

	int d = 1; // Variabile globale inizializzata a 1
	int e; // Variabile globale non inizializzata
	
int main()
	
{
	int a; // Variabile locale automatica
	static int b; // Variabile locale statica inizializzata a valore 1
	static int c; // Variabile locale statica non inizializzata
	std::cout << "Hello, World\n";
	
	return 0;
}

// 	Risposte alle domande dell'esercizio 2:
//	a. La variabile locale automatica non compare in nessuna sezione perché, all'atto della sua dichiarazione, viene allocata e immediatamente deallocata. 
//	b. La variabile automatica è definita in questo modo in quanto smette di esistere automaticamente alla fine dello scope in cui è inserita. 
//	c. Togliendo l'inizializzazione alle variabili statiche, lo spazio in AKA viene comunque riservato perchè deve esistere per definizione per tutta la vita del programma
//	d. Lo scoper di a), b), c) è il main. Lo scoper di d) ed e) è l'intero programma, e quindi possono essere viste anche da altri scopes.