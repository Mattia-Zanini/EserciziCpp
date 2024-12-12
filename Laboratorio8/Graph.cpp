#include <iostream>
#include <stdexcept>
#include <vector>

// Classe che rappresenta un vertice nel grafo
class Vertex {
public:
  int ID; // Identificatore univoco del vertice

  Vertex(int id) : ID(id) {}

  // Sovraccarico dell'operatore di uguaglianza per confrontare vertici tramite
  // ID
  bool operator==(const Vertex &other) const { return ID == other.ID; }
};

// Classe che rappresenta un arco tra due vertici nel grafo
class Edge {
public:
  int vertex1_ID; // ID del primo vertice
  int vertex2_ID; // ID del secondo vertice

  Edge(int v1, int v2) : vertex1_ID(v1), vertex2_ID(v2) {}

  // Sovraccarico dell'operatore di uguaglianza per confrontare archi
  // indipendentemente dalla direzione
  bool operator==(const Edge &other) const {
    return (vertex1_ID == other.vertex1_ID && vertex2_ID == other.vertex2_ID) ||
           (vertex1_ID == other.vertex2_ID && vertex2_ID == other.vertex1_ID);
  }
};

// Classe che rappresenta il grafo utilizzando liste di vertici e archi
class Graph {
private:
  std::vector<Vertex> vertices; // Lista dei vertici del grafo
  std::vector<Edge> edges;      // Lista degli archi del grafo

public:
  // Inserisce un nuovo vertice nel grafo
  void insert_vertex(int id) {
    // Controlla se il vertice esiste già
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices[i].ID == id) {
        throw std::invalid_argument("Il vertice esiste già.");
      }
    }
    // Aggiunge il vertice alla lista
    vertices.push_back(Vertex(id));
  }

  // Inserisce un nuovo arco tra due vertici
  void insert_edge(int v1, int v2) {
    // Verifica che l'arco non formi un loop
    if (v1 == v2) {
      throw std::invalid_argument("I loop non sono permessi.");
    }

    // Verifica che entrambi i vertici esistano nel grafo
    bool v1_exists = false, v2_exists = false;
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices[i].ID == v1)
        v1_exists = true;
      if (vertices[i].ID == v2)
        v2_exists = true;
    }

    if (!v1_exists || !v2_exists) {
      throw std::invalid_argument("Uno o entrambi i vertici non esistono.");
    }

    // Controlla se l'arco esiste già
    Edge new_edge(v1, v2);
    for (int i = 0; i < edges.size(); i++) {
      if (edges[i] == new_edge) {
        throw std::invalid_argument("L'arco esiste già.");
      }
    }

    // Aggiunge l'arco alla lista
    edges.push_back(new_edge);
  }

  // Restituisce un vettore di archi incidenti a un dato vertice
  const std::vector<Edge> incidentEdges(int vertex_id) const {
    std::vector<Edge> incident;
    // Verifica ogni arco per determinare se è connesso al vertice
    for (int i = 0; i < edges.size(); i++) {
      if (edges[i].vertex1_ID == vertex_id ||
          edges[i].vertex2_ID == vertex_id) {
        incident.push_back(edges[i]);
      }
    }
    return incident;
  }

  // Restituisce il vertice opposto a quello dato lungo un arco specifico
  int opposite(int vertex_id, const Edge &e) const {
    if (e.vertex1_ID == vertex_id) {
      return e.vertex2_ID; // Restituisce l'altro vertice
    } else if (e.vertex2_ID == vertex_id) {
      return e.vertex1_ID; // Restituisce l'altro vertice
    } else {
      throw std::invalid_argument("Il vertice non fa parte dell'arco.");
    }
  }

  // Stampa i vertici e gli archi del grafo
  void print_graph() const {
    std::cout << "Vertici: ";
    for (int i = 0; i < vertices.size(); i++) {
      std::cout << vertices[i].ID << " ";
    }
    std::cout << "\nArchi: ";
    for (int i = 0; i < edges.size(); i++) {
      std::cout << "(" << edges[i].vertex1_ID << ", " << edges[i].vertex2_ID
                << ") ";
    }
    std::cout << std::endl;
  }

  // Ricerca in ampiezza (BFS) partendo da un dato vertice
  void BFS(int startVertex) {
    // Vettore per tracciare i vertici visitati
    std::vector<bool> visited(vertices.size(), false);
    // Vettore che funge da "coda" per la BFS
    std::vector<int> toVisit;

    // Segna il vertice di partenza come visitato e lo aggiunge al vettore di
    // visita
    toVisit.push_back(startVertex);
    visited[startVertex] = true;

    // Esegue la BFS
    for (int i = 0; i < toVisit.size(); i++) {
      int current = toVisit[i];

      // Processa il vertice corrente (stampa per dimostrazione)
      std::cout << "Vertice visitato: " << current << std::endl;

      // Ottiene tutti gli archi incidenti al vertice corrente
      std::vector<Edge> incident = incidentEdges(current);

      for (int j = 0; j < incident.size(); j++) {
        int neighbor = opposite(current, incident[j]);

        // Se il vicino non è stato visitato, lo segna e lo aggiunge al vettore
        // di visita
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          toVisit.push_back(neighbor);
        }
      }
    }
  }
};

int main() {
  Graph g;

  try {
    // Inserisce i vertici
    g.insert_vertex(1);
    g.insert_vertex(2);
    g.insert_vertex(3);
    g.insert_vertex(4);

    // Inserisce gli archi
    g.insert_edge(1, 2);
    g.insert_edge(2, 3);

    // Stampa il grafo
    g.print_graph();

    // Ottiene gli archi incidenti al vertice 2
    std::vector<Edge> edges = g.incidentEdges(2);
    std::cout << "Archi incidenti per il vertice 2: ";
    for (int i = 0; i < edges.size(); i++) {
      std::cout << "(" << edges[i].vertex1_ID << ", " << edges[i].vertex2_ID
                << ") ";
    }
    std::cout << std::endl;

    // Trova il vertice opposto lungo un arco
    int opp = g.opposite(2, edges[0]);
    std::cout << "Vertice opposto a 2 lungo l'arco (" << edges[0].vertex1_ID
              << ", " << edges[0].vertex2_ID << ") è " << opp << std::endl;

    // Esegue la BFS
    std::cout << "Esecuzione della BFS a partire dal vertice 1:" << std::endl;
    g.BFS(1);

  } catch (const std::exception &ex) {
    std::cerr << "Errore: " << ex.what() << std::endl;
  }

  return 0;
}