#ifndef DIRECTION_H
#define DIRECTION_H

#include <ostream>

using namespace std;

enum Direction
{
    none,
    forward,
    //rightforward,
    rightward,
    //rightbackward,
    backward,
    //lefbacktward,
    leftward,
    //leftforward
};

inline ostream& operator<<(ostream& os, const Direction& direction )
{
    switch( direction ){
    case Direction::forward: os << "forward"; break;
    case rightward: os << "rightward"; break;
    case backward: os << "backward"; break;
    case leftward: os << "leftward"; break;
    default: os << "none"; break;
    }
}

#endif // DIRECTION_H
