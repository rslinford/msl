#include "student.h"
 
student::student(string id_in, string name_in, string address_in, string phone_in){
	name = name_in;
	id = id_in;
	address = address_in;
	phone = phone_in;
}
void student::dump(){
	cout << name << endl;
	cout << id << endl;
	cout << phone << endl;
	cout << address << endl;
}
student::student(istream &s){
	/*string id_in;
	string name_in;
	string address_in;
	string phone_in;*/

	getline(s, id);
	getline(s, name);
	getline(s, address);
	getline(s, phone);

	/*name = name_in;
	id = id_in;
	address = address_in;
	phone = phone_in;*/
}


string student::getName(){
	return name;
}

bool student::operator < (const student& s) const {
	return id < s.id;
}

string student::getAddress(){
	return address;
}

string student::getPhone(){
	return phone;
}

const string &student::getID(){
	return id;
}
//
//void student::printStdt(){
//
//}