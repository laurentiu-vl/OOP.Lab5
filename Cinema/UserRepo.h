#pragma once
#include <vector>
#include "Film.h"

class UserWatchlist
{
private:
    /** @brief	/ watchlist-ul userului */
    vector<Film> watchlist;

public:

    /**
     * @fn	bool UserWatchlist::watchlist_add(Film);
     *
     * @brief	Watchlist add
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	parameter1	The first parameter.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool watchlist_add(Film);

    /**
     * @fn	bool UserWatchlist::watchlist_delete(Film);
     *
     * @brief	Watchlist delete
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	parameter1	The first parameter.
     *
     * @returns	True if it succeeds, false if it fails.
     */

    bool watchlist_delete(Film);

    /**
     * @fn	vector <Film> UserWatchlist::watchlist_search(Film);
     *
     * @brief	Watchlist search
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @param 	parameter1	The first parameter.
     *
     * @returns	A vector.
     */

    vector <Film> watchlist_search(Film);

    /**
     * @fn	vector <Film> UserWatchlist::watchlist_show();
     *
     * @brief	Watchlist show
     *
     * @author	Laurentiu
     * @date	14-May-20
     *
     * @returns	A vector.
     */

    vector <Film> watchlist_show();

 

    //~UserController();
};