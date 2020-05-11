#include "admin.h"
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

void Repository::ansehen()
{ 
    for (auto i = this->data.begin(); i < this->data.end(); i++) 
    {
        cout << i->get_titel() << "\tYear: " << i->get_jahr() << "\tGenre: " << i->get_genre() << "\t" << i->get_anz_likes() << " likes";
        cout << endl;
    }
}

void Repository::add(Film f) 
{   
    bool found = false;
    for (auto i = this->data.begin(); i < this->data.end(); i++) 
    {
        if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr())
        {
            cout << "Filmul exista deja in lista" << endl << endl;
            found = true;
        }
    }
    if (!found) 
    {
        this->data.push_back(f);
        cout << "Film adaugat" << endl;
    }
}

void Repository::del(Film f)
{   
    bool found = false;
    for (auto i = this->data.begin(); i < this->data.end() ; i++)
    {
        if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr())
        {
            this->data.erase(i);
            cout << "Film sters din lista" << endl << endl;
            found = true;
            break;

        }
    }
        if (!found)
        {
            cout << "Filmul nu se afla in lista" << endl << endl;
        }
}

void Repository::edit(Film f) 
{  
    cout << "Ce se modifica:" << endl;
    cout << "1: Titlul" << endl << "2: Anul" << endl << "3: Genul" << endl << "4: Nr likes" << endl;
    cout << "0: Exit" << endl << "Alegeti o tasta: ";
    int x; cin >> x;
    if (x == 0)
        return;
    while (x != 0) 
    {
        if (x == 1)
        {       
            cout << "Titlu nou: ";
            string n;   cin >> n;

            for (auto& i : this->data) 
            {
                if (i.get_titel() == f.get_titel() &&
                    i.get_jahr() == f.get_jahr())
                {       
                    f.set_titel(n);
                    cout << " Titlu schimbat" << endl << endl;
                }
            }

        }
        else if (x == 2)
        {     
            cout << "Anul nou: "; int k;
            cin >> k;
            for (auto& i : this->data)
            {
                if (i.get_titel() == f.get_titel() &&
                    i.get_jahr() == f.get_jahr())
                {        
                    i.set_jahr(k);                                                      
                    f.set_jahr(k);
                    cout << " An schimbat" << endl << endl;

                }
            }
        }
        else if (x == 3) 
        {      
            cout << "Genul nou: "; string gen;
            cin >> gen;
            for (auto& i : this->data)
            {
                if (i.get_titel() == f.get_titel() &&
                    i.get_jahr() == f.get_jahr()) 
                {        
                    f.set_genre(gen);
                    cout << " Gen schimbat" << endl << endl;

                }
            }
        }
        else if (x == 4)
        {       
            cout << " Nr likes: "; int n; cin >> n;
            for (auto& i : this->data)
            {
                if (i.get_titel() == f.get_titel() &&
                    i.get_jahr() == f.get_jahr())
                {        /// gasesc filmul respectiv in lista
                    i.set_anz_likes(n);                                                  
                    f.set_anz_likes(n);
                    cout << "Numar schimbat" << endl << endl;
                }
            }
        }
        cout << "Mai modificati ceva?" << endl;
        cout << "1: Titlul" << endl << "2: Anul" << endl << "3: Genul" << endl << "4: Nr likes" << endl;
        cout << "0: Exit" << endl << "Alegeti o tasta: ";
        cin >> x;
    }
}

void Repository::suchen(UserController* watchliste) 
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


void Repository::increment(Film f)
{
    /// daca atunci cand userul sterge un film din watchlist doreste sa-i dea nota, se incrementeaza nr de like-uri al filmului
    for (auto i = this->data.begin(); i < this->data.end(); i++)
    {
        if (i->get_titel() == f.get_titel() && i->get_jahr() == f.get_jahr())
        {
            i->set_anz_likes(i->get_anz_likes() + 1);
            cout << "Numarul de like-uri a fost incrementat" << endl << endl;
        }
    }
}

Repository::~Repository() = default;