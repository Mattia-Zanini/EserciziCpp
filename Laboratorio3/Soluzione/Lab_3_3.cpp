//Lab 3 - Esercizio 3 Rev0

#include <iostream>

void print_reference (int x, double y)
{
	std::cout << "Print by reference: " << x << "   " << y << "\n\n";
}


void print_pointer (int z, double k)
{
	std::cout << "Print by pointer: " << z << "   " << k << "\n";
}

int main()
{
	int a = 5;
	double b = 5.5;
	int* aa = &a;
	int& m = a;
	double* bb = &b;
	double& q = b;
	
	print_reference (m, q);
	
	print_pointer (*aa, *bb);
	
	std::cout << std::endl;
	
	return 0;
}
