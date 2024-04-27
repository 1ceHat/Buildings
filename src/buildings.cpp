#include "buildings.h"
#include <iostream>
#include <string>

using namespace std;

buildings::buildings()
{
    IsBuilt = bool(rand()%2);
    Type = BuildingType::unknown;
    Condition = BuildingCondition::unknown;
    NumberFloors = 0;
}

void buildings::repair(BuildingCondition cond){
    switch(cond){
        case BuildingCondition::critical: {setBuildingCondition(BuildingCondition::needs_repair); break;};
        case BuildingCondition::needs_repair: {setBuildingCondition(BuildingCondition::fine); break;};
        case BuildingCondition::fine: {setBuildingCondition(BuildingCondition::fresh); break;};
        default: wcout << L"There's no reasons for repairing" << endl;
    }
}

string getType(BuildingType type){
    switch (type){
        case BuildingType::hospital : {return "Hospital"; break;}
        case BuildingType::house : {return "House"; break;}
        case BuildingType::parking: {return "Parking"; break;}
        case BuildingType::shop_center: {return "Shop center"; break;}
        case BuildingType::unknown: {return "unknown"; break;}
    }
}

string getCondition(BuildingCondition condition){
    switch (condition){
        case BuildingCondition::critical : {return "Critical"; break;}
        case BuildingCondition::needs_repair : {return "Needs repair"; break;}
        case BuildingCondition::fine: {return "Fine"; break;}
        case BuildingCondition::fresh : {return "Fresh"; break;}
        case BuildingCondition::unknown : {return "unknown"; break;}
    }
}

string Houses::getBuilding(){
    //building properties
    string isBuild = getBuildState()? "built" : "not built yet";
    string type = getType(getBuildType());
    string condition = getCondition(getBuildCondition());
    string number = to_string(getNumFloors());
    //hereditary class
    string residents = to_string(getNumObjects());
    return ("I has been " + isBuild +
            ". I'm " + type +
            ". My condition is: " + condition +
            ". I've " + number +
            " floors. And i can keep " + residents +
            " residents.");
}

string Hospitals::getBuilding(){
    //building properties
    string isBuild = getBuildState()? "built" : "not built yet";
    string type = getType(getBuildType());
    string condition = getCondition(getBuildCondition());
    string number = to_string(getNumFloors());
    //hereditary class properties
    string patients = to_string(getNumObjects());
    return ("I has been " + isBuild +
            ". I'm " + type +
            ". My condition is: " + condition +
            ". I've " + number +
            " floors. And i can keep " + patients +
            " patients.");
}

string Parkings::getBuilding(){
    //building properties
    string isBuild = getBuildState()? "built" : "not built yet";
    string type = getType(getBuildType());
    string condition = getCondition(getBuildCondition());
    string number = to_string(getNumFloors());
    //hereditary class properties
    string cars = to_string(getNumObjects());
    string parking_spaces = to_string(getNumParkSpaces());
    return ("I has been " + isBuild +
            ". I'm " + type +
            ". My condition is: " + condition +
            ". I've " + number +
            " floors. And i can keep " + parking_spaces +
            " cars, but now there is " + cars +
            " cars.");
}

string Shops::getBuilding(){
    //building properties
    string isBuild = getBuildState()? "built" : "not built yet";
    string type = getType(getBuildType());
    string condition = getCondition(getBuildCondition());
    string number = to_string(getNumFloors());
    //hereditary class properties
    string shops = to_string(getNumObjects());
    return ("I has been " + isBuild +
            ". I'm " + type +
            ". My condition is: " + condition +
            ". I've " + number +
            " floors. And i can keep " + shops +
            " shops.");
}

BuildingMassive::BuildingMassive(int max_size){
    BuildMassive = new BuildPtr[max_size];
    for (int i = 0; i<max_size; i++){
        BuildMassive[i] = NULL;
    }
    BuildCount = 0;
    MaxSize = max_size;
};
BuildingMassive::~BuildingMassive(){
    for (int i = 0; i<MaxSize; i++){
        if(BuildMassive[i] != NULL){
            BuildMassive[i] = NULL;
        }
    }
    delete[] BuildMassive;
};

void BuildingMassive::add(BuildPtr new_build){
    BuildMassive[BuildCount++] = new_build;
};
