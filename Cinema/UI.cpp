#include "UI.h"
#include "Controller.h"

UI::UI() = default;
UI::~UI() = default;

void UI::program() 
{
    Repository repo = Repository();       /// repo
    UserController watchlist = UserController();    /// watchlist of user

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

    repo.add(f1); repo.add(f2); repo.add(f3); repo.add(f4); repo.add(f5); repo.add(f6); repo.add(f7); repo.add(f8); repo.add(f9);
    repo.add(f10);

    cout << endl << endl;

    cout << "0. Exit" << endl << "1. User Menu" << endl << "2. Admin Menu" << endl;
    int opt; cin >> opt;
    while (opt)
    {
        if (opt == 1)
        {
            cout << "User Menu" << endl << "0. Exit" << endl << "1. Search by genre" << endl << "2. Show watchlist" << endl << "3. Delete from watchlist" << endl << "4. Add movie to watchlist" <<endl ;
            int u;
            cout << "Option: ";
            cin >> u;
            while (u)
            {
                Controller().comandauser(u, &repo, &watchlist);
                cout << "User Menu" << endl << "0. Exit" << endl << "1. Search by genre" << endl << "2. Show watchlist" << endl << "3. Delete from watchlist" << endl <<"4. Add film to watchlist" << endl;
                cout << "Option: ";
                cin >> u;
            }
        }
        else if (opt == 2)
        {
            cout << "Admin Menu" << endl << "0. Exit" << endl << "1. Add Film" << endl << "2. Delete Film" << endl << "3. Edit Film" << endl << "4. Show list" << endl;
            int u;
            cout << "Option: ";
            cin >> u;
            while (u) 
            {
                Controller().comandaadmin(u, &repo, &watchlist);
                cout << "Admin Menu" << endl << "0. Exit" << endl << "1. Add Film" << endl << "2. Delete Film" << endl << "3. Edit Film" << endl << "4. Show list" << endl;
                cout << "Option: ";
                cin >> u;
            }
        }
        cout << endl << endl;
        cout << "0. Exit" << endl << "1. User Menu" << endl << "2. Admin Menu" << endl;
        cin >> opt;
    }
}