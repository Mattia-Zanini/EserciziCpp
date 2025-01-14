//Autore: Braccini Emanuele
#ifndef CICLOPREFISSATO_H
#define CICLOPREFISSATO_H

#include "Dispositivo.h"
#include <string>

class CicloPrefissato:public Dispositivo{
        
	public:
		CicloPrefissato(std::string n, int indirizzo, double p, int t); //costruttore
		~CicloPrefissato(){} //distruttore
		void accensione();
		void decreaseMinRimanenti() {minRimanenti--;} //abbassa di 1 i minuti rimanenti al termine del ciclo
		void resetMinRimanenti() {minRimanenti=durataCiclo;} //resetta i minuti mancanti alla fine del ciclo, questa funzione verrà chiamata ad ogni accensione del dispositivo CP
		int getMinRimanenti() const{return minRimanenti;} //ritorna i minuti rimanenti al termine del ciclo
	
	private:
        int durataCiclo; //durata del ciclo in minuti
		int minRimanenti; //minuti rimanenti al termine del ciclo, e quindi allo spegnimento del dispositivo

};

#endif
