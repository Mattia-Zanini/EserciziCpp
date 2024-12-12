#include <iostream>
#include <vector>

// Classe che rappresenta un vertice nel grafo
class Vertex {
public:
  int ID; // Identificatore univoco del vertice
  bool visited = false;

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
  Vertex *const get_vertex(int vertex_id) {
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices[i].ID == vertex_id)
        return &vertices[i];
    }

    return nullptr;
  }

  // Inserisce un nuovo vertice nel grafo
  void insert_vertex(int id) {
    // Controlla se il vertice esiste già
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices[i].ID == id)
        throw std::invalid_argument("Il vertice esiste già.");
    }
    // Aggiunge il vertice alla lista
    vertices.push_back(Vertex(id));
  }

  // Inserisce un nuovo arco tra due vertici
  void insert_edge(int v1, int v2) {
    // Verifica che l'arco non formi un loop
    if (v1 == v2)
      throw std::invalid_argument("I loop non sono permessi.");

    // Verifica che entrambi i vertici esistano nel grafo
    bool v1_exists = false, v2_exists = false;
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices[i].ID == v1)
        v1_exists = true;
      if (vertices[i].ID == v2)
        v2_exists = true;

      // entrambi esistono, non serve continuare a cercare
      if (v1_exists && v2_exists)
        break;
    }

    if (!v1_exists || !v2_exists)
      throw std::invalid_argument("Uno o entrambi i vertici non esistono.");

    // Controlla se l'arco esiste già
    Edge new_edge(v1, v2);
    for (int i = 0; i < edges.size(); i++)
      if (edges[i] == new_edge)
        throw std::invalid_argument("L'arco esiste già.");

    // Aggiunge l'arco alla lista
    edges.push_back(new_edge);
  }

  // Restituisce un vettore di archi incidenti a un dato vertice
  const std::vector<Edge> incidentEdges(Vertex v) const {
    std::vector<Edge> incident;
    // Verifica ogni arco per determinare se è connesso al vertice
    for (int i = 0; i < edges.size(); i++)
      if (edges[i].vertex1_ID == v.ID || edges[i].vertex2_ID == v.ID)
        incident.push_back(edges[i]);

    return incident;
  }

  // Restituisce il vertice opposto a quello dato lungo un arco specifico
  Vertex *const opposite(Vertex v, const Edge &e) {
    if (e.vertex1_ID == v.ID)
      return get_vertex(e.vertex2_ID);
    else if (e.vertex2_ID == v.ID)
      return get_vertex(e.vertex1_ID);
    else
      throw std::invalid_argument("Il vertice non fa parte dell'arco.");
  }

  // Stampa i vertici e gli archi del grafo
  void print_graph() const {
    std::cout << "Vertici: ";
    for (int i = 0; i < vertices.size(); i++)
      std::cout << vertices[i].ID << " ";

    std::cout << "\nArchi: ";
    for (int i = 0; i < edges.size(); i++) {
      std::cout << "(" << edges[i].vertex1_ID << ", " << edges[i].vertex2_ID
                << ") ";
    }
    std::cout << std::endl;
  }

  // Ricerca in ampiezza (BFS) partendo da un dato vertice
  void BFS() {
    // Vettore che funge da lista per la BFS
    std::vector<Vertex> toVisit;

    // Segna il vertice di partenza come visitato e lo aggiunge al vettore di
    // visita
    toVisit.push_back(vertices.front());
    vertices.front().visited = true;

    // Esegue la BFS
    for (int i = 0; i < toVisit.size(); i++) {
      Vertex current = toVisit[i];
      // Processa il vertice corrente (stampa per dimostrazione)
      std::cout << "Vertice visitato: " << current.ID << std::endl;
      // Ottiene tutti gli archi incidenti al vertice corrente
      const std::vector<Edge> incident = incidentEdges(current);

      for (int j = 0; j < incident.size(); j++) {
        Vertex *const neighbor = opposite(current, incident[j]);

        // Se il vicino non è stato visitato, lo segna e lo aggiunge al vettore
        // di visita
        if ((*neighbor).visited == false) {
          (*neighbor).visited = true;
          toVisit.push_back((*neighbor));
        }
      }
    }
  }

  bool is_connected() {
    for (int i = 0; i < vertices.size(); i++)
      if (vertices[i].visited == false)
        return false;

    return true;
  }
};

int main() {
  Graph g;

  try {
    // Inserisce i vertici
    g.insert_vertex(0);
    g.insert_vertex(2);
    g.insert_vertex(30);
    g.insert_vertex(4);
    g.insert_vertex(5);

    // Inserisce gli archi
    g.insert_edge(0, 2);
    g.insert_edge(2, 30);
    g.insert_edge(5, 4);

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
    Vertex *opp = g.opposite(2, edges[0]);
    std::cout << "Vertice opposto a 2 lungo l'arco (" << edges[0].vertex1_ID
              << ", " << edges[0].vertex2_ID << ") è " << (*opp).ID
              << std::endl;

    // Esegue la BFS
    std::cout << "Esecuzione della BFS a partire dal primo vertice"
              << std::endl;
    g.BFS();

  } catch (const std::exception &ex) {
    std::cerr << "Errore: " << ex.what() << std::endl;
  }

  std::cout << "G è un grafo connesso? " << g.is_connected() << std::endl;

  return 0;
}