//Program #7: Crazy Eights: Card.cpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Card Class Implementation Code: Card.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "Card.hpp"

using namespace std;

// constructor & destructor
card::card(){
   rank = 0;
   suit = 0;
}

card::~card(){

}

// getters & setters
string card::get_rank(){
   string convert;

   switch (rank + 1){
      case 1:
	 convert = "2";
	 break;
      case 2:
	 convert = "3";
	 break;
      case 3:
	 convert = "4";
	 break;
      case 4:
	 convert = "5";
	 break;
      case 5:
	 convert = "6";
	 break;
      case 6:
	 convert = "7";
	 break;
      case 7:
	 convert = "8";
	 break;
      case 8:
	 convert = "9";
	 break;
      case 9:
	 convert = "10";
	 break;
      case 10:
	 convert = "J";
	 break;
      case 11:
	 convert = "Q";
	 break;
      case 12:
	 convert = "K";
	 break;
      case 13:
	 convert = "A";
	 break;
   }
   return convert;
}

string card::get_suit(){
   string convert;

   switch (suit + 1){
      case 1:
	 convert = "H";
	 break;
      case 2:
	 convert = "D";
	 break;
      case 3:
	 convert = "S";
	 break;
      case 4:
	 convert = "C";
	 break;
   }
   return convert;

}

void card::set_suit(string p_suit){
   int convert;

   if (p_suit == "H"){
      convert = 0;
   } else if (p_suit == "D"){
      convert = 1;
   } else if (p_suit == "S"){
      convert = 2;
   } else if (p_suit == "C"){
      convert = 3;
   }

   suit = convert;
}

void card::set_rank(string p_rank){
   int convert;

   if (p_rank == "2"){
      convert = 0;
   } else if (p_rank == "3"){
      convert = 1;
   } else if (p_rank == "4"){
      convert = 2;
   } else if (p_rank == "5"){
      convert = 3;
   } else if (p_rank == "6"){
      convert = 4;
   } else if (p_rank == "7"){
      convert = 5;
   } else if (p_rank == "8"){
      convert = 6;
   } else if (p_rank == "9"){
      convert = 7;
   } else if (p_rank == "10"){
      convert = 8;
   } else if (p_rank == "J"){
      convert = 9;
   } else if (p_rank == "Q"){
      convert = 10;
   } else if (p_rank == "K"){
      convert = 11;
   } else if (p_rank == "A"){
      convert = 12;
   }

   rank  = convert;
}

string card::converter(int p_rank){
   string convert;

   if (p_rank == 0){
      convert = "2";
   } else if (p_rank == 1){
      convert = "3";
   } else if (p_rank == 2){
      convert = "4";
   } else if (p_rank == 3){
      convert = "5";
   } else if (p_rank == 4){
      convert = "6";
   } else if (p_rank == 5){
      convert = "7";
   } else if (p_rank == 6){
      convert = "8";
   } else if (p_rank == 7){
      convert = "9";
   } else if (p_rank == 8){
      convert = "10";
   } else if (p_rank == 9){
      convert = "J";
   } else if (p_rank == 10){
      convert = "Q";
   } else if (p_rank == 11){
      convert = "K";
   } else if (p_rank == 12){
      convert = "A";
   }

   return convert;
}

