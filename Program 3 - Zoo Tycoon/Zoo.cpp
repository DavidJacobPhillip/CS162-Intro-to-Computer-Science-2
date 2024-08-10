#include <iostream>
#include <cstdlib>
#include <string>
#include "Zoo.hpp"
#include "Sealion.hpp"
#include "Bear.hpp"
#include "Tiger.hpp"

using namespace std;

// constructors and destructors
Zoo::Zoo(){
    balance = 100000;
	base_food = 80;

	// creating the array of bears
	b_num = 0;
	bears = new Bear[b_num];

	// creating the array of sealions
	s_num = 0;
	sealions = new Sealion[s_num];

	// creating the array of tigers
	t_num = 0;
	tigers = new Tiger[t_num];
}

Zoo::~Zoo(){
	delete[] bears;
	delete[] sealions;
	delete[] tigers;
}

//copy constructor & assignment operator overloader
Zoo::Zoo(const Zoo& existing) {
	this->t_num = existing.t_num;
	this->tigers = new Tiger[this->t_num];
	for (int i = 0; i < this->t_num; i++) {
		this->tigers[i] = existing.tigers[i];
	}

	this->b_num = existing.b_num;
	this->bears = new Bear[this->b_num];
	for (int i = 0; i < this->b_num; i++) {
		this->bears[i] = existing.bears[i];
	}

	this->s_num = existing.s_num;
	this->sealions = new Sealion[this->s_num];
	for (int i = 0; i < this->s_num; i++) {
		this->sealions[i] = existing.sealions[i];
	}
}

Zoo& Zoo::operator= (const Zoo& existing) {
	delete[] this->bears;
	delete[] this->tigers;
	delete[] this->sealions;

	this->t_num = existing.t_num;
	this->tigers = new Tiger[this->t_num];
	for (int i = 0; i < this->t_num; i++) {
		this->tigers[i] = existing.tigers[i];
	}

	this->b_num = existing.b_num;
	this->bears = new Bear[this->b_num];
	for (int i = 0; i < this->b_num; i++) {
		this->bears[i] = existing.bears[i];
	}

	this->s_num = existing.s_num;
	this->sealions = new Sealion[this->s_num];
	for (int i = 0; i < this->s_num; i++) {
		this->sealions[i] = existing.sealions[i];
	}

	return *this;
}

// getters & setters
int Zoo::get_balance(){ 
    return balance;
}

void Zoo::set_balance(int p_balance){
    balance = p_balance;
}

int Zoo::get_b_num() {
	return b_num;
}

int Zoo::get_t_num() {
	return t_num;
}

int Zoo::get_s_num() {
	return s_num;
}

void Zoo::set_b_num(int p_b_num) {
	b_num = p_b_num;
}

void Zoo::set_t_num(int p_t_num) {
	t_num = p_t_num;
}

void Zoo::set_s_num(int p_s_num) {
	s_num = p_s_num;
}

// increasing / decreasing size of animal arrays
void Zoo::bear_add() {
	b_num++;

	Bear* bears = new Bear[b_num];
	for (int i = 0; i < b_num - 1; i++) {
		bears[i].set_babies(this->bears[i].get_babies());
		bears[i].set_age(this->bears[i].get_age());
		bears[i].set_sick(this->bears[i].get_sick());
		bears[i].set_feed(this->bears[i].get_feed());
		bears[i].set_purchase(this->bears[i].get_purchase());
		bears[i].set_revenue(this->bears[i].get_revenue());
	}

	delete[] this->bears;
	this->bears = bears;
}

void Zoo::bear_sub(int avoid) {
	b_num--;
	int j = 0;

	Bear* bears = new Bear[b_num];
	for (int i = 0; i < b_num + 1; i++) {
		if (i != avoid) {
			bears[j].set_babies(this->bears[i].get_babies());
			bears[j].set_age(this->bears[i].get_age());
			bears[j].set_sick(this->bears[i].get_sick());
			bears[j].set_feed(this->bears[i].get_feed());
			bears[j].set_purchase(this->bears[i].get_purchase());
			bears[j].set_revenue(this->bears[i].get_revenue());
			j++;
		}
	}

	delete[] this->bears;
	this->bears = bears;
}

void Zoo::tiger_add() {
	t_num++;

	Tiger* tigers = new Tiger[t_num];
	for (int i = 0; i < t_num - 1; i++) {
		tigers[i].set_babies(this->tigers[i].get_babies());
		tigers[i].set_age(this->tigers[i].get_age());
		tigers[i].set_sick(this->tigers[i].get_sick());
		tigers[i].set_feed(this->tigers[i].get_feed());
		tigers[i].set_purchase(this->tigers[i].get_purchase());
		tigers[i].set_revenue(this->tigers[i].get_revenue());
	}

	delete[] this->tigers;
	this->tigers = tigers;
}

void Zoo::tiger_sub(int avoid) {
	t_num--;
	int j = 0;

	Tiger* tigers = new Tiger[t_num];
	for (int i = 0; i < t_num + 1; i++) {
		if (i != avoid) {
			tigers[j].set_babies(this->tigers[i].get_babies());
			tigers[j].set_age(this->tigers[i].get_age());
			tigers[j].set_sick(this->tigers[i].get_sick());
			tigers[j].set_feed(this->tigers[i].get_feed());
			tigers[j].set_purchase(this->tigers[i].get_purchase());
			tigers[j].set_revenue(this->tigers[i].get_revenue());
			j++;
		}
	}

	delete[] this->tigers;
	this->tigers = tigers;
}

void Zoo::sealion_add() {
	s_num++;
	Sealion* sealions = new Sealion[s_num];
	for (int i = 0; i < s_num - 1; i++) {
		sealions[i].set_babies(this->sealions[i].get_babies());
		sealions[i].set_age(this->sealions[i].get_age());
		sealions[i].set_sick(this->sealions[i].get_sick());
		sealions[i].set_feed(this->sealions[i].get_feed());
		sealions[i].set_purchase(this->sealions[i].get_purchase());
		sealions[i].set_revenue(this->sealions[i].get_revenue());
	}

	delete[] this->sealions;
	this->sealions = sealions;
}

void Zoo::sealion_sub(int avoid) {
	s_num--;
	int j = 0;

	Sealion* sealions = new Sealion[s_num];
	for (int i = 0; i < s_num + 1; i++) {
		if (i != avoid) {
			sealions[j].set_babies(this->sealions[i].get_babies());
			sealions[j].set_age(this->sealions[i].get_age());
			sealions[j].set_sick(this->sealions[i].get_sick());
			sealions[j].set_feed(this->sealions[i].get_feed());
			sealions[j].set_purchase(this->sealions[i].get_purchase());
			sealions[j].set_revenue(this->sealions[i].get_revenue());
			j++;
		}
	}
	delete[] this->sealions;
	this->sealions = sealions;
}

int Zoo::get_base_food() {
	return base_food;
}

void Zoo::set_base_food(int p_base_food) {
	base_food = p_base_food;
}

// getting the arrays of the animals
Bear* Zoo::get_bear() {
	return bears;
}

Tiger* Zoo::get_tiger() {
	return tigers;
}

Sealion* Zoo::get_sealion() {
	return sealions;
}

// game-design functions
void Zoo::current() {
	int adults = 0;
	int babies = 0;
	int adolescents = 0;

	// determining the number of tigers
	for (int i = 0; i < t_num; i++) {
		if (tigers[i].get_age() <= 6) {
			babies++;
		}
		else if (tigers[i].get_age() < 48) {
			adolescents++;
		}
		else {
			adults++;
		}
	}

	cout << "Tigers: " << t_num << endl;
	cout << " - Adults: " << adults << endl;
	cout << " - Adolescents: " << adolescents << endl;
	cout << " - Babies: " << babies << endl;

	adults = 0;
	babies = 0;
	adolescents = 0;
	cout << endl;

	// determining the number of bears
	for (int i = 0; i < b_num; i++) {
		if (bears[i].get_age() <= 6) {
			babies++;
		}
		else if (bears[i].get_age() < 48) {
			adolescents++;
		}
		else {
			adults++;
		}
	}

	cout << "Bears: " << b_num << endl;
	cout << " - Adults: " << adults << endl;
	cout << " - Adolescents: " << adolescents << endl;
	cout << " - Babies: " << babies << endl;

	adults = 0;
	babies = 0;
	adolescents = 0;
	cout << endl;

	// determining the number of sealions
	for (int i = 0; i < s_num; i++) {
		if (sealions[i].get_age() <= 6) {
			babies++;
		}
		else if (sealions[i].get_age() < 48) {
			adolescents++;
		}
		else {
			adults++;
		}
	}

	cout << "Sealions: " << s_num << endl;
	cout << " - Adults: " << adults << endl;
	cout << " - Adolescents: " << adolescents << endl;
	cout << " - Babies: " << babies << endl;
}

int Zoo::revenue() {
	int profit = 0;
	
	// calculating all of the money from the bears
	for (int i = 0; i < b_num; i++) {
		if (bears[i].get_age() <= 6) {
			profit += (bears[i].get_revenue() * 2);
		}
		else {
			profit += bears[i].get_revenue();
		}
	}

	// calculating all of the money from the tigers
	for (int i = 0; i < t_num; i++) {
		if (tigers[i].get_age() <= 6) {
			profit += (tigers[i].get_revenue() * 2);
		}
		else {
			profit += tigers[i].get_revenue();
		}
	}

	// calculating all of the money from the sealions
	for (int i = 0; i < s_num; i++) {
		if (sealions[i].get_age() <= 6) {
			profit += (sealions[i].get_revenue() * 2);
		}
		else {
			profit += sealions[i].get_revenue();
		}
	}

	return profit;
}

void Zoo::food_cost(int& cheap, int& regular, int& premium) {
	// changing the base food cost between 80%-120%
	set_base_food(((float) get_base_food() * (((rand() % 5) + 8.0) / 10.0)));

	// calculating food costs for bears
	for (int i = 0; i < b_num; i++) {
		if (bears[i].get_age() <= 6) {
			regular += (bears[i].get_feed() * 2 * get_base_food());
		}
		else {
			regular += bears[i].get_feed() * get_base_food();
		}
	}

	// calculating food costs for tigers
	for (int i = 0; i < t_num; i++) {
		if (tigers[i].get_age() <= 6) {
			regular += (tigers[i].get_feed() * 2 * get_base_food());
		}
		else {
			regular += tigers[i].get_feed() * get_base_food();
		}
	}

	// calculating food costs for sealions
	for (int i = 0; i < s_num; i++) {
		if (sealions[i].get_age() <= 6) {
			regular += (sealions[i].get_feed() * 2 * get_base_food());
		}
		else {
			regular += sealions[i].get_feed() * get_base_food();
		}
	}

	// calculating prices for cheap & premium
	premium = regular * 2;
	cheap = regular * 1 / 2;
}

void Zoo::ager() {
	// increasing age of bears by 1 month
	for (int i = 0; i < b_num; i++) {
		bears[i].set_age(bears[i].get_age() + 1);
	}

	// increasing age of tigers by 1 month
	for (int i = 0; i < t_num; i++) {
		tigers[i].set_age(tigers[i].get_age() + 1);

	}

	// increasing age of sealions by 1 month
	for (int i = 0; i < s_num; i++) {
		sealions[i].set_age(sealions[i].get_age() + 1);
	}
}

void Zoo::boom(){
	int extra = 0; // total extra profit
	int profit = 0; // profit per sealion
	for (int i = 0; i < get_s_num(); i++) {
		profit = rand() % 250 + 150;
		extra += profit;
	}

	cout << endl;
	cout << "EXTRA REVENUE: $" << extra << endl;
	set_balance(get_balance() + profit);
	cout << "BALANCE AFTER BOOM: $" << get_balance() << endl;
}

void Zoo::sick() {
	string animal = "";
	string age = "bear";
	int index = 0;
	int cost = 0;
	bool valid = true;
	string input = "";

	// choosing which animal is sick
	chooser(animal, index);
	determiner(animal, index, age, cost);

	cout << "It looks like a(n) " << age << " " << animal << " needs care!" << endl;
	cout << "It will cost $" << cost << " to treat the animal." << endl;
	cout << "Would you like to treat the animal? Input a 'yes' or 'no' response" << endl;
	
	// determining the user's response
	while (valid) {
		cin >> input; 
		if (input == "yes") {
			cout << "Treating the " << animal << "!" << endl;
			set_balance(get_balance() - cost);
			valid = false;
		}
		else if (input == "no") {

			cout << "index: " << index << endl;
			// removing the animal from the array
			cout << "Sadly, the " << animal << " has passed away from a lack of treatment." << endl;
			if (animal == "bear") {
				bear_sub(index);
			}
			else if (animal == "tiger") {
				tiger_sub(index);
			}
			else {
				sealion_sub(index);
			}
			valid = false;
		}
		else {
			cout << "Error, you have inputed an invalid response, please enter 'yes' or 'no' " << endl;
		}
	}

	cout << endl;
	cout << "BALANCE AFTER TREATMENT: $" << get_balance() << endl;
}

void Zoo::chooser(string &animal, int &index) {
	bool valid = true;
	int option = 0;

	// determining which animal to select, and what index
	while (valid) {
		option = rand() % 3 + 1;

		if (option == 1) {
			if (get_b_num() != 0) {
				animal = "bear";
				index = rand() % get_b_num();
				valid = false;
			}
		}
		else if (option == 2) {
			if (get_t_num() != 0) {
				animal = "tiger";
				index = rand() % get_t_num();
				valid = false;
			}
		}
		else {
			if (get_s_num() != 0) {
				animal = "sealion";
				index = rand() % get_s_num();
				valid = false;
			}
		}
	}
}

void Zoo::determiner(string& animal, int& index, string& age, int& cost) {
	// this function is over 20 lines of code because it contains the series of if-else statements to determine the cost and name of the animal
	// determining the age of the animal and cost of treatment
	
	if (animal == "bear") {
		if (bears[index].get_age() <= 6) {
			age = "baby";
			cost = bears[index].get_sick() * 2;
		}
		else if (bears[index].get_age() < 48) {
			age = "adolescent";
			cost = bears[index].get_sick();
		}
		else {
			age = "adult";
			cost = bears[index].get_sick();
		}
	}
	else if (animal == "tiger") {
		if (tigers[index].get_age() <= 6) {
			age = "baby";
			cost = tigers[index].get_sick() * 2;
		}
		else if (tigers[index].get_age() < 48) {
			age = "adolescent";
			cost = tigers[index].get_sick();
		}
		else {
			age = "adult";
			cost = tigers[index].get_sick();
		}
	}
	else {
		if (sealions[index].get_age() <= 6) {
			age = "baby";
			cost = sealions[index].get_sick() * 2;
		}
		else if (sealions[index].get_age() < 48) {
			age = "adolescent";
			cost = sealions[index].get_sick();
		}
		else {
			age = "adult";
			cost = sealions[index].get_sick();
		}
	}
	
}

void Zoo::birth() {
	bool valid = true;
	int adults = 0;
	string animal;
	int index;

	// determines if there are adults present to produce babies
	// number of adult bears
	for (int i = 0; i < b_num; i++) {
		if (bears[i].get_age() >= 48) {
			adults++;
		}
	}

	// number of adult tigers
	for (int i = 0; i < t_num; i++) {
		if (tigers[i].get_age() >= 48) {
			adults++;
		}
	}

	// number of adult sealions
	for (int i = 0; i < s_num; i++) {
		if (sealions[i].get_age() >= 48) {
			adults++;
		}
	}

	// chooses a random adult animal
	if (adults != 0) {
		while (valid) {
			chooser(animal, index);
			if (animal == "bear") {
				if (bears[index].get_age() >= 48) {
					for (int i = 0; i < bears[i].get_babies(); i++) {
						bear_add();
					}
					cout << "A " << animal << " has given birth to " << bears[index].get_babies() << " babies!" << endl;
					valid = false;
				}
			}
			else if (animal == "tiger") {
				if (tigers[index].get_age() >= 48) {
					for (int i = 0; i < tigers[i].get_babies(); i++) {
						tiger_add();
					}
					valid = false;
					cout << "A " << animal << " has given birth to " << tigers[index].get_babies() << " babies!" << endl;
				}
			}
			else {
				if (sealions[index].get_age() >= 48) {
					for (int i = 0; i < sealions[i].get_babies(); i++) {
						sealion_add();
					}
					valid = false;
					cout << "A " << animal << " has given birth to " << sealions[index].get_babies() << " baby!" << endl;
				}
			}

		}
	}
	else {
		cout << "No special events this turn!" << endl;
	}
}