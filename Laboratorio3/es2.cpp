#include <iostream>
#include <string>

void print_array_length(double array[]);
std::string print_index(int value);

int main(){
	constexpr int n = 10;
	double arr[n];
	
	std::cout << "sizeof(arr): " << sizeof(arr) << "\n\n";
	
	for(int i = 0; i < sizeof(arr); i++){
		//std::cout << print_index(i) << arr[i] << '\n';
		std::cout << "[" << i << "]: "<< arr[i] << '\n';
	}
	
	std::cout << "\n\n";
	print_array_length(arr);
	
	return 0;
}

// print_array_length non puo' conoscere l'intera grandezza
// dell'array, lo considera come un puntatore quindi il sizeof
// ritornera' 8 coem lunghezza in byte.
void print_array_length(double *array){
	for(int i = 0; i < sizeof(array); i++){
		//std::cout << print_index(i) << array[i] << '\n';
		std::cout << "[" << i << "]: "<< array[i] << '\n';
	}
}

std::string print_index(int value){
	return "[" + std::to_string(value) + "]: ";
}
