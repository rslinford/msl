#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <vector>
#include "grades.h"
#include "student.h"
using namespace std;

double gradeConvert (string g)
{
	double out = 0.0;
	string letArr[] = { "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "E" };
	double grdArr[] = { 4.0, 3.7, 3.4, 3.0, 2.7, 2.4, 2.0, 1.7, 1.4, 1.0, 0.7, 0.0};
	for (int i = 0; i < 12; i++)
	{
		if (g == letArr[i])
		{
			out = grdArr[i];
			break;
		}
	}
	return out;
}

void fillStdVect (vector<student> &studentlist, istream &in_put)
{
    student* s; 
	while (!in_put.fail())
	{
		s = new student;
		in_put >> *s;
		
		if (!in_put.fail())
		{
			studentlist.push_back(*s); 
		}
	}
}

void fillGrdVect (vector<grades> &gradelist, istream &inGrades)
{
    grades* g;
    while (!inGrades.fail())
    {
		g = new grades;
		inGrades >> *g;

		if (!inGrades.fail())
		{
			gradelist.push_back(*g);
		}
    }
}

void printStudent (vector<student> &studentlist, ostream &print)
{
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
	if (studentlist.size() != 0 )
	{
		print << endl; // Windows line terminator "\r\n"   Linux "\n"
	}
}

void printGrades (vector<grades> &gradelist, ostream &print)
{
   if (gradelist.size() == 0)
	{
		print << endl;
	}
	
    for (int i = 0; i < gradelist.size(); i++)
	{
		
		cout << 56 << gradelist[i].getGrade() << endl;
		print << endl;
		
		cout << 789 << gradelist[i].getGrade() << endl;
		print << gradelist[i];
		
	}
}

double gpaCalculator (vector<grades> &gradelist, string id)
{
    int gradesFound = 0;
    double sum = 0.0;
	for (int i = 0; i < gradelist.size(); i++)
	{
		if (id == gradelist[i].getId())
		{
			gradesFound++;
			double num = gradeConvert(gradelist[i].getGrade());
			sum = sum + num;
		}
	}
	
	if (gradesFound == 0) { 
	    return 0.00;
	}
	
    return sum / gradesFound;
}

void postPrint (vector<grades> &gradelist, ostream &print, int addcounter)
{
    if (addcounter == 0 && gradelist.size() > 0)
    	{
    		print << endl;
    	}
}

int main(int argc, char *argv[]) {
	
	ofstream print;
	print.open(argv[4]);

	ifstream in_put;
	in_put.open(argv[1]);

	vector<student> studentlist;
	
	fillStdVect (studentlist, in_put);

	sort(studentlist.begin(), studentlist.end());
	
	printStudent ( studentlist, print);

	in_put.close();

	ifstream inGrades;
	inGrades.open(argv[2]);

	vector<grades> gradelist;
    fillGrdVect (gradelist, inGrades);

	sort(gradelist.begin(), gradelist.end());
	
    printGrades (gradelist, print);

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
		
		gpa = gpaCalculator (gradelist, id);
		
		postPrint (gradelist, print, addcounter);
		
		addcounter++;
		print << endl << fixed << setprecision(2) << id << "    " << gpa << "    " << name;
	}
	print.close();
	
	//system("pause");
	
	return 0;

}