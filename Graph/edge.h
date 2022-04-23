#include "vertex.h"

enum EStatus
{
    UNDISCOVERED,
    TREE,
    CROSS,
    FORWARD,
    BACKWARD
};
template <typename Te>
struct Edge
{
    Te data;
    int weight;
    EStatus status;
    Edge(Te const &d, int w) : data(d), weight(w), status(UNDISCOVERED);
};