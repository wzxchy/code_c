struct RowColWeight
{
	int row;				//���±�
	int col;				//���±�
	int weight;			//Ȩֵ
};
void CreatGraph(AdjMWGraph &G, DataType V[], int n,RowColWeight E[],int e)
{
	//��ͼG�в���n������
	for(int i = 0; i < n; i++) 
		G.InsertVertex(V[i]);
	//��ͼG�в���e����
	for(int k = 0; k < e; k++) 
		G.InsertEdge(E[k].row, E[k].col, E[k].weight);
}