#include "pch.h"
#include "CppUnitTest.h"

#include "../Cinema/Admin.h"
#include "../Cinema/Controller.h"
#include "../Cinema/Film.h"
//#include "../Cinema/UI.h"
#include "../Cinema/User.h"

#include "../Cinema/Admin.cpp"
#include "../Cinema/Controller.cpp"
#include "../Cinema/Film.cpp"
//#include "../Cinema/UI.cpp"
#include "../Cinema/User.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestCinema
{
	TEST_CLASS(Filme)
	{
	public:

		TEST_METHOD(Constructor)
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
			film->set_titel("Seven");
			film->set_trailer("come.com");

			Assert::AreEqual(string("Seven"), film->get_titel());
			Assert::AreEqual(string("Action"), film->get_genre());
			Assert::AreEqual(2019, film->get_jahr());
			Assert::AreEqual(100, film->get_anz_likes());
			Assert::AreEqual(string("come.com"), film->get_trailer());

		}
	};
	
	TEST_CLASS(AdminTest)
	{
	public:
		//TESTE VLASIN CRISTIA

		TEST_METHOD(AddFilm)
		{
			auto repo1 = new Repository;

			Film f11 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			repo1->Repository::add(f11);

			for (auto i = 0; i < repo1->get_listesize(); i++) /// adaug f1
			{
				Assert::AreEqual(string("Eight"), (repo1->get_film(i)).get_titel());
				Assert::AreEqual(string("Crime"), (repo1->get_film(i)).get_genre());
				Assert::AreEqual(1990, (repo1->get_film(i)).get_jahr());
				Assert::AreEqual(101, (repo1->get_film(i)).get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), (repo1->get_film(i)).get_trailer());
			}

			Film f12 = Film("Nine", "Crime", 1999, 120, "https://www.youtube.com/watch?v=znmZoVkCjpI"); /// adaug f2
			repo1->Repository::add(f12);

			for (auto i = 0; i < repo1->get_listesize(); i++)
				if (i==1)																		/// verific poz
			{
				Assert::AreEqual(string("Nine"), (repo1->get_film(i)).get_titel());
				Assert::AreEqual(string("Crime"), (repo1->get_film(i)).get_genre());
				Assert::AreEqual(1999, (repo1->get_film(i)).get_jahr());
				Assert::AreEqual(120, (repo1->get_film(i)).get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), (repo1->get_film(i)).get_trailer());
			}
				else if (i == 0)																/// verific poz
				{
					Assert::AreEqual(string("Eight"), (repo1->get_film(i)).get_titel());
					Assert::AreEqual(string("Crime"), (repo1->get_film(i)).get_genre());
					Assert::AreEqual(1990, (repo1->get_film(i)).get_jahr());
					Assert::AreEqual(101, (repo1->get_film(i)).get_anz_likes());
					Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), (repo1->get_film(i)).get_trailer());
				}
		}

		TEST_METHOD(DeleteFilm)
		{
			auto repo1 = new Repository;

			Film f2 = Film("Six", "Comedy", 2017, 320, "viki.com");
			repo1->Repository::add(f2);
			Film f1 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			repo1->Repository::add(f1);

			repo1->del(f2);

			for (auto i = 0; i < repo1->get_listesize(); i++)
			{
				Assert::AreEqual(string("Eight"), (repo1->get_film(i)).get_titel());
				Assert::AreEqual(string("Crime"), (repo1->get_film(i)).get_genre());
				Assert::AreEqual(1990, (repo1->get_film(i)).get_jahr());
				Assert::AreEqual(101, (repo1->get_film(i)).get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), (repo1->get_film(i)).get_trailer());
			}

			Film f12 = Film("Nine", "Crime", 1999, 120, "https://www.youtube.com/watch?v=znmZoVkCjpI"); /// adaug alt f
			repo1->Repository::add(f12);

			repo1->del(f1);

			for (auto i = 0; i < repo1->get_listesize(); i++)
			{
				Assert::AreEqual(string("Nine"), (repo1->get_film(i)).get_titel());
				Assert::AreEqual(string("Crime"), (repo1->get_film(i)).get_genre());
				Assert::AreEqual(1999, (repo1->get_film(i)).get_jahr());
				Assert::AreEqual(120, (repo1->get_film(i)).get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), (repo1->get_film(i)).get_trailer());
			}

		}

		TEST_METHOD(IncrementLikes)
		{
			auto repo1 = new Repository;

			Film f11 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI"); /// adaug f1
			repo1->Repository::add(f11);


			Film f12 = Film("Nine", "Crime", 1999, 120, "https://www.youtube.com/watch?v=znmZoVkCjpI"); /// adaug f2
			repo1->Repository::add(f12);

			repo1->Repository::increment(f11); repo1->Repository::increment(f11); repo1->Repository::increment(f11); repo1->Repository::increment(f11); repo1->Repository::increment(f11); repo1->Repository::increment(f11); /// +6 likes

			repo1->Repository::increment(f12); repo1->Repository::increment(f12); repo1->Repository::increment(f12); repo1->Repository::increment(f12); repo1->Repository::increment(f12); /// +5 likes

			for (auto i = 0; i < repo1->get_listesize(); i++)
			{
				if (i == 0) 
				{
					Assert::AreEqual(107, (repo1->get_film(i)).get_anz_likes());
				}
				
				else
				{
					Assert::AreEqual(125, (repo1->get_film(i)).get_anz_likes());
				}
			}

			repo1->del(f11);
			repo1->del(f12);

			Film f13 = Film("Eight", "Crime", 1990, -1, "https://www.youtube.com/watch?v=znmZoVkCjpI"); /// adaug f1
			repo1->Repository::add(f13);

			repo1->Repository::increment(f13); repo1->Repository::increment(f13); repo1->Repository::increment(f13); /// +3 likes
			
			Assert::AreEqual(2, (repo1->get_film(0)).get_anz_likes());

		}
	};

	TEST_CLASS(UserTest)
	{
	public:
		//TESTE VLASIN CRISTIA
		
		TEST_METHOD(AddFilm)
		{
			auto repo1 = new UserController;

			Film f11 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			repo1->UserController::add(f11);

			for (auto i = 0; i < repo1->get_watchlistesize(); i++)
			{
				Assert::AreEqual(string("Eight"), (repo1->get_film(i)).get_titel());
				Assert::AreEqual(string("Crime"), (repo1->get_film(i)).get_genre());
				Assert::AreEqual(1990, (repo1->get_film(i)).get_jahr());
				Assert::AreEqual(101, (repo1->get_film(i)).get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), (repo1->get_film(i)).get_trailer());
			}
		}

		TEST_METHOD(DeleteFilm)
		{
			auto repo1 = new UserController;

			Film f2 = Film("Six", "Comedy", 2017, 320, "viki.com");
			repo1->UserController::add(f2);
			Film f1 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			repo1->UserController::add(f1);

			repo1->UserController::del(f2);

			for (auto i = 0; i < repo1->get_watchlistesize(); i++)
			{
				Assert::AreEqual(string("Eight"),(repo1->get_film(i)).get_titel());
				Assert::AreEqual(string("Crime"), (repo1->get_film(i)).get_genre());
				Assert::AreEqual(1990, (repo1->get_film(i)).get_jahr());
				Assert::AreEqual(101, (repo1->get_film(i)).get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), (repo1->get_film(i)).get_trailer());
			}
		}
		
	};
}
