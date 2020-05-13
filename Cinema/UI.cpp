#include "UI.h"
#include "Controller.h"
#include <string>

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

    bool useless;
    useless = controlleer->Repo.add(f1);
    useless = controller->Repo.add(f2);
    useless = controller->Repo.add(f3);
    useless = controller->Repo.add(f4);
    useless = controller->Repo.add(f5);
    useless = controller->Repo.add(f6);
    useless = controller->Repo.add(f7);
    useless = controller->Repo.add(f8);
    useless = controller->Repo.add(f9);
    useless = controller->Repo.add(f10);

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
                if(u == 0)
                {
                    break;
                }
                else if(u == 1)
                {
                    controller.suchen();
			    }
                else if(u == 2)
                {
                    controller.show_watch();
                }
                else if(u == 3)
                {
                    controller.delete_from_watch(Film);
			    }
                else if(u == 4)
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
                    cout << "\nInvalid Option! Choose a number between 0-4 !"
			    }

        }
        else if (opt == 2)
        {
            int a = -1;
            while (a) 
            {
                cout << "\n\n~ADMIN MENU\n\n"
                << "0. Exit\n" 
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
                    controller.add_admin(f);
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
                    controller.del_admin(Film f);;
                }
                else if(a == 3)
                {
                    string titel;
                    int jahr;
                    cout << "Title: "; cin >> title;
                    cout << "Genre: "; cin >> genre;

                    int edit_op = -1
                    while (edit != 0)
                    cout << "What are you changin?\n";
                    cout << "0. Exit\n";
                        << "1. Title\n" 
                        << "2. Genre\n" 
                        << "3. Year\n" 
                        << "4. Likes\n" 
                        << "5. Link\n" 
                        << "Option: ";
                    cin >> edit_op;

                    if(edit_op == 0)
                    {
                        break;
					}
                    else if (edit_op == 1)
                    {
                        string new_titel;
                        cout << "New Title: ";
                        cin >> new_titel;
                        cont.bearbeiten_titel(titel, genre, jahr, new_titel);
                    }
                    else if (mini_option == 2)
                    {
                        std::string new_genre;
                        std::cout << "What is the new genre?";
                        std::cin >> new_genre;

                        cont.bearbeiten_genre(titel, genre, jahr, new_genre);
                    }
                    else if (mini_option == 3)
                    {
                        int new_year;
                        std::cout << "What is the new year?";
                        std::cin >> new_year;

                        cont.bearbeiten_year(titel, genre, jahr, new_year);
                    }
                    else if (mini_option == 4)
                    {
                        int new_like;
                        std::cout << "What is the new number of likes?";
                        std::cin >> new_like;

                        cont.bearbeiten_likes(titel, genre, jahr, new_like);
                    }
                    else if (mini_option == 5)
                    {
                        std::string new_link;
                        std::cout << "What is the new link?";
                        std::cin >> new_link;

                        cont.bearbeiten_link(titel, genre, jahr, new_link);
                    }
                    else
                    {
                        std::cout << "You did something wrong! Please try again!" << std::endl;
                    }
                    controller.edit_admin(Film f);
			    }
                else if(a == 4)
                {
                    controller.list_films_admin();
                }
                else
                {
                    cout << "\nInvalid Option! Choose a number between 0-4 !"
				}
            }
        }
    }
}