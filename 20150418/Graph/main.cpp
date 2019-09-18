#include <iostream>
#include <stdlib.h>
#include "AdjMWGraph.h"
#include "CreatAdjMWGraph.h"
using namespace std;
void Printchar(char item)
{
	cout<<item<<" ";
}
int main()
{
	AdjMWGraph g;
	char a[]={'A','B','C','D','E'};
	RowColWeight rcw[]={{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
	int n=5,e=5;
	CreatGraph(g,a,n,rcw,e);
	g.DepthFirstSearch(Printchar);
	return 0;
}