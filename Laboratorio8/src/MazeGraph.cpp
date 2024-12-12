#include "../include/MazeGraph.h"
#include <vector>

Vertex::Vertex(int id) : ID(id) { visited = false; }
bool Vertex::operator==(const Vertex &other) const { return ID == other.ID; }

Edge::Edge(int v1, int v2) : vertex1_ID(v1), vertex2_ID(v2) {}
bool Edge::operator==(const Edge &other) const {
  return (vertex1_ID == other.vertex1_ID && vertex2_ID == other.vertex2_ID) ||
         (vertex1_ID == other.vertex2_ID && vertex2_ID == other.vertex1_ID);
}

MazeGraph::MazeGraph() {
  is_graph_updated = false;
  is_graph_connected = false;
}

Vertex *const MazeGraph::get_vertex(int vertex_id) {
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].ID == vertex_id)
      return &vertices[i];
  }

  return nullptr;
}

void MazeGraph::insert_vertex(int id) {
  // Controlla se il vertice esiste già
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].ID == id)
      return; // Il vertice esiste già
  }
  // Aggiunge il vertice alla lista
  vertices.push_back(Vertex(id));
  is_graph_updated = true;
}

void MazeGraph::insert_edge(int v1, int v2) {
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
      return; // L'arco esiste già

  // Aggiunge l'arco alla lista
  edges.push_back(new_edge);
  is_graph_updated = true;
}

const std::vector<Edge> MazeGraph::incidentEdges(Vertex v) const {
  std::vector<Edge> incident;
  // Verifica ogni arco per determinare se è connesso al vertice
  for (int i = 0; i < edges.size(); i++)
    if (edges[i].vertex1_ID == v.ID || edges[i].vertex2_ID == v.ID)
      incident.push_back(edges[i]);

  return incident;
}

Vertex *const MazeGraph::opposite(Vertex v, const Edge &e) {
  if (e.vertex1_ID == v.ID)
    return get_vertex(e.vertex2_ID);
  else if (e.vertex2_ID == v.ID)
    return get_vertex(e.vertex1_ID);
  else
    throw std::invalid_argument("Il vertice non fa parte dell'arco.");
}

/*void MazeGraph::print_graph() const {
  std::cout << "Vertici: ";
  for (int i = 0; i < vertices.size(); i++)
    std::cout << vertices[i].ID << " ";

  std::cout << "\nArchi: ";
  for (int i = 0; i < edges.size(); i++) {
    std::cout << "(" << edges[i].vertex1_ID << ", " << edges[i].vertex2_ID
              << ") ";
  }
  std::cout << std::endl;
}*/

bool MazeGraph::BFS(int startVertex, int endVertex) {
  // Vettore che funge da lista per la BFS
  std::vector<Vertex> toVisit;

  // Segna il vertice di partenza come visitato e lo aggiunge al vettore di
  // visita
  Vertex *const s = get_vertex(startVertex);
  Vertex *const e = get_vertex(endVertex);
  if (s == nullptr || e == nullptr)
    throw std::invalid_argument("Uno dei due vertici non fa parte del grafo");

  toVisit.push_back((*s));

  // Esegue la BFS
  for (int i = 0; i < toVisit.size(); i++) {
    Vertex current = toVisit[i];

    // Se il vertice corrente è il vertice di destinazione, esiste un cammino
    if (current.ID == endVertex)
      return true;

    // Ottiene tutti gli archi incidenti al vertice corrente
    const std::vector<Edge> incident = incidentEdges(current);

    for (int j = 0; j < incident.size(); j++) {
      Vertex *const neighbor = opposite(current, incident[j]);

      // Se il vicino non è stato visitato, lo segna e lo aggiunge
      // alla lista di visita
      if ((*neighbor).visited == false) {
        (*neighbor).visited = true;
        toVisit.push_back((*neighbor));
      }
    }
  }

  // Se il BFS termina senza trovare il vertice di destinazione, non esiste un
  // cammino
  return false;
}