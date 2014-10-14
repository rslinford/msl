#include "student.h"
 
student::student() {
}
	
student::student(const string& id, const string& name, const string& address, const string& phone) : 
      id(id), name(name), address(address), phone(phone) {
}

student::student(istream &s) {
	getline(s, id);
	getline(s, name);
	getline(s, address);
	getline(s, phone);
}

string const & student::getID() const {
	return id;
}

string const & student::getName() const {
	return name;
}

string const & student::getAddress() const {
	return address;
}

string const & student::getPhone() const {
	return phone;
}

bool student::operator< (const student& s) const {
	return id < s.id;
}

istream& operator>> (istream& is, student& s) {
	getline(is, s.id);
	getline(is, s.name);
	getline(is, s.address);
	getline(is, s.phone);
	return is;
}

ostream& operator<< (ostream& os, const student& s) {
	os << s.name << endl;
	os << s.id << endl;
	os << s.phone << endl;
	os << s.address;
	return os;
}

