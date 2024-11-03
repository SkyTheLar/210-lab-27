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
void addVillager(map<string, tuple<int, string, string>>&);
void delVillager(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {6, "Dragon", "Howdy!"};
    villagers["Raymond"] = {2, "Wolf", "Yippie"};
    villagers.insert({"Marshal", {8, "Rat", "I like cheese."}});

    dispVillage(villagers);
    addVillager(villagers);
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
	cin.ignore();
	return choice;
}

void dispVillage(map<string, tuple<int, string, string>> v) {
	cout << "Villager Details:\n";
	for (auto pair : v) {
	    cout << pair.first << " ["
	    	 << get<0>(pair.second) << ", "
			 << get<1>(pair.second) << ", "
			 << get<2>(pair.second) << "]\n";
	}
}

void addVillager(map<string, tuple<int, string, string>> &v) {
	string name;
	tuple<int, string, string> temp;
	cout << "Villager name: ";
	getline(cin, name);
	cout << "Friendship level: ";
	cin >> get<0>(temp);
	cin.ignore();
	cout << "Species: ";
	getline(cin, get<1>(temp));
	cout << "Catchphrase: ";
	getline(cin, get<2>(temp));
	v.insert({name, temp});
	cout << name << " added.\n";
}

void delVillager(map<string, tuple<int, string, string>> &v) {
	string toDelete;
	cout << "Enter the name of the villager to delete: ";
	getline(cin, toDelete);
	auto it = v.find(toDelete);
	if (it != v.end()) {

	}
	else
	   cout << toDelete << " not found." << endl;
}
