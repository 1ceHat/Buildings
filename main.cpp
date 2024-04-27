#include <iostream>
#include "buildings.h"
#include <list>
#include <vector>

using namespace std;

int main()
{
    //* We can repair buildings
    cout <<  "====Base operations with buildings objects=====\n";
    Houses my_house;
    my_house.setNumFloors(10);
    my_house.setNumObjects(30);
    my_house.setBuildingCondition(BuildingCondition::critical);
    cout << my_house.getBuilding() << endl;
    my_house.repair(my_house.getBuildCondition());
    cout << my_house.getBuilding() << endl;
    //*/

    //* Massive
    BuildingMassive my_massive(5);
    cout <<  "\n====Massive of buildings=====\n";


    for (int i = 0; i<my_massive.length(); i++){
        my_massive.add(new Houses());
    }

    Iterator<BuildPtr> *it_mas = my_massive.getIter();
    for (it_mas->first(); !it_mas->isDone(); it_mas->next()){
        cout << (*it_mas->getCurrent()).getBuilding() << endl;
    }

    cout << "Build count: " << my_massive.getCount() << endl;
    cout << "Massive size: " << my_massive.length() << endl;
    //*/

    //* List
    BuildingList my_list;
    cout << "\n====List of buildings=====\n";
    for (int i = 0; i<5; i++){
        my_list.add(new Parkings());
    };

    Iterator<BuildPtr> *it_list = my_list.getIter();
    for (it_list->first(); !it_list->isDone(); it_list->next()){
        cout << (*it_list->getCurrent()).getBuilding() << endl;
    }

    cout << "List size: " << my_list.length() << endl;

    //*/

    //* Vector
    BuildingVector my_vector;
    cout << "\n====Vector of buildings=====" << endl;
    for (int j = 0; j<5; j++){
        my_vector.add(new Hospitals());
    }

    Iterator<BuildPtr> *it_vector = my_vector.getIter();
    for (it_vector->first(); !it_vector->isDone(); it_vector->next()){
        cout << (*it_vector->getCurrent()).getBuilding() << endl;
    }

    cout << "Vector size: " << my_vector.length() << endl;
    cout << "Third building has " << my_vector.getByIndex(2)->getNumFloors() << " floors\n";
    //*/


    BuildingVector decor_vector;
    for (int i=0; i<30; i++){
        BuildingType type = static_cast<BuildingType>(rand()%4);
        decor_vector.add(buildings::create(type));
    }
    Iterator<BuildPtr> *it_Dvector = decor_vector.getIter();
    int i = 0;

    //* is state decorator
    cout << "\n====is state decorator=====" << endl;

    Iterator<BuildPtr> *it_state = new is_state_decor(it_Dvector, true);
    for (it_state->first(); !it_state->isDone(); it_state->next()){
        cout << i++ << ": ";
        cout << it_state->getCurrent()->getBuilding() << endl;
    }
    i=0;
    //*/


    //* is type decorator
    cout << "\n====is type decorator=====" << endl;

    Iterator<BuildPtr> *it_type = new is_type_decor(it_Dvector, BuildingType::shop_center);
    for (it_type->first(); !it_type->isDone(); it_type->next()){
        cout << i++ << ": ";
        cout << it_type->getCurrent()->getBuilding() << endl;
    }
    i=0;
    //*/


    //* is condition decorator
    cout << "\n====is condition decorator=====" << endl;
    Iterator<BuildPtr> *it_condition = new is_condition_decor(it_Dvector, BuildingCondition::fine);
    for (it_condition->first(); !it_condition->isDone(); it_condition->next()){
        cout << i++ << ": ";
        cout << it_condition->getCurrent()->getBuilding() << endl;
    }
    i=0;
    //*/


    //* is type and condition decorator
    cout << "\n====is type and condition decorator=====" << endl;

    Iterator<BuildPtr> *it_type_cond = new is_type_and_condition_decor(it_Dvector, BuildingType::parking, BuildingCondition::critical);
    for (it_type_cond->first(); !it_type_cond->isDone(); it_type_cond->next()){
        cout << i++ << ": ";
        cout << it_type_cond->getCurrent()->getBuilding() << endl;
    }
    i=0;
    //*/



    return 0;
}
