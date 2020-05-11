#include <iostream>
#include "Controller.h"

Controller::Controller() = default;

Controller::~Controller() = default;

void Controller::comandaadmin(int i, Repository * rep, UserController * watchliste) /// admin menu
{    
    if (i == 1)    /// add in repo
    {
        string title, genre, trailer;
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


void Controller::comandauser(int i, Repository * rep, UserController * watchliste) /// user menu
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