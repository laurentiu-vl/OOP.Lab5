#pragma once
#include <vector>
#include "Film.h"

class User 
{
private:
   vector<Film> repo;  /// watchlist-ul userului

public:

    //vector<Film> repo;  /// watchlist-ul userului
    
                        
    /**
    /* 
     * @fn	User::User();
     *
     * @brief	Default constructor
     *
     * @author	Laurentiu
     * @date	04-May-20
     */
     User();

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
   
    ~User();
};