#include "grades.h"


grades::grades(string courseId_in, int id_in, string grade_in){
	courseId = courseId_in;
	id = id_in;
	grade = grade_in;
}

grades::grades(istream &g){
	/*string id_in;
	string name_in;
	string address_in;
	string phone_in;*/

	getline(g, courseId);
	getline(g, id);
	getline(g, grade);
}

grades::grades(){}

istream& operator>> (istream& ig, grades& g){

	getline(ig, g.courseId);
	getline(ig, g.id);
	getline(ig, g.grade);
	return ig;
}

void grades::crap(){
	cout << id << "    " << grade << "    " << courseId << endl;
}

ostream& operator<< (ostream& os, grades& s){

	os << s.id << "    " << s.grade << "    " << s.courseId;
	return os;
}


string grades::getCourseId(){
	return courseId;
}

string grades::getId(){
	return id;
}

string grades::getGrade(){
	return grade;
}

//sort
double converter(string letGrade){
	double numGrade = 0;

	return numGrade;
}


double calcGrd(){
	double totGrade = 0;

	return totGrade;
}



bool grades::operator < (grades g) const {
	return id < g.id ||
		(id == g.id && courseId < g.courseId) ||
		(id == g.id && courseId == g.courseId && grade < g.grade);
}
