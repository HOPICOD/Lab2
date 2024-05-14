#include "Mammals.h"
#include "files.h"
#include "input.h"
#include "Mammals_controller.h"

#include <iostream>
#include <memory>

using namespace std;

enum mammal {MAMMAL = 1, CARNIVORE};

void add_mammal(Mammal_controller& mammals) {
	cout << "1 - add mammal" << endl;
	cout << "2 - add carnivore mammal" << endl;

	int user_choice = input_int("Enter: ", 0, 3);

	switch (user_choice) {
	case(MAMMAL): {

		string name = input_string("Enter name of the mammal:");
		string habitat = input_string("Enter habitat of mammal:");
		double weight = input_double("Enter weight of mammal in kilograms:", 0.001, 100000);

		mammals.add_mammal(make_unique<Mammals>(name, "Unknown", habitat, weight));
		break;

		}
	case(CARNIVORE): {
		
		string name = input_string("Enter name of the mammal:");
		string habitat = input_string("Enter habitat of mammal:");
		double weight = input_double("Enter weight of mammal in kilograms:", 0.001, 100000);
		int danger_rate = input_int("Enter danger rate for human(from 0 to 10): ", -1, 11);
		string is_pack_mammal = input_is_pack_mammal();

		mammals.add_mammal(make_unique<Carnivore>(name, "Carnivore", habitat, weight, danger_rate, is_pack_mammal));
		break;
	}
	}
}

void load_data(Mammal_controller& mammals) {
	
	string filepath = get_valid_filepath();

	vector<unique_ptr<Mammals>> mammals_from_file = get_mammals_from_file(filepath);

	if (mammals_from_file.empty()) { cerr << "Error reading from file" << endl; }

	else {
		mammals.set_mammal(move(mammals_from_file)); }
}

void save_data(Mammal_controller& mammals) {

	//vector<unique_ptr<Mammals>> mammals_to_export = mammals.get_mammals();

	if (mammals.get_mammals().empty()) { cout << "You're haven`t added any mammals yet!" << endl; return; }

	else { export_to_file(mammals.get_mammals()); }
}