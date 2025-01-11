#include "include/Casa.h"
#include <iostream>
#include <string>

void removeUnnecessarySpaces(std::string &s);
std::vector<std::string> splitString(std::string s, const char c);
int orarioToInt(std::string s);
void printCommands();

int main(int argc, char *argv[]) {
  /*if (argc != 2) {
    std::cout << "Utilizzo: main <massima potenza>\n";
    return 0;
  }

  try {
    if (std::stod(argv[1]) <= 0) {
      std::cout << "<massima potenza> deve essere maggiore di 0\n";
      return 0;
    }
  } catch (std::exception &e) {
    std::cout
        << "<massima potenza> deve essere un valore 'double' maggiore di 0\n";
    return 0;
  }*/

  Casa home = Casa(3.5);
  std::string answer = "";

  // DEBUG
  std::vector<std::string> comandi{"set time 2:00", "set Scaldabagno on",
                                   "set Lavatrice on"};

  while (true) {
    // Formattazione iniziale, per far capire che il programma è
    // lanciato ed è in attesa di comandi
    std::cout << ">> ";

    // Prendo in input la riga inserita dall'utente
    // std::getline(std::cin, answer);
    answer = comandi.back();
    comandi.pop_back();

    removeUnnecessarySpaces(answer);
    std::vector<std::string> commands = splitString(answer, ' ');

    try {
      if (answer == "exit")
        break;
      else if (answer == "?" || answer == "help") {
        // stampo la lista dei comandi
        printCommands();
      } else if (commands.at(0) == "set") {
        if (commands.at(1) == "time")
          home.setOrario(orarioToInt(commands.at(2)));
        else if (commands.at(2) == "on")
          home.accendiDispositivo(commands.at(1));
        else if (commands.at(2) == "off")
          home.spegniDispositivo(commands.at(1));
        else if (commands.size() == 4) // set ${DEVICENAME} ${START} [${STOP}]
          home.impostaTimer(commands.at(1), orarioToInt(commands.at(2)),
                            orarioToInt(commands.at(3)));
        else if (commands.size() == 3) // set ${DEVICENAME} ${START}
          home.impostaTimer(commands.at(1), orarioToInt(commands.at(2)));

      } else if (commands.at(0) == "show") {
        if (commands.size() == 2)
          std::cout << home.consumoDispositivo(commands.at(1)) << '\n';
        else if (commands.size() == 1)
          home.allConsumi();
        else
          std::cout << "Comando non valido\n";
      } else if (commands.at(0) == "rm") {
        std::cout << home.rmTimer(commands.at(1)) << '\n';
      } else
        std::cout << "Comando non valido\n";

    } catch (std::out_of_range const &e) {
      std::cout << "Mancano dei parametri" << '\n';
    } catch (std::invalid_argument const &e) {
      std::cout << e.what() << '\n';
    }
  }

  return 0;
}

// Passata una stringa per riferimento, rimuove gli spazi inutili dal comando
void removeUnnecessarySpaces(std::string &s) {
  std::string sCopy = s;
  bool stringStarted = false;
  s.clear();

  for (std::string::iterator is = sCopy.begin(); is != sCopy.end(); ++is) {
    // Se la stringa è iniziata, allora guardo se ci sono
    // spazi di troppo tra le parole
    if (stringStarted) {
      if (*(is) == ' ' && (*(is + 1) == ' ' || *(is + 1) == '\0'))
        continue;
    }
    // Se la stringa non è ancora iniziata allora non considero
    // gli spazi che si trovano ad inizio stringa
    else {
      if (*(is) == ' ')
        continue;
      else
        stringStarted = true;
    }

    s.push_back(*(is));
  }
}

// Data una stringa, la suddivide in sottostringhe,
// in base a un carattere separatore 'c'
std::vector<std::string> splitString(std::string s, const char c) {
  std::vector<std::string> ss(1);
  int spaces = 0;

  for (std::string::iterator is = s.begin(); is != s.end(); ++is) {
    if (*(is) == c) {
      spaces++;
      ss.push_back("");
    } else
      ss[spaces].push_back(*(is));
  }

  return ss;
}

int orarioToInt(std::string s) {
  std::vector<std::string> hm = splitString(s, ':');
  if (hm.size() != 2)
    throw std::invalid_argument("<time> non è in un formato valido");

  int h = -1;
  int m = -1;
  try {
    h = std::stoi(hm[0]);
    m = std::stoi(hm[1]);
  } catch (const std::exception &e) {
    // Lancio questa eccezzione, così sfrutto il catch del main
    // per stampare nel terminale l'eccezione
    throw std::invalid_argument("<time> non è in un formato valido");
  }

  return h * 60 + m;
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
               "(attivi e inattivi) con la produzione/consumo energetico"
               "di ciascuno dalle 00:00 al momento di invio del comando."
               " Inoltre mostra la produzione/consumo energetico totale "
               "del sistema dalle 00:00 al momento di invio del comando\n\n";
  std::cout << "- show ${DEVICENAME}\t\t\t Mostra a schermo produzione/consumo "
               "energetico di uno specifico dispositivo\n\n";
}