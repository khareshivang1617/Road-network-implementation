#include "vertex.h"

using namespace std;

vertex::vertex(string city)
{
	city_name=city;
}

string vertex::get_city_name()
{
	return city_name;
}

