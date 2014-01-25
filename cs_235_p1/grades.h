#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class grades{
private:
	string courseId;
	string id;
	string grade;
	double numberGrade;

public:
	grades();
	virtual ~grades();
	grades(string courseId_in, int id_in, string grade_in);
	grades(istream &g);
	string getCourseId();
	string getId();
	string getGrade();
	friend ostream& operator<< (ostream& os, grades& s);
	friend istream& operator>> (istream& ig, grades& g);

	//sort
	bool operator < (grades g) const;
	double calcGrd(double numGrade);
	void crap();
};