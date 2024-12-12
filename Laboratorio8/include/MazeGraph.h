#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H

#include <vector>

// Classe che rappresenta un vertice nel grafo
class Vertex {
public:
  int ID; // Identificatore univoco del vertice
  bool visited;

  Vertex(int);

  // Sovraccarico dell'operatore di uguaglianza per confrontare vertici tramite
  // ID
  bool operator==(const Vertex &) const;
};

// Classe che rappresenta un arco tra due vertici nel grafo
class Edge {
public:
  int vertex1_ID; // ID del primo vertice
  int vertex2_ID; // ID del secondo vertice

  Edge(int, int);

  // Sovraccarico dell'operatore di uguaglianza per confrontare archi
  // indipendentemente dalla direzione
  bool operator==(const Edge &) const;
};

// Classe che rappresenta il grafo utilizzando liste di vertici e archi
class MazeGraph {
private:
  std::vector<Vertex> vertices; // Lista dei vertici del grafo
  std::vector<Edge> edges;      // Lista degli archi del grafo

  bool is_graph_updated;
  bool is_graph_connected;

public:
  MazeGraph();
  Vertex *const get_vertex(int);
  // Inserisce un nuovo vertice nel grafo
  void insert_vertex(int);
  // Inserisce un nuovo arco tra due vertici
  void insert_edge(int, int);
  // Restituisce un vettore di archi incidenti a un dato vertice
  const std::vector<Edge> incidentEdges(Vertex) const;
  // Restituisce il vertice opposto a quello dato lungo un arco specifico
  Vertex *const opposite(Vertex, const Edge &);
  // Stampa i vertici e gli archi del grafo
  void print_graph() const;
  // Ricerca in ampiezza (BFS) partendo da un dato
  // vertice d'inizio e uno di fine
  bool BFS(int, int);
};

#endif