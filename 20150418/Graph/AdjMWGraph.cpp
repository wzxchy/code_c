#include "AdjMWGraph.h"
#include <iostream>
using namespace std;
AdjMWGraph::AdjMWGraph(const int sz): Vertices(sz)
{
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++)
		{
			if(i == j) Edge[i][j] = 0;
			else Edge[i][j] = MaxWeight;
		}
	numOfEdges = 0;
}
VerT AdjMWGraph::GetValue(const int v)
{
	if(v < 0 || v > Vertices.Size())
	{
		cout << "参数v越界出错!" << endl;
		exit(0);
	}
	return Vertices.GetData(v);
}
int AdjMWGraph::GetWeight(const int v1, const int v2)
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "参数v1或v2越界出错!" << endl;
		exit(0);
	}
	return Edge[v1][v2];
}
void AdjMWGraph::InsertVertex(const VerT &vertex)
{
	//把顶点vertex插入到顺序表的当前表尾位置
	Vertices.Insert(vertex, Vertices.Size());
}
void AdjMWGraph::InsertEdge(const int v1, const int v2, int weight)
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "参数v1或v2越界出错!" << endl;
		exit(0);
	}
	Edge[v1][v2] = weight;			//插入边
	numOfEdges++;			//边的个数加1
}
void AdjMWGraph::DeleteVertex(const int v)
{
	//删除所有包含顶点v的边
	for(int i = 0; i < Vertices.Size(); i++)
		for(int j = 0; j < Vertices.Size(); j++)
			if((i == v || j == v) && i != j && Edge[i][j] > 0 
					&& Edge[i][j] < MaxWeight) 
			{
			        Edge[i][j] = MaxWeight;  //把该边的权值置为无穷大
			        numOfEdges--;		//边的个数减1
			}
	Vertices.Delete(v);		//删除顶点v
}
void AdjMWGraph::DeleteEdge(const int v1, const int v2)
{
	if(v1 < 0 || v1 > Vertices.Size() ||
		v2 < 0 || v2 > Vertices.Size() || v1 == v2)
	{
		cout << "参数v1或v2出错!" << endl;
		exit(0);
	}
	if(Edge[v1][v2] == MaxWeight || v1 == v2)
	{
		cout << "该边不存在!" << endl;
		exit(0);
	}
	Edge[v1][v2] = MaxWeight;	//把该边的权值置为无穷大
	numOfEdges--;			//边的个数减1
}
int AdjMWGraph::GetFirstNeighbor(const int v)
{
	if(v < 0 || v > Vertices.Size())
	{
		cout << "参数v1越界出错!" << endl;
		exit(0);
	}
	for(int col = 0; col <= Vertices.Size(); col++)
		if(Edge[v][col] > 0 && Edge[v][col] < MaxWeight) 					return col;
	return -1;
}
int AdjMWGraph::GetNextNeighbor(const int v1, const int v2)
//若存在返回该顶点的下标序号，否则返回-1
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "参数v1或v2越界出错!" << endl;
		exit(0);
	}
	for(int col = v2+1; col <= Vertices.Size(); col++)
		if(Edge[v1][col] > 0 && Edge[v1][col] < MaxWeight) 
			return col;
	return -1;
}
void AdjMWGraph::DepthFirstSearch(const int v, int visited[], void Visit(VerT item))
{
	Visit(GetValue(v));			//访问该顶点
	visited[v] = 1;				//置已访问标记
	int w = GetFirstNeighbor(v);		//取第一个邻接顶点
	while(w != -1)				//当邻接顶点存在时循环
	{
		if(! visited[w]) DepthFirstSearch(w, visited, Visit);          //递归
		w = GetNextNeighbor(v, w);	//取下一个邻接顶点
	}
}
void AdjMWGraph::DepthFirstSearch2(const int v, int visited[], void Visit(VerT item))
{
	int s[100];
	s[0]=v;
	int top=1;
	while(top>0)
	{
		int t=s[--top];
		if(! visited[t])
		{
			Visit(GetValue(t));
			visited[t]=1;
			int i=Vertices.Size()-1;
			while(i>0)
			{
				if(Edge[t][i]>0&&Edge[t][i]<MaxWeight)  s[top++]=i;
				i--;
			}
		}
	}
}
void AdjMWGraph::DepthFirstSearch(void Visit(VerT item))
{
	int *visited = new int[NumOfVertices()];
	for(int i = 0; i < NumOfVertices(); i++) 
		visited[i] = 0;		//初始化访问标记
	for(i = 0; i < NumOfVertices(); i++)
		if(! visited[i]) 
			DepthFirstSearch2(i, visited, Visit);//深度优先遍历
	delete []visited;
}

