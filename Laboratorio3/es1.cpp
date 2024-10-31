#include <iostream>
#include <string>

void f();
void f_illegal();
std::string print_index(int value);

int main(){
	f();
	std::cout << "\n\n";
	f_illegal();
	
	return 0;
}

void f(){
	int n = 10;
	int array[n];
	int pos = 7;
	int *p = &array[pos];
	int x = n-pos;
	
	int c = 0;
	for(int i = pos*(-1); i < x; i++){
		p[i] = c++;
		std::cout << "[" << i << "]: " << p[i] << '\n';
	}
}

// se non desse problemi dovrebbe arrivare fino a i=10
// partendo da -8, pero' mi da errore di segmentazione.
void f_illegal(){
	int n = 10;
	int array[n];
	int pos = 8;
	int *p = &array[pos];
	
	int c = 1;
	for(int i = pos*(-1); i < n; i++){
		p[i] = c++;
		std::cout << print_index(i) << p[i] << '\n';
		//std::cout << "[" << i << "]: "<< p[i] << '\n';
	}
}

std::string print_index(int value){
	return "[" + std::to_string(value) + "]: ";
}
