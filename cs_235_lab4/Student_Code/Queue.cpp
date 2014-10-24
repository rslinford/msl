#pragma once
#include "Queue.h"

using namespace std;

bool Queue::addToQueue(int x){
    list.insertTail(x);
    return true;
}

int Queue::showTopOfQueue() {
    return list.at(0);
}

bool Queue::removeFromQueue(){
    if (list.size() == 0){
        return false;
    }
    
    list.remove(list.at(0))
    return true;
}

int Queue::showSizeOfQueue(){
    return list.size();
}
