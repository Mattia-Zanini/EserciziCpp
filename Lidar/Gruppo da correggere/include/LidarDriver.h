#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <vector>
#include <iostream>
#include "../include/Scan.h"

class LidarDriver{
	private:
		const int DIM_BUFFER=20;
		Scan* ps; //puntatore al buffer
		int index; // indice del buffer
		int buffer_size; //variabile che rappresenta fino a quanto è riemppito il buffer serve per la ciclicità
		int angular_resolution = 1.0; //angular resolution
		
	public:
		LidarDriver(double a);//crea un Lidar drivere dove a è la angular resolution degli scanner
		LidarDriver();//costruttore di defult
		
		void new_scan(std::vector<double>& v);//inserisce uno scan con reading v nel buffer in maniera ciclica
		void new_scan(const std::vector<double>& v);//);//inserisce uno scan con reading v nel buffer in maniera ciclica
		std::vector<double> get_scan();//restituisce il vettore dell'oggetto scanner più vecchio 
		void clear_buffer(); //svuota di il buffer
		double get_distance(double degree);// restituisce il valre all'angolo degree nell'ultimo scanner inserito
		friend std::ostream& operator<<(std::ostream& os, const LidarDriver& ld); //restituisce l'ulimo elemento 
		int get_index() const;//indice dell'ultimo valore inserito 
		Scan operator[] (int n) const; 
		Scan& operator[] (int n) ;

		class EmptyBufferException{};
};
#endif

