#include "edge.h"

using namespace std;


edge::edge(int v1,int v2,float rl)
{
	index_v1=v1;
	index_v2=v2;
	road_length=rl;
}
		
int edge::get_v1()
{
	return index_v1;
}
		
int edge::get_v2()
{
	return index_v2;
}
		
int edge::get_road_length()
{
	return road_length;
}
