#include <iostream>
#include <string>

std::string lowerString(const std::string s);
void printCommands();

int main() {
  std::string answer = "";
  while (true) {
    // Formattazione iniziale, per far capire che il programma è
    // lanciato ed è in attesa di comandi
    std::cout << ">> ";

    // Prendo in input la risposta dell'utente
    std::cin >> answer;
    if (answer == "exit")
      break;
    else if (answer == "?" || answer == "help") {
      // stampo la lista dei comandi
      printCommands();
    } else if (answer == "") {
      // faro i set
    } else
      std::cout << "Comando non valido\n";
  }
  return 0;
}

std::string lowerString(const std::string s) {
  std::string lowerS = s;
  for (int i = 0; i < lowerS.size(); i++)
    lowerS[i] = tolower(lowerS[i]);
  return lowerS;
}

void printCommands() {
  std::cout << "${DEVICENAME}: Stringa di testo indicante il nome del device\n";
  std::cout << "${START}, ${STOP}, ${TIME}: orario della giornata hh:mm "
               "(formato 24 ore)\n\n";

  std::cout << "- set ${DEVICENAME} on\t\t\t Accende il dispositivo (sia CP "
               "che M)\n";
  std::cout << "- set ${DEVICENAME} off\t\t\t Spegne il dispositivo\n";
  std::cout << "- set time ${TIME}\t\t\t Va a una specifica ora del giorno\n";
  std::cout << "- rm ${DEVICENAME}\t\t\t Rimuove il timer associato al "
               "dispositivo\n";

  std::cout << "- set ${DEVICENAME} ${START} [${STOP}]\t Imposta l'orario di "
               "accensione e spegnimento per il dispositivo. L'orario di "
               "spegnimento è disponibile per solo i dispositivi M.\n\n";
  std::cout << "- show\t\t\t\t\t Mostra la lista di tutti i dispositivi "
               "(attivi e "
               "inattivi) con la produzione/consumo energetico di ciascuno "
               "dalle 00:00 al momento di invio del comando. Inoltre "
               "mostra la produzione/consumo energetico totale del sistema "
               "dalle 00:00 al momento di invio del comando\n\n";
  std::cout << "- show ${DEVICENAME}\t\t\t Mostra a schermo produzione/consumo "
               "energetico di uno specifico dispositivo\n\n";
}