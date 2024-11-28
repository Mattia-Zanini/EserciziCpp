#include <vector>
#include <iostream>
//#include "../include/Scan.h"
#include "../include/LidarDriver.h"

// controllo che le funzioni chiamate su ps vuoto funzionino

LidarDriver::LidarDriver() : index(0), buffer_size(1) {
	ps = new Scan[DIM_BUFFER];
}

LidarDriver::LidarDriver(double a) : index(0), buffer_size(1), angular_resolution(a) {
	if(a<0.1 || a>1) throw std::out_of_range("Error: out fo bound exception\n");
	ps = new Scan[DIM_BUFFER];
}


void LidarDriver::new_scan(std::vector<double>& v){
	if(index<DIM_BUFFER){
		//elemino le cose in index cosi non creao garbage ne con scan() e neanche quando sovrascrivo
		ps[index]=Scan(v,angular_resolution);
		index++;
	}
	else{
		ps[0]=Scan(v,angular_resolution);
		index=1;
	}	
	
	if (buffer_size<DIM_BUFFER){ //se pieno non serve incrementarla quindi lo faccio a parte
		buffer_size++;
	}
}

std::vector<double> LidarDriver::get_scan(){ //il vettore che restituisce deve essere quello inserito più vecchio / che è li da più tempo
	if(index=0) throw EmptyBufferException();
	if(buffer_size<DIM_BUFFER || index==DIM_BUFFER-1) {return ps[0].to_vector();} //buffer non ancora riempito 
	else { return ps[index].to_vector(); }
}

void LidarDriver::clear_buffer(){
	for (int i=0; i<buffer_size; i++){
		delete[] (ps+i);
	}
	index=0;
	buffer_size=1;
}

double LidarDriver::get_distance(double degree){
	if (degree>180 || degree<0) throw std::out_of_range("Error: out fo bound exception\n");
	if (index-1==-1){
		return ps[DIM_BUFFER-1].get_reading(degree);
	}
	else { return ps[index-1].get_reading(degree); }	
}

int LidarDriver::get_index() const{
	if ((index-1)==-1){return DIM_BUFFER-1;}
	else { return index-1; }
}

std::ostream& operator<<(std::ostream& os, const LidarDriver& ld){
	os << "L'ultimo scan inserito e': \n" << ld[ld.get_index()];
	return os;
}

Scan LidarDriver::operator[] (int n) const {return ps[n];}
Scan& LidarDriver::operator[] (int n) {return ps[n];}
	
