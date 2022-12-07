#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Restaurant {
    string _name;
    string _address;
    string _city;
    string _state;
    string _zipcode;
    string _phone;
    string _url;
    string _cuisine;
    string _rating;

public:
    Restaurant();
    Restaurant(string _name, string _address, string _city, string _state, string _zipcode, string _phone, string _url, string _cuisine, string _rating);
    string GetName();
    string GetAddress();
    string GetCity();
    string GetState();
    string GetZipcode();
    string GetPhone();
    string GetURL();
    string GetCuisine();
    string GetRating();

    void zipcodeMatch(vector<Restaurant>& r, string zipcode);
    void unorderedZipcodeMatch(vector<Restaurant>& r, string zipcode);
    void cuisineMatch(vector<Restaurant> &r, string cuisine, string city);
    void unorderedCuisineMatch(vector<Restaurant>& r, string cuisine, string city);
    void searchByName(vector<Restaurant>& r, string name);
    void unorderedSearchByName(vector<Restaurant>& r, string name);
    void topRestaurant(vector<Restaurant>& r, string zipcode);
    void unorderedTopRestaurant(vector<Restaurant>& r, string zipcode);
    void ratingInOrder(vector<Restaurant>& r, string city);
    void printRestaurants(vector<Restaurant>& r);
};


