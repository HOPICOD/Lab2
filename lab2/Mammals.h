#pragma once
#include <string>
#include <iostream>
using namespace std;

class Mammals {
protected:
	string name;
	string method_of_nutrition;
	string habitat;
	double weight;


	public:
		Mammals(string name, string method_of_nutrition, string habitat, double weight) :
			name(name), method_of_nutrition(method_of_nutrition), habitat(habitat), weight(weight) {}

		virtual ~Mammals() = default;


		string get_name() { return name; }
		string get_habitat() { return habitat; }
		string get_method_of_nutrition() { return method_of_nutrition; }
		double get_weight() { return weight;  }

		virtual void show_mammal() {
			cout << endl;
			cout << "It is a mammal with an unknown type of diet: " << get_name() << endl;
			cout << "Weight: " << get_weight() << " kg" << endl;
			cout << "Habitat: " << get_habitat() << endl << endl;
		}

		
};

class Carnivore : public Mammals {
	
	int danger_rate;
	string is_pack_mammal;

	public:
		Carnivore(string name, string method_of_nutrition, string habitat, double weight, int danger_rate, string is_pack_mammal) : Mammals(name, "Carnivore", habitat, weight) {
			this->danger_rate = danger_rate;
			this->is_pack_mammal = is_pack_mammal;
		}

		int get_danger_rate() { return danger_rate; }
		string get_pack_mammal() { return is_pack_mammal; }

		void show_mammal() override {
			cout << endl;
			cout << "It is a carnivore mammal: " << get_name() << endl;
			cout << "Weight: " << get_weight() << " kg" << endl;
			cout << "Habitat: " << get_habitat() << endl;
			cout << "Danger rate for human: " << get_danger_rate() << "/10" << endl;
			cout << "Does this mammal live in a pack: " << get_pack_mammal() << endl;
		}
};