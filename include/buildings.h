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
// Parent class of buildings
class buildings{
private:
    bool IsBuilt;
    BuildingType Type;
    BuildingCondition Condition;
    int NumberFloors;

protected:
    buildings();
    void setBuildigType(BuildingType type){Type = type;}

public:
    // getting information
    bool getBuildState() const {return IsBuilt;};
    BuildingType getBuildType() const {return Type;};
    BuildingCondition getBuildCondition() const {return Condition;};
    virtual int getNumFloors() const {return NumberFloors;}
    virtual int getNumObjects() const {};
    virtual string getBuilding() = 0;

    // upgrade building's condition by 1
    void repair(BuildingCondition cond);

    // setting information
    void setState(bool is_built){IsBuilt = is_built;}
    void setBuildingCondition(BuildingCondition condition){Condition = condition;}
    void setNumFloors(int number) {NumberFloors = number;};
    virtual void setNumObjects(int number) = 0;

    // fabric
    static buildings* create(BuildingType type);
};
typedef buildings* BuildPtr;

// building's hereditary class Houses
class Houses : public buildings{
private:
    int NumberResidents = 0;
public:
    Houses(): buildings(){
        setBuildigType(BuildingType::house);
        if(getBuildState()){
            setBuildingCondition(static_cast<BuildingCondition>(rand()%3));
            setNumFloors(rand()%5+1);
            NumberResidents = rand()%50+1;
        }
    };
    //getting information
    virtual int getNumObjects() const override {return NumberResidents;};
    virtual string getBuilding() override;

    //setting information
    void setNumObjects(int number) {NumberResidents = number;};
};

// building's hereditary class Shops
class Shops : public buildings{
protected:
    int NumberShops = 0;
public:
    Shops(): buildings(){
        setBuildigType(BuildingType::shop_center);
        if(getBuildState()){
            setBuildingCondition(static_cast<BuildingCondition>(rand()%3));
            setNumFloors(rand()%5+1);
            NumberShops = rand()%100+1;
        }
    };
    //getting information
    virtual int getNumObjects() const override {return NumberShops;};
    virtual string getBuilding() override;

    //setting information
    void setNumObjects(int number) {NumberShops = number;};
};

// building's hereditary class Hospitals
class Hospitals : public buildings{
protected:
    int NumberPatient = 0;
public:
    Hospitals(): buildings(){
        setBuildigType(BuildingType::hospital);
        if(getBuildState()){
            setBuildingCondition(static_cast<BuildingCondition>(rand()%3));
            setNumFloors(rand()%3+1);
            NumberPatient = rand()%50+1;
        }
    };
    //getting information
    virtual int getNumObjects() const override {return NumberPatient;};
    virtual string getBuilding() override;

    //setting information
    virtual void setNumObjects(int number) {NumberPatient = number;}
};

// building's hereditary class Parkings
class Parkings : public buildings{
protected:
    int NumberCars = 0;
    int NumberParkingSpaces = 0;
public:
    Parkings(): buildings(){
        setBuildigType(BuildingType::parking);
        if(getBuildState()){
            setBuildingCondition(static_cast<BuildingCondition>(rand()%3));
            setNumFloors(rand()%4+1);
            NumberParkingSpaces = rand()%50+1;
            NumberCars = (rand()%50)%NumberParkingSpaces;
        }
    };
    //getting information
    virtual int getNumObjects() const override {return NumberCars;};
    int getNumParkSpaces() const {return NumberParkingSpaces;};
    virtual string getBuilding();

    //setting information
    virtual void setNumObjects(int number) {NumberCars = number;}
    void setNumParkSpaces(int number) {NumberParkingSpaces = number;}
};

// Parent class of containers
class BuildingContainer{
protected:
    BuildPtr *BuildingCont;

public:
    virtual BuildPtr getLast() const = 0;
    virtual int length() const = 0;
    virtual Iterator<BuildPtr> *getIter() = 0;
    virtual void add(BuildPtr new_build) = 0;
};

// Massive's iterator
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

// container's hereditary class Massive
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

// List's iterator
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

// container's hereditary class List
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

// Vector's iterator
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

// container's hereditary class Vector
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

// decorator filters object by their state
class is_state_decor : public IteratorDecorator<BuildPtr>{
private:
    bool TargetState;

public:

    is_state_decor(Iterator<BuildPtr>* it, bool state):IteratorDecorator(it) {TargetState = state;}

    void first(){
        It->first();
        while(!It->isDone()
            && It->getCurrent()->getBuildState()!=TargetState)
            {It->next();}
    }

    void next(){
        do{It->next();}
        while(!It->isDone()
              && It->getCurrent()->getBuildState()!=TargetState);
    }

};

// decorator filters object by their type
class is_type_decor : public IteratorDecorator<BuildPtr>{
private:
    BuildingType TargetType;

public:

    is_type_decor(Iterator<BuildPtr>* it, BuildingType type):IteratorDecorator(it) {TargetType = type;}

    void first(){
        It->first();
        while(!It->isDone()
            && It->getCurrent()->getBuildType()!=TargetType)
            {It->next();}
    }

    void next(){
        do{It->next();}
        while(!It->isDone()
              && It->getCurrent()->getBuildType()!=TargetType);
    }

};

// decorator filters object by their condition
class is_condition_decor : public IteratorDecorator<BuildPtr>{
private:
    BuildingCondition TargetCondition;

public:
    is_condition_decor(Iterator<BuildPtr> *it, BuildingCondition condition):IteratorDecorator(it){TargetCondition = condition;}

    void first(){
        It->first();
        while (!It->isDone()
               && It->getCurrent()->getBuildCondition()!=TargetCondition)
            {It->next();}
    }

    void next(){
        do{It->next();}
        while(!It->isDone()
               && It->getCurrent()->getBuildCondition()!=TargetCondition);
    }
};

// decorator filters object by their type and condition
class is_type_and_condition_decor : public IteratorDecorator<BuildPtr>{
private:
    BuildingType TargetType;
    BuildingCondition TargetCondition;

public:
    is_type_and_condition_decor(Iterator<BuildPtr> *it, BuildingType type, BuildingCondition condition):IteratorDecorator(it){
        TargetCondition = condition;
        TargetType = type;
    }

    void first(){
        It->first();
        while (!It->isDone()
               && !(It->getCurrent()->getBuildCondition()==TargetCondition
                    &&It->getCurrent()->getBuildType()==TargetType))
            {It->next();}
    }

    void next(){
        do{It->next();}
        while(!It->isDone()
               && !(It->getCurrent()->getBuildCondition()==TargetCondition
                    &&It->getCurrent()->getBuildType()==TargetType));
    }
};
#endif // BUILDINGS_H
