#pragma once
#include <vector>
#include "Film.h"

class Repository
{
private:
   
    vector<Film> data;  /// baza de date cu toate filmele

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

    Film get_film(int);

    int get_listesize() { return data.size(); }

    /**
     * @fn	    vector<Film> Repository::list_films();
     *
     * @brief	List_films
     *
     * @author	Laurentiu
     * @date	04-May-20
     */
    vector<Film> list_films();

    /**
     * @fn	bool add(Film);
     *
     * @brief	Adds parameter1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The parameter 1 to add.
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
    bool suchen(User*);

    /**
     * @fn	void Repository::increment(Film);
     *
     * @brief	Increments the given parameter 1 (nrlikes)
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     */
    bool increment(Film);   

    bool edit_valid(Film);

    vector <Film>::iterator search_a_movie(Film);

    bool edit_title(vector <Film>::iterator i, string title);

    bool edit_year(vector <Film>::iterator i, int year);

    bool edit_genre(vector <Film>::iterator i, string genre);

    bool edit_trailer(vector <Film>::iterator i, string trailer);

    bool edit_nrlikes(vector <Film>::iterator i, int likes);
    
    ~Repository();
};