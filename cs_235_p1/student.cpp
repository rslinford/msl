#include "student.h"
 
student::student(){
	//name;
	//id;
	//address;
	//phone;
}

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

istream& operator>> (istream& is, student& s){

	getline(is, s.id);
	getline(is, s.name);
	getline(is, s.address);
	getline(is, s.phone);
	return is;
}

ostream& operator<< (ostream& os, student& s){

	os << s.name << endl;
	os << s.id << endl;
	os << s.phone << endl;
	os << s.address;
	return os;
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