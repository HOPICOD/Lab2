#pragma once

#include <iostream>
#include "Mammals.h"
#include <memory>
#include <vector>

using namespace std;

class Mammal_controller {

	vector<unique_ptr<Mammals>> mammals;

public:

	void add_mammal(unique_ptr<Mammals> mammal) { 
		mammals.push_back(move(mammal));
	}

	void set_mammal(vector<unique_ptr<Mammals>> new_mammal) { 
		mammals = move(new_mammal); 
	}

	void show_all_mammals() {
		cout << endl;

		if (mammals.empty()) {
			cout << "You`re haven`t added any mammals yet!" << endl;
			return;
		}

		cout << "Your mammals:" << endl << endl;
		
		for (auto& mammal : mammals) {
			mammal->show_mammal();
		}
		cout << endl;
	}

	vector<unique_ptr<Mammals>>& get_mammals() {
		return mammals;
	}
};
