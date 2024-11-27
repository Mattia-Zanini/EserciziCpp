### README  

**Contributi al progetto:**

1. **Emanuele Braccini**
   - Implementato il costruttore della classe `LidarDriver`.  
   - Sviluppato la funzione membro `new_scan` per aggiungere nuove scansioni al buffer.

2. **Sergio Sulozeqi**  
   - Implementato le funzioni membro:
     - `get_scan` per rimuovere e restituire la scansione più vecchia.  
     - `clear_buffer` per resettare il buffer.  
     - `get_distance` per ottenere la distanza in un angolo specifico.  
     - `get_index` per accedere all'indice attuale del buffer.  
     - `get_scansion_dim` per ottenere la dimensione di una singola scansione.

3. **Mattia Zanini**  
   - Sviluppato il **main** per testare la classe `LidarDriver`.  
   - Implementato l'overload dell'operatore `<<` per stampare i dati di scansione.  
   - Creata la funzione membro `get_distance_from_specific_scan` per ottenere la distanza da una scansione specifica e un angolo dato.
   - `get_resolution` per ottenere la risoluzione del Lidar

Le dichiarazioni delle funzioni membro e delle variabili membro della classe nel file header sono state svolte insieme, con tutti e 3 i membri del gruppo, durante l'ora di lezione in laboratorio giovedì