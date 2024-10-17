#include <iostream>

void call_counter(void);

int main(){
	int n = 5;
	for(int i = 0; i < n; i++){
		call_counter();
	}
	return 0;
}

void call_counter(void){
	int static count = 0;
	count++;
	
	std::cout << count << "\n";
}
