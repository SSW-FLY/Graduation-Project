#include "Robot.h"

Robot::Robot()
{
    plate = 0;
    hold = 0;
    loc = -1;
    loc_lock = -1;
    lockType = "";
    lockPlate = -1;

}
Robot::~Robot() {}

void Robot::setPlate(int _plate)
{
    plate = _plate;
}
int Robot::getPlate()
{
    return plate;
}

void Robot::setHold(int _hold)
{
    hold = _hold;
}
int Robot::getHold()
{
    return hold;
}

void Robot::setLoc(int _loc)
{
    loc = _loc;
}
int Robot::getLoc()
{
    return loc;
}

void Robot::setLock(int lock)
{
    loc_lock = lock;
}
int Robot::getLock()
{
    return loc_lock;
}

void Robot::setlockType(string _lockType)
{
    lockType = _lockType;
}
string Robot::getlockType()
{
    return lockType;
}

void Robot::setlockPlate(int _lockPlate)
{
    lockPlate = _lockPlate;
}
int Robot::getlockPlate()
{
    return lockPlate;
}

void Robot::show()
{
    cout << loc << "---" << plate << "---" << hold << endl;
}