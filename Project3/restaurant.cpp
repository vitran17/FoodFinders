#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include "restaurant.h"
using namespace std;

Restaurant::Restaurant()
{
    _name = "";
    _address = " ";
    _city = " ";
    _state = " ";
    _zipcode = " ";
    _phone = " ";
    _url = " ";
    _cuisine = " ";
    _rating = " ";
}

Restaurant::Restaurant(string name, string address, string city, string state, string zipcode, string phone, string url, string cuisine, string rating) {
    _name = name;
    _address = address;
    _city = city;
    _state = state;
    _zipcode = zipcode;
    _phone = phone;
    _url = url;
    _cuisine = cuisine;
    _rating = rating;
}

string Restaurant::GetName() {
    return _name;
}

string Restaurant::GetAddress() {
    return _address;
}

string Restaurant::GetCity() {
    return _city;
}

string Restaurant::GetState() {
    return _state;
}

string Restaurant::GetZipcode() {
    return _zipcode;
}

string Restaurant::GetPhone() {
    return _phone;
}

string Restaurant::GetURL() {
    return _url;
}

string Restaurant::GetCuisine() {
    return _cuisine;
}

string Restaurant::GetRating() {
    return _rating;
}

void Restaurant::zipcodeMatch(vector<Restaurant>& r, string zipcode)
{
    map<string, vector<Restaurant>> restaurants;
    for (int i = 0; i < r.size(); i++) {
        if (r[i].GetZipcode() == zipcode) {
            restaurants[r[i].GetZipcode()].push_back(r[i]);
        }
    }
    if (restaurants[zipcode].empty()) {
        cout << "There are no restaurants found matching that zipcode." << endl;
    }
    else {
        cout << "Here are some awesome places to eat in your zipcode! Bon appetit!" << "\n" << endl;
        for (auto iter: restaurants) {
            for (auto it: iter.second) {
                cout << it.GetName() << endl;
                cout << it.GetAddress() << endl;
                cout << it.GetCity() << ", " << it.GetState() << ", " << it.GetZipcode() << endl;
                cout << it.GetPhone() << "\n" << endl;
            }
        }
    }
}

void Restaurant::unorderedZipcodeMatch(vector<Restaurant>& r, string zipcode) {
    unordered_map<string, vector<Restaurant>> restaurants;
    for (int i = 0; i < r.size(); i++) {
        if (r[i].GetZipcode() == zipcode) {
            restaurants[r[i].GetZipcode()].push_back(r[i]);
        }
    }

    if (restaurants[zipcode].empty()) {
        cout << "There are no restaurants found matching that zipcode." << endl;
    }
    else {
        cout << "Here are some awesome places to eat in your zipcode! Bon appetit!" << "\n" << endl;
        for (auto iter: restaurants) {
            for (auto it: iter.second) {
                cout << it.GetName() << endl;
                cout << it.GetAddress() << endl;
                cout << it.GetCity() << ", " << it.GetState() << ", " << it.GetZipcode() << endl;
                cout << it.GetPhone() << endl;
                cout << it.GetURL() << "\n" << endl;
            }
        }
    }
}

// get all restaurants that match the cuisine
void Restaurant::cuisineMatch(vector<Restaurant> &r, string cuisine, string city)
{
    vector<Restaurant> restaurants_city;
    map<string, vector<Restaurant>> restaurants_cuisine;

    for (int i = 0; i < r.size(); i++)
    {
        if(r[i].GetCity() == city){
            restaurants_city.push_back(r[i]);
        }
    }
    for (int i = 0; i < restaurants_city.size(); i++) {
        size_t found = restaurants_city[i].GetCuisine().find(cuisine);
        if (found != string::npos){
            restaurants_cuisine[cuisine].push_back(restaurants_city[i]);
        }
    }

    if (restaurants_cuisine[cuisine].empty()) {
        cout << "There are no restaurants found matching that cuisine and city." << endl;
    }
    else {
        cout << "Here are some " << cuisine << " restaurants that are sure to satisfy your hunger in " << city << "! Bon appetit!" << "\n" << endl;
        for (auto iter: restaurants_cuisine[cuisine]) {
            cout << iter.GetName() << endl;
            cout << iter.GetAddress() << endl;
            cout << iter.GetCity() << ", " << iter.GetState() << " " << iter.GetZipcode() << endl;
            cout << iter.GetPhone() << "\n" << endl;
        }
    }
}

void Restaurant::unorderedCuisineMatch(vector<Restaurant>& r, string cuisine, string city) {
    vector<Restaurant> restaurants_city;
    unordered_map<string, vector<Restaurant>> restaurants_cuisine;

    for (int i = 0; i < r.size(); i++)
    {
        if(r[i].GetCity() == city){
            restaurants_city.push_back(r[i]);
        }
    }
    for (int i = 0; i < restaurants_city.size(); i++) {
        size_t found = restaurants_city[i].GetCuisine().find(cuisine);
        if (found != string::npos){
            restaurants_cuisine[cuisine].push_back(restaurants_city[i]);
        }
    }

    if (restaurants_cuisine[cuisine].empty()) {
        cout << "There are no restaurants found matching that cuisine and city." << endl;
    }
    else {
        cout << "Here are some " << cuisine << " restaurants that are sure to satisfy your hunger in " << city << "! Bon appetit!" << "\n" << endl;
        for (auto iter: restaurants_cuisine[cuisine]) {
            cout << iter.GetName() << endl;
            cout << iter.GetAddress() << endl;
            cout << iter.GetCity() << ", " << iter.GetState() << " " << iter.GetZipcode() << endl;
            cout << iter.GetPhone() << "\n" << endl;
        }
    }
}

// gets all restaurants that match input restaurant name
void Restaurant::searchByName(vector<Restaurant>& r, string name)
{
    map<string, vector<Restaurant>> restaurants_name;

    for (int i = 0; i < r.size(); i++)
    {
        size_t found = r[i].GetName().find(name);
        if (found != string::npos) {
            restaurants_name[name].push_back(r[i]);
        }
    }

    if (restaurants_name[name].empty()) {
        cout << "There are no restaurants found matching that name." << endl;
    }
    else {
        cout << "Here are the locations of all " << name << " restaurants. Bon appetit!" << "\n" << endl;
        for (auto i: restaurants_name[name]) {
            cout << i.GetAddress() << endl;
            cout << i.GetCity() << ", " << i.GetState() << " " << i.GetZipcode() << endl;
            cout << i.GetPhone() << endl;
            cout << i.GetURL() << '\n' << endl;
        }
    }
}

void Restaurant::unorderedSearchByName(vector<Restaurant>& r, string name)
{
    unordered_map<string, vector<Restaurant>> restaurants_name;

    for (int i = 0; i < r.size(); i++)
    {
        size_t found = r[i].GetName().find(name);
        if (found != string::npos) {
            restaurants_name[name].push_back(r[i]);
        }
    }

    if (restaurants_name[name].empty()) {
        cout << "There are no restaurants found matching that name." << endl;
    }
    else {
        cout << "Here are the locations of all " << name << " restaurants. Bon appetit!" << "\n" << endl;
        for (auto i: restaurants_name[name]) {
            cout << i.GetAddress() << endl;
            cout << i.GetCity() << ", " << i.GetState() << " " << i.GetZipcode() << endl;
            cout << i.GetPhone() << endl;
            cout << i.GetURL() << '\n' << endl;
        }
    }
}

void Restaurant::topRestaurant(vector<Restaurant>& r, string zipcode) {
    map<string, vector<Restaurant>> topRest;

    for (int i = 0; i < r.size(); i++)
    {
        size_t found = r[i].GetZipcode().find(zipcode);
        if (found != string::npos) {
            topRest[zipcode].push_back(r[i]);
        }
    }

    for (auto& iter : topRest[zipcode])
    {
            if (iter.GetRating() == "5") {
                cout << "Rating: *****" << endl;
                cout << iter.GetName() << endl;
                cout << iter.GetAddress() << endl;
                cout << iter.GetCity() << ", " << iter.GetState() << " " << iter.GetZipcode() << endl;
                cout << iter.GetPhone() << endl;
                cout << iter.GetURL() << endl;
                cout << iter.GetCuisine() << '\n' << endl;
            }
    }
}

void Restaurant::unorderedTopRestaurant(vector<Restaurant>& r, string zipcode) {
    unordered_map<string, vector<Restaurant>> topRest;

    for (int i = 0; i < r.size(); i++)
    {
        size_t found = r[i].GetZipcode().find(zipcode);
        if (found != string::npos) {
            topRest[zipcode].push_back(r[i]);
        }
    }

    for (auto& iter : topRest[zipcode])
    {
        if (iter.GetRating() == "5") {
            cout << "Rating: *****" << endl;
            cout << iter.GetName() << endl;
            cout << iter.GetAddress() << endl;
            cout << iter.GetCity() << ", " << iter.GetState() << " " << iter.GetZipcode() << endl;
            cout << iter.GetPhone() << endl;
            cout << iter.GetURL() << endl;
            cout << iter.GetCuisine() << '\n' << endl;
        }
    }
}

void Restaurant::ratingInOrder(vector<Restaurant>& r, string city)
{
    map<string, vector<Restaurant>> rest;

    for (int i = 0; i < r.size(); i++) {
        size_t found = r[i].GetCity().find(city);
        if (found != string::npos) {
            rest[r[i].GetRating()].push_back(r[i]);
        }
    }

    cout << '\n' << "The food critics has decided! Here are the restaurants in your city from terrible to excellent! Bon appetit!" << endl;
    cout << endl;
    for(auto it : rest)
    {
        for (auto iter : it.second) {
            cout << "Rating: " << string(stoi(iter.GetRating()), '*') << endl;
            cout << iter.GetName() << endl;
            cout << iter.GetAddress() << endl;
            cout << iter.GetCity() << ", " << iter.GetState() << " " << iter.GetZipcode() << endl;
            cout << iter.GetPhone() << endl;
            cout << iter.GetURL() << endl;
            cout << iter.GetCuisine() << '\n' << endl;
        }
    }
}

void Restaurant::printRestaurants(vector<Restaurant>& r) {
    for (auto i: r) {
        cout << i.GetName() << endl;
        cout << i.GetAddress() << endl;
        cout << i.GetCity() << ", " << i.GetState() << " " << i.GetZipcode() << endl;
        cout << i.GetPhone() << endl;
        cout << i.GetURL() << endl;
        cout << i.GetCuisine() << '\n' << endl;
    }
}