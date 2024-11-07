// Lab 3 - Esercizio 2 - Revisione 0 - Definitivo

#include <iostream>

int print_array_lenght (double a[]) {
	
	std::cout << "Dimensione array da funzione = " << sizeof(a) << std::endl;
	
	return 0;
}


int main()
{

	constexpr int sz = 10;
	double array[sz] {};
	std::cout << "Dimensione array di un singolo double = " << sizeof(double) << std::endl;
	std::cout << "Dimensione array di " << sz << " doubles = " << sizeof(array) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;	
	print_array_lenght (array);
		
		
	
return 0;
}

/* La funzione non riesce ad accedere alla dimensione dell'array. Per ottenere il
risultato corretto sarebbe necessario definre una classe con relativa funzione membro.
*/