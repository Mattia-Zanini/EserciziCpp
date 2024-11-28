Progetto realizzato da: Nicolò Roccatello, Beatrice Stevan, Maddalena Massaro

Per la realizzazione di questo progetto, abbiamo deciso di strutturarlo suddividendo il lavoro in due classi principali: Scan e LidarDriver, ritenendo che lavorare su due file separati potesse semplificare la gestione e l'effettiva realizzazione del progetto.
Pur essendo consapevoli, tuttavia, che per rendere il tutto più completo sarebbe stato necessario inserire nozioni riguardanti l'ereditarietà, non ancora trattata a lezione, abbiamo comunque cercato di implementare i file nel miglior modo possibile, sfruttando le conoscenze acquisite fino a questo punto.

La classe Scan.h e il relativo file Scan.cpp sono stati sviluppati congiuntamente da Nicolò Roccatello e Beatrice Stevan. In particolare:
-la realizzazione dei tre costruttori è stata svolta in collaborazione tra Nicolò Roccatello e Beatrice Stevan;
- la funzione to_vector() è stata implementata da Beatrice Stevan;
- la funzione get_reading() è stata sviluppata da Nicolò Roccatello;
- l'overloading dell'operatore << è stato curato da Beatrice Stevan;
- i commenti esplicativi all'interno della classe Scan.h sono stati redatti da Beatrice Stevan.

La classe LidarDriver.h e il file LidarDriver.cpp sono stati realizzati principalmente da Maddalena Massaro, con il contributo attivo di Beatrice Stevan e Nicolò Roccatello. In dettaglio:
- i costruttori della classe sono stati realizzati da Massaro Maddalena, come anche le funzioni new_scan e get_scan;
- clear_buffer() e get_distance() sono state sviluppate congiuntamente da Massaro e Roccatello;
- la funzione get_index() e l'overloading dei due operatori << e [] sono stati realizzati da Massaro e Stevan.

Inoltre, Stevan e Massaro hanno collaborato per risolvere le problematiche di linking tra i vari file, mentre Roccatello si è occupato di migliorare i diversi 
programmi da un punto di vista stilistico.

Il file Main.cpp è stato sviluppato principalmente da Beatrice Stevan e Maddalena Massaro, con il supporto di Nicolò Roccatello per alcune ottimizzazioni.
