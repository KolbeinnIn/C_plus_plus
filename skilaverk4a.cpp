﻿// lab5310(1).cpp : Defines the entry point for the console application.
//
#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

class FlightBooking {
private:
	int id;
	int capacity;
	int reserved;
public:
	FlightBooking(int i, int cab, int res)
	{
		id = i;
		capacity = cab;
		reserved = res;
	}
	void Booking()
	{
		if (reserved < 0) {
			reserved = 0;
		}
		int percentage = ((double)reserved / capacity) * 100;
		if (percentage > 105) {
			cout << "To many bookings";
		}
		else {
			std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << percentage << "% seats reserved";
		}
	}
	void reserveSeats(int number_ob_seats)
	{	
		if (number_ob_seats < 0){
			cout << "Cannot perform this operation" << endl;
		}
		else if (((((double)reserved / capacity) * 100) + number_ob_seats) <= 105){
			reserved += number_ob_seats;
		}
		else{
			cout << "Cannot perform this operation" << endl;
		}
	}
	void cancelReservations(int number_ob_seats)
	{
		if (number_ob_seats < 0){
			cout << "Cannot perform this operation" << endl;
		}
		else if (((((double)reserved / capacity) * 100) - number_ob_seats) < 0){
			reserved -= number_ob_seats;
		}
		else{
			cout << "Cannot perform this operation" << endl;
		}
	}

};


int main() {
	int reserved,
		capacity;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking s = FlightBooking(1, capacity, reserved);
	s.Booking();
	cout << endl;
	string command = "";
	int n;
	while (command != "quit")
	{

		cout << "What would you like to do?: ";

		getline(cin, command);

		stringstream ss;
		ss << command;
		cout << endl;
		ss >> command >> n;
		if (command == "add") {
			s.reserveSeats(n);
		}
		else if (command == "cancel") {
			s.cancelReservations(n);
		}
		s.Booking();
		cout << endl;
		// handle the command
	}
	cout << endl;
	return 0;
}
