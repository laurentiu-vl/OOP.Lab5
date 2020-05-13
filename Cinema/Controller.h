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
    Controller(UserWatchlist UserRepo, Repository Repo);

    void list_films_admin();

    void add_admin(Film f);

    void del_admin(Film f);

    void edit_admin(Film f);

    void add_to_watch(Film);

    void delete_from_watch(Film);

    void show_watch();
    
    ~Controller();
};