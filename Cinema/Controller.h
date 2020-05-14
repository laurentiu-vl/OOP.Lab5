#pragma once
#include "Film.h"
#include "Repo.h"
#include "UserRepo.h" 

class Controller
{
private: 
    UserWatchlist UserRepo;

    Repository Repo;

public:

    /**
     * @fn	Controller::Controller();
     *
     * @brief	Default constructor
     *
     * @author	Laurentiu
     * @date	04-May-20
     */
    Controller();

    Controller(UserWatchlist UserRepo, Repository Repo);

    void list_films_admin();

    void add_admin(Film f);

    void del_admin(Film f);

    //void edit_admin(Film f);

    void add_to_watch(Film);

    void delete_from_watch(Film);

    void show_watch();

    void likes_plus(Film);

    void edit_title_admin(string title, int year, string new_title);
    
    void edit_year_admin(string title, int year, int new_year);

    void edit_genre_admin(string title, int year, string genre);

    void edit_trailer_admin(string title, int year, string trailer);

    void edit_nrlikes_admin(string title, int year, int likes);

    ~Controller();
};