#pragma once
#include <vector>
#include "Film.h"
#include "user.h"

class Admin
{
private:
   
   // vector<Film> repo;  /// baza de date cu toate filmele

public:

    vector<Film> repo;  /// baza de date cu toate filmele
    /**
     * @fn	Admin::Admin();
     *
     * @brief	Default constructor
     *
     * @author	Laurentiu
     * @date	04-May-20
     */
    Admin();

    /**
     * @fn	void Admin::ansehen();
     *
     * @brief	Ansehens this 
     *
     * @author	Laurentiu
     * @date	04-May-20
     */
    void ansehen();

    /**
     * @fn	void Admin::add(Film);
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
     * @fn	void Admin::del(Film);
     *
     * @brief	Deletes the given parameter1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     */
    void del(Film);

    /**
     * @fn	void Admin::edit(Film);
     *
     * @brief	Edits the given parameter 1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     */
    void edit(Film);

    /**
     * @fn	void Admin::suchen(User*);
     *
     * @brief	Suchens the given parameter 1
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param [in,out]	parameter1	If non-null, the first parameter.
     */
    void suchen(User*);

    /**
     * @fn	void Admin::increment(Film);
     *
     * @brief	Increments the given parameter 1 (nrlikes)
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     */
    void increment(Film);   
    
    ~Admin();
};