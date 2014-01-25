#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <vector>
#include "grades.h"
#include "student.h"
using namespace std;

double gradeConvert(string g)
{
	if (g == "A")
	{
		return 4.0;
	}
	else if (g == "A-")
	{
		return 3.7;
	}
	else if (g == "B+")
	{
		return 3.7;
	}
	else if (g == "B")
	{
		return 3.0;
	}
	else if (g == "B-")
	{
		return 2.7;
	}
	else if (g == "C+")
	{
		return 2.4;
	}
	else if (g == "C")
	{
		return 2.0;
	}
	else if (g == "C-")
	{
		return 1.7;
	}
	else if (g == "D+")
	{
		return 1.4;
	}
	else if (g == "D")
	{
		return 1.0;
	}
	else if (g == "D-")
	{
		return 0.7;
	}
	else if (g == "E")
	{
		return 0.0;
	}
	return 0;
}



int main(int argc, char *argv[]) {
	
	ofstream print;
	print.open(argv[4]);


	ifstream in_put;
	in_put.open(argv[1]);
	student* s; 
	vector<student> studentlist;
	
	while (!in_put.fail()){
		s = new student;
		in_put >> *s;
		
		if (!in_put.fail())
		{
			studentlist.push_back(*s); 
		}
	}

	sort(studentlist.begin(), studentlist.end());
	
	for (int i = 0; i < studentlist.size(); i++)
	{
		if (i > 0)
		{
			cout << 4321 << endl;
			print << endl;
		}
		cout << 1234 << endl;
		print << studentlist[i];
	}

	in_put.close();

	ifstream inGrades;
	inGrades.open(argv[2]);
	grades* g;
	vector<grades> gradelist;

	while (!inGrades.fail()){
		g = new grades;
		inGrades >> *g;

		if (!inGrades.fail())
		{
			gradelist.push_back(*g);
		}
	}

	if (studentlist.size() != 0)
	{
		print << endl;
	}

	if (gradelist.size() == 0)
	{
		print << endl;
	}

	sort(gradelist.begin(), gradelist.end());

	for (int i = 0; i < gradelist.size(); i++){
		/*if (i == 0)
		{
			cout << 1234 << gradelist[i].getGrade() << endl;
			print << endl;
		}*/
		cout << 56 << gradelist[i].getGrade() << endl;
		print << endl;
		
		cout << 789 << gradelist[i].getGrade() << endl;
		print << gradelist[i];
		
	}

	inGrades.close();

	ifstream inQ;
	inQ.open(argv[3]);
	string id;
	int addcounter = 0;
	while (getline(inQ, id))
	{
		

		string name;
		double gpa = 0.00;
		
		for (int i = 0; i < studentlist.size(); i++)
		{
			if (id == studentlist[i].getID())
			{
				name = studentlist[i].getName();
				break;
			}
			
		}
		if (name == "")
		{
			continue;
		}
		
		int gradesFound = 0;
		for (int i = 0; i < gradelist.size(); i++)
		{
			if (id == gradelist[i].getId())
			{
				gradesFound++;
				double num = gradeConvert(gradelist[i].getGrade());
				gpa = gpa + num;
			}
		}
		if (gradesFound == 0) { gpa = 0.00;}
		else { gpa = gpa / gradesFound; }
		if (addcounter == 0 && gradelist.size() > 0)
		{
			print << endl;
		}
		addcounter++;
		print << endl << fixed << setprecision(2) << id << "    " << gpa << "    " << name;
	}
	print.close();
	
	system("pause");
	
	return 0;

}