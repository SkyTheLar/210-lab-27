/**************************************************

COMSC 210 | Lab 27 | Skylar Robinson | IDE Used: Eclipse

**************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int mainMenu();
void dispVillage(map<string, tuple<int, string, string>>);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {6, "Dragon", "Howdy!"};
    villagers["Raymond"] = {2, "Wolf", "Yippie"};
    villagers.insert({"Marshal", {8, "Rat", "I like cheese."}});

    dispVillage(villagers);

    return 0;
}

int mainMenu() {
	int choice;
	cout << "\n1. Add Villager\n"
		 << "2. Delete Villager\n"
         << "3. Increase Friendship\n"
		 << "4. Decrease Friendship\n"
		 << "5. Search for Villager\n"
		 << "6. Exit\n"
		 << "Select an opiton by number: ";
	cin >> choice;
	return choice;
}

void dispVillage(map<string, tuple<int, string, string>> v) {
	for (auto pair : v) {
	    cout << pair.first << " [";
	    for (auto tup : pair.second)
	        cout << " ";
	    cout << "]\n";
	}
}
