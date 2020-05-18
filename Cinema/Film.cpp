#include "Film.h"

Film::Film(string Title, string Genre, int Year, int nrLikes, string Trailer)
{
   
    this->title = Title;
    
    this->genre = Genre;
   
    this->year = Year;
   
    this->nrlikes = nrLikes;
   
    this->trailer = Trailer;
}

Film::~Film() = default;

bool Film::operator== (Film f2) const
{
    return((this->title == f2.get_titel()) && (this->year == f2.get_jahr()));
}