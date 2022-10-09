#include <bits/stdc++.h>
#include "Singleton.hh"
using namespace std;

//will be completed later

Singleton* Singleton::_singleton = nullptr;

Singleton* Singleton::getInstance (const string& value) {
    //for thread safe use a mutex lock here
    if (!_singleton) {
        _singleton = new Singleton(value);
    }
    return _singleton;
}

int main () {



    return 0;
}