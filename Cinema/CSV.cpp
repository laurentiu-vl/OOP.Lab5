#include "CSV.h"

using namespace std;

string CSV::write_watchlist_in_file(vector<Film> v)
{
	ofstream myfile;
	myfile.open("watchlist.csv");
	for (size_t i = 0; i < v.size(); i++)
	{
		myfile << v[i].get_titel() << "," << v[i].get_genre() << "," << v[i].get_jahr() << "," << v[i].get_anz_likes() << "," << v[i].get_trailer() << "\n";
	}
	return "watchlist.csv";
}