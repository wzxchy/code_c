struct RowColWeight
{
	int row;				//行下标
	int col;				//列下标
	int weight;			//权值
};
void CreatGraph(AdjMWGraph &G, DataType V[], int n,RowColWeight E[],int e)
{
	//在图G中插入n个顶点
	for(int i = 0; i < n; i++) 
		G.InsertVertex(V[i]);
	//在图G中插入e条边
	for(int k = 0; k < e; k++) 
		G.InsertEdge(E[k].row, E[k].col, E[k].weight);
}
