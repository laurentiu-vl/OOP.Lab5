#include "HTML.h"

using namespace std;

string HTML::write_watchlist_in_file(vector<Film> v)
{
	ofstream myfile;
	myfile.open("watchlist.html");

	myfile << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<style>\ntable,th,td {\npadding:10px;\nborder:1px solid black;\nborder-collapse: collapse;\n}\n</style>\n\n<body>\n<table>\n<tr>\n<td>Title</td>\n<td>Genre</td>\n<td>Year</td>\n<td>Likes</td>\n<td>Trailer</td>\n</tr>\n";
	for (int i = 0; i < v.size(); i++)
		myfile << "<tr>\n<td>" << v[i].get_titel() << "</td>\n<td>" << v[i].get_genre() << "</td>\n<td>" << v[i].get_jahr() << "</td>\n<td>" << v[i].get_anz_likes() << "</td>\n<td><a href=" << v[i].get_trailer() << ">Link</a>\n</td>\n</tr>\n";
	myfile << "</table>\n</body>\n</html>\n";
	myfile.flush();
	myfile.close();
	return "watchlist.html";
}