#pragma once
#include <vector>
#include "Film.h"

class UserController 
{
private:
   /** @brief	/ watchlist-ul userului */
   vector<Film> repo;

public:
                        
     UserController();
     
     /**
      * @fn	User User::get_film(int);
      *
      * @brief	Gets a film
      *
      * @author	Laurentiu
      * @date	10-May-20
      *
      * @param 	parameter1	The first parameter.
      *
      * @returns	The film.
      */

     Film get_film(int);

     int get_watchlistesize() { return repo.size(); }

    /**
     * @fn	void User::add(Film);
     *
     * @brief	Adds parameter1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The parameter 1 to add.
     */

    void add(Film);

    /**
     * @fn	void User::del(Film);
     *
     * @brief	Deletes the given parameter1/
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     */

    void del(Film);

    /**
     * @fn	void User::show();
     *
     * @brief	Shows this
     *
     * @author	Laurentiu
     * @date	04-May-20
     */

    void show();

    /**
     * @fn	User::~User();
     *
     * @brief	Destructor
     *
     * @author	Laurentiu
     * @date	10-May-20
     */

    ~UserController();
};