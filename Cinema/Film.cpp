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