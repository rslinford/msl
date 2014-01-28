#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class grades{
private:
	string courseId;
	string id;
	string grade;

public:	
	const int inst;
	
private:
	static int instCounter;

public:
	grades();
	~grades();
	grades(const grades& g);
	grades(const string& courseId, const string& id, const string& grade);
	grades(istream &g);
	
	const string& getCourseId();
	const string& getId();
	const string& getGrade();
	
   grades& operator= (const grades& g);
	bool operator< (const grades& g) const;
	
	friend ostream& operator<< (ostream& os, const grades& g);
	friend istream& operator>> (istream& is, grades& g);
};

