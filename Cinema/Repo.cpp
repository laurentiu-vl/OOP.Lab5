#include "Repo.h"
#include <iostream>

using namespace std;

Repository::Repository() 
{
    this->data = {};
}

Film Repository::get_film(int i)
{
    return data[i];
}

vector<Film> Repository::get_all_films()
{ 
    vector<Film> liste_films = {};
    for (auto i = this->data.begin(); i < this->data.end(); i++) 
    {
        Film temp = Film(i->get_titel(), i->get_genre(), i->get_jahr(), i->get_anz_likes(), i->get_trailer());
        liste_films.push_back(temp);
    }
    return liste_films;
}

bool Repository::add(Film f) 
{   
    for (auto i = this->data.begin(); i < this->data.end(); i++) 
    {
        if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr())
        {
            return false;
        }
    }
    this->data.push_back(f);
    return true;
}

bool Repository::del(Film f)
{
    for (auto i = this->data.begin(); i < this->data.end(); i++)
    {
        if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr())
        {
            this->data.erase(i);
            return true;
        }
    }
    return false;
}


vector <Film>::iterator Repository::search_a_movie(string title, int year)  /// cauta un film in repo
{
    vector <Film>::iterator i;

    for (i = this->data.begin(); i < this->data.end(); i++)
    {
        if (i->get_titel() == title && i->get_jahr() == year)
        {
            return i;
        }
    }
    return i;
}

bool Repository::edit_title(string title, int year, string new_title)
{
    auto i = search_a_movie(title, year);
    if (i == this->data.end())
        return false;
    i->set_title(new_title);
    return true;

}

bool Repository::edit_year(string title, int year, int new_year)
{
    auto i = search_a_movie(title, year);
    if (i == this->data.end())
        return false;
    i->set_jahr(new_year);
    return true;
}

bool Repository::edit_genre(string title, int year, string genre)
{
    auto i = search_a_movie(title, year);
    if (i == this->data.end())
        return false;
    i->set_genre(genre);
    return true;
}

bool Repository::edit_trailer(string title, int year, string trailer)
{
    auto i = search_a_movie(title, year);
    if (i == this->data.end())
        return false;
    i->set_trailer(trailer);
    return true;
}

bool Repository::edit_nrlikes(string title, int year, int likes)
{
    auto i = search_a_movie(title, year);
    if (i == this->data.end())
        return false;
    i->set_anz_likes(likes);
    return true;
}

bool Repository::increment_likes(Film f)
{
    /// daca atunci cand userul sterge un film din watchlist doreste sa-i dea nota, se incrementeaza nr de like-uri al filmului
    for (auto i = this->data.begin(); i < this->data.end(); i++)
    {
        if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr())
        {
            i->set_anz_likes(i->get_anz_likes() + 1);
            return true;
            //cout << "Numarul de like-uri a fost incrementat" << endl << endl;
        }
    }
    return false;
}

vector <Film> Repository::search_by_genre(string genre)
{
    //vector <Film>::iterator i;
    vector <Film> movies_by_genre_list;

    bool ok = false;

    for (auto i = this->data.begin(); i < this->data.end(); i++)
    {
        if (i->get_genre() == genre)
        {
            movies_by_genre_list.push_back(*i);
            ok = true;
        }
    }
    if (ok == false)
    {
        movies_by_genre_list = this->data;
    }

    return movies_by_genre_list;

}

void Repository::ReadFromFile()
{
    ifstream myfile;
    myfile.open("filme.txt", ios::in);
    string line;
    string title, genre, link;
    int year, nr_likes;
    vector <string> v;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            //cout << line << endl;
            v.clear();
            stringstream ss(line);
            while (getline(ss, line, ','))
            {
                v.push_back(line);
            }
            title = v[0];
            genre = v[1];
            year = stoi(v[2]);
            nr_likes = stoi(v[3]);
            link = v[4];

            Film newFilm = Film(title, genre, year, nr_likes, link);
            this->data.push_back(newFilm);
        }
    }
}

void Repository::WriteToFile()
{
    ofstream myfile;
    myfile.open("informatii.txt", ios::trunc);
    for (size_t i = 0; i < data.size(); i++)
    {
        myfile << data[i].get_titel() << "," << data[i].get_genre() << "," << data[i].get_jahr() << "," << data[i].get_anz_likes() << "," << data[i].get_trailer() << ",\n";
    }

}

Repository::~Repository() = default;