#pragma once
#include "Film.h"
#include "BaseFileOutput.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class TEXT : public BaseFileOutput
{
	//void write_filmlist_in_file(vector<Film> v) override;
	string write_watchlist_in_file(vector<Film> v) override;
};