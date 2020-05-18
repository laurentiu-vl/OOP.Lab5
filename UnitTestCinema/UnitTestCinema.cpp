#include "pch.h"
#include "CppUnitTest.h"

#include "../Cinema/Repo.h"
#include "../Cinema/Controller.h"
#include "../Cinema/Film.h"
//#include "../Cinema/UI.h"
#include "../Cinema/UserRepo.h"

#include "../Cinema/Repo.cpp"
#include "../Cinema/Controller.cpp"
#include "../Cinema/Film.cpp"
//#include "../Cinema/UI.cpp"
#include "../Cinema/UserRepo.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestCinema
{
	TEST_CLASS(Filme)
	{
	public:

		TEST_METHOD(Constructor_WITH_Setters_AND_Getters)
		{
			auto film = new Film("Six", "Comedy", 2017, 320, "viki.com");

			Assert::AreEqual(string("Six"), film->get_titel());
			Assert::AreEqual(string("Comedy"), film->get_genre());
			Assert::AreEqual(2017, film->get_jahr());
			Assert::AreEqual(320, film->get_anz_likes());
			Assert::AreEqual(string("viki.com"), film->get_trailer());

			film->set_anz_likes(100);
			film->set_genre("Action");
			film->set_jahr(2019);
			film->set_title("Seven");
			film->set_trailer("come.com");

			Assert::AreEqual(string("Seven"), film->get_titel());
			Assert::AreEqual(string("Action"), film->get_genre());
			Assert::AreEqual(2019, film->get_jahr());
			Assert::AreEqual(100, film->get_anz_likes());
			Assert::AreEqual(string("come.com"), film->get_trailer());

		}
	};

	TEST_CLASS(UnitTestCinema)
	{
	public:
		TEST_METHOD(add_to_repo)
		{
			Repository Controller;
			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			Film f2 = Film("Inception", "Sci-Fi", 2010, 1500, "https://www.youtube.com/watch?v=YoHD9XEInc0");
			Film f3 = Film("Matrix", "Sci-Fi", 1999, 10000, "https://www.youtube.com/watch?v=m8e-FF8MsqU");
			Film f4 = Film("Godfather", "Crime", 1972, 1000, "https://www.youtube.com/watch?v=sY1S34973zA");

			Assert::AreEqual(Controller.add(f1), true);
			Assert::AreEqual(Controller.add(f2), true);
			Assert::AreEqual(Controller.add(f3), true);
			Assert::AreEqual(Controller.add(f4), true);

			
		}

		TEST_METHOD(remv_to_repo)
		{
			Repository Controller;
			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			Film f2 = Film("Inception", "Sci-Fi", 2010, 1500, "https://www.youtube.com/watch?v=YoHD9XEInc0");

			Assert::AreEqual(Controller.add(f1), true);
			Assert::AreEqual(Controller.add(f2), true);

			Assert::AreEqual(Controller.del(f1), true);
			Assert::AreEqual(Controller.del(f2), true);
		}

		TEST_METHOD(like_to_movieinrepo_AND_get_film)
		{
			Repository vectorfilm;
			
			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			Film f2 = Film("Inception", "Sci-Fi", 2010, 1500, "https://www.youtube.com/watch?v=YoHD9XEInc0");

			Assert::AreEqual(vectorfilm.add(f1), true);
			Assert::AreEqual(vectorfilm.add(f2), true);

			Assert::AreEqual(vectorfilm.increment_likes(f1), true);
			vectorfilm.increment_likes(f1);
			
			Assert::AreEqual(vectorfilm.increment_likes(f2), true);
			
			Assert::AreEqual(vectorfilm.get_film(0).get_anz_likes(), 102);	// de la 100
			Assert::AreEqual(vectorfilm.get_film(1).get_anz_likes(), 1501);			
			

		
		}
		TEST_METHOD(edit_title)
		{
			Repository vectorfilm;

			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");

			Assert::AreEqual(vectorfilm.add(f1), true);

			vectorfilm.edit_title("Seven", 1995, "Eight");

			string x = "Eight";
			Assert::AreEqual(vectorfilm.get_film(0).get_titel(), x);

		}
		TEST_METHOD(edit_year)
		{
			Repository vectorfilm;

			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");

			Assert::AreEqual(vectorfilm.add(f1), true);

			vectorfilm.edit_year("Seven", 1995, 2010);

			Assert::AreEqual(vectorfilm.get_film(0).get_jahr(), 2010);
		}
		TEST_METHOD(edit_genre)
		{
			Repository vectorfilm;

			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");

			Assert::AreEqual(vectorfilm.add(f1), true);

			vectorfilm.edit_genre("Seven", 1995, "Documentar");

			string x = "Documentar";
			Assert::AreEqual(vectorfilm.get_film(0).get_genre(), x);

		}
		TEST_METHOD(edit_trailer)
		{
			Repository vectorfilm;

			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");

			Assert::AreEqual(vectorfilm.add(f1), true);

			vectorfilm.edit_trailer("Seven", 1995, "google");

			string x = "google";
			Assert::AreEqual(vectorfilm.get_film(0).get_trailer(), x);
		}
		TEST_METHOD(edit_nrlikes)
		{
			Repository vectorfilm;

			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");

			Assert::AreEqual(vectorfilm.add(f1), true);

			vectorfilm.edit_nrlikes("Seven", 1995, 200);
			Assert::AreEqual(vectorfilm.get_film(0).get_anz_likes(), 200);
		}

		TEST_METHOD(list_films)
		{
			Repository Repo;
			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			Film f2 = Film("Inception", "Sci-Fi", 2010, 1500, "https://www.youtube.com/watch?v=YoHD9XEInc0");
			Film f3 = Film("Matrix", "Sci-Fi", 1999, 10000, "https://www.youtube.com/watch?v=m8e-FF8MsqU");
			Film f4 = Film("Godfather", "Crime", 1972, 1000, "https://www.youtube.com/watch?v=sY1S34973zA");

			Assert::AreEqual(Repo.add(f1), true);
			Assert::AreEqual(Repo.add(f2), true);
			Assert::AreEqual(Repo.add(f3), true);
			Assert::AreEqual(Repo.add(f4), true);

			vector<Film> vector_films_expected;

			vector_films_expected.push_back(f1);
			vector_films_expected.push_back(f2);
			vector_films_expected.push_back(f3);
			vector_films_expected.push_back(f4);

			auto list_films_temp = Repo.get_all_films();
			for (auto i = 0; i < vector_films_expected.size(); i++)
			{
				Assert::AreEqual(vector_films_expected[i] == list_films_temp[i], true);
			}
		}

		TEST_METHOD(addwish)
		{
			UserWatchlist vectortowatch;

			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");

			Assert::AreEqual(vectortowatch.watchlist_add(f1), true);
			Assert::AreEqual(vectortowatch.watchlist_add(f1), false);

		}

		TEST_METHOD(delwish)
		{
			UserWatchlist vectortowatch;

			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			Film f2 = Film("Inception", "Sci-Fi", 2010, 1500, "https://www.youtube.com/watch?v=YoHD9XEInc0");

			Assert::AreEqual(vectortowatch.watchlist_add(f1), true);
			Assert::AreEqual(vectortowatch.watchlist_add(f2), true);

			Assert::AreEqual(vectortowatch.watchlist_delete(f1), true);
			Assert::AreEqual(vectortowatch.watchlist_delete(f1), false);

			Assert::AreEqual(vectortowatch.watchlist_delete(f2), true);
			Assert::AreEqual(vectortowatch.watchlist_delete(f2), false);

		}
		TEST_METHOD(watchlist_show)
		{
			UserWatchlist vectortowatch;

			Film f1 = Film("Seven", "Crime", 1995, 100, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			Film f2 = Film("Inception", "Sci-Fi", 2010, 1500, "https://www.youtube.com/watch?v=YoHD9XEInc0");

			Assert::AreEqual(vectortowatch.watchlist_add(f1), true);
			Assert::AreEqual(vectortowatch.watchlist_add(f2), true);

			vector<Film> watch_list_expected;
			watch_list_expected.push_back(f1);
			watch_list_expected.push_back(f2);

			vector<Film> temp = vectortowatch.watchlist_show();

			for (auto i = 0; i < temp.size(); i++)
			{
				Assert::AreEqual(watch_list_expected[i] == temp[i], true);
			}
		}
	};

}