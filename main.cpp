// COMSC-210 | Lab 27 | Keng C Chan
// IDE used: Visual Studio Code (VS Code)
#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// Display all villagers
void displayVillagers(const map<string, tuple<int, string, string>>& villagers) {
    cout << "\nVillager details:" << endl;
    for (const auto& pair : villagers) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]" << endl;
    }
}

// Add villager
void addVillager(map<string, tuple<int, string, string>>& villagers) {
    string name, species, catchphrase;
    int friendship;

    cout << "Villager name: ";
    cin >> name;
    cout << "Friendship level: ";
    cin >> friendship;
    cout << "Species: ";
    cin >> species;
    cin.ignore();
    cout << "Catchphrase: ";
    getline(cin, catchphrase);

    villagers[name] = make_tuple(friendship, species, catchphrase);
    cout << name << " added." << endl;
}

// Delete villager
void deleteVillager(map<string, tuple<int, string, string>>& villagers) {
    string name;
    cout << "Enter villager name to delete: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        villagers.erase(it);
        cout << name << " deleted." << endl;
    } else {
        cout << "Villager not found." << endl;
    }
}

// Increase friendship
void increaseFriendship(map<string, tuple<int, string, string>>& villagers) {
    string name;
    cout << "Enter villager name to increase friendship: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        get<0>(it->second) += 1;
        cout << name << "'s friendship increased." << endl;
    } else {
        cout << "Villager not found." << endl;
    }
}

// Decrease friendship
void decreaseFriendship(map<string, tuple<int, string, string>>& villagers) {
    string name;
    cout << "Enter villager name to decrease friendship: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        if (get<0>(it->second) > 0)
            get<0>(it->second) -= 1;
        cout << name << "'s friendship decreased." << endl;
    } else {
        cout << "Villager not found." << endl;
    }
}

// Search villager
void searchVillager(const map<string, tuple<int, string, string>>& villagers) {
    string name;
    cout << "Enter villager name to search: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        cout << it->first << " ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
    } else {
        cout << "Villager not found." << endl;
    }
}

int main() {
    map<string, tuple<int, string, string>> villagers;
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    int choice;
    do {
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addVillager(villagers); break;
            case 2: deleteVillager(villagers); break;
            case 3: increaseFriendship(villagers); break;
            case 4: decreaseFriendship(villagers); break;
            case 5: searchVillager(villagers); break;
            case 6: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice." << endl; break;
        }

        if (choice != 6)
            displayVillagers(villagers);

    } while (choice != 6);

    return 0;
}

