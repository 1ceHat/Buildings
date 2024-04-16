#include "buildings.h"

buildings::buildings()
{
    Type = BuildingType::unknown;
    Condition = BuildingCondition::unknown;
}

void buildings::repair(BuildingCondition cond){
    switch(cond){
        case BuildingCondition::critical: {setBuildingCondition(BuildingCondition::needs_repair); break;};
        case BuildingCondition::needs_repair: {setBuildingCondition(BuildingCondition::fine); break;};
        case BuildingCondition::fine: {setBuildingCondition(BuildingCondition::fresh); break;};
        default: wcout << L"There's no reasons for repairing" << endl;
    }
}
