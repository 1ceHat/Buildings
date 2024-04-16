#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <iostream>
#include <vector>
#include <list>

using namespace std;

enum class BuildingType: int{
    house,
    shop_center,
    hospital,
    parking,
    unknown = -1

};

enum class BuildingCondition : int{
    critical = 0,
    needs_repair = 1,
    fine = 2,
    fresh = 3,
    unknown = -1
};

class buildings
{
protected:
    bool BuildingIsBuilt;
    BuildingType Type;
    BuildingCondition Condition;
    int NumberFloors;
    buildings();

public:
    bool getBuildState() const {return BuildingIsBuilt;};
    BuildingType getBuildType() const {return Type;};
    BuildingCondition getBuildCondition() const {return Condition;};
    virtual int getNumFloors() const = 0;
    virtual int getNumObjects() const = 0;
    void setBuildingCondition(BuildingCondition condition){Condition = condition;}
    void setNumFloors(int number) {NumberFloors = number;};
    void repair(BuildingCondition cond);

};

typedef buildings* BuildPtr;

class Houses : public buildings{
protected:
    int NumberResidents;
public:
    Houses(): buildings(){
        Type = BuildingType::house;
        Condition = BuildingCondition::fresh;
        NumberFloors = 5;
        NumberResidents = 50;
    };
    virtual int getNumFloors() const {return NumberFloors;};
    virtual int getNumObjects() const {return NumberResidents;};
};

class Shops : public buildings{
protected:
    int NumberShops;
public:
    Shops(): buildings(){
        Type = BuildingType::shop_center;
        Condition = BuildingCondition::fresh;
        NumberFloors = 3;
        NumberShops = 100;
    };
    virtual int getNumFloors() const {return NumberFloors;};
    virtual int getNumObjects() const {return NumberShops;};
};

class Hospitals : public buildings{
protected:
    int NumberPatient;
public:
    Hospitals(): buildings(){
        Type = BuildingType::hospital;
        Condition = BuildingCondition::fresh;
        NumberFloors = 3;
        NumberPatient = 50;
    };
    virtual int getNumFloors() const {return NumberFloors;};
    virtual int getNumObjects() const {return NumberPatient;};
};

class Parkings : public buildings{
protected:
    int NumberCars;
    int NumberParkingSpaces;
public:
    Parkings(): buildings(){
        Type = BuildingType::parking;
        Condition = BuildingCondition::fresh;
        NumberFloors = 4;
        NumberParkingSpaces = 50;
        NumberCars = 28;
    };
    virtual int getNumFloors() const {return NumberFloors;};
    virtual int getNumObjects() const {return NumberCars;};
    int getNumParkSpaces() const {return NumberParkingSpaces;};
};

#endif // BUILDINGS_H
