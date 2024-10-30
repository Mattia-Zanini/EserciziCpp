// Lab_1: Esercizio 3 - Revisione finale
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

int main() // Corpo del programma che richiama la funzione

{
	std::string message = "Di seguito trovi i quadrati dei seguenti numeri: 2, 3, 4, 5!\n"; // Messaggio all'utente
	
	std::vector<int> yy{4, 9, 16, 25}; // definizione del vettore yy
	
	print(message, yy); // Chiamata della funzione print
	
return 0;
	
}