#include <bits/stdc++.h>
using namespace std;

class Singleton {

    public : 
    static Singleton* getInstance (const string& value);
    string getValue();
    void restart();

    private :
    Singleton (string value) : _value(value) {}
    Singleton (const Singleton& obj);
    void operator=(const Singleton& obj);

    private : 
    static Singleton* _singleton;
    string _value;
};