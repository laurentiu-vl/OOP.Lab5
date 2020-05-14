#include "UI.h"
#include <string>

using namespace std;

UI::UI() = default;
UI::~UI() = default;

void UI::program() 
{
    Repository repo = Repository();       /// repo

    UserWatchlist watchlist = UserWatchlist();    /// watchlist of user

    Controller controller = Controller(watchlist, repo);

    Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");
    Film f2 = Film("Inception", "Sci-Fi", 2010, 1500, "https://www.youtube.com/watch?v=YoHD9XEInc0");
    Film f3 = Film("Matrix", "Sci-Fi", 1999, 10000, "https://www.youtube.com/watch?v=m8e-FF8MsqU");
    Film f4 = Film("Godfather", "Crime", 1972, 1000, "https://www.youtube.com/watch?v=sY1S34973zA");
    Film f5 = Film("Pulp Fiction", "Crime", 1994, 500, "https://www.youtube.com/watch?v=s7EdQ4FqbhY");
    Film f6 = Film("Fight Club", "Drama", 1999, 800, "https://www.youtube.com/watch?v=qtRKdVHc-cE");
    Film f7 = Film("Heat", "Thriller", 1995, 900, "https://www.youtube.com/watch?v=2GfZl4kuVNI");
    Film f8 = Film("Casino", "Crime", 1995, 200, "https://www.youtube.com/watch?v=EJXDMwGWhoA");
    Film f9 = Film("Goodfellas", "Biography", 1990, 500, "https://www.youtube.com/watch?v=qo5jJpHtI1Y");
    Film f10 = Film("The Silence of the Lambs", "Thriller", 1991, 1000, "https://www.youtube.com/watch?v=W6Mm8Sbe__o");

    controller.add_admin(f1);
    controller.add_admin(f2);
    controller.add_admin(f3);   /// am sters din admin add cout-ul si dam cout in ui ca sa nu apara de 10 ori
    controller.add_admin(f4);
    controller.add_admin(f5);
    controller.add_admin(f6);
    controller.add_admin(f7);
    controller.add_admin(f8);
    controller.add_admin(f9);
    controller.add_admin(f10);


    int opt = -1;
    while (opt)
    {
        cout << "\n0. Exit\n" 
            << "1. User Menu\n" 
            << "2. Admin Menu\n\n"
            << "Enter Option: ";
        cin >> opt;
        if (opt == 1)
        {
            int u = -1;
            while (u)
            {
                cout << "\n\n~USER MENU~\n\n"
                    << "0. Back\n"
                    << "1. Search by genre\n"
                    << "2. Show watchlist\n"
                    << "3. Delete from watchlist\n"
                    << "4. Add movie to watchlist\n\n"
                    << "Option: ";
                cin >> u;
                if (u == 0)
                {
                    break;
                }
                else if (u == 1)
                {
                    ;
                    //controller.suchen();
                }
                else if (u == 2)
                {
                    controller.show_watch();
                   
                }
                else if (u == 3)
                {
                    string title, genre, trailer;
                    int year, nrlikes;
                    cout << "Title: "; cin >> title;
                    cout << "Genre: "; cin >> genre;
                    cout << "Year: "; cin >> year;
                    cout << "Number of likes: "; cin >> nrlikes;
                    cout << endl;
                    Film f = Film(title, genre, year, nrlikes, trailer);
                    controller.delete_from_watch(f);
                }
                else if (u == 4)
                {
                    string title, genre, trailer;
                    int year, nrlikes;
                    cout << "Title: "; cin >> title;
                    cout << "Genre: "; cin >> genre;
                    cout << "Year: "; cin >> year;
                    cout << "Number of likes: "; cin >> nrlikes;
                    cout << endl;
                    Film f = Film(title, genre, year, nrlikes, trailer);
                    controller.add_to_watch(f);
                }
                else
                {
                    cout << "\nInvalid Option! Choose a number between 0-4 !";
                }
            }

        }
        else if (opt == 2)
        {
            int a = -1;
            while (a) 
            {
                cout << "\n\n~ADMIN MENU\n\n"
                << "0. Back\n" 
                << "1. Add Film\n" 
                << "2. Delete Film\n"
                << "3. Edit Film\n"
                << "4. Show list\n\n"
                << "Option: ";
                cin >> a;
                if(a == 0)
                {
                    break;

                }
                else if(a == 1)
                {
                    string title, genre, trailer;
                    int year, nrlikes;
                    cout << "Title: "; cin >> title;
                    /*
                    while(cin.fail())
                    {
                        cout << "Invalid input! Please input a string!\n";
                        cin >> title;
			        }
                    */
                    cout << "Genre: "; cin >> genre;
                    cout << "Year: "; cin >> year;
                    cout << "Number of likes: "; cin >> nrlikes;
                    cout << endl;
                    Film f = Film(title, genre, year, nrlikes, trailer);
                    if (controller.add_admin(f) == false)
                        cout << "Filmul exista deja in lista" << endl << endl << "\n";
                    else
                        cout << "Film adaugat" << endl << "\n";


			    }
                else if(a == 2)
                {
                    string title, genre, trailer;
                    int year, nrlikes;
                    cout << "Title: "; cin >> title;
                    cout << "Genre: "; cin >> genre;
                    cout << "Year: "; cin >> year;
                    cout << "Number of likes: "; cin >> nrlikes;
                    cout << endl;
                    Film f = Film(title, genre, year, nrlikes, trailer);
                    controller.del_admin(f);
                }
                else if(a == 3)
                {
                    string title;
                    int year;
                    cout << "Title: "; cin >> title;
                    cout << "Year: "; cin >> year;
                    int edit_op = -1;
                    while (edit_op != 0)
                    {
                        cout << "What are you changing?\n";
                        cout << "0. Back\n"
                        << "1. Title\n"
                            << "2. Genre\n"
                            << "3. Year\n"
                            << "4. Likes\n"
                            << "5. Link\n"
                            << "Option: ";
                        cin >> edit_op;

                        if (edit_op == 0)
                        {
                            break;
                        }
                        else if (edit_op == 1)
                        {
                            string new_title;
                            cout << "New Title: ";
                            cin >> new_title;
                            controller.edit_title_admin(title, year, new_title);
                            break;
                        }
                        else if (edit_op == 2)
                        {
                            string new_genre;
                            cout << "New Genre:";
                            cin >> new_genre;
                            controller.edit_genre_admin(title, year, new_genre);
                            break;
                        }
                        else if (edit_op == 3)
                        {
                            int new_year;
                            cout << "New Year: ";
                            cin >> new_year;
                            controller.edit_year_admin(title, year, new_year);
                            break;
                        }
                        else if (edit_op == 4)
                        {
                            int new_likes;
                            cout << "New Number of Likes: ";
                            cin >> new_likes;
                            controller.edit_nrlikes_admin(title, year, new_likes);
                            break;
                        }
                        else if (edit_op == 5)
                        {
                            string new_trailer;
                            cout << "New Trailer: ";
                            cin >> new_trailer;
                            controller.edit_trailer_admin(title, year, new_trailer);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Option! Choose a number between 0-5 !\n";
                        }
                    }
			    }
                else if(a == 4)
                {
                cout << "\n";
                    controller.list_films_admin();
                    
                }
                else
                {
                cout << "\nInvalid Option! Choose a number between 0-4 !";
				}
            }
        }
    }
}