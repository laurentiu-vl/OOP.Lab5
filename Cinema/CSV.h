#pragma once
#include "Film.h"
#include "BaseFileOutput.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class CSV : public BaseFileOutput
{
public:

	string write_watchlist_in_file(vector<Film> v) override;
};