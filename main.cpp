#include <iostream>
#include <fstream>
#include <vector>
#include "vertex.h"
#include "edge.h"
#include "pathlen.h"
#include "printpath.h"

using namespace std;


int main()
{
	ifstream fin;
	fin.open("capitals.txt");
	
	string str;
	
	vector <vertex*> vertices;
	
	while (fin>>str)
	{
		bool is_new=true;
		for (int i=0; i<vertices.size(); i++)
			if (vertices[i]->get_city_name()==str)
			{
				is_new=false;
				break;
			}
			
		if (is_new)
		{
			vertex *temp = new vertex(str);
			vertices.push_back(temp);
		}
		
		getline(fin,str);
	}
	
	cout<<endl<<"List of all cities with index number: "<<endl<<endl;
	
	for (int i=0; i<vertices.size(); i++)
		cout<<i+1<<") "<<vertices[i]->get_city_name()<<endl;
	
	fin.close();
	fin.open("capitals.txt");
	
	int n=vertices.size();
	
	edge *graph[28][28];
	n=28;
	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			graph[i][j]=NULL;
	
	string v1,v2;
	float dist;
	
	while (fin>>v1)
	{
		fin>>v2;
		fin>>dist;
		
		int i1,i2;
		
		for (int i=0; i<n; i++)
		{
			if (vertices[i]->get_city_name()==v1)
				i1=i;
				
			else if (vertices[i]->get_city_name()==v2)
				i2=i;
		}
		
		edge* temp_edge = new edge(i1,i2,dist);
		graph[i1][i2]=temp_edge;
	}
	
/*	cout<<endl<<"Edge list : "<<endl;
	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (graph[i][j])
			{
				cout<<vertices[graph[i][j]->get_v1()]->get_city_name()<<" "<<vertices[graph[i][j]->get_v2()]->get_city_name()<<" "<<graph[i][j]->get_road_length()<<endl;
			}
*/	
	
	fin.close();
	
	
	int choice;
	choice=-1;
	while (choice)
	{
		bool to_break=false;
		
		cout<<endl<<"Now Choose : "<<endl<<endl;
	
		cout<<"1 : To find the minimum distance between two cities."<<endl;
		cout<<"2 : To find the minimum path between two cities"<<endl;
		cout<<"0 : To exit!!!"<<endl;
		cin>>choice;
	
		switch (choice)
		{
			case 1: 
			{
				cout<<"Enter city names : "<<endl;
				string city1,city2;
				cin>>city1>>city2;
					
				int i1=-1,i2=-1;
				for (int i=0; i<n; i++)
				{
					if (vertices[i]->get_city_name()==city1)
						i1=i;
					
					else if (vertices[i]->get_city_name()==city2)
						i2=i;
				}
		
				if (i1==-1 || i2==-1)
					cout<<endl<<"Invalid names!!!"<<endl;

				else
					cout<<find_path_length(i1,i2,graph)<<endl;
				break;
			}
			
			case 2:
			{
				cout<<"Enter city names : "<<endl;
				string city1,city2;
				cin>>city1>>city2;
					
				int i1=-1,i2=-1;
				for (int i=0; i<n; i++)
				{
					if (vertices[i]->get_city_name()==city1)
						i1=i;
					
					else if (vertices[i]->get_city_name()==city2)
						i2=i;
				}
		
				if (i1==-1 || i2==-1)
					cout<<endl<<"Invalid names!!!"<<endl;

				else
					print_path(i1,i2,graph,vertices);
				break;
			}
			
			case 0:
			{
				to_break=true;
				break;
			}
		}
		
		if (to_break)
			break;
	}
	
	return 0;
}

