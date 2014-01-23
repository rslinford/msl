//#include <iostream>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//	ifstream stdntFl;
//	stdntFl.open("");
//	while (!stdntFl.eof)
//	{
//		getline(stdntFl, );
//	}
//	stdntFl.close();
//
//
//
//	return 0;
//}






#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <vector>
#include "grades.h"
#include "student.h"
using namespace std;


//out << fixed << setprecision(2) << setfill('0') << gpa; //output gpa in correct format


//while (getline(in, s)) {  //Detecting eol in getline
//}


int main(int argc, char *argv[]) {
	
	
	for (int i = 0; i < argc; i++){
		cout << argv[i] << endl;
	}
	

	ifstream in_put;
	in_put.open(argv[1]);
	student s(in_put);
	vector<student> studentlist; 
	studentlist.push_back(s);

	student charles2(in_put);
	studentlist.push_back(charles2);
	
	sort (studentlist.begin(), studentlist.end());

	for (int i = 0; i < studentlist.size(); i++){
		studentlist[i].dump();
	}

	while (getline(inGrades, g)) {
		
	}
	ifstream inGrades;
	inGrades.open(argv[2]);
	grades g(inGrades);
	vector<grades> stdGrades;
	stdGrades.push_back(g);
	
	for (int i = 0; i < stdGrades.size(); i++){
		stdGrades[i].crap();
	}


	//bool b = charles < charles2;
	//cout << b << endl; 
	//b = charles < charles2;
	//cout << b << endl;
	/*string stdtFl(argv[1]);
	string gradFl(argv[2]);
	string quriFl(argv[3]);
	string outFl(argv[4]);


	cout << "\"" << stdtFl << "\"" << endl;
	cout << "\"" << gradFl << "\"" << endl;
	cout << "\"" << quriFl << "\"" << endl;
	cout << "\"" << outFl << "\"" << endl;

	for (int i = 0; i < argc; i++){
	cout << "--Argv: " << argv[i] << "::  " << argc << ":" << endl;
	}*/

	system("pause");
	return 0;

}