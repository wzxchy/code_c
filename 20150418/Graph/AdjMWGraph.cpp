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
		cout << "����vԽ�����!" << endl;
		exit(0);
	}
	return Vertices.GetData(v);
}
int AdjMWGraph::GetWeight(const int v1, const int v2)
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "����v1��v2Խ�����!" << endl;
		exit(0);
	}
	return Edge[v1][v2];
}
void AdjMWGraph::InsertVertex(const VerT &vertex)
{
	//�Ѷ���vertex���뵽˳����ĵ�ǰ��βλ��
	Vertices.Insert(vertex, Vertices.Size());
}
void AdjMWGraph::InsertEdge(const int v1, const int v2, int weight)
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "����v1��v2Խ�����!" << endl;
		exit(0);
	}
	Edge[v1][v2] = weight;			//�����
	numOfEdges++;			//�ߵĸ�����1
}
void AdjMWGraph::DeleteVertex(const int v)
{
	//ɾ�����а�������v�ı�
	for(int i = 0; i < Vertices.Size(); i++)
		for(int j = 0; j < Vertices.Size(); j++)
			if((i == v || j == v) && i != j && Edge[i][j] > 0 
					&& Edge[i][j] < MaxWeight) 
			{
			        Edge[i][j] = MaxWeight;  //�Ѹñߵ�Ȩֵ��Ϊ�����
			        numOfEdges--;		//�ߵĸ�����1
			}
	Vertices.Delete(v);		//ɾ������v
}
void AdjMWGraph::DeleteEdge(const int v1, const int v2)
{
	if(v1 < 0 || v1 > Vertices.Size() ||
		v2 < 0 || v2 > Vertices.Size() || v1 == v2)
	{
		cout << "����v1��v2����!" << endl;
		exit(0);
	}
	if(Edge[v1][v2] == MaxWeight || v1 == v2)
	{
		cout << "�ñ߲�����!" << endl;
		exit(0);
	}
	Edge[v1][v2] = MaxWeight;	//�Ѹñߵ�Ȩֵ��Ϊ�����
	numOfEdges--;			//�ߵĸ�����1
}
int AdjMWGraph::GetFirstNeighbor(const int v)
{
	if(v < 0 || v > Vertices.Size())
	{
		cout << "����v1Խ�����!" << endl;
		exit(0);
	}
	for(int col = 0; col <= Vertices.Size(); col++)
		if(Edge[v][col] > 0 && Edge[v][col] < MaxWeight) 					return col;
	return -1;
}
int AdjMWGraph::GetNextNeighbor(const int v1, const int v2)
//�����ڷ��ظö�����±���ţ����򷵻�-1
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "����v1��v2Խ�����!" << endl;
		exit(0);
	}
	for(int col = v2+1; col <= Vertices.Size(); col++)
		if(Edge[v1][col] > 0 && Edge[v1][col] < MaxWeight) 
			return col;
	return -1;
}
void AdjMWGraph::DepthFirstSearch(const int v, int visited[], void Visit(VerT item))
{
	Visit(GetValue(v));			//���ʸö���
	visited[v] = 1;				//���ѷ��ʱ��
	int w = GetFirstNeighbor(v);		//ȡ��һ���ڽӶ���
	while(w != -1)				//���ڽӶ������ʱѭ��
	{
		if(! visited[w]) DepthFirstSearch(w, visited, Visit);          //�ݹ�
		w = GetNextNeighbor(v, w);	//ȡ��һ���ڽӶ���
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
		visited[i] = 0;		//��ʼ�����ʱ��
	for(i = 0; i < NumOfVertices(); i++)
		if(! visited[i]) 
			DepthFirstSearch2(i, visited, Visit);//������ȱ���
	delete []visited;
}
