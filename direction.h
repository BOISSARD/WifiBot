#ifndef DIRECTION_H
#define DIRECTION_H

#include <ostream>
#include <QDebug>

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
    qDebug() << direction;
    switch( direction ){
    case Direction::forward: os << "forward"; break;
    case rightward: os << "rightward"; break;
    case backward: os << "backward"; break;
    case leftward: os << "leftward"; break;
    default: os << "none"; break;
    }
    return os;
}

#endif // DIRECTION_H
