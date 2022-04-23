#include "vertex.h"
#include "edge.h"
#include "Graph.h"
#include <vector>

template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te>
{
private:
    vector<Vertex<Tv>> V;       // the set of vertices
    vector<vector<Edge<Te>>> E; // the set of edges;

public: /* ...op of vertex,edge; the algorithm of graph;
            No matter how the interface is implemented, it must be unified*/
    GraphMatrix()
    {
        n = e = 0;
    }
    ~GraphMatrix()
    {
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
            {
                delete E[j][i];
            }
    }
};