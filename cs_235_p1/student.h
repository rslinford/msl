#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class student
{
private:
	string name;
	string id;
	string address;
	string phone;
	


public:
	student();
	student(string id_in, string name_in, string address_in, string phone_in);
	student(istream &s);
	friend istream& operator>> ( istream& is, student& s ); 
	friend ostream& operator<< (ostream& os, student& s);
	string getName();
	string getAddress();
	string getPhone();
	const string &getID();
	void printStdt();
	vector<student> students; 

	bool operator < (const student& s) const;
	void dump();



};


