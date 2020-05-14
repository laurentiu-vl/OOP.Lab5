#include <iostream>
#include "Controller.h"
#include "Repo.h"
#include "UserRepo.h"

Controller::Controller(UserWatchlist UserRepo, Repository Repo)
{
     this->UserRepo = UserRepo;
     this->Repo = Repo;
}

Controller::Controller() = default;

Controller::~Controller() = default;

/*
void Controller::comandaadmin(int i, Repository * rep, User * watchliste) /// admin menu
{    
    if (i == 1)    /// add in repo
    {
        string title, genre, trailer; ////////////////////
        int year, nrlikes;
        cout << "Title: "; cin >> title;
        cout << "Genre: "; cin >> genre;
        cout << "Year: "; cin >> year;
        cout << "Number of likes: "; cin >> nrlikes;
        cout << endl;
        Film f = Film(title, genre, year, nrlikes, trailer);
        rep->add(f);
    }
    else if (i == 2)  /// delete in repo
    {
        string title; int year;
        cout << "Title: "; cin >> title;
        cout << "Year: "; cin >> year;
        cout << endl;
        Film f = Film(title, "" , year, 0, "");
        rep->del(f);
    }
    else if (i == 3)  /// edit in repo
    {
        string title;
        int year;
        cout << "Title: "; cin >> title;
        cout << "Year: "; cin >> year;
        cout << endl;
        Film f = Film(title, "", year, 0, "");
        rep->edit(f);
    }
    else if (i == 4)  /// show from repo
    {
        rep->ansehen();
    }
}


void Controller::comandauser(int i, Repository * rep, User * watchliste) /// user menu
{     
    if (i == 1)     /// search by genre
    {
        rep->suchen(watchliste);
    }
    else if (i == 3)  /// delete
    {
        string title; int year;
        cout << "Title: "; cin >> title;
        cout << "Year: "; cin >> year;
        Film f = Film(title, "", year, 0, "");
        watchliste->del(f);
        cout << "Apreciati filmul? " << endl << "1. Da" << endl << "2. Nu" << endl;
        int x; cin >> x;
        if (x == 1)
        {   
            rep->increment(f); /// nrlikes grows if liked
        }
    }
    else if (i == 2)    /// show watchlist
    {
        watchliste->show();
    }
    else if (i == 4)
    {
        string title; int year;
        cout << "Title: "; cin >> title;
        cout << "Year: "; cin >> year;
        cout << endl;
        Film f = Film(title, "", year, 0, "");
        watchliste->add(f);
    }
}
*/

bool Controller::add_admin(Film f)
{
    if (this->Repo.add(f) == false)
        return false;
    else
        return true;
        
}

void Controller::list_films_admin()
{
    vector<Film> temp = this->Repo.list_films();
    for (auto i = temp.begin(); i < temp.end(); i++)
    {
        cout << i->get_titel() << "\tYear: " << i->get_jahr() << "\tGenre: " << i->get_genre() << "\t" << i->get_anz_likes() << " likes";
        cout << "\nTrailer: " << i->get_trailer() << endl;
        cout << "\n";
    }
}

void Controller::del_admin(Film f)
{   
    if(this->Repo.del(f) == true)
        cout << "Film sters din lista" << endl << endl;
    else
        cout << "Filmul nu se afla in lista" << endl << endl;
}

void Controller::likes_plus(Film f1)
{
    if (this->Repo.increment(f1) == true)
    {
        cout << "Numarul de like-uri a fost incrementat" << endl << endl;
    }
}


void Controller::edit_title_admin(string title, int year, string new_title)
{
    bool succes = this->Repo.edit_title(title, year, new_title);
    if (succes)
        cout << "Titlul filmului a fost modificat cu succes\n";
    else
        cout << "Filmul nu a putut fi identificat in lista cu filme";
}

void Controller::edit_year_admin(string title, int year, int new_year)
{
    bool succes = this->Repo.edit_year(title, year, new_year);
    if (succes)
        cout << "Anul filmului a fost modificat cu succes\n";
    else
        cout << "Filmul nu a putut fi identificat in lista cu filme";
}

void Controller::edit_genre_admin(string title, int year, string genre)
{
    bool succes = this->Repo.edit_genre(title, year, genre);
    if (succes)
        cout << "Genul filmului a fost modificat cu succes\n";
    else
        cout << "Filmul nu a putut fi identificat in lista cu filme";
}

void Controller::edit_trailer_admin(string title, int year, string trailer)
{
    bool succes = this->Repo.edit_trailer(title, year, trailer);
    if (succes)
        cout << "Trailerul filmului a fost modificat cu succes\n";
    else
        cout << "Filmul nu a putut fi identificat in lista cu filme";
}

void Controller::edit_nrlikes_admin(string title, int year, int likes)
{
    bool succes = this->Repo.edit_nrlikes(title, year, likes);
    if (succes)
        cout << "Numarul de like-uri ale filmului a fost modificat cu succes\n";
    else
        cout << "Filmul nu a putut fi identificat in lista cu filme";
}

void Controller::add_to_watch(Film f1)
{
    if (UserRepo.watchlist_add(f1) == false)
    {
        cout << "Filmul exista deja in watchlist" << endl << endl;
    }
    else
    {
        cout << "Film adaugat in watchlist" << endl << endl;
    }
}

void Controller::delete_from_watch(Film f1)
{
    if (UserRepo.watchlist_delete(f1) == false)
    {
        cout << "Filmul nu se afla in lista" << endl << endl;
    }
    else
    {
        cout << "Film sters din watchlist" << endl << endl;
    }
}

void Controller::show_watch()
{
    vector <Film> movies = UserRepo.watchlist_show();
    for (auto i = movies.begin(); i < movies.end(); i++)
    {
        cout << "Numele filmului: " + i->get_titel() + "\n";
        cout << "Anul aparitiei filmului: " + to_string(i->get_jahr()) + "\n";
        cout << "Genul filmului: " + i->get_genre() + "\n";
        cout << "Numarul de like-uri: " + to_string(i->get_anz_likes()) + "\n\n";
    }
}

vector <Film> Controller::movies_by_genre_to_show(string genre)
{
    vector <Film> temp = Repo.list_films();
    vector <Film> list_g = Repo.search_by_genre(genre);

    cout << "\nFilmele sunt:\n\n";
        int k = 1;

    for (auto i = list_g.begin(); i < list_g.end(); i++)
    {   
        cout << k;
        cout << ". Numele filmului: " + i->get_titel() + "\n";
        cout << "Anul aparitiei filmului: " + to_string(i->get_jahr()) + "\n";
        cout << "Genul filmului: " + i->get_genre() + "\n";
        cout << "Numarul de like-uri: " + to_string(i->get_anz_likes()) + "\n\n";
        k++;
    }

    return list_g;
}