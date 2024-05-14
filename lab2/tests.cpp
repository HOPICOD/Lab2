#include "Mammals.h"
#include <iostream>
#include <cassert>

using namespace std;

bool is_tests_right() {
        Mammals mammal1("Horse", "Herbivore", "Field", 400);

        assert(mammal1.get_name() == "Horse");
        assert(mammal1.get_method_of_nutrition() == "Herbivore");
        assert(mammal1.get_habitat() == "Field");
        assert(mammal1.get_weight() == 400);


        Carnivore carnivore1("Tiger", "Carnivore", "Jungle", 220, 8, "Yes");

        assert(carnivore1.get_name() == "Tiger");
        assert(carnivore1.get_method_of_nutrition() == "Carnivore");
        assert(carnivore1.get_habitat() == "Jungle");
        assert(carnivore1.get_weight() == 220);
        assert(carnivore1.get_danger_rate() == 8);
        assert(carnivore1.get_pack_mammal() == "Yes");


        Mammals mammal2("bear", "omnivorous", "forest", 612.32);

        assert(mammal2.get_name() == "bear");
        assert(mammal2.get_method_of_nutrition() == "omnivorous");
        assert(mammal2.get_habitat() == "forest");
        assert(mammal2.get_weight() == 612.32);


        Carnivore carnivore2("Shark", "Carnivore", "Sea", 250.5, 9, "Yes");

        assert(carnivore2.get_name() == "Shark");
        assert(carnivore2.get_method_of_nutrition() == "Carnivore");
        assert(carnivore2.get_habitat() == "Sea");
        assert(carnivore2.get_weight() == 250.5);
        assert(carnivore2.get_danger_rate() == 9);
        assert(carnivore2.get_pack_mammal() == "Yes");

        Mammals mammal3("AaBb", "AaCc", "qwerty", 63112.32321312313);

        assert(mammal3.get_name() == "AaBb");
        assert(mammal3.get_method_of_nutrition() == "AaCc");
        assert(mammal3.get_habitat() == "qwerty");
        assert(mammal3.get_weight() == 63112.32321312313);


        return true;
}

void result_of_tests() {
    if (is_tests_right()) {
        cout << "All tests passed succesfully!" << endl;
    }
    else {
        cout << "Tests failed!" << endl;
    }
}