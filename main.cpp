#include <iostream>
#include "buildings.h"
#include <list>
#include <vector>

using namespace std;

int main()
{
    Houses my_house;
    /*my_house.setBuildingCondition(BuildingCondition::needs_repair);
    BuildingCondition cur_cond = my_house.getBuildCondition();
    wcout << static_cast<int>(cur_cond) <<endl;
    my_house.repair(cur_cond);
    cur_cond = my_house.getBuildCondition();
    wcout << static_cast<int>(cur_cond);*/

    /*
    BuildingMassive my_massive(5);
    cout <<  "====Massive of buildings=====\n";
    for (int i = 0; i<my_massive.length(); i++){
        my_massive.add(new Houses());
        cout << i << " " << my_massive.getByIndex(i)->getBuilding() << endl;
    }
    cout << "Build count: " << my_massive.getCount() << endl;
    cout << "Massive size: " << my_massive.length() << endl;


    BuildingList my_list;
    cout << "\n====List of buildings=====\n";
    for (int i = 0; i<5; i++){
        my_list.add(new Parkings());
        cout << i << " " << my_list.getLast()->getBuilding()<< endl;
    };
    cout << "List size: " << my_list.length() << endl;


    BuildingVector my_vector;
    cout << "\n====Vector of buildings=====" << endl;
    for (int j = 0; j<5; j++){
        my_vector.add(new Hospitals());
        cout << j << " " << my_vector.getLast()->getBuilding()<< endl;
    }
    cout << "Vector size: " << my_vector.length() << endl;
    cout << "Third building has " << my_vector.getByIndex(2)->getNumFloors() << " floors\n";
    */



    return 0;
}
