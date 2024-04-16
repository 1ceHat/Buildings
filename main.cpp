#include <iostream>
#include "buildings.h"

using namespace std;

int main()
{
    Houses my_house;
    my_house.setBuildingCondition(BuildingCondition::needs_repair);
    BuildingCondition cur_cond = my_house.getBuildCondition();
    wcout << static_cast<int>(cur_cond) <<endl;
    my_house.repair(cur_cond);
    cur_cond = my_house.getBuildCondition();
    wcout << static_cast<int>(cur_cond);

    return 0;
}
