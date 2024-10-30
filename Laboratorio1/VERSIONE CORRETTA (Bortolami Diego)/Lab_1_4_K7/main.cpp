//Lab_1: Esercizio 4 - Revisione finale

#include <iostream>
#include <vector>

int print (std::string message_x, std::vector<int> y) // Creo la funzione che stampa il vettore.
{
	std::cout << message_x << "\n";
	
	for (int i : y) // Range for loop
	{
		std::cout << i << "     ";
		
	}
	
	std::cout << "\n";
	
return 0;

}


std::vector<int> fibonacci(int z, int q, std::vector<int> k, int c) // Funzione Fibonacci.

{
			
			z = k[0];
			
			q = k[1];
			
			
			for (int r = 3; r <= c and k.back() > 0; r++)
			{	
				
				k.push_back(k[r-2]+k[r-3]);
				
			}
			
			
			if (k.back() < 0) // Tutela contro il limite di rappresentabilità
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
	int n;
	
	std::cout << "Scrivi di seguito il numero intero di elementi della serie di Fibonacci\n\n"; // Richiesta all'utente
	
	std::cin >> n;
	
	if (n <= 0) // Caso di inserimento valore errato
		{ 
			std::cout << "Ti prego di inserire un numero intero positivo > 0! Riavvia il programma grazie! \n"; 
		}
		
	
	else if (n == 1) // Caso di vettore con un solo elemento
		{ 
			std::vector<int> v(n);
			
			v[0]=1;
			
			std::string message_1 = "Di seguito è ripotata la successione di Fibonacci richiesta: \n";
			
			print(message_1 , v);
		}
		
	else if (n == 2) // Caso di vettore con 2 elementi
		{ 
			std::vector<int> v(n);
			
			v[0]=1;
			
			v[1]=1;
			
			std::string message_2 = "Di seguito è ripotata la successione di Fibonacci richiesta:\n\n";
			
			print(message_2 , v);
		}
	
	 else 
		{ 	
			std::vector<int> v(2); // Caso di vettore con "n" elementi
			
			int x = 1;
			
			int y = 1;
			
			v[0]=x;
			
			v[1]=y;
			
			std::vector<int> vv;
			
			vv.clear();
			
			vv = fibonacci (x, y, v, n);
			
			std::string message = "Di seguito è ripotata la successione di Fibonacci richiesta: \n";
			
			
			print (message, vv);
					
			
		}
			
return 0;
	
}
