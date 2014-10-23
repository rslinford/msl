#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    int value0 = 0;
    int value1 = 1;
    int value2 = 2;
    int value5 = 5;
    int value10 = 10;
    
    LinkedList t = LinkedList();
    
    t.insertHead(123);
    if (t.at(0) != 123) {
        cout << "Error expected 123 at [0] found " << t.at(0) << endl;
        return 1;
    }
    
    t.insertHead(321);
    if (t.at(0) != 321) {
        cout << "Error expected 321 at [0] found " << t.at(0) << endl;
        return 1;
    }
    
    t.insertHead(123);
    if (t.size() != 2) {
        cout << "Error expected size of 2 but found " << t.size() << endl;
        return 1;
    }
    
    if (t.at(0) != 321) {
        cout << "Error expected 321 at [0] found " << t.at(0) << endl;
        return 1;
    }
    
    if (t.at(1) != 123) {
        cout << "Error expected 123 at [0] found " << t.at(0) << endl;
        return 1;
    }
    
    t.clear();
    if (t.size() != 0) {
        cout << "Error expected size of 0 but found " << t.size() << endl;
        return 1;
    }
    
    t.insertHead(321);   
    t.insertHead(123);   
    t.insertHead(654);
    t.insertHead(456);
    t.insertHead(987);
    
    if (t.size() != 5) {
        cout << "Error expected size of 5 but found " << t.size() << endl;
        return 1;
    }    
    
    t.remove(654);

    if (t.size() != 4) {
        cout << "Error expected size of 4 but found " << t.size() << endl;
        return 1;
    }
    
    t.remove(987);
    if (t.size() != 3) {
        cout << "Error expected size of 3 but found " << t.size() << endl;
        return 1;
    }

    cout << endl << "All tests passed!" << endl;
    return 0;
}
