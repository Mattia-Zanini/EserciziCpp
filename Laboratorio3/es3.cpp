#include <iostream>

void print_reference(const int &var1, const double &var2);
void print_pointer(int *var1, double *var2);

int main(){
	int a;
	double b;
	
	print_reference(a, b);
	print_pointer(&a, &b);
	
	return 0;
}

void print_reference(const int &var1, const double &var2){
	std::cout << "Reference var1: " << var1 << '\n';
	std::cout << "Reference var2: " << var2 << '\n';
}

void print_pointer(int *var1, double *var2){
	std::cout << "Pointer var1: " << *var1 << '\n';
	std::cout << "Pointer var2: " << *var2 << '\n';
	
	std::cout << "Pointer var1 (address): " << var1 << '\n';
	std::cout << "Pointer var2 (address): " << var2 << '\n';
}
