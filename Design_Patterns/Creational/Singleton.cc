#include <bits/stdc++.h>
#include "Singleton.hh"
using namespace std;

Singleton* Singleton::_singleton = nullptr;

Singleton* Singleton::getInstance (const string& value) {
    if (!_singleton) {
        _singleton = new Singleton(value);
    }
    return _singleton;
}

string Singleton::getValue() { 
    return _value;
}

void Singleton::restart() {
    delete _singleton;
}

int main () {

    Singleton* obj1 = Singleton::getInstance("1st");
    Singleton* obj2 = Singleton::getInstance("2nd");

    cout<<"obj1 used : "<<obj1->getValue()<<"\n";
    cout<<"obj2 used : "<<obj2->getValue()<<"\n";

    return 0;
}