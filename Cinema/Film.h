#pragma once
#include <string>

using namespace std;

class Film 
{

private:
    string title;
   
    string genre;
   
    int year;
    
    int nrlikes;
   
    string trailer;

public:

    /**
     * @fn	Film::Film(string, string, int, int, string);
     *
     * @brief	Constructor
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	parameter1	The first parameter.
     * @param 	parameter2	The second parameter.
     * @param 	parameter3	The third parameter.
     * @param 	parameter4	The fourth parameter.
     * @param 	parameter5	The fifth parameter.
     */
    Film(string, string, int, int, string); 

    /**
     * @fn	void Film::set_titel(string newtitle)
     *
     * @brief	Sets a titel
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	newtitle	The newtitle.
     */
    void set_titel(string newtitle) { this->title = newtitle; };

    /**
     * @fn	void Film::set_genre(string newgenre)
     *
     * @brief	Sets a genre
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	newgenre	The newgenre.
     */
    void set_genre(string newgenre) { this->genre = newgenre; };

    /**
     * @fn	void Film::set_jahr(int newyear)
     *
     * @brief	Sets a jahr
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	newyear	The newyear.
     */
    void set_jahr(int newyear) { this->year = newyear; };

    /**
     * @fn	void Film::set_anz_likes(int newnrlikes)
     *
     * @brief	Sets anz likes
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	newnrlikes	The newnrlikes.
     */
    void set_anz_likes(int newnrlikes) { this->nrlikes = newnrlikes; };

    /**
     * @fn	void Film::set_trailer(string newtrailer)
     *
     * @brief	Sets a trailer
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @param 	newtrailer	The newtrailer.
     */
    void set_trailer(string newtrailer) { this->trailer = newtrailer; };

    /**
     * @fn	string Film::get_titel()
     *
     * @brief	Gets the titel
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @returns	The titel.
     */
    string get_titel() { return this->title; };

    /**
     * @fn	string Film::get_genre()
     *
     * @brief	Gets the genre
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @returns	The genre.
     */
    string get_genre() { return this->genre; };

    /**
     * @fn	int Film::get_jahr()
     *
     * @brief	Gets the jahr
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @returns	The jahr.
     */
    int get_jahr() { return this->year; };

    /**
     * @fn	int Film::get_anz_likes()
     *
     * @brief	Gets anz likes
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @returns	The anz likes.
     */
    int get_anz_likes() { return this->nrlikes; };

    /**
     * @fn	string Film::get_trailer()
     *
     * @brief	Gets the trailer
     *
     * @author	Laurentiu
     * @date	04-May-20
     *
     * @returns	The trailer.
     */
    string get_trailer() { return this->trailer; };

    ~Film();
};