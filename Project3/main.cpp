#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream>
#include "restaurant.h"
#include <algorithm>
using namespace std;

void GetDataFromFile(string filePath, vector<Restaurant>& restaurants) {
    ifstream file(filePath);

    if (file.is_open()) {
        // Read the heading data from the file
        string lineFromFile;
        getline(file, lineFromFile);

        // Get all entries from the file, one line at a time
        while (getline(file, lineFromFile)) {
            istringstream stream(lineFromFile);

            string name, address, city, state, zipcode, phone, url, cuisine, rating;

            getline(stream, name, ',');
            getline(stream, address, ',');
            getline(stream, city, ',');
            getline(stream, state, ',');
            getline(stream, zipcode, ',');
            getline(stream, phone, ',');
            getline(stream, url, ',');
            getline(stream, cuisine, ',');
            cuisine.erase(std::remove(cuisine.begin(), cuisine.end(), '\r'), cuisine.end());
            getline(stream, rating, ',');
            rating.erase(std::remove(rating.begin(), rating.end(), '\r'), rating.end());

            Restaurant set(name, address, city, state, zipcode, phone, url, cuisine, rating);
            restaurants.push_back(set);
        }
    }
    else if (!file.is_open()) {
        cout << "Could not open file." << endl;
    }
}

int main() {
    Restaurant obj;

    vector<Restaurant> rList;

    GetDataFromFile("restaurants-database.csv", rList);
    string zipcode;
    string cuisine;
    string city;
    string name;
    int option;

    do {
        cout << "Menu Options: " << endl;
        cout << "1. Search restaurants by zip code (map)" << endl;
        cout << "2. Search restaurants by zip code (unordered map)" << endl;
        cout << "3. Search restaurants by city and cuisine (delivered by map)" << endl;
        cout << "4. Search restaurants by city and cuisine (unordered map)" << endl;
        cout << "5. Search restaurant by name (map)" << endl;
        cout << "6. Search restaurant by name (unordered map)" << endl;
        cout << "7. Search top restaurants by zipcode (map)" << endl;
        cout << "8. Search top restaurants by zipcode (unordered map)" << endl;
        cout << "9. Print restaurant's rating in descending order" << endl;
        cout << "10. Print all restaurants" << endl;
        cout << "11. Exit the program" << endl;

        cin >> option;

        switch (option)
        {
            case 1: {
                cout << "Please enter your zipcode." << endl;
                cin >> zipcode;
                obj.zipcodeMatch(rList, zipcode);
                break;
            }
            case 2: {
                cout << "Please enter your zipcode." << endl;
                cin >> zipcode;
                obj.unorderedZipcodeMatch(rList, zipcode);
                break;
            }
            case 3:
                cin.ignore();
                cout << "Please enter your city." << endl;
                getline(cin, city);

                cout << "Please enter your choice of cuisine." << endl;

                getline(cin, cuisine);
                obj.cuisineMatch(rList, cuisine, city);
                break;
            case 4:
                cin.ignore();
                cout << "Please enter your city." << endl;
                getline(cin, city);

                cout << "Please enter your choice of cuisine." << endl;

                getline(cin, cuisine);
                obj.unorderedCuisineMatch(rList, cuisine, city);
                break;
            case 5:
                cin.ignore();
                cout << "Please enter restaurant's name." << endl;
                getline(cin, name);
                obj.searchByName(rList, name);
                break;
            case 6:
                cin.ignore();
                cout << "Please enter restaurant's name." << endl;
                getline(cin,name);
                obj.unorderedSearchByName(rList, name);
                break;
            case 7:
                cin.ignore();
                cout << "Please enter restaurant's zipcode." << endl;
                getline(cin,zipcode);
                obj.topRestaurant(rList, zipcode);
                break;
            case 8:
                cin.ignore();
                cout << "Please enter restaurant's zipcode." << endl;
                getline(cin,zipcode);
                obj.unorderedTopRestaurant(rList, zipcode);
                break;
            case 9:
                cin.ignore();
                cout << "Please enter desired city." << endl;
                getline(cin,city);
                obj.ratingInOrder(rList, city);
                break;
            case 10:
                obj.printRestaurants(rList);
                break;
        }
    }
    while (option != 11);
    return 0;
}
