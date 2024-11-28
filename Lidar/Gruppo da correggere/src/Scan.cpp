//#include "../include/Scan.h"
#include "../include/Scan.h"

Scan::Scan() : angular_resolution(1.0), dim(180) {}

Scan::Scan(const std::vector<double>& v, int ra) : angular_resolution(ra) , dim(180 / ra) { 
	// (180 / angular_resolution) è la formula per ottenere il numero totale di letture per una scansione
	if(v.size()<dim){
		for(int i=0; i<v.size(); i++){
			degree.push_back(i*ra);  //vengono calcolati gli angoli
			reading.push_back(v.at(i));
		}
		for(int i=v.size(); i<dim; i++){
			degree.push_back(i*ra);  //vengono calcolati gli angoli
			reading.push_back(0);
		}
	}
	else{
		for(int i=0; i<dim; i++){
			degree.push_back(i*ra);  //vengono calcolati gli angoli
			reading.push_back(v.at(i));
		}
	}	
}

Scan::Scan(std::vector<double>& v, int ra) : angular_resolution(ra) , dim(180 / ra) { 
	// (180 / angular_resolution) è la formula per ottenere il numero totale di letture per una scansione
	if(v.size()<dim){
		for(int i=0; i<v.size(); i++){
			degree.push_back(i*ra);  //vengono calcolati gli angoli
			reading.push_back(v.at(i));
		}
		for(int i=v.size(); i<dim; i++){
			degree.push_back(i*ra);  //vengono calcolati gli angoli
			reading.push_back(0);
		}
	}
	else{
		for(int i=0; i<dim; i++){
			degree.push_back(i*ra);  //vengono calcolati gli angoli
			reading.push_back(v.at(i));
		}
	}	
}

std::vector<double> Scan::to_vector(){
	std::vector<double> v; 
	for(int i=0; i<dim; i++){
		//restituire un vettore delle misure relativo a quella specifica scansione
		v.push_back(reading.at(i));
	}
	return v;
}
	
double Scan::get_reading(double deg){
	if(deg<=0 || deg>=180) throw std::out_of_range("Error: out fo bound exception\n");
	int index = round(deg/angular_resolution); //per trovare l'indice utilizziamo round
	return reading.at(index);
}
	
std::ostream& operator<<(std::ostream& os, const Scan& scan){
	for (int i = 0; i < scan.dim; i++) {
       	os << "Degree: " << scan.degree.at(i) << " - Reading: " << scan.reading.at(i) <<std::endl;
    }
     return os;
}

