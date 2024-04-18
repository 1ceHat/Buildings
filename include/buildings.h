#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <iostream>
#include <vector>
#include <list>

using namespace std;
#include "pattern_iterators.h"

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

class buildings{
protected:
    bool IsBuilt;
    BuildingType Type;
    BuildingCondition Condition;
    int NumberFloors;
    buildings();

public:
    bool getBuildState() const {return IsBuilt;};
    BuildingType getBuildType() const {return Type;};
    BuildingCondition getBuildCondition() const {return Condition;};
    virtual int getNumFloors() const = 0;
    virtual int getNumObjects() const = 0;
    virtual string getBuilding() = 0;
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
        if(getBuildState()){
            Condition = static_cast<BuildingCondition>(rand()%3);
            NumberFloors = rand()%5+1;
            NumberResidents = rand()%50+1;
        }
        else{
            Condition = BuildingCondition::unknown;
            NumberFloors = 0;
            NumberResidents = 0;
        }
    };
    virtual int getNumFloors() const {return NumberFloors;};
    virtual int getNumObjects() const {return NumberResidents;};
    virtual string getBuilding();
};

class Shops : public buildings{
protected:
    int NumberShops;
public:
    Shops(): buildings(){
        Type = BuildingType::shop_center;
        if(getBuildState()){
            Condition = static_cast<BuildingCondition>(rand()%3);
            NumberFloors = rand()%5+1;
            NumberShops = rand()%100+1;
        }
        else{
            Condition = BuildingCondition::unknown;
            NumberFloors = 0;
            NumberShops = 0;

        }
    };
    virtual int getNumFloors() const {return NumberFloors;};
    virtual int getNumObjects() const {return NumberShops;};
    virtual string getBuilding();
};

class Hospitals : public buildings{
protected:
    int NumberPatient;
public:
    Hospitals(): buildings(){
        Type = BuildingType::hospital;
        if(getBuildState()){
            Condition = static_cast<BuildingCondition>(rand()%3);
            NumberFloors = rand()%3+1;
            NumberPatient = rand()%50+1;
        }
        else{
            Condition = BuildingCondition::unknown;
            NumberFloors = 0;
            NumberPatient = 0;
        }
    };
    virtual int getNumFloors() const {return NumberFloors;};
    virtual int getNumObjects() const {return NumberPatient;};
    virtual string getBuilding();
};

class Parkings : public buildings{
protected:
    int NumberCars;
    int NumberParkingSpaces;
public:
    Parkings(): buildings(){
        Type = BuildingType::parking;
        if(getBuildState()){
            Condition = static_cast<BuildingCondition>(rand()%3);
            NumberFloors = rand()%4+1;
            NumberParkingSpaces = rand()%50+1;
            NumberCars = (rand()%50)%NumberParkingSpaces;
        }
        else{
            Condition = BuildingCondition::unknown;
            NumberFloors = 0;
            NumberParkingSpaces = 0;
            NumberCars = 0;
        }
    };
    virtual int getNumFloors() const {return NumberFloors;};
    virtual int getNumObjects() const {return NumberCars;};
    int getNumParkSpaces() const {return NumberParkingSpaces;};
    virtual string getBuilding();
};

class BuildingContainer{
protected:
    BuildPtr *BuildingCont;

public:
    virtual BuildPtr getLast() const = 0;
    virtual int length() const = 0;
    virtual void add(BuildPtr new_build) = 0;
    virtual Iterator<BuildPtr> *getIter() = 0;
};

class BuildMassiveIter : public Iterator<BuildPtr>{
private:
    const BuildPtr *BuildMassive;
    int Count;
    int Pos;

public:
    BuildMassiveIter(const BuildPtr* buildMassive, int amount){
        BuildMassive = buildMassive;
        Count = amount;
        Pos = 0;
    }
    void first() {Pos = 0;}
    void next() {Pos++;}
    bool isDone() const {return Pos>=Count;}
    BuildPtr getCurrent() const {return BuildMassive[Pos];}
};

class BuildingMassive : public BuildingContainer{
private:
    BuildPtr *BuildMassive;
    int BuildCount;
    int MaxSize;
public:
    BuildingMassive(int max_size);
    virtual ~BuildingMassive();
    BuildPtr getLast() const {return BuildMassive[-1];}
    BuildPtr getByIndex(int index) const {return BuildMassive[index];}
    int length() const {return MaxSize;}
    int getCount() const {return BuildCount;}
    void add(BuildPtr new_build);

    Iterator<BuildPtr> *getIter(){
        return new BuildMassiveIter(BuildMassive, BuildCount);
    }
};

class BuildListIter : public Iterator<BuildPtr>{
private:
    const list<BuildPtr> *BuildList;
    list<BuildPtr>::const_iterator it;

public:
    BuildListIter(const list<BuildPtr>* buildList){
        BuildList = buildList;
        it = BuildList->begin();
    }
    void first() {it = BuildList->begin();}
    void next() {it++;}
    bool isDone() const {return it==BuildList->end();}
    BuildPtr getCurrent() const {return *it;}
};

class BuildingList : public BuildingContainer{
private:
    list<BuildPtr> BuildList;
public:
    BuildPtr getLast() const {return BuildList.back();}
    int length() const {return BuildList.size();}
    void add(const BuildPtr new_build) {BuildList.push_back(new_build);}

    Iterator<BuildPtr> *getIter(){
        return new BuildListIter(&BuildList);
    }
};

class BuildVectorIter : public Iterator<BuildPtr>{
private:
    const vector<BuildPtr>* BuildVector;
    int Count;
    int Pos;
public:
    BuildVectorIter(const vector<BuildPtr>* buildVector){
        BuildVector = buildVector;
        Count = buildVector->size();
        Pos = 0;
    }
    void first() {Pos = 0;}
    void next() {Pos++;}
    bool isDone() const {return Pos>=Count;}
    BuildPtr getCurrent() const {return BuildVector->at(Pos);}
};

class BuildingVector : public BuildingContainer{
private:
    vector<BuildPtr> BuildVector;

public:
    BuildPtr getByIndex(int index) const {return BuildVector[index];}
    int length() const {return BuildVector.size();}
    BuildPtr getLast() const {return BuildVector.back();}
    void add(BuildPtr new_build) {BuildVector.push_back(new_build);}

    Iterator<BuildPtr>* getIter(){
        return new BuildVectorIter(&BuildVector);
    }
};

#endif // BUILDINGS_H
