// Lab 3 - Esercizio 1 - Revisione 2 - Definitivo

#include <iostream>

void f(int n, int k, int r) 
{
	int a[n] = {}; 
	
	int* p = &a[k];
	
// Scrittura con indice negativo (verso sx)	
	int t = 0;
	
	while (-(k) <= t) 
	{	p[t] = r;
		t = t - 1;
	}


// Scrittura con indice positivo (verso dx) 
	int w = 1;
	
	while (w < (n-k)) // Scrittura con indice positivo (verso dx) 
	{	p[w] = r;
		w = w + 1;
	}
	
// Stampa array
    std::cout << "Array Elements: "; 
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " "; 
    std::cout << std::endl;
	std::cout << std::endl;	
	
}


void f_illegal(int n, int k, int r) // n = numero di elementi, k indice interno
{
	int a[n] = {}; // Vettore con n elementi inizializzato tutto a 0
	
	int* p = &a[k];
	
// Scrittura con indice negativo (verso sx)
	int t = 0;
	
	while (-(k+5) <= t) // 5 è la posizione di memoria (a sx) a partire dalla quale si verificano l'errore di esecuzione
	{	p[t] = r;
		t = t - 1;
	}


	
// Scrittura con indice positivo (verso dx) 
	int w = 1;
	
	while (w < (n-k+5)) // 5 è la posizione di memoria (a dx) a partire dalla quale si verificano l'errore di esecuzione
	{	p[w] = r;
		w = w + 1;
	}
	
// Stampa array
    std::cout << "Array Elements illegal: ";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
	
}


int main()
{

		int a = 10; // numero elementi
		int b = 5;  // indice interno all'arrai
		int c = 8;  // Intero da scrivere all'interno dell'array
		f(a, b, c);
		int d = 5; // Indice interno illegale da cui iniziano gli errori di esecuzione
		int e = 3;
		f_illegal (a, d, e);
		
		
	
return 0;
}

