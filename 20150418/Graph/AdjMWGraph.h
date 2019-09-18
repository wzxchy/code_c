#include "SeqList.h"		//������̬����ṹ��˳�����
const int MaxVertices=100;
const int MaxWeight=10000;
const int MaxQueueSize=100;
typedef char VerT;
typedef char DataType; 
class AdjMWGraph
{
private:
	SeqList Vertices;			//����˳���
	int Edge[MaxVertices][MaxVertices];	//��Ȩֵ����
	int numOfEdges;			//�ߵĸ���?
	void DepthFirstSearch(const int v, int visited[], void Visit(VerT item));
	void DepthFirstSearch2(const int v, int visited[], void Visit(VerT item));
	void BroadFirstSearch(const int v, int visited[], void Visit(VerT item));
public:
	AdjMWGraph(const int sz = MaxVertices);	//���캯��
	~AdjMWGraph(void){};			//��������?
	int NumOfVertices(void) {return Vertices.Size();} 	//ȡ�������
	int NumOfEdges(void) {return numOfEdges;}	//ȡ�ߵĸ���
	VerT GetValue(const int v);			//ȡ������ֵ
	int GetWeight(const int v1, const int v2);		//ȡ�ߵ�Ȩֵ?
	void InsertVertex(const VerT &vertex);		//���붥��
	void InsertEdge(const int v1, const int v2, int weight);//�����
	void DeleteVertex(const int v);			//ɾ������
	void DeleteEdge(const int v1, const int v2);	//ɾ����
	int GetFirstNeighbor(const int v);		//ȡ��һ���ڽӶ���
   	int GetNextNeighbor(const int v1, const int v2);	//ȡ��һ���ڽӶ���?
    void DepthFirstSearch(void Visit(VerT item));	//������ȱ���
   	void BroadFirstSearch(void Visit(VerT item));	//������ȱ���
}; 