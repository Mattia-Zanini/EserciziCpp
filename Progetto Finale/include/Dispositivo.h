//Autore: Braccini Emanuele
#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

class Dispositivo{

	public:
		virtual ~Dispositivo(){} //il distruttore è virtuale per permettere il corretto funzionamento quando un ogetto derivato viene eliminato tramite un puntatore alla classe base
		Dispositivo(const Dispositivo&) = delete; // Costruttore di copia disabilitato
    Dispositivo& operator=(const Dispositivo&) = delete; // Operatore "=" disabilitato
		void setTimerAccensione(int s){timerAccensione = s;} //setta un orario di accensione
		virtual void accensione(){stato = true;} //mette il dispositivo in stato acceso
		void spegnimento(){stato = false;} //mette il dispositivo in stato spento
		void increaseEnergia(); //aggiorna il valore di energia prodotta/consumata dal dispositivo, verrà chiamata al passaggio di ogni minuto, se il dispositivo è acceso
		void resetEnergia() {energia = 0;} // resetta il valore di energia prodotta/consumata dal dispositivo
		bool getStato() const{return stato;} //restituisce lo stato
		double getPotenza() const{return potenza;} //restituisce la potenza del dispositivo
		double getEnergia() const{return energia;} //restituisce l'energia prodotta/consumata dal dispositivo dalle 00:00 fino all'ora in cui viene chiamata questa funzione
		std::string getNome() const{return nome;} //restituisce il nome del dispositivo
		int getTimerAccensione() const{return timerAccensione;} //restituisce l'orario programmato di accensione
	
	protected:
		std::string nome;
		int id;
		double potenza; //(in kW) è la potenza indicata nella tabella, può essere positiva o negativa
		double energia; //(in kWh) dipende dalla potenza, è sempre positiva (la differenza sta nel fatto che questa quantità può essere prodotta o consumata)
		bool stato; //acceso/spento
		int timerAccensione; //orario programmato di accensione
		Dispositivo(std::string n, int indirizzo, double p); //Non vogliamo che si creino oggetti Dispositivo, ma solamente manuali o CP, per questo motivo il costruttore é protected.

};

#endif