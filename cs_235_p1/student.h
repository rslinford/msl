#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class student
{
private:
	string id;
	string name;
	string address;
	string phone;

public:
	student();
	student(const string& id, const string& name, const string& address, const string& phone);
	
	student(istream &s);
	
   const string& getID() const;
   const string& getName() const;
   const string& getAddress() const;
   const string& getPhone() const;

	bool operator< (const student& s) const;

	friend istream& operator>> (istream& is, student& s);
	friend ostream& operator<< (ostream& os, const student& s);
};

