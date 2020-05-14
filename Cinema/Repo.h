#pragma once
#include <vector>
#include "Film.h"

class Repository
{
private:
   
    /** @brief	/ baza de date cu toate filmele */
    vector<Film> data;

public:    

    /**
     * @fn	Repository::Repository();
     *
     * @brief	Default constructor
     *
     * @author	Laurentiu
     * @date	04-May-20
     */

    Repository();

    /**
     * @fn	Film Repository::get_film(int);
     *
     * @brief	Gets a film
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	parameter1	The first parameter.
     *
     * @returns	The film.
     */

    Film get_film(int);

    /**
     * @fn	int Repository::get_listesize()
     *
     * @brief	Gets the listesize
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @returns	The listesize.
     */

    int get_listesize() { return static_cast<int>(data.size()); }

    /**
     * @fn	vector<Film> Repository::list_films();
     *
     * @brief	List_films
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @returns	A vector&lt;Film&gt;
     */

    vector<Film> list_films();

    /**
     * @fn	bool Repository::add(Film);
     *
     * @brief	Adds parameter1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The parameter 1 to add.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool add(Film);

    /**
     * @fn	bool Repository::del(Film);
     *
     * @brief	Deletes the given parameter1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool del(Film);

    /**
     * @fn	bool Repository::edit(Film);
     *
     * @brief	Edits the given parameter 1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool edit(Film);

    /**
     * @fn	void Repository::suchen(User*);
     *
     * @brief	Suchens the given parameter 1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param [in,out]	parameter1	If non-null, the first parameter.
     */
    
     //bool suchen(User*);

    /**
     * @fn	bool Repository::increment(Film);
     *
     * @brief	Increments the given parameter 1 (nrlikes)
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool increment(Film);   

    /**
     * @fn	bool Repository::edit_valid(Film);
     *
     * @brief	Edit valid
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	parameter1	The first parameter.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool edit_valid(Film);

    /**
     * @fn	vector <Film>::iterator Repository::search_a_movie(string title, int year);
     *
     * @brief	Searches for the first a movie
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title	The title.
     * @param 	year 	The year.
     *
     * @returns	The found a movie.
     */

    vector <Film>::iterator search_a_movie(string title, int year);

    /**
     * @fn	bool Repository::edit_title(string title, int year, string new_title);
     *
     * @brief	Edit title
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title	 	The title.
     * @param 	year	 	The year.
     * @param 	new_title	The new title.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool edit_title(string title, int year, string new_title);

    /**
     * @fn	bool Repository::edit_year(string title, int year, int new_year);
     *
     * @brief	Edit year
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title   	The title.
     * @param 	year		The year.
     * @param 	new_year	The new year.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool edit_year(string title, int year, int new_year);

    /**
     * @fn	bool Repository::edit_genre(string title, int year, string genre);
     *
     * @brief	Edit genre
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title	The title.
     * @param 	year 	The year.
     * @param 	genre	The genre.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool edit_genre(string title, int year, string genre);

    /**
     * @fn	bool Repository::edit_trailer(string title, int year, string trailer);
     *
     * @brief	Edit trailer
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title  	The title.
     * @param 	year   	The year.
     * @param 	trailer	The trailer.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool edit_trailer(string title, int year, string trailer);

    /**
     * @fn	bool Repository::edit_nrlikes(string title, int year, int likes);
     *
     * @brief	Edit nrlikes
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	title	The title.
     * @param 	year 	The year.
     * @param 	likes	The likes.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool edit_nrlikes(string title, int year, int likes);

    /**
     * @fn	Repository::~Repository();
     *
     * @brief	Destructor
     *
     * @author	Laurentiu
     * @date	14-May-20
     */

    ~Repository();
};