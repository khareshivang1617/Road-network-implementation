#include <iostream>

using namespace std;

class edge
{
	private:
		int index_v1;
		int index_v2;
		float road_length;
		
	public:
		edge(int v1,int v2,float rl);
		
		int get_v1();
		
		int get_v2();
		
		int get_road_length();
};
