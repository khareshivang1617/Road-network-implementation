#ifndef PATHLEN_H_
#define PATHLEN_H_

#include <iostream>


using namespace std;

int find_path_length(int s, int d, edge* adj[28][28])
{
	int dis[28];
	for (int i=0; i<28; i++)
	{
		dis[i]=1000000000;
	}
	
	dis[s]=0;
	
	bool vis[28];
	for (int i=0; i<28; i++)
		vis[i]=false;
	
	int curr=s;
	
	while (curr!=d)
	{
		for (int i=0; i<28; i++)
			if (!vis[i])
			{
				curr=i;
				break;
			}
			
		for (int i=curr; i<28; i++)
			if ((!vis[i])&&(dis[i]<dis[curr]))
				curr=i;
				
		vis[curr]=true;
		
		for (int i=0; i<28; i++)
			if ((adj[curr][i])&&(adj[curr][i]->get_road_length()+dis[curr]<dis[i]))
				dis[i]=adj[curr][i]->get_road_length()+dis[curr];
			
	}
	
	return dis[d];
}

#endif
