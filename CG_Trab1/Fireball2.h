#ifndef FIREBALL2_H
#define FIREBALL2_H

#include<URGE/URGE.h>

USING_URGE;

class Fireball2 : public Generic
{
    public:
        Fireball2();

        void act();
        int collide(Object& other);
};

#endif // FIREBALL2_H
