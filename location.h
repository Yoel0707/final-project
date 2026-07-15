#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

class Location {

private:
    string name;
    string description;
bool completed; 
public:

    Location(string locationName, string locationDescription);

    string getname();
    string getdescription();
    void completelocation(); 
    bool iscompleted();

};

#endif