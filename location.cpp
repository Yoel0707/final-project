#include "location.h"

Location::Location(string locationName, string locationDescription) {
    name = locationName;
    description = locationDescription;
completed = false;
}

string Location::getname() {
    return name;
}

string Location::getdescription() {
    return description;
}

bool Location::iscompleted() {
    return completed;
}

void Location::completelocation() {
    completed = true;
}