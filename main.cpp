#include <iostream>
#include "buildings.h"
#include <list>
#include <vector>

using namespace std;

int main()
{
    /* We can repair buildings
    Houses my_house;
    my_house.setBuildingCondition(BuildingCondition::needs_repair);
    BuildingCondition cur_cond = my_house.getBuildCondition();
    wcout << static_cast<int>(cur_cond) <<endl;
    my_house.repair(cur_cond);
    cur_cond = my_house.getBuildCondition();
    wcout << static_cast<int>(cur_cond);
    */

    /* Massive
    BuildingMassive my_massive(5);
    cout <<  "====Massive of buildings=====\n";


    for (int i = 0; i<my_massive.length(); i++){
        my_massive.add(new Houses());
    }

    Iterator<BuildPtr> *it_mas = my_massive.getIter();
    for (it_mas->first(); !it_mas->isDone(); it_mas->next()){
        cout << (*it_mas->getCurrent()).getBuilding() << endl;
    }

    cout << "Build count: " << my_massive.getCount() << endl;
    cout << "Massive size: " << my_massive.length() << endl;
    */

    /* List
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

    */

    /* Vector
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
    */


    BuildingVector decor_vector;
    for (int i=0; i<30; i++){
        BuildingType type = static_cast<BuildingType>(rand()%4);

    }
    Iterator<BuildPtr> *it_vector = decor_vector.getIter();

    /* is state decorator

    Iterator<BuildPtr> *it_state = new is_state_decor(it_vector, true);


    */


    /* is type decorator

    Iterator<BuildPtr> *it_type = new is_type_decor(it_vector, BuildingType::shop_center);

    */


    /* is condition decorator

    Iterator<BuildPtr> *it_condition = new is_condition_decor(it_vector, BuildingCondition::fine);

    */


    /* is type and condition decorator

    Iterator<BuildPtr> *it_type_cond = new is_type_and_condition_decor(it_vector, BuildingType::parking, BuildingCondition::fresh);

    */



    return 0;
}
