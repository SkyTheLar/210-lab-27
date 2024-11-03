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
void incFriendship(map<string, tuple<int, string, string>>&);
void decFriendship(map<string, tuple<int, string, string>>&);
void vSearch(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {6, "Dragon", "Howdy!"};
    villagers["Raymond"] = {2, "Wolf", "Yippie"};
    villagers.insert({"Marshal", {8, "Rat", "I like cheese."}});

    // run menu loop
    int choice;
    while (choice != 6){
    	choice = mainMenu();
    	switch (choice) {
    	case 1: addVillager(villagers); dispVillage(villagers); break;
    	case 2: delVillager(villagers); dispVillage(villagers); break;
    	case 3: incFriendship(villagers); dispVillage(villagers); break;
    	case 4: decFriendship(villagers); dispVillage(villagers); break;
    	case 5: vSearch(villagers); break;
    	default: break;
    	}
    }

    return 0;
}

int mainMenu() {
	int choice;
	cout << "1. Add Villager\n"
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
	cout << "\nVillager Details:\n";
	for (auto pair : v) {
	    cout << pair.first << " ["
	    	 << get<0>(pair.second) << ", "
			 << get<1>(pair.second) << ", "
			 << get<2>(pair.second) << "]\n";
	}
	cout << endl;
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
		v.erase(it);
		cout << toDelete << " deleted.\n";
	}
	else
	   cout << toDelete << " not found.\n";
}

void incFriendship(map<string, tuple<int, string, string>> &v){
	for (auto it = v.begin(); it != v.end(); it++) {
		if (get<0>(it->second) < 10)
			get<0>(it->second)++;
	}
	cout << "Friendship increased.\n";
}

void decFriendship(map<string, tuple<int, string, string>> &v){
	for (auto it = v.begin(); it != v.end(); it++) {
		if (get<0>(it->second) > 0)
			get<0>(it->second)--;
	}
	cout << "Friendship decreased.\n";
}

void vSearch(map<string, tuple<int, string, string>> &v) {
	string toFind;
	cout << "Enter the name of the villager to search for: ";
	getline(cin, toFind);
	auto it = v.find(toFind);
	if (it != v.end()) {
		cout << "Displaying " << toFind << ":\n";
		cout << it->first << " ["
			 << get<0>(it->second) << ", "
		     << get<1>(it->second) << ", "
			 << get<2>(it->second) << "]\n\n";
	}
	else
	   cout << toFind << " not found.\n\n";
}
