#include <iostream>
#include <cstdlib>
#include <string>
#include "Animal.hpp"

using namespace std;

// constructor & destructor
Animal::Animal(string animal){
    if (animal == "tiger") {
        babies = 3;
        age = 0;
        sick = 6000;
        feed = 5;
        purchase = 12000;
        revenue = 1200;
    }
    else if (animal == "bear") {
        babies = 2;
        age = 0;
        sick = 2500;
        feed = 3;
        purchase = 5000;
        revenue = 1200;
    }
    else {
        babies = 1;
        age = 0;

        sick = 350;
        feed = 1;
        purchase = 700;

        revenue = 70;
    }
}

Animal::~Animal(){

}

// setters & getters
int Animal::get_babies() {
    return babies;
}

int Animal::get_age() {
    return age;
}

int Animal::get_sick() {
    return sick;
}

int Animal::get_feed() {
    return feed;
}

int Animal::get_purchase() {
    return purchase;
}

int Animal::get_revenue() {
    return revenue;
}

void Animal::set_babies(int p_babies) {
    babies = p_babies;
}

void Animal::set_age(int p_age) {
    age = p_age;
}

void Animal::set_sick(int p_sick) {
    sick = p_sick;
}

void Animal::set_feed(int p_feed) {
    feed = p_feed;
}

void Animal::set_purchase(int p_purchase) {
    purchase = p_purchase;
}

void Animal::set_revenue(int p_revenue) {
    revenue = p_revenue;
}