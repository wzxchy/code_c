#include "SeqList.h"		//包含动态数组结构的顺序表类
const int MaxVertices=100;
const int MaxWeight=10000;
const int MaxQueueSize=100;
typedef char VerT;
typedef char DataType; 
class AdjMWGraph
{
private:
	SeqList Vertices;			//顶点顺序表
	int Edge[MaxVertices][MaxVertices];	//边权值数组
	int numOfEdges;			//边的个数?
	void DepthFirstSearch(const int v, int visited[], void Visit(VerT item));
	void DepthFirstSearch2(const int v, int visited[], void Visit(VerT item));
	void BroadFirstSearch(const int v, int visited[], void Visit(VerT item));
public:
	AdjMWGraph(const int sz = MaxVertices);	//构造函数
	~AdjMWGraph(void){};			//析构函数?
	int NumOfVertices(void) {return Vertices.Size();} 	//取顶点个数
	int NumOfEdges(void) {return numOfEdges;}	//取边的个数
	VerT GetValue(const int v);			//取顶点数值
	int GetWeight(const int v1, const int v2);		//取边的权值?
	void InsertVertex(const VerT &vertex);		//插入顶点
	void InsertEdge(const int v1, const int v2, int weight);//插入边
	void DeleteVertex(const int v);			//删除顶点
	void DeleteEdge(const int v1, const int v2);	//删除边
	int GetFirstNeighbor(const int v);		//取第一个邻接顶点
   	int GetNextNeighbor(const int v1, const int v2);	//取下一个邻接顶点?
    void DepthFirstSearch(void Visit(VerT item));	//深度优先遍历
   	void BroadFirstSearch(void Visit(VerT item));	//广度优先遍历
}; 
