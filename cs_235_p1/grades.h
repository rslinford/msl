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
	grades(string courseId_in, int id_in, string grade_in);
	grades(istream &g);
	string getCourseId();
	string getId();
	string getGrade();
	//sort
	bool operator < (grades g) const;
	double converter(string letGrade);
	double calcGrd(double numGrade);
	void grades::crap();
};