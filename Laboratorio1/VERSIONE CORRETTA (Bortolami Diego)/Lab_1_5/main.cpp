// Lab_1: Esercizio 5 - Revisione finale; 2147483647 è il massimo numero rappresentabile per un "int" di 32 bit (con segno).
// L'ho rilevato dalla successione di Fibonacci dell'esercizio 1_4, in quant le uscite iniziavano ad essere con segno negativo

#include <iostream>
#include <vector>

std::vector<int> fibonacci(int z, int q, std::vector<int> k, int c) // Funzione Fibonacci.

{
			
			z = k[0];
			
			q = k[1];
			
			for (int r = 2; r <= c and k.back() > 0; r++) // Range for loop
			
			{	
				k.push_back(k[r-1]+k[r-2]);
			}
			
			
			if (k.back() < 0)
				
			{	
				k.pop_back();
			
				std::cout << "\n****E' STATO RAGGIUNTO IL LIMITE MASSIMO DI RAPPRESENTABILITA' DELLA SERIE CON INT DI 32 BIT!**** \n";
			
				return k;
			}
			
			
			else
			{	
				
			return k;
			
			}
		
}

int main() // Corpo del programa che richiama le funzioni

{
	
	int n = 2;
	
	std::vector<int> v(n);
	
	int x = 1;
	
	int y = 1;
	
	int h = 2147483647;
	
	v[0]=x;
	
	v[1]=y;
	
	std::vector<int> vv;
			
	vv.clear();
			
	vv = fibonacci (x, y, v, h);
	
	std::cout << "Nella serie di Fibonacci, la migliore approssimazione di " << h << " è: " << vv.back() << "\n";
	
							
return 0;
	
}