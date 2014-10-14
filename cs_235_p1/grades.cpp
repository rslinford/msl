#include "grades.h"

int grades::instCounter = 0;

grades::grades() : inst(instCounter) {
   cout << endl << "Construct grade [" << inst << "] (no arg) " << *this << endl;
   instCounter++;
}

grades::grades(const grades& g) : inst(instCounter) {
   cout << endl << "Construct grade [" << inst << "] (copied) from grade [" << g.inst << "]" << endl;
   instCounter++;
}

grades::~grades() {
   cout << endl << "Destruct grade [" << inst << "] " << *this << endl;
}

grades::grades(const string& courseId, const string& id, const string& grade) :
   courseId(courseId), id(id), grade(grade), inst(instCounter) {
   cout << endl << "Construct grade [" << inst << "] (all arg)" << *this << endl;
   instCounter++;
}

grades::grades(istream &is) : inst(instCounter) {
	getline(is, courseId);
	getline(is, id);
	getline(is, grade);
   cout << endl << "Construct grade [" << inst << "] (stream arg)" << endl;
   instCounter++;
}

const string& grades::getCourseId() {
	return courseId;
}

const string& grades::getId() {
	return id;
}

const string& grades::getGrade() {
	return grade;
}

grades& grades::operator= (const grades& g) {
   if (this == &g) {
      return *this;
   }
   cout << endl << "Assign grade [" << g.inst << "] to grade [" << inst << "]" << endl << "   (" << *this << ") = (" << g << ")" << endl;
   courseId = g.courseId;
   id = g.id;
   grade = g.grade;
   return *this;
}

bool grades::operator< (const grades& g) const {
	return id < g.id ||
		(id == g.id && courseId < g.courseId) ||
		(id == g.id && courseId == g.courseId && grade < g.grade);
}

ostream& operator<< (ostream& os, const grades& g) {
	os << g.inst << "] id(" << g.id << ") grade(" << g.grade << ") courseId(" << g.courseId << ")";
	return os;
}
/*
ostream& operator<< (ostream& os, grades& g) {
	os << g.id << "    " << g.grade << "    " << g.courseId;
	return os;
}
*/

istream& operator>> (istream& ig, grades& g){
	getline(ig, g.courseId);
	getline(ig, g.id);
	getline(ig, g.grade);
	return ig;
}


