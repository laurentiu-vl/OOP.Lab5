#pragma once
#include "Film.h"
#include "BaseFileOutput.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class HTML : public BaseFileOutput
{
public:

	void write_watchlist_in_file(vector<Film> v) override;
};