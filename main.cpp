// COMSC-210 | Lab 27 | Keng C Chan
// IDE used: Visual Studio Code (VS Code)
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // Milestone 2: Demo map with tuple values
    map<string, tuple<int, string, string>> villagers;

    // Insert elements: {friendship, species, catchphrase}
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers.insert({"Raymond", make_tuple(8, "Cat", "Nice fit")});

    // Display using range-based for loop
    cout << "Villager details (range-based):" << endl;
    for (auto& pair : villagers) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]" << endl;
    }

    // Search example
    string searchKey = "Drago";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {
        cout << "\nFound " << searchKey << ": ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
    } else {
        cout << searchKey << " not found." << endl;
    }

    return 0;
}
