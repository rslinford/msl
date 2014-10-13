#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
using namespace std;

/*
void printMap(map<string, vector<int>> &result) 
{
    cout << " in PrintMap " << endl;
}
*/

void printMap(map<string, list<int>> &result)
{
 for (map<string, list<int>>::const_iterator it = result.begin(); it != result.end(); ++it)
 {
 	cout << "Key " << it->first << endl;
 	//cout << "Value " << it->second << endl;
 	const list<int> &v = it->second;
 	for (list<int>::const_iterator it2 = v.begin(); it2 != v.end(); ++it2)
 	{
 	 cout << "Value " << it2->first << endl;
 	}
 	//cout << "My map[" << it->first << "] = " /*<< it->second*/ << endl;
 }
}


int main(int argc, char *argv[]) 
{
 //   map<string, list<int>> m;
    
//    list<int> l;
    
  //  m["hello"] = l;

    //cout << m["hello"] << endl;
    return 0;
}
