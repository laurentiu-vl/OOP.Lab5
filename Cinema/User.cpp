#include "user.h"
#include <iostream>
using namespace std;

UserController::UserController() 
{
    this->repo = {};
}

Film UserController::get_film(int i)
{
    return repo[i] ;
}

void UserController::del(Film f) /// deletes movie from watchlist
{    
    if (this->repo.empty())
        cout << " Lista goala!" << endl;
    else 
    {
        bool found = false;
        for (auto i = this->repo.begin(); i < this->repo.end(); i++) 
        {
            if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr())   /// if found in watchlist
            { 
                this->repo.erase(i);                                                /// deleted
                cout << "Film sters din watchlist" << endl << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Filmul nu se afla in lista" << endl << endl;
        }
    }
}

void UserController::show() /// show watchlist
{   
    if (this->repo.empty())
        cout << " Lista goala!" << endl << endl;
    else
        for (auto i = this->repo.begin(); i < this->repo.end(); i++) 
        {
            cout << i->get_titel() << "t\Year: " << i->get_jahr() << "\tGenre: " << i->get_genre() << "\t" << i->get_anz_likes() << " likes";
            cout << endl;
        }
}

void UserController::add(Film f)  /// movie in watchlist added
{    
    bool found = false;
    for (auto i = this->repo.begin(); i < this->repo.end(); i++)
    {

        if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr()) 
        {
            cout << "Filmul exista deja in watchlist" << endl << endl;
            found = true;
        }
    }
    if (!found) 
    {
        this->repo.push_back(f);
        cout << "Film adaugat in watchlist" << endl << endl;
    }

}

UserController::~UserController() = default;