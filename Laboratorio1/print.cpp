#include <iostream>
#include <vector>

void print(std::string str, std::vector<int> v);

int main(){
	std::string s = "Questo e' il vettore:\n";
	std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	print(s, v);
	
	return 0;
}

void print(std::string str, std::vector<int> v){
	std::cout << str;
	for(int i = 0; i < v.size(); i++){
		std::cout << "[" << i << "]: " << v[i] << "\n";
	}
	return;
}
