#include "../include/LidarDriver.h"

#include <iostream>
#include <vector>

int main(){
	std::cout<<"prova 1 \n";
	
	std::vector<double> vec{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
	std::vector<double> v2{1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9};

//TEST SCAN
	Scan s = Scan(vec,10);
	//to vector 
	std::vector <double> v = s.to_vector();
	for (int i=0;i<v.size();i++){
		std::cout<<v.at(i)<<"; ";
	}
	std::cout<<"\nfine stampa di s \n";
	
	//get reading
	double a = s.get_reading(20);
	std::cout<<a<<" \n";

	double a1 = s.get_reading(28);
	std::cout<<a1<<" \n";
	
	//operator <<;
	std::cout<<"stampo lo scanner: \n"<< s <<"\n";

//TEST LIDARDRIVER
	std::cout<<"TESTER LIDARDRIVER\n";
	LidarDriver ld = LidarDriver(0.2);
	
    //new_scan
    std::cout<<"Palle 3\n";
	ld.new_scan(vec);
    std::cout<<"Palle 2\n";
	ld.new_scan(v2);
	std::cout<<"Palle 1\n";
    //get_scan()
    std::vector<double> v3 = ld.get_scan();
	std::cout<<"get_scan: \n";
	for (int i=0; i<v3.size(); i++){
		std::cout<<v3[i]<<"; ";
	}
	std::cout<<"/n";
	
	//get_distance(double degree)
	double r=ld.get_distance(23);
	std::cout<<"get_distance restituisce:"<<r<<"\n";
	
	//operator<<
	std::cout<<"stampo l'ultimo scanner inserito \n"<<ld<<"\n";
	
	
	return 0;
}