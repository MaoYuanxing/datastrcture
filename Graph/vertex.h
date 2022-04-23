#include <climits>

enum VStatus
{
    UNDISCOVERED,
    DISCOVERED,
    VISITED
};

template <typename Tv>
struct Vertex
{ // the object of vertex
    Tv data;
    int inDegree, outDegre; //入度，出度

    //遍历算法的信息
    VStatus status;   // 状态
    int dTime, fTime; //时间标签 第一次发现，访问完毕时间
    int parent;       //树中父节点
    int priority;     //在遍历树中的优先级

    Vertex(Tv const &d) : // construct new vertex
                          data(d), inDegree(0), outDegre(0), status(UNDISCOVERED),
                          dTime(-1), fTime(-1), parent(-1), priority(INT_MAX){};
};