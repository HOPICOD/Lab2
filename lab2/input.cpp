#include <iostream>
using namespace std;



int input_int(string message, int min, int max) {

	int user_input;

	cout << message << endl;

	cin >> user_input;

	while (cin.fail() || user_input <= min || user_input >= max) {

		cin.clear();//снимает тип ошибки
		cin.ignore(INT_MAX, '\n');// очищает поток ввода

		cout << "Retype:" << endl;
		cin >> user_input;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return user_input;
}

double input_double(string message, double min, double max) {

	double user_input;

	cout << message << endl;

	cin >> user_input;

	while (cin.fail() || user_input < min || user_input > max) {

		cin.clear();//снимает тип ошибки
		cin.ignore(INT_MAX, '\n');// очищает поток ввода

		cout << "Retype:" << endl;
		cin >> user_input;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return user_input;
}

string input_string(string message) {

	string user_input;

	cout << message << endl;

	cin >> user_input;

	while (user_input.empty()) {

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "Retype:" << endl;
		cin >> user_input;
	}

	cin.ignore(INT_MAX, '\n');

	return user_input;
}

string input_is_pack_mammal() {
	string is_pack_mammal;
	int user_input = input_int("Does this mammal live in a pack? (1 - Yes, 2 - No):", 0, 3);
	if (user_input == 1) {
		return is_pack_mammal = "Yes";
	}
	else {
		return is_pack_mammal = "No";
	}

}
