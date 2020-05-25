#include "HTML.h"

using namespace std;

HTML::HTML()
{

}

string HTML::write_watchlist_in_file(vector<Film> v)
{
	auto filename = string("C:\\temp\\watchlist.html");
	ofstream html(filename, ios::out || ios::trunc);
	
	//html.open(filename, ofstream::out || ofstream::trunc);

	html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<body>\n<table style='align='center''>\n<tr style='font-weight:bold'>\n<td>Title</td>\n<td>Genre</td>\n<td>Releaseyear</td>\n<td>Likes</td>\n<td>Trailer link</td>\n</tr>\n";
	for (int i = 0; i < v.size(); i++)
		html << "<tr>\n<td>" << v[i].get_titel() << "</td>\n<td>" << v[i].get_genre() << "</td>\n<td>" << v[i].get_jahr() << "</td>\n<td>" << v[i].get_anz_likes() << "</td>\n<td><a href=" << v[i].get_trailer() << ">Link</a>\n</td>\n</tr>\n";
	html << "</table>\n</body>\n</html>\n";
	html.flush();
	html.close();
	return filename;
}