#pragma once
#include "Mammals.h"

#include <iostream>
#include <vector>

using namespace std;

bool file_exists(string filename);

bool confirm_overwrite(string filename);

vector <unique_ptr<Mammals>> get_mammals_from_file(string filename);

bool is_filepath_valid(string filepath);

bool is_filename_valid(string filename);

string get_valid_filepath();

string get_overwrite_confirmation(string& full_path);

void export_to_file(vector<unique_ptr<Mammals>>& mammals_to_export);

