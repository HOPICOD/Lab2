#include "Mammals.h"
#include "input.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

bool is_weight_valid(const double &weight) {
	return (weight >= 0.001 && weight <= 100000);
}
bool is_pack_valid(const string &is_pack_mammal) {
	return (is_pack_mammal == "Yes" || is_pack_mammal == "yes" || is_pack_mammal == "No" || is_pack_mammal == "no");
}

bool is_danger_valid(const int &danger_rate) {
	return (danger_rate >= 0 && danger_rate <= 10);
}

bool file_exists(string filename) {
	ifstream file(filename);
	return file.is_open();
}

bool confirm_overwrite(string filename) {

	const int YES = 1;

	cout << "File '" << filename << "' already exists." << endl;
	cout << "Do you want to overwrite it?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;

	int user_choice = 0;

	user_choice = input_int("Enter menu item:", 0, 3);

	if (user_choice == YES) { return true; }

	return false;

}

vector <unique_ptr<Mammals>> get_mammals_from_file(string filename) {

	vector<unique_ptr<Mammals>> mammals;

	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return mammals;
	}

	string line;
	while (getline(input_file, line)) {
		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		stringstream ss(line);

		string name;
		string method_of_nutrition;
		string habitat;
		string is_pack_mammal;
		double weight;
		int danger_rate;

		/*if (!(ss >> name >> method_of_nutrition >> habitat >> weight >> danger_rate)) {
			cerr << "Error reading data from line:\" " << line << "\"" << endl;
			continue;
		}

		if (is_data_valid(weight, danger_rate)) {
			cerr << "Error invalid data in line:\" " << line << "\"" << endl;
			continue;
		}

		if (method_of_nutrition == "carnivore" || method_of_nutrition == "Carnivore") {
			mammals.push_back(make_unique<Carnivore>(name, method_of_nutrition, habitat, weight, danger_rate));
		}
		else {
			mammals.push_back(make_unique<Mammals>(name, method_of_nutrition, habitat, weight));
		}
	}*/

		if (!(ss >> name >> method_of_nutrition >> habitat >> weight)) {
			cerr << "Error reading data from line: \"" << line << "\"" << endl;
			continue;
		}

		if (!is_weight_valid(weight)) {
			cerr << "Error invalid data in line: \"" << line << "\"" << endl;
			continue;
		}

		
		if (method_of_nutrition == "carnivore" || method_of_nutrition == "Carnivore") {
			if (!(ss >> danger_rate)) {
				cerr << "Error reading danger rate data from line: \"" << line << "\"" << endl;
				continue;
			}

			if (!is_danger_valid(danger_rate)) {
				cerr << "Error invalid danger rate in line: \"" << line << "\"" << endl;
				continue;
			}
			if (!(ss >> is_pack_mammal)) {
				cerr << "Error reading danger rate data from line: \"" << line << "\"" << endl;
				continue;
			}
			if (!is_pack_valid(is_pack_mammal)) {
				cerr << "Error invalid danger rate in line: \"" << line << "\"" << endl;
				continue;
			}
			mammals.push_back(make_unique<Carnivore>(name, method_of_nutrition, habitat, weight, danger_rate, is_pack_mammal));
		}
		else {
			mammals.push_back(make_unique<Mammals>(name, method_of_nutrition, habitat, weight));
		}
	}

	return mammals;
}


bool is_filepath_valid(string filepath) {

	regex file_path_regex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.txt$");

	if (!regex_match(filepath, file_path_regex)) {
		cerr << "Error: Invalid file path." << endl;
		return false;
	}

	return true;
}
bool is_filename_valid(string filename) {
	regex filename_regex("^[^\\/:*?\"<>|]+\\.txt$");

	regex filename_reserved_names("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");

	regex filename_reserved_chars("[\\/:*?\"<>|]");

	if (!regex_match(filename, filename_regex)) {
		cerr << "Error: Invalid file name." << endl;
		return false;
	}

	if (regex_match(filename, filename_reserved_names)) {
		cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << endl;
		return false;
	}

	if (regex_search(filename, filename_reserved_chars)) {
		cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << endl;
		return false;
	}

	return true;
}

string get_valid_filepath() {
	bool is_path_valid = false;
	bool is_name_valid = false;

	string filepath{ "" };

	while (!is_path_valid || !is_name_valid) {
		cout << "Enter fullpath with filename (only txt acceptable): " << endl;
		getline(cin, filepath);
		size_t pos = filepath.find_last_of("\\");

		if (pos > sizeof(filepath)) {

			if (is_filename_valid(filepath)) {

				is_path_valid = true;
				is_name_valid = true;

			}
		}

		if (pos != string::npos) {
			string filename = filepath.substr(pos + 1);
			string path = filepath.substr(0, pos + 1);

			if (is_filepath_valid(path + filename) && is_filename_valid(filename)) {
				is_path_valid = true;
				is_name_valid = true;
			}

		}
	}

	return filepath;
}

string get_overwrite_confirmation(string& full_path) {
	if (file_exists(full_path)) {
		if (!confirm_overwrite(full_path)) {
			cout << "Please choose another file." << endl;
			full_path = get_valid_filepath();
			return get_overwrite_confirmation(full_path);
		}
	}
	return full_path;
}

void export_to_file(vector<unique_ptr<Mammals>>& mammals_to_export) {

	string full_path = get_valid_filepath();
	full_path = get_overwrite_confirmation(full_path);

	ofstream file(full_path);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		while (true) {
			cout << "Please enter a new path." << endl;
			full_path = get_valid_filepath();
			full_path = get_overwrite_confirmation(full_path);

			file.open(full_path);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}

	for (auto& export_mammals : mammals_to_export) {
		Carnivore* carnivore_ptr = dynamic_cast<Carnivore*>(export_mammals.get());
		if (carnivore_ptr != nullptr) {
			file << carnivore_ptr->get_name() << ' ' << carnivore_ptr->get_method_of_nutrition() << ' ' << carnivore_ptr->get_habitat() << ' ' << carnivore_ptr->get_weight() << ' ' << carnivore_ptr->get_danger_rate() << ' ' << carnivore_ptr->get_pack_mammal() << "\n";
		}
		else {
			file << export_mammals->get_name() << ' ' << export_mammals->get_method_of_nutrition() << ' ' << export_mammals->get_habitat() << ' ' << export_mammals->get_weight() << "\n";
		}
	}
	file.close();
	cout << "Data successfully exported to file: " << full_path << endl;
}