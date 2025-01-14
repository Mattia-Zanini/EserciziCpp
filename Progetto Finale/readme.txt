//Autore: Sulozeqi Sergio
Come richiesto dalla consegna, il codice è adeguatamente commentato, tuttavia abbiamo deciso
di riportare in questo file alcune delle scelte implementative più importanti:

- Se si prova ad accendere un dispositivo accesso oppure a spegnere un dispositivo spento
  il comando viene ignorato.

- Per i dispositivi manuali: Se spengo un dispositivo, ad es., alle 15:00 e vi è un timer
  dalle 14:00 alle 16:00 allora il timer di spegnimento delle 16:00 viene rimosso. Se invece,
  il timer è impostato dalle 15:30 alle 16:30, il dispositivo viene spento senza alcun
  effetto sui timer.

- Non é possibile programmare 2 accensioni(con eventuali relativi spegnimenti) nel futuro,
  ma solamente una. Es.: se sono le 15:00 e ho un timer dalle 16:00 alle 17:00 e uso il
  comando per settare un timer dalle 18:00 alle 19:00, allora quest’ultimo sovrascrive il
  precedente.

- Quando si setta un timer di solo inizio, non viene rimosso un eventuale timer di
  spegnimento settato precedentemente, ma solamente sovrascritto quello di inizio

- Se si imposta un timer di accensione ad un orario precedente a quello attuale, il sistema
  lo interpreta come un orario del giorno successivo, per cui viene impostato ma essendo che
  il programma termina alle 23:59 allora questo timer non provocherà mai l'accensione
  del dispositivo

- Quando accendendo un dispositivo, si supera il limite di potenza del sistema, allora
  procediamo spegnendo i dispositivi in ordine inverso all'accensione, ma effettuando sempre
  un controllo sulla potenza in uso rispetto a quella massima, basterà spegnere solo il
  dispositivo appena acceso per tornare al di sotto della soglia. È invece più complicato
  il caso in cui si spegne un dispositivo che produce energia, in questo caso i dispositivi
  da spegnere potrebbero essere più di uno e il procedimento è spiegato tramite commenti
  nel codice

Abbiamo ritenuto necessario aggiungere un unico log non presente nella consegna:
- quando viene usato il comando "reset timers" viene stampato il log "[hh:mm] I timer di tutti
  i dispositivi sono stati rimossi"