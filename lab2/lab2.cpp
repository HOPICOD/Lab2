#include <iostream>
#include "menu.h"
#include "menu_tasks.h"
#include "Mammals_controller.h"
#include "Mammals.h"
#include "input.h"
#include "tests.h"

using namespace std;

enum menu {ADD_MAMMALS = 1, SHOW_MAMMALS, LOAD_DATA, SAVE_DATA, RUN_TESTS, EXIT };

int main()
{
	show_greeting();

	int user_choice = 0;

	Mammal_controller mammals;

	bool repeat = true;

	do {
		show_task();
		user_choice = input_int("Enter: ", 0, 7);
		switch (user_choice)
		{
		case(ADD_MAMMALS): {
			add_mammal(mammals);
			break;
		}
		case(SHOW_MAMMALS): {
			mammals.show_all_mammals();
			break;
		}
		case(LOAD_DATA): {
			load_data(mammals);
			break;
		}
		case(SAVE_DATA): {
			save_data(mammals);
			break;
		}
		case(RUN_TESTS): {
			result_of_tests();
			break;
		}
		case(EXIT): {
			repeat = false;
		}
		default:
			break;
		}

	} while (repeat);

}