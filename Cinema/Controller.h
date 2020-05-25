#pragma once
#include "Film.h"
#include "Repo.h"
#include "UserRepo.h" 
#include "BaseFileOutput.h"
#include <map>
#include <utility>

using namespace std;

class Controller
{
protected: 
    /** @brief	The user repo */
    UserWatchlist UserRepo;

    /** @brief	The repo */
    Repository Repo;

    map<string, BaseFileOutput*> OutputMap;

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

    /**
     * @fn	Controller::Controller(UserWatchlist UserRepo, Repository Repo);
     *
     * @brief	Constructor
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	UserRepo	The user repo.
     * @param 	Repo		The repo.
     */

    Controller(UserWatchlist UserRepo, Repository Repo);

    /**
     * @fn	void Controller::list_films_admin();
     *
     * @brief	List films admin
     *
     * @author	Laurentiu
     * @date	14-May-20
     */

    void list_films_admin();

    /**
     * @fn	bool Controller::add_admin(Film f);
     *
     * @brief	Adds an admin
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	f	A Film to process.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool add_admin(Film f);

    /**
     * @fn	void Controller::del_admin(Film f);
     *
     * @brief	Deletes the admin described by f
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	f	A Film to process.
     */

    void del_admin(Film f);

    /**
     * @fn	void Controller::add_to_watch(Film);
     *
     * @brief	Adds to the watch
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	parameter1	The first parameter.
     */

    void add_to_watch(Film);

    /**
     * @fn	void Controller::delete_from_watch(Film);
     *
     * @brief	Deletes from watch described by parameter1
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	parameter1	The first parameter.
     */

    void delete_from_watch(Film);

    /**
     * @fn	void Controller::show_watch();
     *
     * @brief	Shows the watch
     *
     * @author	Laurentiu
     * @date	14-May-20
     */

    void show_watch();

    /**
     * @fn	void Controller::likes_plus(Film);
     *
     * @brief	Likes plus
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	parameter1	The first parameter.
     */

    void likes_plus(Film);

    /**
     * @fn	void Controller::edit_title_admin(string title, int year, string new_title);
     *
     * @brief	Edit title admin
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title	 	The title.
     * @param 	year	 	The year.
     * @param 	new_title	The new title.
     */

    void edit_title_admin(string title, int year, string new_title);

    /**
     * @fn	void Controller::edit_year_admin(string title, int year, int new_year);
     *
     * @brief	Edit year admin
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title   	The title.
     * @param 	year		The year.
     * @param 	new_year	The new year.
     */

    void edit_year_admin(string title, int year, int new_year);

    /**
     * @fn	void Controller::edit_genre_admin(string title, int year, string genre);
     *
     * @brief	Edit genre admin
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title	The title.
     * @param 	year 	The year.
     * @param 	genre	The genre.
     */

    void edit_genre_admin(string title, int year, string genre);

    /**
     * @fn	void Controller::edit_trailer_admin(string title, int year, string trailer);
     *
     * @brief	Edit trailer admin
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title  	The title.
     * @param 	year   	The year.
     * @param 	trailer	The trailer.
     */

    void edit_trailer_admin(string title, int year, string trailer);

    /**
     * @fn	void Controller::edit_nrlikes_admin(string title, int year, int likes);
     *
     * @brief	Edit nrlikes admin
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title	The title.
     * @param 	year 	The year.
     * @param 	likes	The likes.
     */

    void edit_nrlikes_admin(string title, int year, int likes);



    vector <Film> movies_by_genre_to_show(string);

    bool Export_Watchlist(string option);
    
        /**
         * @fn	Controller::~Controller();
         *
         * @brief	Destructor
         *
         * @author	Laurentiu
         * @date	14-May-20
        */

    ~Controller();
};