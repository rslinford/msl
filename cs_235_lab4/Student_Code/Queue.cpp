#pragma once
#include "Queue.h"

using namespace std;

bool Queue::addToQueue(int x){
    list->insertTail(x);
    return true;
}

int Queue::showTopOfQueue() {
    if (list->size() <= 0) {
        return -1;
    }
    return list->at(0);
}

bool Queue::removeFromQueue(){
    if (list->size() <= 0){
        return false;
    }
    
    list->remove(list->at(0));
    return true;
}

int Queue::showSizeOfQueue(){
    return list->size();
}

bool Queue::isDuplicate(int x) {
    return list->duplicate(x);
}
