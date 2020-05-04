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
			auto repo1 = new Admin;

			Film f11 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			repo1->Admin::add(f11);

			for (auto i = 0; i < repo1->repo.size(); i++)
			{
				Assert::AreEqual(string("Eight"), repo1->repo[i].get_titel());
				Assert::AreEqual(string("Crime"), repo1->repo[i].get_genre());
				Assert::AreEqual(1990, repo1->repo[i].get_jahr());
				Assert::AreEqual(101, repo1->repo[i].get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), repo1->repo[i].get_trailer());
			}
		}

		TEST_METHOD(DeleteFilm)
		{
			auto repo1 = new Admin;

			Film f2 = Film("Six", "Comedy", 2017, 320, "viki.com");
			repo1->Admin::add(f2);
			Film f1 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			repo1->Admin::add(f1);

			repo1->del(f2);

			for (auto i = 0; i < repo1->repo.size(); i++)
			{
				Assert::AreEqual(string("Eight"), repo1->repo[i].get_titel());
				Assert::AreEqual(string("Crime"), repo1->repo[i].get_genre());
				Assert::AreEqual(1990, repo1->repo[i].get_jahr());
				Assert::AreEqual(101, repo1->repo[i].get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), repo1->repo[i].get_trailer());
			}
		}
	};

	TEST_CLASS(UserTest)
	{
	public:
		//TESTE VLASIN CRISTIA
		
		TEST_METHOD(AddFilm)
		{
			auto repo1 = new User;

			Film f11 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			repo1->User::add(f11);

			for (auto i = 0; i < repo1->repo.size(); i++)
			{
				Assert::AreEqual(string("Eight"), repo1->repo[i].get_titel());
				Assert::AreEqual(string("Crime"), repo1->repo[i].get_genre());
				Assert::AreEqual(1990, repo1->repo[i].get_jahr());
				Assert::AreEqual(101, repo1->repo[i].get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), repo1->repo[i].get_trailer());
			}
		}

		TEST_METHOD(DeleteFilm)
		{
			auto repo1 = new User;

			Film f2 = Film("Six", "Comedy", 2017, 320, "viki.com");
			repo1->User::add(f2);
			Film f1 = Film("Eight", "Crime", 1990, 101, "https://www.youtube.com/watch?v=znmZoVkCjpI");
			repo1->User::add(f1);

			repo1->User::del(f2);

			for (auto i = 0; i < repo1->repo.size(); i++)
			{
				Assert::AreEqual(string("Eight"), repo1->repo[i].get_titel());
				Assert::AreEqual(string("Crime"), repo1->repo[i].get_genre());
				Assert::AreEqual(1990, repo1->repo[i].get_jahr());
				Assert::AreEqual(101, repo1->repo[i].get_anz_likes());
				Assert::AreEqual(string("https://www.youtube.com/watch?v=znmZoVkCjpI"), repo1->repo[i].get_trailer());
			}
		}
		
	};
}
