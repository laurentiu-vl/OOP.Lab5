#pragma once
#include "Film.h"
#include "admin.h"
#include "user.h"

class Controller 
{
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
     * @fn	void Controller::comandaadmin(int, admin*, User*);
     *
     * @brief	Comandaadmins
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 		  	parameter1	The first parameter.
     * @param [in,out]	parameter2	If non-null, the second parameter.
     * @param [in,out]	parameter3	If non-null, the third parameter.
     */
    void comandaadmin(int, Repository*, UserController*);  /// Metodele meniului de ADMIN

    /**
     * @fn	void Controller::comandauser(int, admin*, User*);
     *
     * @brief	Comandausers
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 		  	parameter1	The first parameter.
     * @param [in,out]	parameter2	If non-null, the second parameter.
     * @param [in,out]	parameter3	If non-null, the third parameter.
     */
    void comandauser(int, Repository*, UserController*);   /// Metodele meniului de USER
    
    ~Controller();
};