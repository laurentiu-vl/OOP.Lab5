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

vector<Film> Repository::list_films()
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

//void Repository::edit(Film f) 
//{  
//    cout << "Ce se modifica:" << endl;
//    cout << "1: Titlul" << endl << "2: Anul" << endl << "3: Genul" << endl << "4: Nr likes" << endl;
//    cout << "0: Exit" << endl << "Alegeti o tasta: ";
//    int x; cin >> x;
//    if (x == 0)
//        return;
//    while (x != 0) 
//    {
//        if (x == 1)
//        {       
//            cout << "Titlu nou: ";
//            string n;   cin >> n;
//
//            for (auto& i : this->data) 
//            {
//                if (i.get_titel() == f.get_titel() &&
//                    i.get_jahr() == f.get_jahr())
//                {       
//                    f.set_titel(n);
//                    cout << " Titlu schimbat" << endl << endl;
//                }
//            }
//
//        }
//        else if (x == 2)
//        {     
//            cout << "Anul nou: "; int k;
//            cin >> k;
//            for (auto& i : this->data)
//            {
//                if (i.get_titel() == f.get_titel() &&
//                    i.get_jahr() == f.get_jahr())
//                {        
//                    i.set_jahr(k);                                                      
//                    f.set_jahr(k);
//                    cout << " An schimbat" << endl << endl;
//
//                }
//            }
//        }
//        else if (x == 3) 
//        {      
//            cout << "Genul nou: "; string gen;
//            cin >> gen;
//            for (auto& i : this->data)
//            {
//                if (i.get_titel() == f.get_titel() &&
//                    i.get_jahr() == f.get_jahr()) 
//                {        
//                    f.set_genre(gen);
//                    cout << " Gen schimbat" << endl << endl;
//
//                }
//            }
//        }
//        else if (x == 4)
//        {       
//            cout << " Nr likes: "; int n; cin >> n;
//            for (auto& i : this->data)
//            {
//                if (i.get_titel() == f.get_titel() &&
//                    i.get_jahr() == f.get_jahr())
//                {        /// gasesc filmul respectiv in lista
//                    i.set_anz_likes(n);                                                  
//                    f.set_anz_likes(n);
//                    cout << "Numar schimbat" << endl << endl;
//                }
//            }
//        }
//        cout << "Mai modificati ceva?" << endl;
//        cout << "1: Titlul" << endl << "2: Anul" << endl << "3: Genul" << endl << "4: Nr likes" << endl;
//        cout << "0: Exit" << endl << "Alegeti o tasta: ";
//        cin >> x;
//    }
//}

/*
void Repository::suchen(User* watchliste) 
{  
    cout << "Gen: ";
    string gen;
    cin.get();
    getline(std::cin, gen);  
    cout << endl;

    if (gen.empty()) 
    {  /// daca nu se trece niciun gen, se afiseaza toate filmele
        for (auto i = this->data.begin(); i < this->data.end(); i++) 
        {
            cout << i->get_titel() << " " << i->get_jahr() << " " << i->get_genre() << " " << i->get_anz_likes();
            cout << endl;
        }
    }
    else
    {  
        bool found = false;
        auto i = this->data.begin();
        bool go = true;

        while (i != this->data.end() && go)
        {        /// se afiseaza cate un film din genul respectiv
            if (i->get_genre() == gen) 
            {
                found = true;
                cout << i->get_titel() << " " << i->get_jahr() << " " << i->get_genre() << " " << i->get_anz_likes();
                cout << endl;

                system(string("start " + i->get_trailer()).c_str());    /// afisez trailerul

                cout << "Daca va place si doriti sa-l adaugati in watchlist apasati tasta 1, daca nu 0" << endl;
                int x;
                cin >> x;
                if (x == 1) 
                {
                    Film f = Film(i->get_titel(), i->get_genre(), i->get_jahr(), i->get_anz_likes(), i->get_trailer());
                    watchliste->add(f); /// il adaug in watchlist
                }
                cout << "0. Stop searching" << endl << "1. Next movie" << endl;
                cin >> go;
            }
            i++;
        }
        if (!found) 
        {
            cout << "Niciun film de genul acesta !" << endl;
        }
    }
}
*/

bool Repository::increment(Film f)
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

Repository::~Repository() = default;