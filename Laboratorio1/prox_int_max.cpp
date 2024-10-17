#include <iostream>
#include <vector>

void print(std::string str, std::vector<int>& v);
void fibonacci(int x, int y, std::vector<int>& v, int n);

int main(){
	int n = 50;
	std::string s = "Questo e' il vettore:\n";
	std::vector<int> v;
	
	int x = 1;
	int y = 2;
	
	fibonacci(x, y, v, n);
	print(s, v);
	
	return 0;
}

void print(std::string str, std::vector<int>& v){
	std::cout << str;
	for(int i = 0; i < v.size(); i++){
		std::cout << "[" << i << "]: " << v[i] << "\n";
	}
	return;
}

void fibonacci(int x, int y, std::vector<int>& v, int n){
	v.clear(); // pulisco l'array
	
	v.push_back(x); // v[0]
	v.push_back(y); // v[1]
	
	for(int i = 2; i < n; i++){
		int next = v[i-1] + v[i-2];
		if(next <= 0)
			return;
		v.push_back(v[i-1] + v[i-2]);
	}
	return;
}




