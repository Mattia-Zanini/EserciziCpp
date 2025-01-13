#include "include/Casa.h"
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void removeUnnecessarySpaces(std::string &s);
std::vector<std::string> splitString(std::string s, const char c);
int orarioToInt(std::string s);
std::string getDeviceName(std::string s);
void printAndLog(std::ofstream &ofs, const std::string s);
void printCommands();

int main(int argc, char *argv[]) {
  if (argc != 2) {
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
  }

  std::ofstream fs = std::ofstream();
  fs.open("log.txt", std::fstream::app);
  if (fs.fail()) {
    std::cout << "errore nell'apertura del file in modalità 'append'\n";
    return -1;
  }

  constexpr bool DEBUG = true;
  std::deque<std::string> comandi{
      "set Impianto fotovoltaico on",
      "set Impianto fotovoltaico 1:00 1:20",
      "set Pompa di calore + termostato on",
      "set Lavastoviglie on",
      "set Lavastoviglie off",
      "set time 1:30",
      "set Frigorifero on",
      "set Frigorifero 2:00 3:00",
      "set Lavatrice off",
      "set time 3:05",
      "set Pompa di calore + termostato off",
      "reset all",
      "exit",
  };

  Casa home = Casa(std::stod(argv[1]));
  std::string answer = "";

  while (true) {
    // Formattazione iniziale, per far capire che il programma è
    // lanciato ed è in attesa di comandi
    std::cout << ">> ";

    // Prendo in input la riga inserita dall'utente
    if (DEBUG) {
      answer = comandi.front();
      comandi.pop_front();
      std::cout << answer << '\n';
    } else
      std::getline(std::cin, answer);

    removeUnnecessarySpaces(answer);
    std::vector<std::string> commands = splitString(answer, ' ');

    try {
      if (answer == "exit") {
        std::cout << '\n';
        break;
      } else if (answer == "?" || answer == "help") {
        // stampo la lista dei comandi
        printCommands();
      } else if (commands.at(0) == "set") {

        if (commands.at(1) == "time")
          // set time ${TIME}
          printAndLog(fs, home.setOrario(orarioToInt(commands.at(2))));
        else if (answer.find("on") != std::string::npos) {
          // set ${DEVICENAME} on
          if (commands.size() == 3)
            printAndLog(fs, home.accendiDispositivo(commands.at(1)));
          else {
            // Esempio: "set Impianto fotovoltaico on"
            // inputSize = answer.size() (= 28)
            // onStrPos = answer.find("on"); (= 26)
            // onStrPos = 26
            // Comincio da 4, ovvero 'I'
            //
            // Dalla lunghezza totale della stringa (inputSize) tolgo la
            // posizione di "on" quindi faccio (28 - 26) = 2, questo lo tolgo da
            // inputSize -> 26, poi tolgo dal conteggio la lunghezza di "set"
            // e i due spazi ==> 26 - 3 - 1 - 1 = 21 che è lunghezza del nome
            // del dispositivo "Impianto fotovoltaico"
            // Formula: inputSize - (inputSize - onStrPos) - 5
            // Semplifico la formula e ottengo: (onStrPos - 5)
            std::string deviceName = answer.substr(4, answer.find("on") - 5);

            printAndLog(fs, home.accendiDispositivo(deviceName));
          }
        } else if (answer.find("off") != std::string::npos) {
          // set ${DEVICENAME} off

          // Ho spiegato i calcoli su "set ${DEVICENAME} on"
          std::string deviceName = answer.substr(4, answer.find("off") - 5);
          printAndLog(fs, home.spegniDispositivo(deviceName));
        } else {
          // set ${DEVICENAME} ${START} [${STOP}]

          std::string deviceName = getDeviceName(answer.substr(4));
          std::string str = answer.substr(4 + deviceName.size() + 1);
          commands = splitString(str, ' ');

          if (commands.size() == 1)
            printAndLog(
                fs, home.impostaTimer(deviceName, orarioToInt(commands.at(0))));
          else
            printAndLog(fs, home.impostaTimer(deviceName,
                                              orarioToInt(commands.at(0)),
                                              orarioToInt(commands.at(1))));
        }

      } else if (commands.at(0) == "show") {
        if (commands.size() == 1)
          printAndLog(fs, home.allConsumi()); // show
        else {
          // show ${DEVICENAME}

          // Ho spiegato i calcoli su "set ${DEVICENAME} on"
          std::string deviceName = answer.substr(5);
          printAndLog(fs, home.consumoDispositivo(deviceName));
        }
      } else if (commands.at(0) == "rm") {
        // rm ${DEVICENAME}

        // Ho spiegato i calcoli su "set ${DEVICENAME} on"
        std::string deviceName = answer.substr(3);
        printAndLog(fs, home.rmTimer(deviceName));
      } else if (answer == "reset time" && DEBUG)
        printAndLog(fs, home.resetOrario());
      else if (answer == "reset timers" && DEBUG)
        printAndLog(fs, home.resetTimers());
      else if (answer == "reset all" && DEBUG)
        printAndLog(fs, home.resetAll());
      else
        std::cout << "Comando non valido\n";

    } catch (std::out_of_range const &e) {
      std::cout << "Mancano dei parametri" << '\n';
    } catch (std::invalid_argument const &e) {
      std::cout << e.what() << '\n';
    }
  }

  fs.close();
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

std::string getDeviceName(std::string s) {
  std::string deviceName = "";
  for (std::string::iterator is = s.begin(); is != s.end(); ++is) {
    if (isdigit(*(is))) {
      // rimuovo lo spazio che sicuramente c'è prima dell'ora
      deviceName.pop_back();
      break;
    }

    deviceName.push_back(*(is));
  }
  return deviceName;
}

void printAndLog(std::ofstream &ofs, const std::string s) {
  std::cout << s;
  ofs << s;
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