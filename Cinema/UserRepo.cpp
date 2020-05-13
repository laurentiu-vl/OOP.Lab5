#include "UserRepo.h"
#include <iostream>

using namespace std;

bool UserWatchlist::watchlist_add(Film f)  /// movie in watchlist added
{
    bool found = true;
    for (auto i = this->watchlist.begin(); i < this->watchlist.end(); i++)
    {

        if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr())
        {
            //cout << "Filmul exista deja in watchlist" << endl << endl;
            found = false;

        }
    }
    if (found)
    {
        this->watchlist.push_back(f);
        //cout << "Film adaugat in watchlist" << endl << endl;

    }
    return found;
}

bool UserWatchlist::watchlist_delete(Film f1) /// deletes movie from watchlist
{    
    if (this->watchlist.empty())
        return false;
    else 
    {
        bool found = false;
        for (auto i = this->watchlist.begin(); i < this->watchlist.end(); i++)
        {
            if (i->get_titel() == f1.get_titel() && i->get_jahr() == f1.get_jahr())   /// if found in watchlist
            { 
                this->watchlist.erase(i);                                                /// deleted
                //cout << "Film sters din watchlist" << endl << endl;
                found = true;
                return found;
                break;
            }
        }
        if (!found)
        {
            //cout << "Filmul nu se afla in lista" << endl << endl;
            return false;
        }
    }
}

vector <Film> UserWatchlist::watchlist_show() /// show watchlist
{   
    vector <Film> to_show;

    if (this->watchlist.empty()) /// if ->nimic
        cout << " Lista goala!" << endl << endl;
    else
        for (auto i = this->watchlist.begin(); i < this->watchlist.end(); i++)
        {
            cout << i->get_titel() << "t\Year: " << i->get_jahr() << "\tGenre: " << i->get_genre() << "\t" << i->get_anz_likes() << " likes";
            cout << endl;
            to_show.push_back(*i);
            
        }
    return to_show;
}