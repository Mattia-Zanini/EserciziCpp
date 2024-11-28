#ifndef SCAN_H
#define SCAN_H
#include <vector>
#include <cmath>
#include <iostream>

class Scan{

	private:
		double angular_resolution;  //risoluzione angolare del LIDAR
		int dim;  //rappresenta il numero totale di letture per una scansione, calcolato in base alla risoluzione angolare 
		std::vector<double> degree;  //un vettore che contiene i gradi corrispondenti per ciascuna lettura
		std::vector<double> reading;  //un vettore che contiene le letture delle distanze per ciascun angolo
		
	public:
		//costruttore di default
		Scan();

		//costruttori
		Scan(const std::vector<double>& v, int ra);
		Scan(std::vector<double>& v, int ra);
		/* Entrambi i costruttori accettano un vettore di letture v e una risoluzione angolare ra, calcolano il numero
		di letture previste (dim) per una scansione, copiano i valori da v in reading e calcolano gli angoli corrispondenti,
		inserendoli in degree. Il primo è const mentre il secondo no */
		
		std::vector<double> to_vector(); /* Restituisce un riferimento a un nuovo vettore contenente le misure relative a 
		quella specifica scansione, dunque il vettore reading è copiato in questo nuovo vettore */
		
		double get_reading(double degree); /* Calcola l'indice del vettore reading corrispondente a un determinato angolo degree
		e restituisce la lettura associata */
		
		friend std::ostream& operator<<(std::ostream& os, const Scan& scan); /*Sovraccarica l'operatore << per stampare le
		informazioni di una scansione */
};
#endif