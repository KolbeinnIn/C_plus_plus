﻿// lokaverkefni.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

class Booking {
protected:
	int id;
	int capacity;
	int reserved;
public:
	int type;
	Booking(int i, int cab, int res, int t)
	{
		id = i;
		capacity = cab;
		reserved = res;
		type = t;
	}
	Booking()
	{
		id = 0;
		capacity = 0;
		reserved = 0;
		type = 0;
	}
	void virtual Syna_Booking()
	{
		if (reserved < 0) {
			reserved = 0;
		}
		int percentage = ((double)reserved / capacity) * 100;
		if (percentage > 105) {
			cout << "To many bookings";
		}
		else if (id < 0) {

		}
		else {
			std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << percentage << "% seats reserved" << endl;
		}
	}
	void reserveSeats(int number_ob_seats)
	{
		if (number_ob_seats < 0) {
			cout << "Cannot perform this operation" << endl;
		}
		else if ((((double)reserved + number_ob_seats / capacity) * 100) <= 105) {
			reserved += number_ob_seats;
		}
		else {
			cout << "Cannot perform this operation" << endl;
		}
	}
	void cancelReservations(int number_ob_seats)
	{
		if (number_ob_seats < 0) {
			cout << "Cannot perform this operation" << endl;
		}
		else if ((((double)reserved - number_ob_seats / capacity) * 100) >= 0) {
			reserved -= number_ob_seats;
		}
		else {
			cout << "Cannot perform this operation" << endl;
		}
	}
	int returnId() {
		return id;
	}
};
class FlightBooking : public Booking {
public:
	FlightBooking(int id, int capacity, int reserved, int type) : Booking(id, capacity, reserved, type){}
	void Syna_Booking()
	{
		if (reserved < 0) {
			reserved = 0;
		}
		int percentage = ((double)reserved / capacity) * 100;
		if (percentage > 105) {
			cout << "To many bookings";
		}
		else if (id < 0) {

		}
		else {
			std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << percentage << "% seats reserved" << endl;
		}
	}

};
class ShipBooking : public Booking {
public:
	ShipBooking(int id, int capacity, int reserved, int type) : Booking(id, capacity, reserved, type) {}
	void Syna_Booking()
	{
		if (reserved < 0) {
			reserved = 0;
		}
		int percentage = ((double)reserved / capacity) * 100;
		if (percentage > 105) {
			cout << "To many bookings";
		}
		else if (id < 0) {

		}
		else {
			std::cout << "Ship " << id << " : " << reserved << "/" << capacity << " " << percentage << "% seats reserved" << endl;
		}
	}

};
class BusBooking : public Booking {
public:
	BusBooking(int id, int capacity, int reserved, int type) : Booking(id, capacity, reserved, type) {}
	void Syna_Booking()
	{
		if (reserved < 0) {
			reserved = 0;
		}
		int percentage = ((double)reserved / capacity) * 100;
		if (percentage > 105) {
			cout << "To many bookings";
		}
		else if (id < 0) {

		}
		else {
			std::cout << "Bus " << id << " : " << reserved << "/" << capacity << " " << percentage << "% seats reserved" << endl;
		}
	}

};


class FlightList {
private:
	Booking **listi;
	int next;
	int staerd;
public:
	FlightList() {
		this->staerd = 2;
		listi = new Booking*[staerd];
		next = 0;
	}
	void setja_flight(FlightBooking stak) {
		if (next <= staerd - 1)
			listi[next++] = new FlightBooking(stak);
		else {
			Booking **temp = new Booking*[staerd * 2];
			for (int i = 0; i < staerd; i++)
				temp[i] = listi[i];

			delete[]listi;
			listi = temp;
			staerd *= 2;
			listi[next++] = new FlightBooking(stak);
		}
	}
	void setja_ship(ShipBooking stak) {
		if (next <= staerd - 1)
			listi[next++] = new ShipBooking(stak);
		else {
			Booking **temp = new Booking*[staerd * 2];
			for (int i = 0; i < staerd; i++)
				temp[i] = listi[i];

			delete[]listi;
			listi = temp;
			staerd *= 2;
			listi[next++] = new ShipBooking(stak);
		}
	}
	void setja_bus(BusBooking stak) {
		if (next <= staerd - 1)
			listi[next++] = new BusBooking(stak);
		else {
			Booking **temp = new Booking*[staerd * 2];
			for (int i = 0; i < staerd; i++)
				temp[i] = listi[i];

			delete[]listi;
			listi = temp;
			staerd *= 2;
			listi[next++] = new BusBooking(stak);
		}
	}

	int id(int b) {
		for (int i = 0; i < next; i++)
		{
			if (listi[i]->returnId() == b) {
				return i;
			}
		}
	}
	void syna() {
		for (int i = 0; i < next; i++){
			if (listi[i]->type == 1){
				listi[i]->Syna_Booking();
			}
		}
		for (int i = 0; i < next; i++){
			if (listi[i]->type == 2){
				listi[i]->Syna_Booking();
			}
		}
		for (int i = 0; i < next; i++){
			if (listi[i]->type == 3){
				listi[i]->Syna_Booking();
			}
		}
			
	}
	void add(int b, int reserved) {
		listi[b]->reserveSeats(reserved);
	}
	void cancel(int b, int reserved) {
		listi[b]->cancelReservations(reserved);
	}
	void del(int b) {
		//listi[b]->id = -1;
	}
	~FlightList() {
		delete[]listi;
	}
};


int main() {
	FlightList booking = FlightList();
	booking.setja_ship(ShipBooking(1, 400, 0, 2));
	booking.setja_flight(FlightBooking(3, 600, 0, 1));
	booking.setja_bus(BusBooking(4, 800, 0, 3));
	int asd = booking.id(2);
	booking.syna();
	string command = "";
	string type = "";
	int n;
	int id;
	int teljari = 0;
	int s = 0;
	while (command != "quit")
	{

		cout << "What would you like to do?: ";

		getline(cin, command);

		stringstream ss;
		ss << command;
		cout << endl;
		ss >> command >> type >> id >> n;
		int s = booking.id(id);
		if (command == "add") {
			booking.add(s, n);
		}
		else if (command == "cancel") {
			booking.cancel(s, n);
		}
		else if (command == "create") {
			if (type == "ship") {
				booking.setja_ship(ShipBooking(id, n, 0, 2));
			}
			else if (type == "flight") {
				booking.setja_flight(FlightBooking(id, n, 0, 1));
			}
			else if (type == "bus") {
				booking.setja_bus(BusBooking(id, n, 0, 3));
			}
		}
		else if (command == "delete") {
			booking.del(s);
		}
		booking.syna();
	}
	cout << endl;
	return 0;
}
