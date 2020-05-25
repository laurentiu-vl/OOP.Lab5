#pragma once
#include "Film.h"
#include <string>
#include <vector>
#include <windows.h>
#include <shellapi.h>

class BaseFileOutput
{
public:

	BaseFileOutput();
	virtual string write_watchlist_in_file(vector<Film> v) = 0;

};
