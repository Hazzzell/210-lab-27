#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // Milestone 1: Demo map with favorite colors
    map<string, vector<string>> villagerColors;

    // Insert elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // Display using range-based for loop
    cout << "Villagers and their favorite colors (range-based):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // Display using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (auto it = villagerColors.begin(); it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second)
            cout << color << " ";
        cout << endl;
    }

    // Delete an element
    villagerColors.erase("Raymond");

    // Search for an element
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)
            cout << color << " ";
        cout << endl;
    } else {
        cout << searchKey << " not found." << endl;
    }

    // Size and clear
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
